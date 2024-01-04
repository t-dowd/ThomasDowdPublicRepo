#include "MazeNode.h"
#include "MazeFunctions.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

std::string enter_maze_file(){
    std::string wumpusFileName = " ";
    std::cout << "Enter Maze (EXPLICITLY) file to read from: ";
    std::cin >> wumpusFileName;
    return wumpusFileName;
}

bool open_files(std::ifstream& wumpusFileIn, const std::string WUMPUS_FILE_NAME,int& width, int& height){
    wumpusFileIn.open(WUMPUS_FILE_NAME);
    if ((wumpusFileIn.is_open() == true)){
        wumpusFileIn >> width;
        wumpusFileIn >> height;
        return true;
    }
    else {
        // wumpusFileIn.close();
        return false;
    }
    // gameLogOut.open(GAME_LOG_FILE_NAME);
}
MazeNode* makeNodeForValue(std::ifstream& filein){
    MazeNode* tempMazeNode = new MazeNode;
    char tempChar = '+';
    
    filein >> tempChar;
    tempMazeNode->value = tempChar;
    // std::cout << tempChar;
    tempMazeNode->passed = false;
    return tempMazeNode;
}
MazeNode* makeNodeForValue(int x, int y,char chrtr){
    MazeNode* tempMazeNode = new MazeNode;
    tempMazeNode->value = chrtr;
    tempMazeNode->xVal = x;
    tempMazeNode->yVal = y;
    return tempMazeNode;

}
MazeNode** FileToLit2D(int const WIDTH, int const HEIGHT,std::ifstream& filein){
    MazeNode** List = new MazeNode*[HEIGHT]; // Has a HEIGHT of HEIGHT
    for (int i = 0; i < HEIGHT;i++){
        List[i] = new MazeNode[WIDTH];
    }
    for (int i = 0; i < HEIGHT; i++){
        for (int r = 0; r < WIDTH;r++){
            List[i][r] = *makeNodeForValue(filein);
        }// std::
    // std::cout<<std::endl;
    }

    return List;
}

