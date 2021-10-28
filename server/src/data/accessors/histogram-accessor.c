#include <ulfius.h>
#include "../../api/models/histogram.h"
#include "../models/vowel-list.h"
#include "../../api/models/process.h"
#include "../../properties/const.h"

histogram_t find()
{
    histogram_t response = empty();
    struct vowel_count_node *actual = count_list.start;
    int offset = count_list.size - HIST_PROCESS;

    for (int i = 0; i < count_list.size; i++)
    {
        int x = i - offset;
        if(actual == NULL)
            break;

        if(offset < 0)
        {
            strcpy(response.name[i], actual->count->proc->filename);
            response.a[i] = actual->count->a_count;
            response.e[i] = actual->count->e_count;
            response.i[i] = actual->count->i_count;
            response.o[i] = actual->count->o_count;
            response.u[i] = actual->count->u_count;
        }
        else if(x > 0)
        {
            strcpy(response.name[x], actual->count->proc->filename);
            response.a[x] = actual->count->a_count;
            response.e[x] = actual->count->e_count;
            response.i[x] = actual->count->i_count;
            response.o[x] = actual->count->o_count;
            response.u[x] = actual->count->u_count;
        }

        actual = actual->next;
    }

    return response;
}