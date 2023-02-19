#ifndef __MESH_H__
#define __MESH_H__

#include "matrix.h"

typedef struct mesh_type mesh_t;

struct mesh_type
{
    struct attributes
    {
        float (*vertices)[3];
        int (*indices)[3];
    } attributes;

    struct attributes_sizes
    {
        size_t vertices_size;
        size_t indices_size;
    } attributes_sizes;
};

mesh_t *mesh_create(const struct attributes_sizes *const attr_sizes);
void mesh_destroy(mesh_t *mesh);
mesh_t *mesh_create_from_file(const char *const filename);

void mesh_translate(mesh_t *mesh, const float d[3]);
void mesh_rotate(mesh_t *mesh, const float angle, const float rot_axis[3]);
void mesh_scale(mesh_t *mesh, const float k[3]);

float *mesh_vertices_as_one_dim_array(const mesh_t* const mesh);
float *mesh_indices_as_one_dim_array(const mesh_t* const mesh);

#endif // __MESH_H__
