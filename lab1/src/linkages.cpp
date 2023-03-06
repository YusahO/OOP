#include "linkages.h"
#include <cstdlib>
#include <ctype.h>
#include <locale>
#include <cstring>

void linkages_init(linkages_t &linkages)
{
    linkages.array = nullptr;
    linkages.amount = 0;
}

void linkages_destroy(linkages_t &linkages)
{
    free(linkages.array);
    linkages.amount = 0;
    linkages.array = nullptr;
}

error_code_t linkages_draw(scene_t &scene, const vertices_t &verts, const linkages_t &linkages)
{
    if (!verts.array || !linkages.array)
        return ERR_MESH_NOT_LOADED;

    error_code_t ec = SUCCESS;
    for (size_t i = 0; i < linkages.amount && ec == SUCCESS; ++i)
    {
        bool correct = linkage_check(verts.amount, linkages.array[i]);
        if (correct)
            linkage_draw(scene, verts.array, linkages.array[i]);
        else
            ec = ERR_INCORRECT_LINKAGE_DATA;
    }

    return ec;
}

error_code_t linkages_check(const size_t vamount, const linkages_t &linkages)
{
    bool res = true;
    for (size_t i = 0; i < linkages.amount && res; ++i)
    {
        res = linkage_check(vamount, linkages.array[i]);
    }
    return res ? SUCCESS : ERR_INCORRECT_LINKAGE_DATA;
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

static error_code_t read_linkages_amount(size_t &amount, FILE *f)
{
    error_code_t ec = SUCCESS;
    size_t amt = 0;
    if (fscanf(f, "%lu", &amt) != 1 || amt == 0)
        ec = ERR_INSUFFICIENT_LINKAGE_DATA;

    amount = amt;
    return ec;
}

static error_code_t read_linkages(linkages_t &linkages, FILE *f)
{
    const char *current_locale = "";
    setlocale(LC_NUMERIC, "C");

    error_code_t ec = SUCCESS;
    for (size_t i = 0; i < linkages.amount && ec == SUCCESS; ++i)
        ec = linkage_read_into(linkages.array[i], f);

    setlocale(LC_NUMERIC, current_locale);
    return ec;
}

error_code_t linkages_load_from_file(linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;

    size_t amt = 0;

    ec = read_linkages_amount(amt, f);

    if (ec == SUCCESS)
    {
        ec = create_linkage_array(linkages, amt);
        if (ec == SUCCESS)
        {
            ec = read_linkages(linkages, f);
        }
    }

    return ec;
}


static void write_linkage_amount_to_file(const size_t amt, FILE *f)
{
    fprintf(f, "\n%lu\n", amt);
}

error_code_t linkages_save_to_file(const linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    if (!linkages.array)
        return ERR_INSUFFICIENT_LINKAGE_DATA;

    write_linkage_amount_to_file(linkages.amount, f);

    for (size_t i = 0; i < linkages.amount; ++i)
        linkage_write_to_file(linkages.array[i], f);

    return SUCCESS;
}