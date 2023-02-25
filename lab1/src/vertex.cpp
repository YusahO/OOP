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
    free(verts.array);
}

static error_code_t create_vertex_array(vertices_t &verts)
{
    error_code_t ec = SUCCESS;
    verts.array = (vertex_t *)malloc(sizeof(vertex_t) * verts.amount);
    if (!verts.array)
        ec = ERR_ALLOC;

    return ec;
}

size_t vertices_get_amount(const vertices_t &verts)
{
    return verts.amount;
}

error_code_t vertices_copy(vertices_t &dst, const vertices_t &src)
{
    dst.amount = src.amount;
    error_code_t ec = create_vertex_array(dst);
    if (ec == SUCCESS)
        for (size_t i = 0; i < src.amount; ++i)
            dst.array[i] = src.array[i];

    return ec;
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
static inline void vertex_rotate_x(vertex_t &vert, const vec3_t &pivot, const double ax)
{
    double vy = vert.y;
    double vz = vert.z;
    vert.y = pivot.y + cos(ax) * (vy - pivot.y) - sin(ax) * (vz - pivot.z);
    vert.z = pivot.z + sin(ax) * (vy - pivot.y) + cos(ax) * (vz - pivot.z);
}

static inline void vertex_rotate_y(vertex_t &vert, const vec3_t &pivot, const double ay)
{
    double vx = vert.x;
    double vz = vert.z;
    vert.x = pivot.x + cos(ay) * (vx - pivot.x) + sin(ay) * (vz - pivot.z);
    vert.z = pivot.z - sin(ay) * (vx - pivot.x) + cos(ay) * (vz - pivot.z);
}

static inline void vertex_rotate_z(vertex_t &vert, const vec3_t &pivot, const double az)
{
    double vx = vert.x;
    double vy = vert.y;
    vert.x = pivot.x + cos(az) * (vx - pivot.x) - sin(az) * (vy - pivot.y);
    vert.y = pivot.y + sin(az) * (vx - pivot.x) + cos(az) * (vy - pivot.y);
}

static void vertex_rotate(vertex_t &vert, const vec3_t &pivot, const vec3_t &angles)
{
    vertex_rotate_x(vert, pivot, angles.x);
    vertex_rotate_y(vert, pivot, angles.y);
    vertex_rotate_z(vert, pivot, angles.z);
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
    vert.x = vert.x * factor.x + (1 - factor.x) * pivot.x;
    vert.y = vert.y * factor.y + (1 - factor.y) * pivot.y;
    vert.z = vert.z * factor.z + (1 - factor.z) * pivot.z;
}

void vertices_scale(vertices_t &verts, const vec3_t &pivot, const vec3_t &factor)
{
    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_scale(verts.array[i], pivot, factor);
    }
}

// ------------------------- проекция -------------------------
static void vertex_model_to_view(const scene_t &scene, vertex_t &vert)
{
    vert.x /= scene.width;
    vert.y /= scene.height;
}

void vertices_model_to_view(const scene_t &scene, vertices_t &verts)
{
    for (size_t i = 0; i < verts.amount; ++i)
        vertex_model_to_view(scene, verts.array[i]);
}

// ------------------------- чтение вершин -------------------------
static size_t get_vertices_amount(FILE *f)
{
    size_t amt = 0;
    char buffer[BUFFER_SIZE];
    bool started_reading = false;
    while (fgets(buffer, BUFFER_SIZE, f) && !feof(f))
    {
        if (strstr(buffer, "v "))
        {
            started_reading = true;
            ++amt;
        }
        // else if (started_reading)
        //     break;
    }

    return amt;
}

static error_code_t read_into_vertex(vertex_t &vert, string_t str)
{
    error_code_t ec = SUCCESS;
    if (sscanf(str, "%lf %lf %lf", &vert.x, &vert.y, &vert.z) != 3)
        ec = ERR_INCORRECT_VERTEX_DATA;

    return ec;
}

static error_code_t read_vertices(vertices_t &verts, FILE *f)
{
    rewind(f);
    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    error_code_t ec = SUCCESS;
    char buffer[BUFFER_SIZE];
    for (size_t i = 0; i < verts.amount;)
    {
        fgets(buffer, BUFFER_SIZE, f);
        if (strstr(buffer, "v "))
        {
            ec = read_into_vertex(verts.array[i++], buffer + 2);
            if (ec != SUCCESS)
                break;
        }
    }

    setlocale(LC_NUMERIC, current_locale);
    return ec;
}

error_code_t vertices_load_from_file(vertices_t &verts, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;

    size_t amt = get_vertices_amount(f);
    if (amt == 0)
        return ERR_INSUFFICIENT_VERTEX_DATA;

    verts.amount = amt;

    ec = create_vertex_array(verts);
    if (ec != SUCCESS)
        return ec;

    ec = read_vertices(verts, f);
    if (ec != SUCCESS)
        vertices_destroy(verts);

    return ec;
}