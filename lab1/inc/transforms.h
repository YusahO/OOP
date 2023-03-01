#ifndef __TRANSFORMS_H__
#define __TRANSFORMS_H__

#include "vec.h"
#include "mesh.h"
#include "error_processor.h"

struct translation_data_t
{
    vec3_t delta;
};

struct rotation_data_t
{
    vec3_t pivot;
    vec3_t angles;
};

struct scaling_data_t
{
    vec3_t pivot;
    vec3_t factor;
};

error_code_t transform_translate(mesh_t &mesh, const translation_data_t &translation);
error_code_t transform_rotate(mesh_t &mesh, const rotation_data_t &rotation);
error_code_t transform_scale(mesh_t &mesh, const scaling_data_t &scaling);

#endif // __TRANSFORMS_H__