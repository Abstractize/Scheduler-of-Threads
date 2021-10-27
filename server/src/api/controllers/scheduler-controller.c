#include <stdio.h>
#include <yder.h>
#include <jansson.h>
#include <ulfius.h>
#include "../models/lists.h"
#include "../models/process.h"

#define OBJ_MAIN "payload"
#define OBJ_PATA "Ta"
#define OBJ_PAFN "filename"
#define OBJ_PAFC "file_content"

int callback_post(const struct _u_request *request, struct _u_response *response, void *userData)
{
    json_t *json_nb_payload = ulfius_get_json_body_request(request, NULL), *json_body = NULL, *obj = NULL;
    json_int_t *nb_sheep = userData;

    size_t index = 0;
    json_t *value, *data_fn, *data_ta, *data_fc;

    if (json_nb_payload != NULL)
    {
        *nb_sheep = json_object_size(obj);
        obj = json_object_get(json_nb_payload, OBJ_MAIN);
        y_log_message(Y_LOG_LEVEL_DEBUG, "\t%s \t%s \t%s \t%s", "Index", "Ta", "Filename", "Content");
        json_array_foreach(obj, index, value)
        {
            // value = json_array_get(obj, index);         // Get element of array
            data_ta = json_object_get(value, OBJ_PATA); // Get Key OBJ_PATA
            data_fn = json_object_get(value, OBJ_PAFN); // Get Key OBJ_PAFN
            data_fc = json_object_get(value, OBJ_PAFC); // Get Key OBJ_PAFC
            setup_proc(json_integer_value(data_ta), json_string_value(data_fn), json_string_value(data_fc), 0.3);

            y_log_message(Y_LOG_LEVEL_DEBUG, "\t%i \t%i \t%s \t%s", index, json_integer_value(data_ta), json_string_value(data_fn), json_string_value(data_fc));
        }
    }
    json_decref(json_nb_payload);
    return U_CALLBACK_CONTINUE;
}
