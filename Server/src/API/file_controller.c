#include <ulfius.h>

int post_file_info(const struct _u_request *request, struct _u_response *response, void *user_data)
{
  printf("POST File Content:\n");
  printf("%s\n", u_map_get(request->map_post_body, "file"));
  printf("POST word:\n");
  printf("%s\n", u_map_get(request->map_post_body, "word"));

  return U_CALLBACK_CONTINUE;
}
