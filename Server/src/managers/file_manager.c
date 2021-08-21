#include "../data/file_repository.h"

int count_word(const char *filename, const char *content, const char *word)
{
    //create_file(filename, content);

    int counter = 0;

    const char *holdcontent, *holdword, *wordtop, *text = content;
    while (*text != '\0')
    {
        for (wordtop = holdcontent = text, holdword = word;
             *holdword != '\0' && *holdcontent == *holdword;
             holdword++, holdcontent++)
            ;
        if (!*holdword && (wordtop == content || isspace(wordtop[-1])) && (!*holdcontent || isspace(*holdcontent)))
        {
            counter++;
        }
        *text++;
    }

    return counter;
}