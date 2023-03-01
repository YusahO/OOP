#include "scene.h"
#include <cstdlib>

void scene_draw_line(scene_t &scene, const vertex_t &p1, const vertex_t &p2)
{
    scene.scene->addLine(p1.x, p1.y, p2.x, p2.y);
}
