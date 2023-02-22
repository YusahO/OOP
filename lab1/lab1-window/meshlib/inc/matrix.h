#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stddef.h>
#include <stdlib.h>
// #include "vec3.h"
// #include "vec4.h"

typedef struct mat_type mat_t;

struct mat_type
{
    float **mat;
    size_t n, m;
};

mat_t *mat_create(const size_t n, const size_t m, const float *const elements);
void mat_destroy(mat_t *mat);

void mat_set(mat_t *mat, const float *const elements);
void mat_make_unit(mat_t *mat);

mat_t *mat_add(const mat_t *first, const mat_t *second);
mat_t *mat_mul(const mat_t *first, const mat_t *second);

#endif // __MATRIX_H__