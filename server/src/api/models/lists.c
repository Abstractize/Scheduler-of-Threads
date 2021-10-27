#include "lists.h"
#include "process.h"
#include "../../data/models/vowel-list.h"
#include "../../managers/scheduler-manager.h"

struct vowel_count_list setup_count_list(){
    struct vowel_count_list list = {
        .size = 0,
        .start = NULL
    };
    return list;
}

void push_count_element(struct process *proc_assign, double quantum_assign){
    struct vowel_count *new_count = (struct vowel_count*)malloc(sizeof(struct vowel_count));
    new_count->proc = proc_assign;
    new_count->a_count = 0;
    new_count->e_count = 0;
    new_count->i_count = 0;
    new_count->o_count = 0;
    new_count->u_count = 0;
    new_count->current_point = 0;
    new_count->len = strlen(proc_assign->file_content);
    new_count->is_finished = false;
    new_count->quantum = quantum_assign;

    struct vowel_count_node *new_node = (struct vowel_count_node*)malloc(sizeof(struct vowel_count_node));
    new_node->count = new_count;
    new_node->next = NULL;

    if (count_list.start == NULL)
    {
        count_list.start = new_node;
    }
    else
    {
        struct vowel_count_node *last = count_list.start;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
    count_list.size++;
}

void clear_count(){
    struct vowel_count_node *last = count_list.start;
    while (last != NULL)
    {
        last->count->a_count = 0;
        last->count->e_count = 0;
        last->count->i_count = 0;
        last->count->o_count = 0;
        last->count->u_count = 0;
        last->count->current_point = 0;
        last->count->is_finished = false;
        last = last->next;
    }
}
