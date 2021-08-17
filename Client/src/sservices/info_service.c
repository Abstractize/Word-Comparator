#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "service.h"

CURLcode post_info(CURL *curl, char *url)
{
  printf("Posting: %s\n", url);
  CURLcode res;
  curl_mime *form = NULL;
  curl_mimepart *field = NULL;
  struct curl_slist *headerlist = NULL;
  static const char buf[] = "Expect:";
  
  form = curl_mime_init(curl);

  field = curl_mime_addpart(form);
  curl_mime_name(field, "filename");
  curl_mime_data(field, "hello.txt", CURL_ZERO_TERMINATED);

  field = curl_mime_addpart(form);
  curl_mime_name(field, "file");
  curl_mime_data(field, "Hello World! Hello other World! Hello World Again!", CURL_ZERO_TERMINATED);

  field = curl_mime_addpart(form);
  curl_mime_name(field, "word");
  curl_mime_data(field, "Hello", CURL_ZERO_TERMINATED);

  headerlist = curl_slist_append(headerlist, buf);
  
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

  res = curl_easy_perform(curl);
  check_response(res);


  curl_easy_cleanup(curl);
  curl_mime_free(form);
  curl_slist_free_all(headerlist);
  return res;
}
