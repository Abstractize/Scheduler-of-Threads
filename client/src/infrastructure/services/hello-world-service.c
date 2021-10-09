#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "service.h"

const char path[] = "hello-world";

CURLcode get_hello_world(CURL *curl, char *url)
{
  int length = strlen(url) + strlen(path);
  char new_url[length];

  strcpy(new_url, url);
  strcat(new_url, path);

  printf("Getting on: %s\n", new_url);
  CURLcode res;
  CURLcode value;
  char *ct;
  
  curl_easy_setopt(curl, CURLOPT_URL, new_url);

  res = curl_easy_perform(curl);

  check_response(res);
  return res;
}

CURLcode post_hello_world(CURL *curl, char *url)
{
  int length = strlen(url) + strlen(path);
  char new_url[length];

  strcpy(new_url, url);
  strcat(new_url, path);

  printf("Posting: %s\n", new_url);
  CURLcode res;
  curl_mime *form = NULL;
  curl_mimepart *field = NULL;
  struct curl_slist *headerlist = NULL;
  static const char buf[] = "Expect:";

  form = curl_mime_init(curl);

  field = curl_mime_addpart(form);
  curl_mime_name(field, "id");
  curl_mime_data(field, "Hello World!", CURL_ZERO_TERMINATED);

  headerlist = curl_slist_append(headerlist, buf);

  curl_easy_setopt(curl, CURLOPT_URL, new_url);
  curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

  res = curl_easy_perform(curl);
  check_response(res);

  curl_easy_cleanup(curl);
  curl_mime_free(form);
  curl_slist_free_all(headerlist);
  return res;
}
