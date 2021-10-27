#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "lists.h"

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
