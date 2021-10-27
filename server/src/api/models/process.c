#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "lists.h"

struct process_list setup_list(){
    struct process_list list = {.size = 0, .start = NULL};
    return list;
}

void push_proc(struct process_list *list, struct process *process){
    struct process_node *new_node = (struct process_node*)malloc(sizeof(struct process_node));
    new_node->proc = process;
    new_node->next = NULL;

    if (list->start == NULL)
    {
        list->start = new_node;
    }
    else
    {
        struct process_node *last = list->start;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
    list->size++;
}

void setup_proc(int Ta_assign, char* filename_assign, char* file_content_assign, double quantum_assign){
    struct process *new_proc = (struct process*)malloc(sizeof(struct process));
    new_proc->Ta = Ta_assign;
    // new_proc->filename = filename_assign;
    // new_proc->file_content = file_content_assign;
    strcpy(new_proc->filename, filename_assign);
    strcat(new_proc->filename, "\0");
    strcpy(new_proc->file_content, file_content_assign);
    strcat(new_proc->file_content, "\0");
    push_count_element(new_proc, quantum_assign);
}
