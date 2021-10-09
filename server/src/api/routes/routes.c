#include "routes.h"
#include <ulfius.h>
#include "../controllers/hello-world-controller.h"
#include <stdio.h>

void add_routes(struct _u_instance* instance)
{
    ulfius_add_endpoint_by_val(instance, "GET", "/hello-world", NULL, 0, &get_hello_world, NULL);
    ulfius_add_endpoint_by_val(instance, "POST", "/hello-world", NULL, 0, &post_hello_world, NULL);
}