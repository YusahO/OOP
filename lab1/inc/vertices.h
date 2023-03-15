#ifndef __VERTICES_H__
#define __VERTICES_H__

#include "vertex.h"

struct vertices_t
{
    vertex_t *array;
    size_t amount;
};

void vertices_init(vertices_t &verts);
void vertices_destroy(vertices_t &verts);

error_code_t vertices_get_array(vertex_t *&dst, const vertices_t &verts);
size_t vertices_get_amount(const vertices_t &verts);
error_code_t vertices_copy(vertices_t &dst, const vertices_t &src);

error_code_t vertices_project(vertices_t &verts, const scene_t &scene);
error_code_t vertices_get_projected(vertex_t *&projected_verts, const scene_t &scene, const vertices_t &verts);

error_code_t vertices_translate(vertices_t &verts, const vec3_t &delta);
error_code_t vertices_rotate(vertices_t &verts, const vec3_t &pivot, const vec3_t &angles);
error_code_t vertices_scale(vertices_t &verts, const vec3_t &pivot, const vec3_t &factor);

error_code_t vertices_load_from_file(vertices_t &verts, FILE *f);
error_code_t vertices_save_to_file(const vertices_t &verts, FILE *f);

#endif // __VERTICES_H__