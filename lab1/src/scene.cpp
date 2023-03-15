#include "scene.h"
#include <cstdlib>

error_code_t scene_draw_line(qscene_t scene, const vertex_t &p1, const vertex_t &p2)
{
    if (!scene)
        return ERR_INVALID_PTR_PASSED;
    
    scene->addLine(p1.x, p1.y, p2.x, p2.y);
    return SUCCESS;
}

error_code_t scene_get_qscene(qscene_t &qscene, const scene_t &scene)
{
    qscene = scene.scene;
    return SUCCESS;
}