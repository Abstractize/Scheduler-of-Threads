#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include <ulfius.h>
#include "../../managers/histogram-manager.h"

int get_histrogram_data(const struct _u_request *request, struct _u_response *response, void *user_data)
{
  int ret;

  if ((ret = ulfius_set_websocket_response(response, NULL, NULL, &websocket_manager_callback, NULL, NULL, NULL, NULL, NULL)) == U_OK) 
  {
    return U_CALLBACK_CONTINUE;
  } 
  else 
  {
    return U_CALLBACK_ERROR;
  }
}