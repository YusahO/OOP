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

error_code_t linkages_draw(qscene_t qscene, const vertex_t *varray, const linkages_t &linkages)
{
    if (!varray)
        return ERR_MESH_NOT_LOADED;
    if (!linkages.array)
        return ERR_MESH_NOT_LOADED;
    if (!qscene)
        return ERR_INVALID_PTR_PASSED;
        
    error_code_t ec = SUCCESS;
    for (size_t i = 0; ec == SUCCESS && i < linkages.amount; ++i)
    {
        ec = linkage_draw(qscene, varray, linkages.array[i]);
    }

    return ec;
}

error_code_t linkages_check(const size_t vamount, const linkages_t &linkages)
{
    if (!linkages.array)
        return ERR_INVALID_PTR_PASSED;
        
    error_code_t ec = SUCCESS;
    bool res = true;
    for (size_t i = 0; res && i < linkages.amount; ++i)
    {
        res = linkage_check(vamount, linkages.array[i]);
    }
    if (!res)
        ec = ERR_INCORRECT_LINKAGE_DATA;

    return ec;
}

static error_code_t linkages_init(linkages_t &linkages, const size_t amount)
{
    if (amount == 0)
        return ERR_INSUFFICIENT_LINKAGE_DATA;
    
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
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    
    error_code_t ec = SUCCESS;
    size_t amt = 0;
    if (fscanf(f, "%lu", &amt) != 1 || amt == 0)
        ec = ERR_INSUFFICIENT_LINKAGE_DATA;

    amount = amt;
    return ec;
}

static error_code_t read_linkages(linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    if (!linkages.array)
        return ERR_INVALID_PTR_PASSED;
    
    error_code_t ec = SUCCESS;

    for (size_t i = 0; ec == SUCCESS && i < linkages.amount; ++i)
        ec = linkage_read_into(linkages.array[i], f);

    return ec;
}

error_code_t linkages_load_from_file(linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    size_t amt;

    error_code_t ec = read_linkages_amount(amt, f);
    if (ec == SUCCESS)
    {
        ec = linkages_init(linkages, amt);
        if (ec == SUCCESS)
        {
            ec = read_linkages(linkages, f);
            if (ec != SUCCESS)
                linkages_destroy(linkages);
        }
    }

    return ec;
}

static error_code_t write_linkage_amount_to_file(const size_t amt, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    
    fprintf(f, "\n%lu\n", amt);
    return SUCCESS;
}

error_code_t linkages_save_to_file(const linkages_t &linkages, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;
    if (!linkages.array)
        return ERR_INVALID_PTR_PASSED;
    if (linkages.amount == 0)   
        return ERR_INSUFFICIENT_LINKAGE_DATA;

    error_code_t ec = write_linkage_amount_to_file(linkages.amount, f);

    for (size_t i = 0; ec == SUCCESS && i < linkages.amount; ++i)
        ec = linkage_write_to_file(linkages.array[i], f);

    return SUCCESS;
}