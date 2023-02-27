#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "error_processor.h"
#include "vec.h"
#include "scene.h"
// #include "common.h"
#include <cstdio>

struct scene_t;

struct vertex_t
{
    double x, y, z;
};

struct vertices_t
{
    vertex_t *array;
    size_t amount;
};

void vertices_init(vertices_t &verts);
void vertices_destroy(vertices_t &verts);
size_t vertices_get_amount(const vertices_t &verts);

void vertices_translate(vertices_t &verts, const vec3_t &delta);
void vertices_rotate(vertices_t &verts, const vec3_t &pivot, const vec3_t &angles);
void vertices_scale(vertices_t &verts, const vec3_t &pivot, const vec3_t &factor);

error_code_t vertices_load_from_file(vertices_t &verts, FILE *f);

#endif // __VERTEX_H__