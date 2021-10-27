#include <ulfius.h>

int get_hello_world(const struct _u_request *request, struct _u_response *response, void *user_data)
{
  ulfius_set_string_body_response(response, 200, "Hello World!\n");
  return U_CALLBACK_CONTINUE;
}

int post_hello_world(const struct _u_request *request, struct _u_response *response, void *user_data)
{
  printf("POST\n");
  printf("%s\n", u_map_get(request->map_post_body, "id"));
  //ulfius_set_string_body_response(response, 200, response_body);
  //o_free(response_body);

  return U_CALLBACK_CONTINUE;
}