void fullprint(MazeNode** ListFromMain,int Width, int Height){ // Just prints out the currnet game board
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j <Width; j++) {
    
            std::cout << ListFromMain[i][j].value;
        }
    std::cout << std::endl;
    }
}
void findStart(MazeNode** ListFromMain,int& Width, int& Height){
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j <Width; j++) {
            if (ListFromMain[i][j].value == 'S'){
                Height = i;
                Width= j;
                return;
            }
        }
    }
}
void dfsWayOut(MazeNode** ListFromMain,int X, int Y,bool& stopit,const int width, const int height){
    // Base Case
    if (stopit == true){
        return;
    }
    try{// To catch out of range functions
        // ** Is the same format for the following. **
        if (X + 1 > width){throw width;}
        else if ((ListFromMain[Y][X+1].value == '.'||ListFromMain[Y][X+1].value == 'E') && stopit != true){
            // If the character to the [DIRECTION] is a '.' then recurse, else move on. 
            if(ListFromMain[Y][X+1].value == 'E'){
        
                std::cout << "\nWAY OUT FOUND\n(" << X+1 << "," << Y << ")" << std::endl;
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                stopit = true;
                return;
            }
            else{
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                dfsWayOut(ListFromMain,X+1,Y,stopit,width,height);
            }
        }
    } catch(...){}
    try{
        if (Y+1 >= height){throw height;}
        else if ((ListFromMain[Y+1][X].value == '.'||ListFromMain[Y+1][X].value == 'E') && stopit != true){
            // If the character to the [DIRECTION] is a '.' then recurse, else move on. 
            if(ListFromMain[Y+1][X].value == 'E'){
        
                std::cout << "\nWAY OUT FOUND\n(" << X << "," << Y+1 << ")" << std::endl;
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                stopit = true;
                return;
            }
            else{
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                dfsWayOut(ListFromMain,X,Y+1,stopit,width,height);
            }
        }
    } catch(...){}
    try{
        if (X-1 < 0){throw width;}
        else if ((ListFromMain[Y][X-1].value == '.'|| ListFromMain[Y][X-1].value == 'E') && stopit != true){
            // If the character to the [DIRECTION] is a '.' then recurse, else move on. 
            if(ListFromMain[Y][X-1].value == 'E'){
        
                std::cout << "\nWAY OUT FOUND\n(" << X-1 << "," << Y << ")" << std::endl;
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                stopit = true;
                return;
            }
            else{
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                dfsWayOut(ListFromMain,X-1,Y,stopit,width,height);
            }
        }
    } catch(...){}
    try{
        if (Y-1 < 0){throw height;}
        else if ((ListFromMain[Y-1][X].value == '.' || ListFromMain[Y-1][X].value == 'E') && stopit != true){
            if(ListFromMain[Y-1][X].value == 'E'){
        
                std::cout << "\nWAY OUT FOUND\n(" << X << "," << Y-1 << ")" << std::endl;
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                stopit = true;
                return;
            }
            else{
                ListFromMain[Y][X].passed = true;
                ListFromMain[Y][X].value = '@';
                dfsWayOut(ListFromMain,X,Y-1,stopit,width,height);
            }
        }
    } catch(...){}
    if (ListFromMain[Y][X].value == 'E' && stopit == false){ // Redundancy for winchecking.

        std::cout << "\nWAY OUT FOUND\n(" << X << "," << Y << ")" << std::endl;
        stopit = true;
        return;
    }
    else{
        ListFromMain[Y][X].passed = true;
        ListFromMain[Y][X].value = '@';
        return;
    }
}
void bfsFindWayOut(MazeNode** ListFromMain, std::vector <MazeNode*> & Queue, int X, int Y,const int width, const int height){
    try{
        if (X + 1 > width){
            throw width;
            }
        else if (ListFromMain[Y][X+1].value == '.'||ListFromMain[Y][X+1].value == 'E'){
            if (ListFromMain[Y][X+1].value == 'E'){
                return;
            }
            MazeNode* tempnode1 = makeNodeForValue(X+1,Y,ListFromMain[Y][X+1].value);
            tempnode1->value = '@';
            Queue.push_back(tempnode1);
            // print(Queue);
        }
    } catch(...){}
    try{
        if (Y+1 >= height){throw height;}
        else if ((ListFromMain[Y+1][X].value == '.'||ListFromMain[Y+1][X].value == 'E')){
            if (ListFromMain[Y+1][X].value == 'E'){
                return;
            }
            MazeNode* tempnode1 = makeNodeForValue(X,Y+1,ListFromMain[Y+1][X].value);
            tempnode1->value = '@';
            Queue.push_back(tempnode1);
            // print(Queue);
        }
    } catch(...){}
    try{
        if (X-1 < 0){throw width;}
        else if ((ListFromMain[Y][X-1].value == '.'|| ListFromMain[Y][X-1].value == 'E')){
            if (ListFromMain[Y][X-1].value == 'E'){
                return;
            }
            MazeNode* tempnode1 = makeNodeForValue(X-1,Y,ListFromMain[Y][X-1].value);
            tempnode1->value = '@';
            Queue.push_back(tempnode1);
            // print(Queue);
        }
    } catch(...){}
    try{
        if (Y-1 < 0){throw height;}
        else if ((ListFromMain[Y-1][X].value == '.' || ListFromMain[Y-1][X].value == 'E')){
            if (ListFromMain[Y-1][X].value == 'E'){
                return;
            }
            MazeNode* tempnode1 = makeNodeForValue(X,Y-1,ListFromMain[Y-1][X].value);
            tempnode1->value = '@';
            Queue.push_back(tempnode1);
            // print(Queue);
        }
    } catch(...){}
    //===================================
while (Queue.size() != 0){
        // fullprint(ListFromMain,width,height);
        if (Queue.front()->value == 'E'){
            std::cout << "found way out!" << std::endl;
                return;
        }
        try{
            if (Queue.front()->xVal + 1 > width){
                throw width;
                }
            else if (ListFromMain[Queue.front()->yVal][Queue.front()->xVal+1].value == '.'||ListFromMain[Queue.front()->yVal][Queue.front()->xVal+1].value == 'E'){
                if(ListFromMain[Queue.front()->yVal][Queue.front()->xVal+1].value == 'E'){
                    ListFromMain[Queue.front()->yVal][Queue.front()->xVal].passed = true;
                    ListFromMain[Queue.front()->yVal][Queue.front()->xVal].value = '@';
                    std::cout << "found way out!" << std::endl;
                    return;
                }
                MazeNode* tempnode1 = makeNodeForValue(Queue.front()->xVal+1,Queue.front()->yVal,ListFromMain[Queue.front()->yVal][Queue.front()->xVal+1].value);
                tempnode1->value = '@';
                tempnode1->passed = true;
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal+1].passed = true;
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal+1].value = '@';
                Queue.push_back(tempnode1);
                // print(Queue);
            }
    } catch(...){}
        try{
            if (Queue.front()->yVal+1 >= height){throw height;}
            else if ((ListFromMain[Queue.front()->yVal+1][Queue.front()->xVal].value == '.'||ListFromMain[Queue.front()->yVal+1][Queue.front()->xVal].value == 'E')){
                if(ListFromMain[Queue.front()->yVal+1][Queue.front()->xVal].value == 'E'){
                    ListFromMain[Queue.front()->yVal][Queue.front()->xVal].passed = true;
                    ListFromMain[Queue.front()->yVal][Queue.front()->xVal].value = '@';
                    std::cout << "found way out!" << std::endl;
                    return;
                }
                MazeNode* tempnode1 = makeNodeForValue(Queue.front()->xVal,Queue.front()->yVal+1,ListFromMain[Queue.front()->yVal+1][Queue.front()->xVal].value);
                tempnode1->value = '@';
                tempnode1->passed = true;
                ListFromMain[Queue.front()->yVal+1][Queue.front()->xVal].passed = true;
                ListFromMain[Queue.front()->yVal+1][Queue.front()->xVal].value = '@';
                Queue.push_back(tempnode1);
                // print(Queue);
            }
    } catch(...){}
    try{
        if (Queue.front()->xVal-1 < 0){throw width;}
        else if ((ListFromMain[Queue.front()->yVal][Queue.front()->xVal-1].value == '.'|| ListFromMain[Queue.front()->yVal][Queue.front()->xVal-1].value == 'E')){
            if (ListFromMain[Queue.front()->yVal][Queue.front()->xVal-1].value == 'E'){
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal].passed = true;
                std::cout << "found way out!" << std::endl;
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal].value = '@';
                return;
            }
                MazeNode* tempnode1 = makeNodeForValue(Queue.front()->xVal-1,Queue.front()->yVal,ListFromMain[Queue.front()->yVal][Queue.front()->xVal-1].value);
                tempnode1->value = '@';
                tempnode1->passed = true;
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal-1].passed = true;
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal-1].value = '@';
                Queue.push_back(tempnode1);
                // print(Queue);
        }
    } catch(...){}
    try{
        if (Queue.front()->yVal-1 < 0){throw height;}
        else if ((ListFromMain[Queue.front()->yVal-1][Queue.front()->xVal].value == '.' || ListFromMain[Queue.front()->yVal-1][Queue.front()->xVal].value == 'E')){
            if (ListFromMain[Queue.front()->yVal-1][Queue.front()->xVal].value == 'E'){
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal].passed = true;
                std::cout << "found way out!" << std::endl;
                ListFromMain[Queue.front()->yVal][Queue.front()->xVal].value = '@';
                return;
            }
                MazeNode* tempnode1 = makeNodeForValue(Queue.front()->xVal,Queue.front()->yVal-1,ListFromMain[Queue.front()->yVal-1][Queue.front()->xVal].value);
                tempnode1->value = '@';
                ListFromMain[Queue.front()->yVal-1][Queue.front()->xVal].passed = true;
                ListFromMain[Queue.front()->yVal-1][Queue.front()->xVal].value = '@';
                Queue.push_back(tempnode1);
                // print(Queue);
            }
        } catch(...){}
        ListFromMain[Queue.front()->yVal][Queue.front()->xVal].passed = true;
        ListFromMain[Queue.front()->yVal][Queue.front()->xVal].value = '@';
        Queue.erase (Queue.begin());
        // std::cout << "\n" << std::endl;
    }
}