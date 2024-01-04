/* CSCI 200: Lab 6B - SFML: Starcraft
 *
 * Author: Thomas Dowd
 * Resources used: N/A
 *
 * DRAW STARS!!!
 * 
 */

#include "starNode.h"
#include "starCraftFunctions.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;


int main() {
    vector <starNode*> vecMain;
    std::ifstream file;
    std::string file_string_beans = "data/beans.txt";
    if(enter_star_file(file) == true){}
    else{return -1;}
    file_to_vector(file,vecMain);
    vector_to_file(file_string_beans,vecMain);
    draw_stars(vecMain);
    return 0;
}