#include <ulfius.h>
#include "./listener-manager.h"
#include "../api/routes/routes.h"
#include "./scheduler-manager.h"

void *start_listener()
{
  struct _u_instance instance;

  json_int_t payload = 0;
  y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[+] Server Starting...");
  // Initialize instance with the port number
  if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
  {
    y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[!] Error: Instance creation...");
  }

  // Endpoint list declaration
  add_routes(&instance, payload);

  // Start the framework
  if (ulfius_start_framework(&instance) == U_OK)
  {
    y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[+] Server Listening...");
    pthread_t tid;
    pthread_create(&tid, NULL, scheduler, NULL);
    // Wait for the user to press <enter> on the console to quit the application
    getchar();
  }
  else
  {
    y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[!] Error: Framework Start...");
  }
  y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[-] Server Stopping...");

  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);
}