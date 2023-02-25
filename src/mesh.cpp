#include "mesh.h"
#include <cstdio>

mesh_t &mesh_init(void)
{
    static mesh_t mesh;
    vertices_init(mesh.vertices);
    linkages_init(mesh.indices);
    return mesh;
}

void mesh_destroy(mesh_t &mesh)
{
    vertices_destroy(mesh.vertices);
    linkages_destroy(mesh.indices);
}

error_code_t mesh_load_from_file(mesh_t &mesh, const filename_t filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERR_OPENING_FILE;

    error_code_t ec = SUCCESS;
    ec = vertices_load_from_file(mesh.vertices, f);

    if (ec == SUCCESS)
        ec = linkages_load_from_file(mesh.indices, f); // TODO: check linkages

    fclose(f);
    return ec;
}

error_code_t mesh_render(const mesh_t &mesh, scene_t &scene)
{
    vertices_t projected_verts;
    error_code_t ec = vertices_copy(projected_verts, mesh.vertices);
    vertices_model_to_view(scene, projected_verts);

    linkages_draw(scene, mesh.vertices, mesh.indices);
    return ec;
}
