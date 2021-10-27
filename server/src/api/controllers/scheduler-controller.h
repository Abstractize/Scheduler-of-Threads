#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#ifndef SCHEDULE_CONTROLLER_H
#define SCHEDULE_CONTROLLER_H

struct vowel_count_list count_list;
bool continue_schedule;

void *vowel_counter(void *input);
void *vowel_counter_quant(void *input);
void continue_schedule_method();
void fcfs();
void priority();
void *scheduler();

#endif