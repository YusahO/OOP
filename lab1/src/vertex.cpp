#include "vertex.h"
#include "common.h"
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <locale>

// ------------------------- перемещение -------------------------
void vertex_translate(vertex_t &vert, const vec3_t &delta)
{
    vert.x += delta.x;
    vert.y += delta.y;
    vert.z += delta.z;
}

// ------------------------- поворот -------------------------
static inline void vertex_rotate_x(vertex_t &vert, const double ax)
{
    double vy = vert.y;
    double vz = vert.z;
    vert.y = cos(ax) * vy + sin(ax) * vz;
    vert.z = -sin(ax) * vy + cos(ax) * vz;
}

static inline void vertex_rotate_y(vertex_t &vert, const double ay)
{
    double vx = vert.x;
    double vz = vert.z;
    vert.x =  cos(ay) * vx + sin(ay) * vz;
    vert.z = -sin(ay) * vx + cos(ay) * vz;
}

static inline void vertex_rotate_z(vertex_t &vert, const double az)
{
    double vx = vert.x;
    double vy = vert.y;
    vert.x = cos(az) * vx + sin(az) * vy;
    vert.y = -sin(az) * vx + cos(az) * vy;
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

void vertex_rotate(vertex_t &vert, const vec3_t &pivot, const vec3_t &angles)
{
    shift_to_zero(vert, pivot);
    vertex_rotate_x(vert, angles.x);
    vertex_rotate_y(vert, angles.y);
    vertex_rotate_z(vert, angles.z);
    shift_to_pos(vert, pivot);
}

// ------------------------- масштабирование -------------------------
void vertex_scale(vertex_t &vert, const vec3_t &pivot, const vec3_t &factor)
{
    vert.x = factor.x * vert.x + (1 - factor.x) * pivot.x;
    vert.y = factor.y * vert.y + (1 - factor.y) * pivot.y;
    vert.z = factor.z * vert.z + (1 - factor.z) * pivot.z;
}

// ------------------------- чтение вершин -------------------------
error_code_t read_into_vertex(vertex_t &vert, FILE *f)
{
    error_code_t ec = SUCCESS;

    if (fscanf(f, "%lf %lf %lf", &vert.x, &vert.y, &vert.z) != 3)
        ec = ERR_INCORRECT_VERTEX_DATA;
    return ec;
}

// ------------------------- запись в файл -------------------------
void write_vertex_to_file(const vertex_t &vert, FILE *f)
{
    fprintf(f, "%lf %lf %lf\n", vert.x, vert.y, vert.z);
}

