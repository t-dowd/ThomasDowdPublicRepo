/* CSCI 200: Assignment 5: A5 - a-MAZE-ing
 *
 * Author: Thomas Dowd
 * Resources used: N/A
 *
 * Description:
 *  This program will solve any combination of mazes using BFS. The goal is 
 *  to determine if it is possible to move from the Start Space to the End Space.
 * 
 */

#include "MazeNode.h"
#include "MazeFunctions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string filestring = " ";        // Initalizing Variables
    filestring = enter_maze_file();
    int Height = -1, Width = -1;
    ifstream reader;
    if (open_files(reader,filestring,Height,Width) == true){ // Opens a file gives an ifstream object a file
        cout << "File '" << filestring << "' has been successfully opened\n" <<
            "Height: " << Height << "\n" <<
            " Width: " << Width << endl;
    }
    else{
        cout << "File Not Availiable, or something went wrong\nTry banging your head on the desk and trying again!" << endl;
    }
    int pick = -1;
    cout << "Press 1 for BFS, press 2 for DFS: "; cin >> pick;
    MazeNode** ListMain = FileToLit2D(Width,Height,reader); //  Grabs values from the Maze File and Puts it into a 2-D
                                                            // Array. The array are two Static arrays with values in the
                                                            // Free store. 
    fullprint(ListMain,Width,Height); // Prints out the whole function.
    int startCol = Width;
    int startRow = Height;
    findStart(ListMain,startCol,startRow); // Finds the S value.
    if (pick == 1){
        vector <MazeNode*> CheckHere; // makes a list of values that need to be checked.
        bfsFindWayOut(ListMain, CheckHere,startCol,startRow, Width, Height); // Main BFS function
        cout << "final Graph!" << endl; 
        fullprint(ListMain,Width,Height); // Function to print the full board.
    }
    else{
        bool stopit = false;                // A boolen used in FindWayOut as a redundancy to ensure the function unwinds
                                            // unwinds properly. 
        dfsWayOut(ListMain,startCol,startRow,stopit,Width,Height); // Main Recursive function
        cout << "~~ Final Maze ~~" <<endl;
        ListMain[startRow][startCol].value = 'S';
        if (stopit == false){
            cout << "Exit Unreachable" << endl;
        }
        fullprint(ListMain,Width,Height);
        reader.close();
    }
    return 0;
}