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
    bool run = true;
    while (run)
    {
        if (curl)
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
            free(response);

            printf("If you want to end the process please press 'f' and enter, otherwise press only enter to continue.\n");


            char end[1];
            scanf("%s", end);
            if(end[0] == 'f')
            {
                printf("Program Closed.\n");
                run = false;
            }
            printf("\n");

        }
    }
    curl_easy_cleanup(curl);   
    return 0;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}