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

size_t vertices_get_amount(const vertices_t &verts)
{
    return verts.amount;
}

error_code_t vertices_try_get_value(vertex_t &dst, const vertices_t &verts, size_t ind)
{
    error_code_t ec = SUCCESS;
    if (ind < 0 || ind >= verts.amount)
        ec = ERR_INCORRECT_LINKAGE_DATA;
    else
        dst = verts.array[ind];
    
    return ec;
}

void vertices_translate(vertices_t &verts, const vec3_t &delta)
{
    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_translate(verts.array[i], delta);
    }
}

void vertices_rotate(vertices_t &verts, const vec3_t &pivot, const vec3_t &angles)
{
    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_rotate(verts.array[i], pivot, angles);
    }
}

void vertices_scale(vertices_t &verts, const vec3_t &pivot, const vec3_t &factor)
{
    for (size_t i = 0; i < verts.amount; ++i)
    {
        vertex_scale(verts.array[i], pivot, factor);
    }
}

static error_code_t create_vertex_array(vertices_t &verts, const size_t amount)
{
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
    error_code_t ec = SUCCESS;
    size_t amt = 0;
    if (fscanf(f, "%lu", &amt) != 1 || amt == 0)
        ec = ERR_INSUFFICIENT_VERTEX_DATA;

    amount = amt;
    return ec;
}

static error_code_t read_vertices(vertices_t &verts, FILE *f)
{
    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    error_code_t ec = SUCCESS;
    for (size_t i = 0; i < verts.amount && ec == SUCCESS; ++i)
        ec = read_into_vertex(verts.array[i], f);

    setlocale(LC_NUMERIC, current_locale);
    return ec;
}

error_code_t vertices_load_from_file(vertices_t &verts, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;
    size_t amt = 0;

    ec = read_vertices_amount(amt, f);

    ec = create_vertex_array(verts, amt);
    if (ec == SUCCESS)
    {
        ec = read_vertices(verts, f);
        
        if (ec != SUCCESS)
            vertices_destroy(verts);
    }

    return ec;
}

static void write_vertex_amount_to_file(const size_t amt, FILE *f)
{
    fprintf(f, "%lu\n", amt);
}

error_code_t vertices_save_to_file(const vertices_t &verts, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    if (!verts.array)
        return ERR_INSUFFICIENT_VERTEX_DATA;

    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    write_vertex_amount_to_file(verts.amount, f);
    
    for (size_t i = 0; i < verts.amount; ++i)
        write_vertex_to_file(verts.array[i], f);

    setlocale(LC_NUMERIC, current_locale);
    return SUCCESS;
}
