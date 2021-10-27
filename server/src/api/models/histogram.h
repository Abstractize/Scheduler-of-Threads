#include <stdbool.h>
#ifndef HISTOGRAM_HEADER_H
#define HISTOGRAM_HEADER_H

#define BIGENOUGH 255

typedef struct
{
    char name[BIGENOUGH];
    int a;
    int e;
    int i;
    int o;
    int u;
} histogram_t;

bool equals(histogram_t a, histogram_t b);

#endif