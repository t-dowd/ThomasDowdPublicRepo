#ifndef MAZEFUNC_h
#define MAZEFUNC_h

#include <string>
#include <vector>
/**
 * @brief  Gets the name of file
 * 
 * @return std::string 
 */
std::string enter_maze_file();
/**
 * @brief Opens the file
 * 
 * @param file The file Object
 * @param filename The string filename
 * @param xcoord 
 * @param ycoord 
 * @return true Opened Properly
 * @return false Failed to open
 */
bool open_files(std::ifstream& file, const std::string filename,int& xcoord,int& ycoord);
/**
 * @brief Puts the file into a 2-d array
 * 
 * @param xval the x-Value or width
 * @param yval the Y-Value or Height
 * @param fileobj The file Object
 * @return MazeNode** An epic list
 */
MazeNode** FileToLit2D(int xval, int yval,std::ifstream& fileobj);
/**
 * @brief Function to make a value for a MazeNode
 * 
 * @param filein 
 * @return MazeNode* 
 */
MazeNode* makeNodeForValue(std::ifstream& filein);
/**
 * @brief Overloaded MakeNodeforValue
 * 
 * @param x 
 * @param y 
 * @param chrtr 
 * @return MazeNode* 
 */
MazeNode* makeNodeForValue(int x, int y,char chrtr);
/**
 * @brief FullPrints the Array
 * 
 * @param MainList 
 * @param x 
 * @param y 
 */
void fullprint(MazeNode** MainList,int x,int y);
/**
 * @brief Main Recusive Function
 * 
 * @param X CURRENT x value
 * @param Y CURRENT y value
 * @param width Width of total array
 * @param height Height of Array
 */
void dfsWayOut(MazeNode**,int X, int Y, bool&,const int width, const int height);
/**
 * @brief Finds the S value
 * 
 * @param ListFromMain The large list.
 * @param Width 
 * @param Height 
 */
void findStart(MazeNode **ListFromMain, int &Width, int &Height);
/**
 * @brief BFS Algorithm for a way out
 * 
 * @param ListFromMain The large list.
 * @param Queue a list of values that need to be checked
 * @param X X value of start Pos
 * @param Y Y valye of start Pos
 * @param width Width of board
 * @param height Height of Boar
 */
void bfsFindWayOut(MazeNode** ListFromMain, std::vector <MazeNode*> & Queue, int X, int Y,const int width, const int height);


#endif