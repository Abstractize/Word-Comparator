#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "service.h"
struct memory
{
  char *response;
  size_t size;
};

static size_t function_pt(void *data, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct memory *mem = (struct memory *)userp;

  char *ptr = realloc(mem->response, mem->size + realsize + 1);
  if (ptr == NULL)
    return 0; /* out of memory! */

  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), data, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;

  return realsize;
}

char *post_info(CURL *curl, char *url, char *filename, char *word)
{
  char *path = "./data/";
  char *file = (char *)malloc(1 + strlen(path) + strlen(filename));
  strcpy(file, path);
  strcat(file, filename);

  printf("Posting: %s\n", url);
  CURLcode res;
  curl_mime *form = NULL;
  curl_mimepart *field = NULL;
  struct curl_slist *headerlist = NULL;
  static const char buf[] = "Expect:";

  form = curl_mime_init(curl);

  field = curl_mime_addpart(form);
  curl_mime_name(field, "file");
  curl_mime_filedata(field, file);

  field = curl_mime_addpart(form);
  curl_mime_name(field, "filename");
  curl_mime_data(field, filename, CURL_ZERO_TERMINATED);

  field = curl_mime_addpart(form);
  curl_mime_name(field, "word");
  curl_mime_data(field, word, CURL_ZERO_TERMINATED);

  headerlist = curl_slist_append(headerlist, buf);

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

  struct memory chunk = {0};
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

  res = curl_easy_perform(curl);

  check_response(res);

  curl_mime_free(form);
  curl_slist_free_all(headerlist);

  return chunk.response;
}
