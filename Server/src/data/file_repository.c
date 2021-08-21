#include <stdio.h>
#include <memory.h>

void create_file(const char *filename, const char *content)
{
    FILE *fp;
    const char *path = "./data/";
    char *direction = (char *) malloc(1 + strlen(path) + strlen(filename));

    strcpy(direction, path);
    strcat(direction, filename);

    fp = fopen(direction, "w+");
    fprintf(fp, content);
    fclose(fp);
    free(direction)
    free(fp)
    free(path)
}