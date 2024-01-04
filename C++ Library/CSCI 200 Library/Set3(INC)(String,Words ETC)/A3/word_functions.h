#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H
#include<fstream>
#include<vector>
// #include<string>
/**
 * @brief (1) The input file stream (2) The string filename to open Output: True if the file successfully opened, False if the file could not be opened
 * 
 * @param streamin this is a variable for the file being read to. PASSED VIA REF
 * @param fileString a constant variable for the name of the file. 
 * 
 * @return true File Opened
 * @return false File didnt open.
 */
bool open_file(std::ifstream& streamin, const std::string fileString);
/**
 * @brief Task: Read all the words that are in the file stream and return a vector of all the words in the order present in the file.
 * 
 * @param streamin The input file stream VIA REF
 * @return std::vector<std::string> A vector of strings
 */
std::vector<std::string> read_words_from_file(std::ifstream& streamin);
/**
 * @brief Task: For each word in the vector, remove all occurrences of all the punctuation characters denoted by the punctuation string. When complete, the input vector will now hold all the words with punctuation removed. The punctuation string will remain unchanged.
 * 
 * @param streamin The input file stream VIA REF
 * @param PUNCTTOREMOVE String of all the puncuation to remove.
 */
void remove_punctuation(std::vector<std::string>& bigVector, std::string const PUNCTTOREMOVE);
/**
 * @brief Takes out Capitalized letters
 * 
 * @param bigVecotrNoPunct a big vector of strings passed via refFor each word in the vector, convert each character to its upper case equivalent. When complete, the input vector will now hold all the words capitalized.
 */
void capitalize_words(std::vector<std::string>&bigVecotrNoPunct);
/**
 * @brief The function will return only the unique words present in the input vector. The output vector will not contain any duplicate words.
 * 
 * @param bigVecotrNoPunctNoCaps A vector of strings
 * @return std::vector<std::string> 
 */
std::vector<std::string> filter_unique_words(std::vector<std::string>&bigVecotrNoPunctNoCaps);
/**
 * @brief The function will count the number of occurrences of each unique word in the entire text. The output vector will be the same size as the vector of unique words with element positions corresponding to the same word and count.
 * 
 * @param bigVector  (1) A vector of strings containing all the words
 * @param bigVectorFilterdUniqueWords A vector of strings containing only the unique words, Grabbed from previous FILTER function.
 * @return std::vector<unsigned int> 
 */
std::vector<unsigned int> count_unique_words(std::vector<std::string>& bigVector, std::vector<std::string>& bigVectorFilterdUniqueWords);
/**
 * @brief Count the number of occurrences of each letter present in all words. Each position of the array corresponds to each letter as ordered by the English alphabet. Upon completion, the array will hold the counts of each letter and the vector of strings will remain unchanged.
 * 
 * @param bigVector (1) A vector of strings
 * @param letters   (2) An array of 26 unsigned integers
 */
void count_letters(std::vector<std::string>& bigVector, unsigned int (&letters)[26]);
/**
 * @brief For each letter, print out the letter and its corresponding count to the standard out. Format the output as follows:
 * 
 * @param letters An array of 26 unsigned integers
 */
void print_letter_counts(unsigned int (&letters)[26]);
/**
 * @brief Task: For each letter, print out the letter and its corresponding count to the standard out. Format the output as follows:
 * 
 * @param bigVector SEE RUBRIC FOR FULL INFO
 * @param array input: An array of 26 unsigned integers
 */
void print_unique_word_counts(std::vector<std::string>& bigVector, std::vector<unsigned int> uniqueWordCounts); // There could be problems here with the unsigned array list see back later.
/**
 * @brief Print out the two letters that occur least often and most often to the standard out. If there is more than one letter that occurs the same number of times, print the one that comes first alphabetically. Upon completion, the input array will remain unchanged. Print out the following pieces of information:
 * 
 * @param letters An array of 26 unsigned integers
 */
void print_max_min_letter(unsigned int (&letters)[26]);
#endif