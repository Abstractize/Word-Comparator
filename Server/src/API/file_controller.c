#include <ulfius.h>
#include "../Managers/file_manager.h"

int post_file_info(const struct _u_request *request, struct _u_response *response, void *user_data)
{
  printf("POST Filename: \n");
  const char *filename = u_map_get(request->map_post_body, "filename");
  printf("%s\n", filename);
  printf("POST File Content:\n");
  const char *content = u_map_get(request->map_post_body, "file");
  printf("%s\n", content);
  printf("POST word:\n");
  const char *word = u_map_get(request->map_post_body, "word");
  printf("%s\n", word);

  int count = count_word(filename, content, word);

  return U_CALLBACK_CONTINUE;
}
