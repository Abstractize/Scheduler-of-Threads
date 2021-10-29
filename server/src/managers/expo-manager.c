#include <gtk/gtk.h>
#include "./expo-manager.h"
#include "../properties/enums.h"
#include "../api/models/lists.h"
#include "../data/models/vowel-list.h"

const struct vowel_count_list *get_scheduler_result()
{
     return (&count_list);
}

const schedule_e get_scheduler_count()
{
     return actual_schedule;
}

const int get_count()
{
     return (count_list.size);
}

const int get_index(const schedule_e current)
{
     struct vowel_count_node *head = count_list.start;
     for (int i; i < current; i++)
          head = head->next;
     return head->index;
}

const float get_progress_1()
{
     struct vowel_count_node *head = count_list.start;
     double res = 0.0;
     if (head != NULL)
     {
          int max = head->count->len;
          max = (max > 0) ? max : 1;
          res = 1 / max;
     }
     return (res);
}

const float get_progress_2()
{
     double res = 0.0;
     struct vowel_count_node *head = count_list.start;
     if (head == NULL)
          return res;
     head = head->next;

     if (head != NULL)
     {
          int max = head->count->len;
          max = (max > 0) ? max : 1;
          res = 1 / max;
     }
     return (res);
}

const float get_progress_3()
{
     double res = 0.0;
     struct vowel_count_node *head = count_list.start;
     if (head == NULL)
          return res;
     head = head->next;
     if (head == NULL)
          return res;
     head = head->next;

     if (head != NULL)
     {
          int max = head->count->len;
          max = (max > 0) ? max : 1;
          res = 1 / max;
     }
     return (res);
}

const float get_progress_4()
{
     double res = 0.0;
     struct vowel_count_node *head = count_list.start;
     if (head == NULL)
          return res;
     head = head->next;
     if (head == NULL)
          return res;
     head = head->next;
     if (head == NULL)
          return res;
     head = head->next;
     if (head != NULL)
     {
          int max = head->count->len;
          max = (max > 0) ? max : 1;
          res = 1 / max;
     }
     return (res);
}

const float get_progress_5()
{
     double res = 0.0;
     struct vowel_count_node *head = count_list.start;
     if (head == NULL)
          return res;
     head = head->next;
     if (head == NULL)
          return res;
     head = head->next;
     if (head == NULL)
          return res;
     head = head->next;
     if (head == NULL)
          return res;
     head = head->next;

     if (head != NULL)
     {
          int max = head->count->len;
          max = (max > 0) ? max : 1;
          res = 1 / max;
     }
     return (res);
}