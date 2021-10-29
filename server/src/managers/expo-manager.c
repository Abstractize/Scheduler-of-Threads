#include <gtk/gtk.h>
#include "../data/models/vowel-list.h"
#include "./expo-manager.h"

const int get_count()
{
     return (count_list.size);
}

const float get_progress_1()
{
     struct vowel_count_node *head = count_list.start;
     double res = 0.0;
     if (head != NULL)
     {
          int max = head->count->len;
          max = (max > 0) ? max : 1;
          int act = head->count->current_point;
          res = act / max;
     }
     return (res);
}

const float get_progress_2()
{
     struct vowel_count_node *head = count_list.start;
     head = head->next;
     int max = head->count->len;
     max = (max > 0) ? max : 1;
     int act = head->count->current_point;
     return (act / max);
}

const float get_progress_3()
{
     struct vowel_count_node *head = count_list.start;
     head = head->next;
     head = head->next;
     int max = head->count->len;
     int act = head->count->current_point;
     return (act / max);
}

const float get_progress_4()
{
     struct vowel_count_node *head = count_list.start;
     head = head->next;
     head = head->next;
     head = head->next;
     int max = head->count->len;
     int act = head->count->current_point;
     return (act / max);
}

const float get_progress_5()
{
     struct vowel_count_node *head = count_list.start;
     head = head->next;
     head = head->next;
     head = head->next;
     head = head->next;
     int max = head->count->len;
     int act = head->count->current_point;
     return (act / max);
}