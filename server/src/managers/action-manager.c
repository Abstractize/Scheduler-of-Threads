#include "./action-manager.h"
#include "./view-manager.h"
#include "./scheduler-manager.h"

void action_clear_queue()
{
    clear_count();
}

void action_next_queue()
{
    continue_schedule_method();
}