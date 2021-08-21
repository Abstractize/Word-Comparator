#include <ulfius.h>
#include "../managers/file_manager.h"

int post_file_info(const struct _u_request *request, struct _u_response *response, void *user_data)
{
  const char *filename = u_map_get(request->map_post_body, "filename");
  const char *content = u_map_get(request->map_post_body, "file");
  const char *word = u_map_get(request->map_post_body, "word");

  int count = count_word(filename, content, word);
  printf("%s is %i times in %s\n", word, count, content);


  const char *response_body;
  sprintf(response_body, "%i\n", count);
  ulfius_set_string_body_response(response, 200, response_body);
  free(response_body);

  return U_CALLBACK_CONTINUE;
}
