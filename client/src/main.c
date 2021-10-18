#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "infrastructure/services/hello-world-service.h"

#define FLAG_FILE "-f"
#define FLAG_STRG "-t"
#define DEBUG 1

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int main(int argc, char *argv[])
{
    
    char *fcontent = NULL;

    if (argc < 1) // no arguments were passed
    {
        printf("[!] Usage is %s [ -f file_name |-t {\"Ta\":t, file:name_1},...,{Ta:t, file:name_n}]] ]  \n", argv[0]);
        return -1;
    }

    if (strcmp(FLAG_FILE, argv[1]) == 0) // file mode
    {
        FILE *fp = fopen(argv[2], "r");
        int fsize = 0;
        if (fp == NULL)
        {
            printf("[E] Cannot open %s \n", argv[2]);
            return EXIT_FAILURE;
        }
        fseek(fp, 0, SEEK_END);
        fsize = ftell(fp);
        rewind(fp);
        fcontent = (char *)malloc(sizeof(char) * fsize);
        fread(fcontent, 1, fsize, fp);
        if (fclose(fp) == EOF)
        {
            printf("[E] Failed to close %s \n", argv[2]);
            return EXIT_FAILURE;
        }
    }
    else if (strcmp(FLAG_STRG, argv[1]) == 0) // text mode
    {
        fcontent = argv[2];
    }
    else
    {
        printf("[!] Usage is %s [ -f name |-t [{Ta:t, file name_1}]] ]  \n", argv[0]);
        return -1;
    }

    //remove_spaces(fcontent);

    if (DEBUG) {
        printf("[D] Content:\n%s", fcontent);
    }
    /*
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
        */
    return EXIT_SUCCESS;
}