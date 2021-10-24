/**
 * @file main.c
 * @brief Scheduler of threads client program. Sends payloads to be processed to the server.
 * @author Arturo Mora
 *
 * @date 10/21/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "infrastructure/services/hello-world-service.h"

#define FLAG_FILE "-f"
#define FLAG_STRG "-t"
#define DEBUG 1

/**
 * Read a text file.
 * @author Arturo Mora
 * @param filename Name of the file.
 * @param fcontent Pointer to the content result.
 * @date 10/18/2021
 */
int read_file(char *filename, char *fcontent);

/**
 * Send HTTP Post with JSON.
 * @author Arturo Mora
 * @date 10/22/2021
 */
int send_post(char *fcontent);

int main(int argc, char *argv[])
{
    {

        char *fcontent = NULL;

        if (argc < 3) // no arguments were passed
        {
            printf("[!] Usage is %s [ -f file_name |-t {\"Ta\":t, file:name_1},...,{Ta:t, file:name_n}]] ]  \n", argv[0]);
            return -1;
        }

        if (strcmp(FLAG_FILE, argv[1]) == 0) // file mode
        {
            read_file(argv[2], fcontent);
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
        if (DEBUG)
        {
            printf("[D] Content:\n%s\n", fcontent);
        }

        // CURL Hello
        send_post(fcontent);
        return EXIT_SUCCESS;
    }
}

int read_file(char *filename, char *fcontent)
{
    FILE *fp = fopen(filename, "r");
    int fsize = 0;
    if (fp == NULL)
    {
        printf("[E] Cannot open %s \n", filename);
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);
    fcontent = (char *)malloc(sizeof(char) * fsize);
    fread(fcontent, 1, fsize, fp);
    if (fclose(fp) == EOF)
    {
        printf("[E] Failed to close %s \n", filename);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int send_post(char *fcontent)
{
    char *url = "http://127.0.0.1:6969/server/"; // TODO = getenv("REST_URL");
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl)
    {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fcontent);
        res = curl_easy_perform(curl);
        if (DEBUG)
        {
            printf("[D] Response Code:\n%i", res);
        }
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        /* always cleanup */
        curl_easy_cleanup(curl);
        curl_slist_free_all(chunk);
    }
    curl_global_cleanup();
    return EXIT_SUCCESS;
}