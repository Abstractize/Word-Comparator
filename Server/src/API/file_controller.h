#include <ulfius.h>
/**
 * File and Word Controller
 */

/**
 * @brief Post Word and File
 * 
 * @param request posted info
 * @param response info to client
 * @param user_data authentication data
 * @return int API Code
 */
int post_file_info(const struct _u_request *request, struct _u_response *response, void *user_data);