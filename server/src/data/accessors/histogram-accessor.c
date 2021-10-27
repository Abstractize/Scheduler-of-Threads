#include "../../api/models/histogram.h"
#include "../models/vowel-list.h"
#include "../../api/models/process.h"

histogram_t find()
{
    struct vowel_count_node *actual = count_list.start;
    histogram_t response;
    strcpy(response.name, actual->count->proc->filename);
    response.a = actual->count->a_count;
    response.e = actual->count->e_count;
    response.i = actual->count->i_count;
    response.o = actual->count->o_count;
    response.u = actual->count->u_count;
    return response;
}