#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#ifndef SCHEDULER_MANAGER_HEADER_H
#define SCHEDULER_MANAGER_HEADER_H

void *vowel_counter(void *input);
void *vowel_counter_quant(void *input);
void continue_schedule_method();
void fcfs();
void round_robin();
void *scheduler();

#endif