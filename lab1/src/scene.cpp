#include "scene.h"
#include <cstdlib>

void scene_draw_line(scene_t &scene, const vertex_t &p1, const vertex_t &p2)
{
    scene.scene->addLine(p1.x, p1.y, p2.x, p2.y);
}

vertex_t scene_project(scene_t &scene, const vertex_t &v)
{
    vertex_t projected = {
        .x = v.x - scene.width / 2,
        .y = v.y - scene.height / 2,
        .z = 0
    };
    return projected;
}