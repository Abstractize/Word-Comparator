/**
 * @file file_manager.h
 * @author Gabriel Abarca (gababarca@estudiantec.cr)
 * @brief Logic for File Processing
 * @version 0.1
 * @date 2021-08-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief counts how many times word is in content
 * 
 * @param filename name of the file
 * @param content where to count
 * @param word what to count
 * @return int times word is in content
 */
int count_word(const char *filename, const char *content, const char *word);