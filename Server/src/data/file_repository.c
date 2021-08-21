#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

void create_file(const char *filename, const char *content)
{

    const char *path = "./data/";
    char *direction = (char *)malloc(1 + strlen(path) + strlen(filename));

    strcpy(direction, path);
    strcat(direction, filename);
    FILE *fp = fopen(direction, "w+");

    free(direction);
    if (fp == NULL)
    {
        mkdir(path, 0700);
        FILE *fp = fopen(direction, "w+");
        if (fp == NULL)
        {
            perror("fopen()");
            return EXIT_FAILURE;
        }
    }

    char dirpath[MAX_BUF];

    getcwd(dirpath, MAX_BUF);
    printf("Created file on %s: %s\n", filename, dirpath);

    fprintf(fp, content);
    fclose(fp);
}