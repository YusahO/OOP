#include "vertex.h"
#include "common.h"
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <locale>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif

void vertices_init(vertices_t &verts)
{
    verts.array = nullptr;
    verts.amount = 0;
}

void vertices_destroy(vertices_t &verts)
{
    verts.amount = 0;
    free(verts.array);
    verts.array = nullptr;
}

static error_code_t create_vertex_array(vertices_t &verts, const size_t amount)
{
    error_code_t ec = SUCCESS;
    vertex_t *arr = (vertex_t *)malloc(sizeof(vertex_t) * amount);
    if (arr)
    {
        verts.array = arr;
        verts.amount = amount;
    }
    else
        ec = ERR_ALLOC;

    return ec;
}

size_t vertices_get_amount(const vertices_t &verts)
{
    return verts.amount;
}

// ------------------------- перемещение -------------------------
static inline void vertex_translate(vertex_t &vert, const vec3_t &delta)
{
    vert.x += delta.x;
    vert.y += delta.y;
    vert.z += delta.z;
}

void vertices_translate(vertices_t &verts, const vec3_t &delta)
{
    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_translate(verts.array[i], delta);
    }
}

// ------------------------- поворот -------------------------
static inline void vertex_rotate_x(vertex_t &vert, const double ax)
{
    double vy = vert.y;
    double vz = vert.z;
    vert.y = cos(ax) * vy - sin(ax) * vz;
    vert.z = sin(ax) * vy + cos(ax) * vz;
}

static inline void vertex_rotate_y(vertex_t &vert, const double ay)
{
    double vx = vert.x;
    double vz = vert.z;
    vert.x = cos(ay) * vx + sin(ay) * vz;
    vert.z = sin(ay) * vx + cos(ay) * vz;
}

static inline void vertex_rotate_z(vertex_t &vert, const double az)
{
    double vx = vert.x;
    double vy = vert.y;
    vert.x = cos(az) * vx - sin(az) * vy;
    vert.y = sin(az) * vx + cos(az) * vy;
}

static inline void shift_to_zero(vertex_t &vert, const vec3_t &pivot)
{
    vert.x -= pivot.x;
    vert.y -= pivot.y;
    vert.z -= pivot.z;
}

static inline void shift_to_pos(vertex_t &vert, const vec3_t &pivot)
{
    vert.x += pivot.x;
    vert.y += pivot.y;
    vert.z += pivot.z;
}

static void vertex_rotate(vertex_t &vert, const vec3_t &pivot, const vec3_t &angles)
{
    shift_to_zero(vert, pivot);
    vertex_rotate_x(vert, angles.x);
    vertex_rotate_y(vert, angles.y);
    vertex_rotate_z(vert, angles.z);
    shift_to_pos(vert, pivot);
}

void vertices_rotate(vertices_t &verts, const vec3_t &pivot, const vec3_t &angles)
{
    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_rotate(verts.array[i], pivot, angles);
    }
}

// ------------------------- масштабирование -------------------------
static inline void vertex_scale(vertex_t &vert, const vec3_t &pivot, const vec3_t &factor)
{
    shift_to_zero(vert, pivot);
    vert.x *= factor.x;
    vert.y *= factor.y;
    vert.z *= factor.z;
    shift_to_pos(vert, pivot);
}

void vertices_scale(vertices_t &verts, const vec3_t &pivot, const vec3_t &factor)
{
    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_scale(verts.array[i], pivot, factor);
    }
}

// ------------------------- чтение вершин -------------------------
static error_code_t read_vertices_amount(size_t &amount, FILE *f)
{
    error_code_t ec = SUCCESS;
    size_t amt = 0;
    if (fscanf(f, "%lu", &amt) != 1 || amt == 0)
        ec = ERR_INSUFFICIENT_VERTEX_DATA;

    amount = amt;
    return ec;
}

static error_code_t read_into_vertex(vertex_t &vert, FILE *f)
{
    error_code_t ec = SUCCESS;

    if (fscanf(f, "%lf %lf %lf", &vert.x, &vert.y, &vert.z) != 3)
        ec = ERR_INCORRECT_VERTEX_DATA;
    return ec;
}

static error_code_t read_vertices(vertices_t &verts, FILE *f)
{
    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    error_code_t ec = SUCCESS;
    for (size_t i = 0; i < verts.amount && ec == SUCCESS; ++i)
        ec = read_into_vertex(verts.array[i], f);

    setlocale(LC_NUMERIC, current_locale);
    return ec;
}

static error_code_t read_vertices_from_file(vertices_t &verts, FILE *f)
{
    error_code_t ec = SUCCESS;
    size_t amt = 0;

    ec = read_vertices_amount(amt, f);

    ec = create_vertex_array(verts, amt);
    if (ec == SUCCESS)
    {
        ec = read_vertices(verts, f);
        
        if (ec != SUCCESS)
            vertices_destroy(verts);
    }

    return ec;
}

error_code_t vertices_load_from_file(vertices_t &verts, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = read_vertices_from_file(verts, f);

    return ec;
}

// ------------------------- запись в файл -------------------------
static void write_vertex_to_file(const vertex_t &vert, FILE *f)
{
    fprintf(f, "v %lf %lf %lf\n", vert.x, vert.y, vert.z);
}

error_code_t vertices_save_to_file(const vertices_t &verts, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    if (!verts.array)
        return ERR_INSUFFICIENT_VERTEX_DATA;

    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    for (size_t i = 0; i < verts.amount; ++i)
        write_vertex_to_file(verts.array[i], f);

    setlocale(LC_NUMERIC, current_locale);
    return SUCCESS;
}
