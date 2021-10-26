#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <pthread.h>
#include "../models/lists.c"

void *vowel_counter(void *input){
    clock_t begin_quant = clock();
    char* to_count = ((struct vowel_count*)input)->proc->file_content;
    int len = strlen(to_count);

    for (int i = ((struct vowel_count*)input)->start_point; i < ((struct vowel_count*)input)->len; i++)
    {
        switch (to_count[i])
        {
        case 'A':
            ((struct vowel_count*)input)->a_count++;
            break;

        case 'a':
            ((struct vowel_count*)input)->a_count++;
            break;

        case 'E':
            ((struct vowel_count*)input)->e_count++;
            break;

        case 'e':
            ((struct vowel_count*)input)->e_count++;
            break;

        case 'I':
            ((struct vowel_count*)input)->i_count++;
            break;

        case 'i':
            ((struct vowel_count*)input)->i_count++;
            break;

        case 'O':
            ((struct vowel_count*)input)->o_count++;
            break;

        case 'o':
            ((struct vowel_count*)input)->o_count++;
            break;

        case 'U':
            ((struct vowel_count*)input)->u_count++;
            break;

        case 'u':
            ((struct vowel_count*)input)->u_count++;
            break;
        
        default:
            break;
        }
        //endtime: if end - start > quant: return
        clock_t end_quant = clock();
        double cpu_time_used = ((double) (end_quant - begin_quant)) / CLOCKS_PER_SEC;
        if (cpu_time_used > ((struct vowel_count*)input)->quantum)
        {
            return;
        }
    } 
    ((struct vowel_count*)input)->is_finished = true;
}

void priority(struct process_list procs){
    bool finish = false;
    struct vowel_count_list list = setup_count_list(&procs, LONG_MAX);
    int len = list.size;
    while (!finish)
    {
        struct vowel_count_node *node = list.start;
        finish = true;
        for (int i = 0; i < len; i++)
        {
            pthread_t tid;
            pthread_create(&tid, NULL, vowel_counter, (void *)node->count);
            pthread_join(&tid, NULL);
            if (finish && !node->count->is_finished)
            {
                finish = false;
            }
            node = node->next;
        }
    }
}
