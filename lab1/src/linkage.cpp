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
    free(linkages.array);
}

// ---------------------------- отрисовка ----------------------------
static void linkage_draw(scene_t &scene, const vertices_t &verts, const linkage_t &linkage)
{
    vertex_t p1 = verts.array[linkage.v1];
    vertex_t p2 = verts.array[linkage.v2];
    vertex_t p3 = verts.array[linkage.v3];

    scene_draw_line(scene, p1, p2);
    scene_draw_line(scene, p2, p2);
    scene_draw_line(scene, p1, p3);
}

void linkages_draw(scene_t &scene, const vertices_t &verts, const linkages_t &linkages)
{
    for (size_t i = 0; i < linkages.amount; ++i)
        linkage_draw(scene, verts, linkages.array[i]);
}

// ---------------------------- чтение данных ----------------------------
static error_code_t create_linkage_array(linkages_t &linkages)
{
    error_code_t ec = SUCCESS;
    linkages.array = (linkage_t *)malloc(sizeof(linkage_t) * linkages.amount);
    if (!linkages.array)
        ec = ERR_ALLOC;

    return ec;
}

static size_t get_linkages_amount(FILE *f)
{
    size_t amt = 0;
    char buffer[BUFFER_SIZE];
    bool started_reading = false;
    while (fgets(buffer, BUFFER_SIZE, f) && !feof(f))
    {
        if (strstr(buffer, "f "))
        {
            started_reading = true;
            ++amt;
        }
        // else if (started_reading)
        //     break;
    }

    return amt;
}

static error_code_t read_into_linkage(linkage_t &linkage, string_t str)
{
    error_code_t ec = SUCCESS;
    int *fields[] = {&linkage.v1, &linkage.v2, &linkage.v3};
    size_t ind = 0;

    for (const char *p = str; *p != '\0' && *p != '\n'; ++p)
    {
        if (isspace(*p) && !isspace(*(p + 1)))
        {
            int buf;
            if (sscanf(p, "%d", &buf) != 1)
            {
                ec = ERR_INCORRECT_LINKAGE_DATA;
                break;
            }
            *(fields[ind++]) = buf - 1;
        }
    }

    if (ec == SUCCESS)
    {
        if (ind != 3)
            ec = ERR_INSUFFICIENT_LINKAGE_DATA;
    }

    return ec;
}

static error_code_t read_linkages(linkages_t &linkages, FILE *f)
{
    rewind(f);

    error_code_t ec = SUCCESS;
    char buffer[BUFFER_SIZE];
    for (size_t i = 0; i < linkages.amount;)
    {
        fgets(buffer, BUFFER_SIZE, f);
        if (strstr(buffer, "f "))
        {
            ec = read_into_linkage(linkages.array[i++], buffer);
            if (ec != SUCCESS)
                break;
        }
    }

    return ec;
}

error_code_t linkages_load_from_file(linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;

    size_t amt = get_linkages_amount(f);
    if (amt == 0)
        return ERR_INSUFFICIENT_LINKAGE_DATA;
    linkages.amount = amt;

    ec = create_linkage_array(linkages);
    if (ec != SUCCESS)
        return ec;

    ec = read_linkages(linkages, f);
    if (ec != SUCCESS)
        linkages_destroy(linkages);

    return ec;
}