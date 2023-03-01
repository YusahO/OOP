// #ifndef _GNU_SOURCE
// #define _GNU_SOURCE
// #endif

#include "linkage.h"
#include "common.h"
#include <cstdlib>
#include <ctype.h>
#include <locale>
#include <cstring>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif

void linkages_init(linkages_t &linkages)
{
    linkages.array = nullptr;
    linkages.amount = 0;
}

void linkages_destroy(linkages_t &linkages)
{
    linkages.amount = 0;
    free(linkages.array);
    linkages.array = nullptr;
}

static error_code_t create_linkage_array(linkages_t &linkages, const size_t amount)
{
    error_code_t ec = SUCCESS;
    linkage_t *arr = (linkage_t *)malloc(sizeof(linkage_t) * amount);
    if (arr)
    {
        linkages.array = arr;
        linkages.amount = amount;
    }
    else
        ec = ERR_ALLOC;

    return ec;
}

// ---------------------------- отрисовка ----------------------------
static void linkage_draw(scene_t &scene, const vertex_t *array, const linkage_t &linkage)
{
    vertex_t p1 = array[linkage.v1];
    vertex_t p2 = array[linkage.v2];
    vertex_t p3 = array[linkage.v3];

    scene_draw_line(scene, p1, p2);
    scene_draw_line(scene, p2, p2);
    scene_draw_line(scene, p1, p3);
}

error_code_t linkages_draw(scene_t &scene, const vertices_t &verts, const linkages_t &linkages)
{
    if (!verts.array || !linkages.array)
        return ERR_MESH_NOT_LOADED;

    for (size_t i = 0; i < linkages.amount; ++i)
        linkage_draw(scene, verts.array, linkages.array[i]);
    
    return SUCCESS;
}

// ---------------------------- чтение данных ----------------------------
static error_code_t read_linkages_amount(size_t &amount, FILE *f)
{
    error_code_t ec = SUCCESS;
    size_t amt = 0;
    if (fscanf(f, "%lu", &amt) != 1 || amt == 0)
        ec = ERR_INSUFFICIENT_LINKAGE_DATA;

    amount = amt;
    return ec;
}

static error_code_t read_into_linkage(linkage_t &linkage, FILE *f)
{
    error_code_t ec = SUCCESS;

    int v1, v2, v3;

    if (fscanf(f, "%d %d %d", &v1, &v2, &v3) != 3)
        ec = ERR_INCORRECT_LINKAGE_DATA;
    
    linkage.v1 = v1 - 1;
    linkage.v2 = v2 - 1;
    linkage.v3 = v3 - 1;

    return ec;
}

static error_code_t read_linkages(linkages_t &linkages, FILE *f)
{
    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    error_code_t ec = SUCCESS;
    for (size_t i = 0; i < linkages.amount && ec == SUCCESS; ++i)
        ec = read_into_linkage(linkages.array[i], f);

    setlocale(LC_NUMERIC, current_locale);
    return ec;
}

static error_code_t read_linkages_from_file(linkages_t &linkages, FILE *f)
{
    error_code_t ec = SUCCESS;

    size_t amt = 0;

    ec = read_linkages_amount(amt, f);

    if (ec == ERR_INCORRECT_LINKAGE_DATA)
        return ec;

    ec = create_linkage_array(linkages, amt);
    if (ec == SUCCESS)
    {
        ec = read_linkages(linkages, f);
    }

    return ec;
}

error_code_t linkages_load_from_file(linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = read_linkages_from_file(linkages, f);

    return ec;
}

// ------------------------- запись в файл -------------------------
static void write_linkage_to_file(const linkage_t &linkage, FILE *f)
{
    fprintf(f, "f %d %d %d\n", linkage.v1 + 1, linkage.v2 + 1, linkage.v3 + 1);
}

error_code_t linkages_save_to_file(const linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    if (!linkages.array)
        return ERR_INSUFFICIENT_LINKAGE_DATA;

    for (size_t i = 0; i < linkages.amount; ++i)
        write_linkage_to_file(linkages.array[i], f);
    
    return SUCCESS;
}