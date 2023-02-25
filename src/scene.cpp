#include "scene.h"
#include <cstdlib>

void scene_draw_line(scene_t &scene, const vertex_t &p1, const vertex_t &p2)
{
    scene.scene->addLine(p1.x*100, p1.y*100, p2.x*100, p2.y*100);
}
