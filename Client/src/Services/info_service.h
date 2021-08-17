/**
 * Service to post info
 */

/**
 * @brief posts document and word
 * 
 * @param curl instance of the curl
 * @param url service URL to do the Post
 * @return int CURLcode of the process 
 */
int post_info(CURL *curl, char *url);