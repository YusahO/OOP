#include "mesh.h"
#include <cstdio>

mesh_t &mesh_init(void)
{
    static mesh_t mesh;
    vertices_init(mesh.vertices);
    linkages_init(mesh.linkages);
    return mesh;
}

void mesh_destroy(mesh_t &mesh)
{
    vertices_destroy(mesh.vertices);
    linkages_destroy(mesh.linkages);
}

void mesh_copy(mesh_t &dst, const mesh_t &src)
{
    dst = src;
}

static error_code_t read_into_temp_mesh(mesh_t &temp_mesh, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;

    ec = vertices_load_from_file(temp_mesh.vertices, f);
    if (ec == SUCCESS)
    {
        ec = linkages_load_from_file(temp_mesh.linkages, f);
        if (ec != SUCCESS)
            vertices_destroy(temp_mesh.vertices);
    }
    return ec;
}

static error_code_t check_mesh(const mesh_t &mesh)
{
    error_code_t ec = linkages_check(vertices_get_amount(mesh.vertices), mesh.linkages);
    return ec;
}

error_code_t mesh_load_from_file(mesh_t &mesh, const filename_t filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERR_OPENING_FILE;

    mesh_t tmp;

    error_code_t ec = read_into_temp_mesh(tmp, f);
    fclose(f);

    if (ec == SUCCESS)
    {
        ec = check_mesh(tmp);
        if (ec == SUCCESS)
        {
            mesh_destroy(mesh);
            mesh_copy(mesh, tmp);
        }
        else
            mesh_destroy(tmp);
    }

    return ec;
}

error_code_t mesh_save_to_file(const mesh_t &mesh, const filename_t filename)
{
    FILE *f = fopen(filename, "w");
    if (!f)
        return ERR_OPENING_FILE;

    error_code_t ec = vertices_save_to_file(mesh.vertices, f);
    if (ec == SUCCESS)
        ec = linkages_save_to_file(mesh.linkages, f);

    fclose(f);
    return ec;
}

error_code_t mesh_render(scene_t &scene, const mesh_t &mesh)
{
    vertex_t *arr;
    error_code_t ec = vertices_get_projected(arr, scene, mesh.vertices);

    if (ec == SUCCESS)
    {
        qscene_t qscene;
        ec = scene_get_qscene(qscene, scene);
        if (ec == SUCCESS)
            ec = linkages_draw(qscene, arr, mesh.linkages);
    }
    return ec;
}
