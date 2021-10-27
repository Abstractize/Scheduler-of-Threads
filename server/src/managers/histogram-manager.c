#include <stdio.h>
#include <string.h>
#include <ulfius.h>
#include "../api/models/histogram.h"
#include "../data/accessors/histogram-accessor.h"

void websocket_manager_callback(const struct _u_request *request,
                                struct _websocket_manager *websocket_manager,
                                void *websocket_manager_user_data)
{
  histogram_t sent_state;
  sent_state.a = -1;
  sent_state.e = -1;
  sent_state.i = -1;
  sent_state.o = -1;
  sent_state.u = -1;

  histogram_t state;
  for (;;)
  {
    state = find();
    if (!equals(state, sent_state))
    {
      sent_state = state;

      json_t *message = json_pack("{sssisisisisi}", "name", state.name, "a", state.a, "e", state.e, "i", state.i, "o", state.o, "u", state.u);
      char *json = json_dumps(message, JSON_COMPACT);
      int ret = ulfius_websocket_send_message(websocket_manager, U_WEBSOCKET_OPCODE_TEXT, strlen(json), json);
      o_free(json);
      json_decref(message);
    }

    if (ulfius_websocket_wait_close(websocket_manager, 5000) != U_WEBSOCKET_STATUS_OPEN)
      break;
  }

  y_log_message(Y_LOG_LEVEL_DEBUG, "Closing websocket_manager_callback");
}