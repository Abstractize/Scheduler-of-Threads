#ifndef LISTS_HEADER_H
#define LISTS_HEADER_H

struct vowel_count
{
    struct process *proc;
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

struct vowel_count_list setup_count_list(struct process_list *procs, double quantum_assign);
void push_count_element(struct vowel_count_list *list, struct process *proc_assign, double quantum_assign);

#endif