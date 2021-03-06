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
#include <pthread.h>
#include <jansson.h>

#include "infrastructure/services/service.h"

#define IN_SIZE 1000
#define OBJ_MAIN "payload"
#define OBJ_PAFN "filename"
#define OBJ_PAFC "file_content"
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
int read_file(char *filename, char **fcontent);


/**
 * Create new thread to handle Post.
 * @param fcontent JSON Input before read file.
 * @author Arturo Mora
 * @date 10/24/2021
 */
void *thread_express(void *fcontent);

/**
 * Converts a JSON object into a string.
 * @param text String output.
 * @author Arturo Mora
 * @date 10/25/2021
 */
json_t *load_json(const char *text);


int main(int argc, char *argv[])
{
    {

        char *fcontent = NULL;
        pthread_t t0;
        char str[500];

        if (argc < 3) // no arguments were passed
        {
            printf("[!] Usage is %s [ -f file_name |-t {\"Ta\":t, file:name_1},...,{Ta:t, file:name_n}]] ]  \n", argv[0]);
            return -1;
        }

        if (strcmp(FLAG_FILE, argv[1]) == 0) // file mode
        {
            read_file(argv[2], &fcontent);
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


        // Send first payload
        if (DEBUG)
        {
            printf("[D] Content:\n%s\n", fcontent);
        }

        if (pthread_create(&t0, NULL, thread_express, (void *)fcontent) == -1)
        {
            printf("[!] Cannot create thread\n");
        }

        // Get Ready to other payloads
        while (0 == 0)
        {
            printf("[+] Ready for next payload:\n");
            fgets(str, IN_SIZE, stdin);
            fcontent = &str[0];
            if (pthread_create(&t0, NULL, thread_express, (void *)fcontent) == -1)
            {
                printf("[!] Cannot create thread\n");
            }
            if (DEBUG)
            {
                printf("[D] Content:\n%s\n", fcontent);
            }
        }

        return EXIT_SUCCESS;
    }
}

int read_file(char *filename, char **fcontent)
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
    *fcontent = (char *)malloc(sizeof(char) * fsize);
    fread(*fcontent, 1, fsize, fp);
    if (fclose(fp) == EOF)
    {
        printf("[E] Failed to close %s \n", filename);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}



void *thread_express(void *fcontent)
{
    char *sfcontent = (char *)fcontent;

    json_t *root = load_json(sfcontent);
    json_t *obj = json_object_get(root, OBJ_MAIN);
    size_t index = 0;
    json_t *value, *data_fn;

    json_array_foreach(obj, index, value)
    {
        value = json_array_get(obj, index);         // Get element of array
        data_fn = json_object_get(value, OBJ_PAFN); // Get Key OBJ_PAFN;
        char *dfcontent = json_string_value(data_fn);
        char *rfcontent = 0;
        read_file(dfcontent, &rfcontent);
        json_object_set(value, OBJ_PAFC, json_string(rfcontent)); // Set New Key & Value
    }
    sfcontent = json_dumps(root, 0);
    send_post(sfcontent);
    json_decref(root);
}

json_t *load_json(const char *text)
{
    json_t *root;
    json_error_t error;

    root = json_loads(text, 0, &error);

    if (root)
    {
        return root;
    }
    else
    {
        fprintf(stderr, "json error on line %d: %s\n", error.line, error.text);
        return (json_t *)0;
    }
}