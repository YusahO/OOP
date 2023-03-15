#ifndef __SCENE_H__
#define __SCENE_H__

// #include "mesh.h"
#include "vertex.h"
#include "common.h"
#include <QGraphicsScene>

struct vertex_t;

struct scene_t
{
    QGraphicsScene *scene;
    size_t width, height;
};

error_code_t scene_draw_line(qscene_t scene, const vertex_t &p1, const vertex_t &p2);
error_code_t scene_get_qscene(qscene_t &qscene, const scene_t &scene);

#endif // __SCENE_H__