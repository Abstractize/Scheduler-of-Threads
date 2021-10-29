#include <stdio.h>
#include <yder.h>
#include <jansson.h>
#include <ulfius.h>
#include <time.h>
#include "../engines/scheduling.h"
#include "../api/models/process.h"
#include "../api/models/lists.h"
#include "../data/models/vowel-list.h"

int compare(const void *a, const void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a == int_b)
        return 0;
    else if (int_a < int_b)
        return -1;
    else
        return 1;
}

void *vowel_counter(void *input)
{
    char to_count[BIGENOUGH];
    strcpy(to_count, ((vowel_count *)input)->proc->file_content);
    int len = strlen(to_count);

    for (int i = ((vowel_count *)input)->current_point; i < ((vowel_count *)input)->len; i++)
    {
        switch (to_count[i])
        {
        case 'A':
            ((vowel_count *)input)->a_count++;
            break;

        case 'a':
            ((vowel_count *)input)->a_count++;
            break;

        case 'E':
            ((vowel_count *)input)->e_count++;
            break;

        case 'e':
            ((vowel_count *)input)->e_count++;
            break;

        case 'I':
            ((vowel_count *)input)->i_count++;
            break;

        case 'i':
            ((vowel_count *)input)->i_count++;
            break;

        case 'O':
            ((vowel_count *)input)->o_count++;
            break;

        case 'o':
            ((vowel_count *)input)->o_count++;
            break;

        case 'U':
            ((vowel_count *)input)->u_count++;
            break;

        case 'u':
            ((vowel_count *)input)->u_count++;
            break;

        default:
            break;
        }
    }
    ((vowel_count *)input)->is_finished = true;
}

void *vowel_counter_quant(void *input)
{
    clock_t begin_quant = clock();
    char to_count[BIGENOUGH];
    strcpy(to_count, ((vowel_count *)input)->proc->file_content);
    int len = strlen(to_count);
    bool break_flag = false;
    for (int i = ((vowel_count *)input)->current_point; i < ((vowel_count *)input)->len; i++)
    {
        switch (to_count[i])
        {
        case 'A':
            ((vowel_count *)input)->a_count++;
            break;

        case 'a':
            ((vowel_count *)input)->a_count++;
            break;

        case 'E':
            ((vowel_count *)input)->e_count++;
            break;

        case 'e':
            ((vowel_count *)input)->e_count++;
            break;

        case 'I':
            ((vowel_count *)input)->i_count++;
            break;

        case 'i':
            ((vowel_count *)input)->i_count++;
            break;

        case 'O':
            ((vowel_count *)input)->o_count++;
            break;

        case 'o':
            ((vowel_count *)input)->o_count++;
            break;

        case 'U':
            ((vowel_count *)input)->u_count++;
            break;

        case 'u':
            ((vowel_count *)input)->u_count++;
            break;

        default:
            break;
        }
        //endtime: if end - start > quant: return
        clock_t end_quant = clock();
        double cpu_time_used = ((double)(end_quant - begin_quant)) / CLOCKS_PER_SEC;
        if (cpu_time_used > ((vowel_count *)input)->quantum)
        {
            break_flag = true;
            break;
        }
    }
    if (!break_flag)
        ((vowel_count *)input)->is_finished = true;
}

void continue_schedule_method()
{
    continue_schedule = true;
}

void *scheduler()
{
    continue_schedule = false;
    count_list = setup_count_list();
    while (true)
    {
        if (count_list.size > 0)
        {
            sleep(3);
            printf("Scheduling with FCFS\n");
            fcfs();
            // while (!continue_schedule)
            // {
            //     continue;
            // }
            // continue_schedule = false;
            clear_count();
            printf("Scheduling with Priority\n");
            priority();
            // while (!continue_schedule)
            // {
            //     continue;
            // }
            // continue_schedule = false;
            clear_count();
            printf("Scheduling with RR\n");
            round_robin();
            // while (!continue_schedule)
            // {
            //     continue;
            // }
            // continue_schedule = false;
            clear_count();
            printf("Scheduling with Lottery\n");
            lottery();
            // while (!continue_schedule)
            // {
            //     continue;
            // }
            // continue_schedule = false;
            clear_count();
            printf("Scheduling with SRTN\n");
            srtn();
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