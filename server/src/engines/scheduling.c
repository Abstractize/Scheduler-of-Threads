#include <stdio.h>
#include <yder.h>
#include <jansson.h>
#include <ulfius.h>
#include "../managers/scheduler-manager.h"
#include "../api/models/process.h"
#include "../api/models/lists.h"
#include "../data/models/vowel-list.h"

void fcfs()
{
    bool finish = false;
    while (!finish)
    {
        struct vowel_count_node *node = count_list.start;
        finish = true;
        while (node != NULL)
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

void round_robin()
{
    bool finish = false;
    while (!finish)
    {
        struct vowel_count_node *node = count_list.start;
        finish = true;
        while (node != NULL)
        {
            pthread_t tid;
            pthread_create(&tid, NULL, vowel_counter_quant, (void *)node->count);
            pthread_join(tid, NULL);
            if (finish && !node->count->is_finished)
            {
                finish = false;
            }
            node = node->next;
        }
    }
}

void lottery()
{
    bool finish = false;
    struct vowel_count_node *node;
    int indexes[count_list.size];

    srand(time(NULL));
    for (int i = 0; i < count_list.size; i++){
        indexes[i] = i;
    }
    for (int i = 0; i < count_list.size - 1; ++i)
    {
        int j = rand() % (count_list.size - i) + i;
        int temp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = temp;
    }
    while (!finish)
    {
        node = count_list.start;
        finish = true;
        int counter = 0;
        while (counter < count_list.size)
        {
            while (node != NULL)
            {
                if (indexes[counter] == node->index)
                {
                    pthread_t tid;
                    pthread_create(&tid, NULL, vowel_counter_quant, (void *)node->count);
                    pthread_join(tid, NULL);
                    if (finish && !node->count->is_finished)
                    {
                        finish = false;
                    }
                    break;
                }
                node = node->next;
            }
            counter++;
        }
    }
}