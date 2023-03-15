#include "vertices.h"

void vertices_init(vertices_t &verts)
{
    verts.array = nullptr;
    verts.amount = 0;
}

void vertices_destroy(vertices_t &verts)
{
    free(verts.array);
    verts.amount = 0;
    verts.array = nullptr;
}

error_code_t vertices_get_array(vertex_t *&dst, const vertices_t &verts)
{
    dst = verts.array;
    return SUCCESS;
}

static error_code_t vertices_copy_array(vertex_t *&dst, const vertex_t *src, const size_t size)
{
    if (!src)
        return ERR_INVALID_PTR_PASSED;

    dst = (vertex_t *)malloc(sizeof(vertex_t) * size);
    for (size_t i = 0; i < size; ++i)
    {
        dst[i] = src[i];
    }
    return SUCCESS;
}

error_code_t vertices_copy(vertices_t &dst, const vertices_t &src)
{
    if (!src.array)
        return ERR_INVALID_PTR_PASSED;
    
    dst.amount = src.amount;
    error_code_t ec = vertices_copy_array(dst.array, src.array, src.amount);
    return ec;
}

size_t vertices_get_amount(const vertices_t &verts)
{
    return verts.amount;
}

error_code_t vertices_translate(vertices_t &verts, const vec3_t &delta)
{
    if (!verts.array)
        return ERR_INVALID_PTR_PASSED;

    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_translate(verts.array[i], delta);
    }
    return SUCCESS;
}

error_code_t vertices_rotate(vertices_t &verts, const vec3_t &pivot, const vec3_t &angles)
{
    if (!verts.array)
        return ERR_INVALID_PTR_PASSED;

    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_rotate(verts.array[i], pivot, angles);
    }
    return SUCCESS;
}

error_code_t vertices_scale(vertices_t &verts, const vec3_t &pivot, const vec3_t &factor)
{
    if (!verts.array)
        return ERR_INVALID_PTR_PASSED;

    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_scale(verts.array[i], pivot, factor);
    }
    return SUCCESS;
}

error_code_t vertices_project(vertices_t &verts, const scene_t &scene)
{
    if (!verts.array)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;

    for (size_t i = 0; ec == SUCCESS && i < verts.amount; ++i)
    {
        ec = vertex_project(verts.array[i], scene.width, scene.height);
    }
    return ec;
}

error_code_t vertices_get_projected(vertex_t *&projected_verts, const scene_t &scene, const vertices_t &verts)
{
    vertices_t projected;
    error_code_t ec = vertices_copy(projected, verts);
    if (ec == SUCCESS)
    {
        ec = vertices_project(projected, scene);
        if (ec != SUCCESS)
        {
            vertices_destroy(projected);
        }
        else
        {
            ec = vertices_get_array(projected_verts, projected);
            if (ec != SUCCESS)
            vertices_destroy(projected);
            {
                vertices_destroy(projected);
            }
        }
    }

    return ec;
}

static error_code_t vertices_init(vertices_t &verts, const size_t amount)
{
    if (amount == 0)
        return ERR_INSUFFICIENT_VERTEX_DATA;

    error_code_t ec = SUCCESS;
    vertex_t *arr = (vertex_t *)malloc(sizeof(vertex_t) * amount);
    if (arr)
    {
        verts.array = arr;
        verts.amount = amount;
    }
    else
        ec = ERR_ALLOC;

    return ec;
}

static error_code_t read_vertices_amount(size_t &amount, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;
    size_t amt = 0;
    if (fscanf(f, "%lu", &amt) != 1 || amt == 0)
        ec = ERR_INSUFFICIENT_VERTEX_DATA;

    amount = amt;
    return ec;
}

static error_code_t read_vertices(vertices_t &verts, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    if (!verts.array)
        return ERR_INVALID_PTR_PASSED;
    if (verts.amount == 0)
        return ERR_INSUFFICIENT_VERTEX_DATA;

    error_code_t ec = SUCCESS;
    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    for (size_t i = 0; ec == SUCCESS && i < verts.amount; ++i)
        ec = vertex_read_into(verts.array[i], f);

    setlocale(LC_NUMERIC, current_locale);
    return ec;
}

error_code_t vertices_load_from_file(vertices_t &verts, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    
    error_code_t ec = SUCCESS;

    size_t amt;

    ec = read_vertices_amount(amt, f);
    if (ec == SUCCESS)
    {
        ec = vertices_init(verts, amt);
        if (ec == SUCCESS)
        {
            ec = read_vertices(verts, f);

            if (ec != SUCCESS)
                vertices_destroy(verts);
        }
    }
    
    return ec;
}

static error_code_t write_vertex_amount_to_file(const size_t amt, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    
    fprintf(f, "%lu\n", amt);
    return SUCCESS;
}

error_code_t vertices_save_to_file(const vertices_t &verts, FILE *f)
{
    if (!f || !verts.array)
        return ERR_INVALID_PTR_PASSED;

    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    error_code_t ec = SUCCESS;
    write_vertex_amount_to_file(verts.amount, f);
    if (ec == SUCCESS)
    {
        for (size_t i = 0; ec == SUCCESS && i < verts.amount; ++i)
            vertex_write_to_file(verts.array[i], f);

        setlocale(LC_NUMERIC, current_locale);
    }
    return ec;
}
