#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void create_file(const char *filename, const char *content)
{
    
    const char *path = "./data/";
    char *direction = (char *) malloc(1 + strlen(path) + strlen(filename));

    strcpy(direction, path);
    strcat(direction, filename);
    FILE *fp = fopen(direction, "w+");

    free(direction);
    if(fp == NULL)
    {
        perror("fopen()");
        return EXIT_FAILURE;
    }

    fprintf(fp, content);
    fclose(fp);
}