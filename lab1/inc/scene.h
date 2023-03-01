#ifndef __SCENE_H__
#define __SCENE_H__

// #include "mesh.h"
#include "vertex.h"
#include <QGraphicsScene>

struct vertex_t;

struct scene_t
{
    QGraphicsScene *scene;
};

void scene_draw_line(scene_t &scene, const vertex_t &p1, const vertex_t &p2);

#endif // __SCENE_H__