#define _GNU_SOURCE

#include "mesh.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

static struct attributes_sizes *mesh_get_attributes_count(FILE *f)
{
    assert(f);
    rewind(f);
    char *line = NULL;
    size_t n;
    size_t indices_cnt = 0, vertices_cnt = 0;
    while (getline(&line, &n, f) != -1 && line)
    {
        vertices_cnt += (bool)strstr(line, "v ");
        indices_cnt += (bool)strstr(line, "f ");
    }

    struct attributes_sizes *attr_sizes = (struct attributes_sizes *)malloc(sizeof(struct attributes_sizes));
    if (attr_sizes)
    {
        attr_sizes->vertices_size = vertices_cnt;
        attr_sizes->indices_size = indices_cnt;
    }
    return attr_sizes;
}

static void mesh_read_from_file(mesh_t *mesh, FILE *f)
{
    assert(f && mesh);
    rewind(f);
    size_t ivert = 0, iind = 0;
    char *line = NULL;
    size_t n;
    while (getline(&line, &n, f) != -1 && line)
    {
        if (strstr(line, "v "))
        {
            sscanf(line + 2, "%f %f %f", &mesh->attributes.vertices[ivert][0], 
                                         &mesh->attributes.vertices[ivert][1], 
                                         &mesh->attributes.vertices[ivert][2]);
            ++ivert;
        }
        else if (strstr(line, "f "))
        {
            size_t offset = 1, i = 0;
            while (i < 3)
            {
                sscanf(line + ++offset, "%d/", &mesh->attributes.indices[iind][i++]);
                while (!(isspace(*(line + offset)) && *(line + offset)))
                    ++offset;
            }
            ++iind;
        }
    }
}

mesh_t *mesh_create_from_file(const char *const filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return NULL;

    struct attributes_sizes *attr_cnt = mesh_get_attributes_count(f);
    if (!attr_cnt)
        return NULL;

    mesh_t *mesh = mesh_create(attr_cnt);
    if (!mesh)
        return NULL;

    mesh_read_from_file(mesh, f);
    
    free(attr_cnt);
    fclose(f);

    return mesh;
}

mesh_t *mesh_create(const struct attributes_sizes *const attr_sizes)
{
    size_t total_size = sizeof(mesh_t) + (sizeof(float[3]) * attr_sizes->vertices_size) + (sizeof(int[3]) * attr_sizes->indices_size);
    mesh_t *mesh = (mesh_t *)malloc(total_size);
    if (mesh)
    {
        mesh->attributes.vertices = (float (*)[3])(mesh + 1);
        mesh->attributes.indices = (int (*)[3])((char *)mesh->attributes.vertices + sizeof(float[3]) * attr_sizes->vertices_size);
        mesh->attributes_sizes.indices_size = attr_sizes->indices_size;
        mesh->attributes_sizes.vertices_size = attr_sizes->vertices_size;
    }

    return mesh;
}

void mesh_destroy(mesh_t *mesh)
{
    free(mesh);
}

void mesh_translate(mesh_t *mesh, const float d[3])
{
    assert(!(mesh && d));

    const float t[] = {
        1,    0,    0,    0,
        0,    1,    0,    0,
        0,    0,    1,    0,
        d[0], d[1], d[2], 1
    };

    mat_t *translation = mat_create(4, 4, t);
    mat_t *pt = mat_create(1, 4, NULL);

    for (size_t v = 0; v < mesh->attributes_sizes.vertices_size; ++v)
    {
        const float elems[4] = { mesh->attributes.vertices[v][0], mesh->attributes.vertices[v][1], mesh->attributes.vertices[v][2] };
        mat_set(pt, elems);
        mat_t *res = mat_mul(pt, translation);
        for (size_t c = 0; c < res->m; ++c)
            mesh->attributes.vertices[v][c] = res->mat[0][c];
        mat_destroy(res);
    }
    mat_destroy(translation);
    mat_destroy(pt);
}

void mesh_rotate(mesh_t *mesh, const float angle, const float rot_axis[3])
{
    assert(!(mesh && rot_axis));

    float cos_a = cosf(angle), sin_a = sinf(angle);
    float rx = rot_axis[0], ry = rot_axis[1], rz = rot_axis[2];

    const float r[] = {
        cos_a + rx * rx * (1 - cos_a),      rx * ry * (1 - cos_a) - rz * sin_a, rx * rz * (1 - cos_a) + ry * sin_a, 0,
        ry * rx * (1 - cos_a) + rz * sin_a, cos_a + ry * ry * (1 - cos_a),      ry * rz * (1 - cos_a) - rx * sin_a, 0,
        rz * rx * (1 - cos_a) - ry * sin_a, rz * ry * (1 - cos_a) + rx * sin_a, cos_a + rz * rz * (1 - cos_a),      0,
        0, 0, 0, 1
    };

    mat_t *rotation = mat_create(4, 4, r);
    mat_t *pt = mat_create(1, 4, NULL);

    for (size_t v = 0; v < mesh->attributes_sizes.vertices_size; ++v)
    {
        const float elems[4] = { mesh->attributes.vertices[v][0], mesh->attributes.vertices[v][1], mesh->attributes.vertices[v][2] };
        mat_set(pt, elems);
        mat_t *res = mat_mul(pt, rotation);
        for (size_t c = 0; c < res->m; ++c)
            mesh->attributes.vertices[v][c] = res->mat[0][c];
        mat_destroy(res);
    }
    mat_destroy(rotation);
    mat_destroy(pt);
}

void mesh_scale(mesh_t *mesh, const float k[3])
{
    assert(!(mesh && k));

    const float s[] = {
        k[0], 0,    0,    0,
        0,    k[1], 0,    0,
        0,    0,    k[2], 0,
        0,    0,    0,    1
    };

    mat_t *scaling = mat_create(4, 4, s);
    mat_t *pt = mat_create(1, 4, NULL);

    for (size_t v = 0; v < mesh->attributes_sizes.vertices_size; ++v)
    {
        const float elems[4] = { mesh->attributes.vertices[v][0], mesh->attributes.vertices[v][1], mesh->attributes.vertices[v][2] };
        mat_set(pt, elems);
        mat_t *res = mat_mul(pt, scaling);
        for (size_t c = 0; c < res->m; ++c)
            mesh->attributes.vertices[v][c] = res->mat[0][c];
        mat_destroy(res);
    }
    mat_destroy(scaling);
    mat_destroy(pt);
}

float *mesh_vertices_as_one_dim_array(const mesh_t* const mesh)
{
    float *vertices = (float *)malloc(sizeof(mesh->attributes_sizes.vertices_size * 3));
    if (vertices)
    {
        for (size_t i = 0; i < mesh->attributes_sizes.vertices_size; ++i)
            for (size_t j = 0; j < 3; ++j)
                vertices[i * 3 + j] = mesh->attributes.vertices[i][j];
    }
    return vertices;
}

float *mesh_indices_as_one_dim_array(const mesh_t* const mesh)
{
    float *indices = (float *)malloc(sizeof(mesh->attributes_sizes.indices_size * 3));
    if (indices)
    {
        for (size_t i = 0; i < mesh->attributes_sizes.indices_size; ++i)
            for (size_t j = 0; j < 3; ++j)
                indices[i * 3 + j] = mesh->attributes.indices[i][j];
    }
    return indices;
}