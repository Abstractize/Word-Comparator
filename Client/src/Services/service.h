#include <curl/curl.h>

/**
 *  Service common functions
 */

/**
 * @brief Prints an error if the response is not correct
 * 
 * @param res CURLcode to check
 */
void check_response(CURLcode res);