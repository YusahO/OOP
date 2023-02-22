#include "matrix.h"
#include <math.h>
#include <assert.h>
#include <string.h>

mat_t *mat_create(const size_t n, const size_t m, const float *const elements)
{
    mat_t *mat = malloc(sizeof(mat_t) + n * sizeof(float *) + n * m * sizeof(float));
    if (mat)
    {
        for (size_t i = 0; i < n; ++i)
        {
            mat->mat[i] = (float *)((char *)mat->mat + n * sizeof(float *) + i * m * sizeof(float));
            if (!elements)
                memset(mat->mat[i], 0, m * sizeof(float));
            else
            {
                for (size_t j = 0; j < m; ++j)
                    mat->mat[i][j] = elements[i * m + j];
            }
        }
        mat->n = n;
        mat->m = m;
    }
    return mat;
}

void mat_destroy(mat_t *mat)
{
    if (mat)
        free(mat);
}

void mat_set(mat_t *mat, const float *const elements)
{
    for (size_t i = 0; i < mat->n; ++i)
        for (size_t j = 0; j < mat->m; ++j)
            mat->mat[i][j] = elements[i * mat->m + j];
}

void mat_make_unit(mat_t *mat)
{
    for (size_t i = 0; i < mat->n; ++i)
    {
        memset(mat->mat[i], 0.0f, mat->m * sizeof(float));
        mat->mat[i][i] = 1;
    }
}

mat_t *mat_add(const mat_t *first, const mat_t *second)
{
    assert(first == second || first->n != second->n || first->m != second->m);
    assert(!(first && second));

    mat_t *res = mat_create(first->n, first->m, NULL);

    for (size_t i = 0; i < first->n; ++i)
        for (size_t j = 0; j < first->m; ++j)
            res->mat[i][j] = first->mat[i][j] + second->mat[i][j];
    return res;
}

mat_t *mat_mul(const mat_t *first, const mat_t *second)
{
    assert(first == second || first->m != second->n);
    assert(!(first && second));

    mat_t *res = mat_create(first->n, second->m, NULL);

    for (size_t i = 0; i < first->n; ++i)
        for (size_t j = 0; j < second->m; ++j)
            for (size_t k = 0; k < first->m; ++k)
                res->mat[i][j] += first->mat[i][k] * second->mat[k][j];
    return res;
}

