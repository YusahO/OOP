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

void vertex_translate(vertex_t &vert, const vec3_t &delta);
void vertex_rotate(vertex_t &vert, const vec3_t &pivot, const vec3_t &angles);
void vertex_scale(vertex_t &vert, const vec3_t &pivot, const vec3_t &factor);

error_code_t read_into_vertex(vertex_t &vert, FILE *f);

void write_vertex_to_file(const vertex_t &vert, FILE *f);

#endif // __VERTEX_H__