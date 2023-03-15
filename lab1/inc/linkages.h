#ifndef __LINKAGES_H__
#define __LINKAGES_H__

#include "linkage.h"
#include "vertices.h"

struct linkages_t
{
    linkage_t *array;
    size_t amount;
};

void linkages_init(linkages_t &linkages);
void linkages_destroy(linkages_t &linkages);

error_code_t linkages_check(const size_t vamount, const linkages_t &linkages);

error_code_t linkages_load_from_file(linkages_t &linkages, FILE *f);
error_code_t linkages_save_to_file(const linkages_t &linkages, FILE *f);

error_code_t linkages_draw(qscene_t scene, const vertex_t *varray, const linkages_t &linkages);

#endif // __LINKAGES_H__