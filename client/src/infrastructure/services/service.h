#include <curl/curl.h>


/**
 * Send HTTP Post with JSON.
 * @author Arturo Mora
 * @param fcontent JSON file to send.
 * @date 10/22/2021
 */
CURLcode send_post(char *fcontent);

void check_response(CURLcode res);