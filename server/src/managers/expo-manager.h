#include <gtk/gtk.h>
#include "../properties/enums.h"
#include "../api/models/lists.h"
#include "../data/models/vowel-list.h"

#ifndef EXPO_MANAGER_HEADER_H
#define EXPO_MANAGER_HEADER_H

const int get_count();

const int get_index(const schedule_e current);

const float get_progress_1();

const float get_progress_2();

const float get_progress_3();

const float get_progress_4();

const float get_progress_5();

const schedule_e get_scheduler_count();

const struct vowel_count_list* get_scheduler_result(); 

#endif // EXPO_MANAGER_HEADER_H