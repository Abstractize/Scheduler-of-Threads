#include <stdbool.h>
#include "../../properties/const.h"
#ifndef HISTOGRAM_HEADER_H
#define HISTOGRAM_HEADER_H

typedef struct
{
    char name[HIST_PROCESS][BIGENOUGH];
    int a[HIST_PROCESS];
    int e[HIST_PROCESS];
    int i[HIST_PROCESS];
    int o[HIST_PROCESS];
    int u[HIST_PROCESS];
} histogram_t;

histogram_t empty();
bool equals(histogram_t a, histogram_t b);

#endif