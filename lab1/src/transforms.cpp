#include "transforms.h"

error_code_t transform_translate(mesh_t &mesh, const translation_data_t &translation)
{
    if (vertices_get_amount(mesh.vertices) == 0)
        return ERR_MESH_NOT_LOADED;

    vertices_translate(mesh.vertices, translation.delta);
    return SUCCESS;
}

error_code_t transform_rotate(mesh_t &mesh, const rotation_data_t &rotation)
{
    if (vertices_get_amount(mesh.vertices) == 0)
        return ERR_MESH_NOT_LOADED;

    vertices_rotate(mesh.vertices, rotation.pivot, rotation.angles);
    return SUCCESS;
}

error_code_t transform_scale(mesh_t &mesh, const scaling_data_t &scaling)
{
    if (vertices_get_amount(mesh.vertices) == 0)
        return ERR_MESH_NOT_LOADED;
        
    vertices_scale(mesh.vertices, scaling.pivot, scaling.factor);
    return SUCCESS;
}