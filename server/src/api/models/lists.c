#include <stdio.h>
#include <stdbool.h>
#include "process.h"
#include "lists.h"

struct vowel_count_list setup_count_list(struct process_list *procs, double quantum_assign){
    struct vowel_count_list list = {
        .size = 0,
        .start = NULL
    };
    struct process_node *actual = procs->start;
    for (int i = 0; i < procs->size - 1; i++)
    {
        push_count_element(&list, actual->proc, quantum_assign);
        actual = actual->next;
    }
    return list;
}

void push_count_element(struct vowel_count_list *list, struct process *proc_assign, double quantum_assign){
    struct vowel_count *new_count = (struct vowel_count*)malloc(sizeof(struct vowel_count));
    new_count->proc = proc_assign;
    new_count->a_count = 0;
    new_count->e_count = 0;
    new_count->i_count = 0;
    new_count->o_count = 0;
    new_count->u_count = 0;
    new_count->start_point = 0;
    new_count->len = sizeof(proc_assign->file_content);
    new_count->is_finished = false;
    new_count->quantum = quantum_assign;

    struct vowel_count_node *new_node = (struct vowel_count_node*)malloc(sizeof(struct vowel_count_node));
    new_node->count = new_count;
    new_node->next = NULL;

    if (list->start == NULL)
    {
        list->start = new_node;
    }
    else
    {
        struct vowel_count_node *last = list->start;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
    list->size++;
}
