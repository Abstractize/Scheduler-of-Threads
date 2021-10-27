#include <stdio.h>
#include <yder.h>
#include <jansson.h>
#include <ulfius.h>
#include "../models/process.h"
#include "../models/lists.h"
#include "../models/process.h"

#define OBJ_MAIN "payload"
#define OBJ_PATA "Ta"
#define OBJ_PAFN "filename"
#define OBJ_PAFC "file_content"

int callback_post(const struct _u_request *request, struct _u_response *response, void *userData)
{
    json_t *json_nb_payload = ulfius_get_json_body_request(request, NULL), *json_body = NULL, *obj = NULL;
    json_int_t *nb_sheep = userData;

    size_t index = 0;
    json_t *value, *data_fn, *data_ta, *data_fc;

    struct process_list list = setup_list();

    if (json_nb_payload != NULL)
    {
        *nb_sheep = json_object_size(obj);
        obj = json_object_get(json_nb_payload, OBJ_MAIN);
        y_log_message(Y_LOG_LEVEL_DEBUG, "\t%s \t%s \t%s", "Index", "Ta", "Filename");
        json_array_foreach(obj, index, value)
        {
            // value = json_array_get(obj, index);         // Get element of array
            data_ta = json_object_get(value, OBJ_PATA); // Get Key OBJ_PATA
            data_fn = json_object_get(value, OBJ_PAFN); // Get Key OBJ_PAFN
            data_fc = json_object_get(value, OBJ_PAFC); // Get Key OBJ_PAFC
            setup_proc(json_integer_value(data_ta), json_string_value(data_fn), json_string_value(data_fc), &list);

            y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i \t%i \t%s", index, json_integer_value(data_ta), json_string_value(data_fn));
        }
        y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i", list.size);
        struct process_node *node = list.start;
        y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i \t%s \t%s", node->proc->Ta, node->proc->filename, node->proc->file_content);
        for (int i = 0; i < list.size - 1; i++)
        {
            node = node->next;
            y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i \t%s \t%s", node->proc->Ta, node->proc->filename, node->proc->file_content);
        }
    }
    json_decref(json_nb_payload);
    return U_CALLBACK_CONTINUE;
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
    } 
    ((struct vowel_count*)input)->is_finished = true;
}

void *vowel_counter_quant(void *input){
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
