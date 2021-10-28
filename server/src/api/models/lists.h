#include <stdio.h>
#include <stdbool.h>

#ifndef LISTS_HEADER_H
#define LISTS_HEADER_H

typedef struct
{
    struct process *proc;
    int a_count;
    int e_count;
    int i_count;
    int o_count;
    int u_count;
    int current_point;
    int len;
    bool is_finished;
    double quantum;
} vowel_count;

struct vowel_count_node
{
    vowel_count *count;
    struct vowel_count_node *next;
};

struct vowel_count_list
{
    int size;
    struct vowel_count_node *start;
};

struct vowel_count_list setup_count_list();
void push_count_element(struct process *proc_assign, double quantum_assign);
void clear_count();

#endif