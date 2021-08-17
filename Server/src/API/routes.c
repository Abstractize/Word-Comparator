#include "routes.h"
#include <ulfius.h>
#include <stdio.h>
#include "file_controller.h"

void add_routes(struct _u_instance* instance)
{
    ulfius_add_endpoint_by_val(instance, "POST", "/file", NULL, 0, &post_file, NULL);
    ulfius_add_endpoint_by_val(instance, "POST", "/word", NULL, 0, &post_word, NULL);
}