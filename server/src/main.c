/**
 * @file main.c
 * @brief Scheduler of threads server program. Receives payloads and Schedules threads
 * @author Arturo Mora
 *
 * @date 10/21/2021
 */

#include <stdio.h>
#include <yder.h>
#include <jansson.h>
#include <ulfius.h>
#include "./api/models/process.h"
#include "./api/routes/routes.h"

int main(void)
{

  struct _u_instance instance;
  json_int_t payload = 0;

  y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[+] Server Starting...");
  // Initialize instance with the port number
  if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
  {
    fprintf(stderr, "Error ulfius_init_instance, abort\n");
    return (1);
  }

  // Endpoint list declaration
  add_routes(&instance, payload);

  // Start the framework
  if (ulfius_start_framework(&instance) == U_OK)
  {
    y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[+] Server Listening...");

    // Wait for the user to press <enter> on the console to quit the application
    getchar();
  }
  else
  {
    fprintf(stderr, "Error starting framework\n");
    fprintf(stderr, "Error code: %i\n", ulfius_start_framework(&instance));
  }
  y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[-] Server Stopping...");

  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);

  return 0;
}