#include "transforms.h"

error_code_t transform_translate(mesh_t &mesh, const translation_data_t &translation)
{
    error_code_t ec = vertices_translate(mesh.vertices, translation.delta);
    return ec;
}

error_code_t transform_rotate(mesh_t &mesh, const rotation_data_t &rotation)
{
    error_code_t ec = vertices_rotate(mesh.vertices, rotation.pivot, rotation.angles);
    return ec;
}

error_code_t transform_scale(mesh_t &mesh, const scaling_data_t &scaling)
{
    error_code_t ec = vertices_scale(mesh.vertices, scaling.pivot, scaling.factor);
    return ec;
}
