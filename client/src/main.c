#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "infrastructure/services/hello-world-service.h"

int main(int argc, char *argv[])
{
    char *url = getenv("REST_URL");
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl)
    {
        get_hello_world(curl, url);
        post_hello_world(curl, url);
    }
    return 0;
}