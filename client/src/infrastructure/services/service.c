#include <stdio.h>
 
#include <curl/curl.h>

void check_response(CURLcode res)
{
    if (res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
}