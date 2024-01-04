#ifndef STARCRAFTFUNC_h
#define STARCRAFTFUNC_h

#include <string>
#include <vector>
/**
 * @brief Returns a valid ifstream object by object
 * 
 * @return true 
 * @return false 
 */
bool enter_star_file(std::ifstream&);
/**
 * @brief From a file into a vector class
 * 
 */
void file_to_vector(std::ifstream&, std::vector <starNode*>&);
/**
 * @brief From a vector to a file
 * 
 */
void vector_to_file(std::string, std::vector <starNode*>);
/**
 * @brief Draw stars to sfml terminal.
 * 
 */
void draw_stars(std::vector <starNode*>);
#endif