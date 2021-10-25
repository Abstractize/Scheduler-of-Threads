#include <stdio.h>
#include <stdbool.h>
#include "process.c"

struct vowel_count
{
    process *proc;
    int a_count;
    int e_count;
    int i_count;
    int o_count;
    int u_count;
    int start_point;
    int len;
    bool is_finished;
    double quantum;
};

struct vowel_count_node
{
    struct vowel_count *count;
    struct vowel_count_node *next;
};

struct vowel_count_list
{
    int size;
    struct vowel_count_node *start;
};

struct vowel_count_list setup_list(process* procs, double quantum_assign){
    int total_procs = sizeof(procs);
    struct vowel_count_list list;
    for (int i = 0; i < total_procs; i++)
    {
        list_push(list, &procs[i],quantum_assign);
    }
    return list;
}

void list_push(struct vowel_count_list list, process *proc_assign, double quantum_assign){
    struct vowel_count new_count = {
        .proc = proc_assign,
        .a_count = 0,
        .e_count = 0,
        .i_count = 0,
        .o_count = 0,
        .u_count = 0,
        .start_point = 0,
        .len = sizeof(proc_assign->file_content),
        .is_finished = false,
        .quantum = quantum_assign
    };
    struct vowel_count_node new_node = {
        .count = &new_count
    };
    if (list.start == NULL)
    {
        list.start = &new_node;
    }
    else
    {
        struct vowel_count_node *last = list.start;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = &new_node;
    }
    list.size++;
}
