#include <stdbool.h>
#include "histogram.h"
#include <stdio.h>
#include <string.h>
#include "../../properties/const.h"

bool equals(histogram_t a, histogram_t b)
{
    return (a.a == b.a && a.e == b.e && a.i == b.i && a.o == b.o && a.u == b.u);
}

histogram_t empty()
{
    histogram_t value;
    for(int i = 0; i < HIST_PROCESS; i++)
    {
        strcpy(value.name[i], "Value not Defined");
        value.a[i] = 0;
        value.e[i] = 0;
        value.i[i] = 0;
        value.o[i] = 0;
        value.u[i] = 0;
    }
    return value;
}