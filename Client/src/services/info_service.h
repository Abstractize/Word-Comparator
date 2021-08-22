/**
 * Service to post info
 */

/**
 * @brief posts document and word. Get Code from https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
 * 
 * @param curl instance of the curl
 * @param url service URL to do the Post
 * @param filename file to send
 * @param word word to count
 * @return int CURLcode of the process 
 */
char *post_info(CURL *curl, char *url, char *filename, char *word);