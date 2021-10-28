#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PROCESS_HEADER_H
#define PROCESS_HEADER_H

#define BIGENOUGH 512

struct process
{
    int Ta;
    char filename[BIGENOUGH];
    char file_content[BIGENOUGH];
};

void setup_proc(int Ta_assign, const char* filename_assign, const char* file_content_assign, double quantum_assign);

#endif
