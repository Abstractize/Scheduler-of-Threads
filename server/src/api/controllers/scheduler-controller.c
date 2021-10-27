#include "scheduler-controller.h"
#include "../models/lists.h"
#include "../models/process.h"

void *vowel_counter_priority(void *input){
    clock_t begin_quant = clock();
    char to_count[BIGENOUGH];
    strcpy(to_count, ((struct vowel_count*)input)->proc->file_content);
    int len = strlen(to_count);

    for (int i = ((struct vowel_count*)input)->current_point; i < ((struct vowel_count*)input)->len; i++)
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
    } 
    ((struct vowel_count*)input)->is_finished = true;
}

void *vowel_counter(void *input){
    clock_t begin_quant = clock();
    char to_count[BIGENOUGH];
    strcpy(to_count, ((struct vowel_count*)input)->proc->file_content);
    int len = strlen(to_count);

    for (int i = ((struct vowel_count*)input)->current_point; i < ((struct vowel_count*)input)->len; i++)
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

void continue_schedule_method(){
    continue_schedule = true;
}

void fcfs(){
    bool finish = false;
    while (!finish)
    {
        struct vowel_count_node *node = count_list.start;
        finish = true;
        while(node != NULL)
        {
            pthread_t tid;
            pthread_create(&tid, NULL, vowel_counter, (void *)node->count);
            pthread_join(tid, NULL);
            if (finish && !node->count->is_finished)
            {
                finish = false;
            }
            node = node->next;
        }
    }
}

void priority(){
    bool finish = false;
    while (!finish)
    {
        struct vowel_count_node *node = count_list.start;
        finish = true;
        while(node != NULL)
        {
            pthread_t tid;
            pthread_create(&tid, NULL, vowel_counter_priority, (void *)node->count);
            pthread_join(tid, NULL);
            if (finish && !node->count->is_finished)
            {
                finish = false;
            }
            node = node->next;
        }
    }
}

void *scheduler(){
    continue_schedule = false;
    count_list = setup_count_list();
    while(true){
        if (count_list.size > 0){
            fcfs();
            clear_count(); 
            priority();
            struct vowel_count_node *actual = count_list.start;
            while (actual != NULL)
            {
                printf("%s \n", actual->count->proc->filename);
                printf("a: %i \n", actual->count->a_count);
                printf("e: %i \n", actual->count->e_count);
                printf("i: %i \n", actual->count->i_count);
                printf("o: %i \n", actual->count->o_count);
                printf("u: %i \n", actual->count->u_count);
                actual = actual->next;
            }
            break;
        }
    }
}
