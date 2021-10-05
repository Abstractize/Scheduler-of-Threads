#include <stdio.h>
#include <ulfius.h>
#include "api/routes.h"

#define PORT 8080

int main(void)
{

  struct _u_instance instance;

  // Initialize instance with the port number
  if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
  {
    fprintf(stderr, "Error ulfius_init_instance, abort\n");
    return (1);
  }

  // Endpoint list declaration
  add_routes(&instance);

  // Start the framework
  if (ulfius_start_framework(&instance) == U_OK)
  {
    printf("Start framework on port %d\n", instance.port);
    while(1);
  }
  else
  {
    fprintf(stderr, "Error starting framework\n");
    fprintf(stderr, "Error code: %i\n", ulfius_start_framework(&instance));
  }
  printf("End framework\n");

  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);

  return 0;
}
