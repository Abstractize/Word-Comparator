#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>
#include "services/info_service.h"

#define MAX 255

int main(int argc, char *argv[])
{

    char *url = getenv("REST_URL");
    CURL *curl;
    CURLcode res;

    printf("Connects to API URL: %s\n", url);

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl)
    {
        bool run = true;
        while (run)
        {
            char filename[MAX];
            printf("Please enter the filename: \n");
            scanf("%s", filename);
            printf("Chosen file is: %s\n\n", filename);

            char word[MAX];
            printf("Please enter the word to search: \n");
            scanf("%s", word);
            printf("Chosen word is: %s\n\n", word);

            char *response = post_info(curl, url, filename, word);
            printf("Number of times the word %s is in %s: %s\n\n", word, filename, response);
        
            char end;
            printf("If you want to end the process please press 'f', otherwise press another key to continue. \n");
            scanf("%c", &end);
            if(end == 'f')
            {
                printf("Program Closed.\n");
                run = false;
            }
        }
    }
    return 0;
}