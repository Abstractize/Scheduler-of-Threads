#include <stdio.h>
#include <string.h>
#include <ulfius.h>
#include "../api/models/histogram.h"
#include "../data/accessors/histogram-accessor.h"

void websocket_manager_callback(const struct _u_request *request,
                                struct _websocket_manager *websocket_manager,
                                void *websocket_manager_user_data)
{
  y_log_message(Y_LOG_LEVEL_DEBUG, "Opening websocket_manager_callback");
  histogram_t sent_state = empty();

  histogram_t state = empty();
  for (;;)
  {
    state = find();
    if (!equals(state, sent_state))
    {
      sent_state = state;

      json_t *message = json_pack("{s[ssssssssss]s[iiiiiiiiii]s[iiiiiiiiii]s[iiiiiiiiii]s[iiiiiiiiii]s[iiiiiiiiii]}", 
        "name", state.name[9], state.name[8], state.name[7], state.name[6], state.name[5], state.name[4], state.name[3], state.name[2], state.name[1], state.name[0], 
        "a", state.a[9], state.a[8], state.a[7], state.a[6], state.a[5], state.a[4], state.a[3], state.a[2], state.a[1], state.a[0],
        "e", state.a[9], state.a[8], state.a[7], state.a[6], state.a[5], state.a[4], state.a[3], state.a[2], state.a[1], state.a[0],
        "i", state.a[9], state.a[8], state.a[7], state.a[6], state.a[5], state.a[4], state.a[3], state.a[2], state.a[1], state.a[0],
        "o", state.a[9], state.a[8], state.a[7], state.a[6], state.a[5], state.a[4], state.a[3], state.a[2], state.a[1], state.a[0],
        "u", state.a[9], state.a[8], state.a[7], state.a[6], state.a[5], state.a[4], state.a[3], state.a[2], state.a[1], state.a[0]
      );
      char *json = json_dumps(message, JSON_COMPACT);
      int ret = ulfius_websocket_send_message(websocket_manager, U_WEBSOCKET_OPCODE_TEXT, strlen(json), json);
      o_free(json);
      json_decref(message);
    }

    if (ulfius_websocket_wait_close(websocket_manager, 1000) != U_WEBSOCKET_STATUS_OPEN)
      break;
  }

  y_log_message(Y_LOG_LEVEL_DEBUG, "Closing websocket_manager_callback");
}