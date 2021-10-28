#include "routes.h"
#include <ulfius.h>
#include "../controllers/hello-world-controller.h"
#include "../controllers/histogram-controller.h"
#include "../controllers/scheduler-controller.h"
#include <stdio.h>

#define PREFIX "/server"

void add_routes(struct _u_instance* instance, json_int_t payload)
{
    ulfius_add_endpoint_by_val(instance, "GET", "/hello-world", NULL, 0, &get_hello_world, NULL);
    ulfius_add_endpoint_by_val(instance, "POST", "/hello-world", NULL, 0, &post_hello_world, NULL);
    ulfius_add_endpoint_by_val(instance, "POST", PREFIX, NULL, 1, &callback_post, &payload);
    ulfius_add_endpoint_by_val(instance, "GET", "/websocket", NULL, 0, &get_histrogram_data, NULL);
}