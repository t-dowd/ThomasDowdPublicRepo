/* CSCI 200: Final Project: MINESWEEPER++
 *
 * Author: Thomas Dowd
 * 
 * Sources: https://www.sfml-dev.org/tutorials/2.3/graphics-view.php#coordinates-conversions (Used 
 *          for interacting with the board via mouse and keyboard)
 *  
 * Description: The gamne of Minesweeper
 */
#include "Sweep.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


int main(){
    firstBoot(); // File Io as well as terminal splash screen.
    srand(time(0)); // Seeds random
    int const yBorderValue = 9;
    int const xBorderValue = 13; // DO NOT CHANGE you will have funky stuff
    int const NUMMINES = 7;
    // bool doonce= true;
    // 7(width)x11(height)            y X 
    GameNode** ListMain = CreateBoard(yBorderValue,xBorderValue,NUMMINES); // Creates the game board that wil be used
    drawGameBoard(ListMain,yBorderValue,xBorderValue); // Main game loop for SFML See implementation
    delete[] ListMain;
}
