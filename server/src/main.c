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
#include "api/models/process.h"

#define PORT 6969
#define PREFIX "/server"
#define OBJ_MAIN "payload"
#define OBJ_PATA "Ta"
#define OBJ_PAFN "filename"
#define OBJ_PAFC "file_content"

/**
 * Get a JSON Request.
 * @author Arturo Mora
 * @param request HTTP request.
 * @param response HTTP response.
 * @param userData Information attached to body.
 * @date 10/22/2021
 */
int callback_post(const struct _u_request *request, struct _u_response *response, void *userData);

int main(void)
{

  struct _u_instance instance;
  json_int_t nb_sheep = 0;

  y_init_logs("Server", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "[+] Server Starting...");
  // Initialize instance with the port number
  if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
  {
    fprintf(stderr, "Error ulfius_init_instance, abort\n");
    return (1);
  }

  // Endpoint list declaration
  ulfius_add_endpoint_by_val(&instance, "POST", PREFIX, NULL, 1, &callback_post, &nb_sheep);

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

int callback_post(const struct _u_request *request, struct _u_response *response, void *userData)
{
  json_t *json_nb_payload = ulfius_get_json_body_request(request, NULL), *json_body = NULL, *obj = NULL;
  json_int_t *nb_sheep = userData;

  size_t index = 0;
  json_t *value, *data_fn, *data_ta, *data_fc;

  struct process_list list = setup_list();

  if (json_nb_payload != NULL)
  {
    *nb_sheep = json_object_size(obj);
    obj = json_object_get(json_nb_payload, OBJ_MAIN);
    y_log_message(Y_LOG_LEVEL_DEBUG, "\t%s \t%s \t%s", "Index", "Ta", "Filename");
    json_array_foreach(obj, index, value)
    {
      // value = json_array_get(obj, index);         // Get element of array
      data_ta = json_object_get(value, OBJ_PATA); // Get Key OBJ_PATA
      data_fn = json_object_get(value, OBJ_PAFN); // Get Key OBJ_PAFN
      data_fc = json_object_get(value, OBJ_PAFC); // Get Key OBJ_PAFC
      setup_proc(json_integer_value(data_ta), json_string_value(data_fn), json_string_value(data_fc), &list);
      
      y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i \t%i \t%s", index, json_integer_value(data_ta), json_string_value(data_fn));
    }
    y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i", list.size);
    struct process_node *node = list.start;
    y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i \t%s \t%s", node->proc->Ta, node->proc->filename, node->proc->file_content);
    for (int i = 0; i < list.size - 1; i++)
    {
      node = node->next;
      y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i \t%s \t%s", node->proc->Ta, node->proc->filename, node->proc->file_content);
    }
    
  }
  json_decref(json_nb_payload);
  return U_CALLBACK_CONTINUE;
}