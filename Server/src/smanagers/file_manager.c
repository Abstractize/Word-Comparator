#include "../data/file_repository.h"

int count_word(const char *filename, const char *content, const char *word)
{
    create_file(filename, content);

    int counter = 0;
    char *text = content;
    char *actual_word;

    while(text != '\0')
    {
        if(text == ' ')
        {

        }
        else
        {
            // Adds char to actual_word

            // 
        }
    }

    return counter;
}