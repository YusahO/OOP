#include "linkage.h"
#include "common.h"
#include "vertices.h"


error_code_t linkage_draw(qscene_t scene, const vertex_t *array, const linkage_t &linkage)
{
    if (!array)
        return ERR_INVALID_PTR_PASSED;

    if (!scene)
        return ERR_INVALID_PTR_PASSED;

    vertex_t p1 = array[linkage.v1];
    vertex_t p2 = array[linkage.v2];
    vertex_t p3 = array[linkage.v3];

    error_code_t ec = scene_draw_line(scene, p1, p2);
    if (ec == SUCCESS)
    {
        scene_draw_line(scene, p2, p3);
        scene_draw_line(scene, p1, p3);
    }

    return ec;
}

bool linkage_check(const size_t vamount, const linkage_t &linkage)
{
    bool cmp = (0 <= linkage.v1 && linkage.v1 < (int)vamount);
    cmp &=     (0 <= linkage.v2 && linkage.v2 < (int)vamount);
    cmp &=     (0 <= linkage.v3 && linkage.v3 < (int)vamount);
    return cmp;
}


error_code_t linkage_read_into(linkage_t &linkage, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    error_code_t ec = SUCCESS;

    int v1, v2, v3;

    if (fscanf(f, "%d %d %d", &v1, &v2, &v3) != 3)
        ec = ERR_INCORRECT_LINKAGE_DATA;

    linkage.v1 = v1 - 1;
    linkage.v2 = v2 - 1;
    linkage.v3 = v3 - 1;

    return ec;
}

error_code_t linkage_write_to_file(const linkage_t &linkage, FILE *f)
{
    if (!f)
        return ERR_INVALID_PTR_PASSED;

    fprintf(f, "%d %d %d\n", linkage.v1 + 1, linkage.v2 + 1, linkage.v3 + 1);
    return SUCCESS;
}