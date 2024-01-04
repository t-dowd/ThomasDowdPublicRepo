#ifndef WUMPUS_FUNCTION_H
#define WUMPUS_FUNCTION_H

// #include<iostream>
#include<fstream>
using namespace std;
/**
 * @brief Prompts the user to imput a string.
 * 
 * @return string 
 */
std::string enter_wumpus_file();
/**
 * @brief Prompts the user for the .log file to open
 * 
 * @return string 
 */
std::string enter_game_log_file();
/**
 * @brief Opens the corresponding files for reading and writing based on the file names provided. Verifies that both files successfully opened, returning true if so. Otherwise, if either file failed to open, returns false.
 * 
 * @param wumpusFileIn  an ifstream object to open
 * @param wumpusFileOut an ofstream object to open
 * @param WUMPUS_FILE_NAME  a string corresponding to the file to read from
 * @param GAME_LOG_FILE_NAME a string corresponding to the file to write to
 * @return true 
 * @return false 
 */
bool open_files(std::ifstream& , std::ofstream&, const string, const string); //THIS IS CORRECT SEE HERE FOR ELSE
/**
 * @brief Reads the cave size information of the file (the first two values). Upon completion, the parameters corresponding to the width & height will match the values read from the file
 * 
 * @param wumpusFileIn an ifstream object to read from
 * @param caveWidth Width passed via refrence
 * @param caveHeight Height Passed via refrence
 */
void read_world_header(std::ifstream& wumpusFileIn,int& caveWidth, int& caveHeight);
/**
 * @brief Reads the object header information of the file (the next six values). Upon completion, the parameters corresponding to the (X, Y) location of each object will correspond to the values read from the file.
 * 
 * @param wumpusFileIn an ifstream object to read from
 * @param wumpusX Wumpus x value
 * @param wumpusY Wumpus y value
 * @param heroX hero x value
 * @param heroY hero y value
 * @param itX pit x value 
 * @param pitY pit y value
 * @return true 
 * @return false 
 */
bool read_object_header(std::ifstream& wumpusFileIn,int& wumpusX, int& wumpusY,int& heroX, int& heroY,int& itX,int &pitY);
/**
 * @brief Reads the number of moves information of the file (the next values). Upon completion, the parameter corresponding to the number of moves will match the value read from the file.
 * 
 * @param wumpusFileIn an ifstream object to read from
 * @param numMoves  an integer corresponding to the number of moves that follow passed by reference
 */
void read_number_moves(std::ifstream& wumpusFileIn, int &numMoves);
/**
 * @brief Promts the user if they want to play as hero(H) or wumpus(w). return true for hero, false otherwise. 
 * 
 * @return true 
 * @return false 
 */
bool choose_player();
/**
 * @brief Simulates the game play as laid out in the input file and writes the game log to the output file.
 * 
 * @param wumpusFileIn an ifstream object to read from
 * @param gameLogOut an ofstream object to write to 
 * @param caveWidth intiger representing cave width passed by refrence
 * @param caveHeight intiger representing cave height passed by refrence
 * @param numMoves intiger representing number of moved passed by refrence
 * @param wumpusX intiger representing wupmus x value passed by refrence
 * @param wumpusY intiger representing wupmus y value passed by refrence
 * @param heroX intiger representing hero x value passed by refrence
 * @param heroY intiger representing hero x value passed by refrence
 * @param pitX intiger representing pit x value passed by refrence
 * @param pitY intiger representing pit y value passed by refrence
 * @param PLAY_AS_HERO boolean if user is hero. Passed via ref
 */
void play_game(std::ifstream& wumpusFileIn, std::ofstream& gameLogOut,
              int &caveWidth, int &caveHeight,
              int &numMoves,
              int &wumpusX, int &wumpusY,
              int &heroX, int &heroY,
              int &pitX, int &pitY,
              const bool &PLAY_AS_HERO);

#endif