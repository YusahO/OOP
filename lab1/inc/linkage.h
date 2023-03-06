#ifndef __LINKAGE_H__
#define __LINKAGE_H__

#include "error_processor.h"
#include "scene.h"
#include "vertices.h"
// #include "common.h"
#include <stddef.h>
#include <cstdio>

struct scene_t;
struct vertices_t;

struct linkage_t
{
    int v1, v2, v3;
};

void linkage_draw(scene_t &scene, const vertex_t *array, const linkage_t &linkage);

bool linkage_check(const size_t vamount, const linkage_t &linkage);
error_code_t linkage_read_into(linkage_t &linkage, FILE *f);

void linkage_write_to_file(const linkage_t &linkage, FILE *f);

#endif // __LINKAGE_H__