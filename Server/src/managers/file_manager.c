#include "../data/file_repository.h"

int count_word(const char *filename, const char *content, const char *word)
{
    create_file(filename, content);

    int counter = 0;

    const char *tmp_text, *tmp_text, *first_char, *text = content;
    while (*text != '\0')
    {
        for (first_char = tmp_text = text, tmp_text = word;
             *tmp_text != '\0' && *tmp_text == *tmp_text;
             tmp_text++, tmp_text++)
            ;

        if (!*tmp_text && (first_char == content || isspace(first_char[-1])) && (!*tmp_text || isspace(*tmp_text)))
        {
            counter++;
        }
        *text++;
    }

    return counter;
}