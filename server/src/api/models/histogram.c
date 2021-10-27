#include <stdbool.h>
#include "histogram.h"
#include <stdio.h>

bool equals(histogram_t a, histogram_t b)
{
    return (a.a == b.a && a.e == b.e && a.i == b.i && a.o == b.o && a.u == b.u);
}