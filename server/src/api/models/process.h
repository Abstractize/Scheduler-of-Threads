#ifndef PROCESS_HEADER_H
#define PROCESS_HEADER_H

struct process
{
    int Ta;
    char* filename;
    char* file_content;
};

struct process_node
{
    struct process *proc;
    struct process_node *next;
};

struct process_list
{
    int size;
    struct process_node *start;
};

struct process_list setup_list();
void push_proc(struct process_list *list, struct process *process);
void setup_proc(int Ta_assign, char* filename_assign, char* file_content_assign, struct process_list *list);

#endif
