#ifndef __MESH_H__
#define __MESH_H__

#include "vertices.h"
#include "linkages.h"
#include "common.h"
#include "scene.h"
#include "error_processor.h"
#include <cstdlib>

struct mesh_t
{
    vertices_t vertices;
    linkages_t linkages;
};

mesh_t &mesh_init(void);
void mesh_destroy(mesh_t &mesh);

error_code_t mesh_load_from_file(mesh_t &mesh, const filename_t filename);
error_code_t mesh_save_to_file(const mesh_t &mesh, const filename_t filename);

error_code_t mesh_render(const mesh_t &mesh, scene_t &scene);

#endif // __MESH_H__
