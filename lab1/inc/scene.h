#ifndef __SCENE_H__
#define __SCENE_H__

// #include "mesh.h"
#include "vertex.h"
#include <QGraphicsScene>

struct vertex_t;

struct scene_t
{
    QGraphicsScene *scene;
    int width, height;
};

void scene_draw_line(scene_t &scene, const vertex_t &p1, const vertex_t &p2);
vertex_t scene_project(scene_t &scene, const vertex_t &v);

#endif // __SCENE_H__