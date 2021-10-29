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
        "name", state.name[0], state.name[1], state.name[2], state.name[3], state.name[4], state.name[5], state.name[6], state.name[7], state.name[8], state.name[9], 
        "a", state.a[0], state.a[1], state.a[2], state.a[3], state.a[4], state.a[5], state.a[6], state.a[7], state.a[8], state.a[9],
        "e", state.e[0], state.e[1], state.e[2], state.e[3], state.e[4], state.e[5], state.e[6], state.e[7], state.e[8], state.e[9],
        "i", state.i[0], state.i[1], state.i[2], state.i[3], state.i[4], state.i[5], state.i[6], state.i[7], state.i[8], state.i[9],
        "o", state.o[0], state.o[1], state.o[2], state.o[3], state.o[4], state.o[5], state.o[6], state.o[7], state.o[8], state.o[9],
        "u", state.u[0], state.u[1], state.u[2], state.u[3], state.u[4], state.u[5], state.u[6], state.u[7], state.u[8], state.u[9]
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