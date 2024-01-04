/* CSCI 200: Assignment 2: A2 - Watch the Wumpus
 *
 * Author: Thomas Dowd
 * Resources Used: N/A
 *
 * Functions for the related Main.cpp Wumpusfunction.h. 
 * 
 * EDUT FILE
 */
#include <string>
#include <iostream>
#include <fstream>
#include "wumpus_functions.h"

using namespace std;

string enter_wumpus_file(){
    string wumpusFileName = " ";
    cout << "Enter wumpus file to read from: ";
    cin >> wumpusFileName;
    return wumpusFileName;
}

string enter_game_log_file(){
    string logFileName = " ";
    cout << "Enter the Log file to write to: ";
    cin >> logFileName;
    return logFileName;
}
bool open_files(std::ifstream& wumpusFileIn, std::ofstream& gameLogOut, const string WUMPUS_FILE_NAME, const string GAME_LOG_FILE_NAME){
    wumpusFileIn.open(WUMPUS_FILE_NAME);
    gameLogOut.open(GAME_LOG_FILE_NAME);
    if ((wumpusFileIn.is_open() == true)){
        // wumpusFileIn.close();
    }
    else {
        // wumpusFileIn.close();
        return false;
    }
    // gameLogOut.open(GAME_LOG_FILE_NAME);
    if (gameLogOut.is_open()){
        // gameLogOut.close();
    }
    else {
        // gameLogOut.close();
        return false;
    }
    return true;
}

void read_world_header(std::ifstream& wumpusFileIn,int &caveWidth, int &caveHeight){
    wumpusFileIn >> caveWidth;
    wumpusFileIn >> caveHeight;
}

bool read_object_header(std::ifstream& wumpusFileIn,int& wumpusX, int& wumpusY,int& heroX, int& heroY,int& pitX,int &pitY){
    
    for (int i = 0; i <= 2; i++){
        char temp1 = 'l';
        wumpusFileIn >> temp1;
        if (wumpusFileIn.fail()){
            // wumpusFileIn.close();
            return false;
        }
        if (temp1 == 'W'){
            wumpusFileIn >> wumpusX;
            wumpusFileIn >> wumpusY;
        }
        else if (temp1 == 'H'){
            wumpusFileIn >> heroX;
            wumpusFileIn >> heroY;
        }
        else if (temp1 == 'P'){
            wumpusFileIn >> pitX;
            wumpusFileIn >> pitY;
            // cout << temp1 << endl;
        }
        else{
            // cerr << "ERROR: Improper Object Naming";
            // wumpusFileIn.close();
            return false;
        }
    }
    // cout << wumpusX << " " << wumpusX << endl << heroX << " " << heroY << endl << pitX << " " << pitY;
    // wumpusFileIn.close();
    return true;
}

void read_number_moves(std::ifstream& wumpusFileIn, int &numMoves){
    wumpusFileIn >> numMoves;
    if (wumpusFileIn.fail()){
        cerr << "ERROR: something very wrong happened here: Read Number Moves";
        // wumpusFileIn.close();
        return;
    }
    return;
}

bool choose_player(){
    char playerChoice = 'E';
    bool askedYet = false;
    while(playerChoice != 'H' || playerChoice != 'W'){
        if (playerChoice == 'H' || playerChoice == 'W'){
            break;
        }
        if (askedYet == true){
            cout << "Invalid choice, please select again.";
        }
        cout << "Who do you wish to play as?\n        H - Hero\n        W - Wumpus\nCharacter: ";
        cin >> playerChoice;
        askedYet = true;
    }   
    if (playerChoice == 'H'){
        return true;
    }
    else{
        return false;
    }

}

void play_game(std::ifstream &wumpusFileIn, std::ofstream &gameLogOut,
              int &caveWidth, int &caveHeight,
              int &numMoves,
              int &wumpusX, int &wumpusY,
              int &heroX, int &heroY,
              int &pitX, int &pitY,
              const bool &PLAY_AS_HERO){
    int counter = 1;
    while (!wumpusFileIn.eof()){
        char tempchar = 'L';  // Clears the tempchars here
        char tempchar2 = ' '; // Clears the tempchars here
        char thrown = ' ';
        wumpusFileIn >> tempchar;
        if (tempchar == 'W' || tempchar == 'H'){
            // cout << endl << tempchar << " ";
            wumpusFileIn >> tempchar2;
            // cout << tempchar2 << endl;
            if (tempchar == 'H'){ // hero stuff here. 
                if (tempchar2 == 'N'){
                    if(heroY + 1 > caveHeight){
                        if (PLAY_AS_HERO == true){
                            gameLogOut << "You cannot move north\n";
                        }
                        else{
                            gameLogOut << "Hero cannot move north\n";
                        }
                        
                    }
                    else{
                        heroY += 1;
                    }
                }
                else if (tempchar2 == 'E'){
                    if(heroX + 1 > caveWidth){
                        if (PLAY_AS_HERO == true){
                            gameLogOut << "You cannot move East\n";
                        }
                        else{
                            gameLogOut << "Hero cannot move East\n";
                        }
                        // cout << "hero cannot move east\n";
                    }
                    else {
                        heroX += 1;
                    }
                }
                else if (tempchar2 == 'S'){
                     if(heroY - 1 < 1){
                        if (PLAY_AS_HERO == true){
                            gameLogOut << "You cannot move South\n";
                        }
                        else{
                            gameLogOut << "Hero cannot move South\n";
                        }
                        // cout << "hero cannot move south\n";
                    }
                    else{
                        heroY -= 1;
                    }
                }
                else if (tempchar2 == 'W'){
                     if(heroX - 1 < 1){
                        if (PLAY_AS_HERO == true){
                            gameLogOut << "You cannot move West\n";
                        }
                        else{
                            gameLogOut << "Hero cannot move West\n";
                        }
                        // cout << "hero cannot move west\n";
                    }
                    else{
                        heroX -= 1;
                    }
                }

                if (PLAY_AS_HERO == true){
                    gameLogOut << "You are at ("<< heroX << ", "<<heroY<<").\n";
                }
                else {
                    gameLogOut << "the Hero is at ("<< heroX << ", "<<heroY<<").\n";
                }
                
            }   
        if (tempchar == 'W'){
            if (tempchar2 == 'N'){
                if(wumpusY + 1 > caveHeight){
                    if (PLAY_AS_HERO == false){
                            gameLogOut << "You cannot move West\n";
                        }
                        else{
                            gameLogOut << "Wumpus cannot move West\n";
                        }
                    // cout << "Wumpus cannot move north\n";
                    }
                    else{
                    wumpusY += 1;
                    }
                }
                else if (tempchar2 == 'E'){
                    if(wumpusX + 1 > caveWidth){
                        if (PLAY_AS_HERO == false){
                            gameLogOut << "You cannot move East\n";
                        }
                        else{
                            gameLogOut << "Wumpus cannot move East\n";
                        }
                        //cout << "wumpus cannot move east\n";
                    }
                    else {
                        wumpusX += 1;
                    }
                }
                else if (tempchar2 == 'S'){
                    if(wumpusY  - 1 < 1){
                        if (PLAY_AS_HERO == false){
                            gameLogOut << "You cannot move South\n";
                        }
                        else{
                            gameLogOut << "Wumpus cannot move South\n";
                        }
                        // cout << "Wumpus cannot move south\n";
                    }
                    else{
                        wumpusY -= 1;
                    }
                }
                else if (tempchar2 == 'W'){
                     if(wumpusX - 1 < 1){
                        if (PLAY_AS_HERO == false){
                            gameLogOut << "You cannot move West\n";
                        }
                        else{
                            gameLogOut << "Wumpus cannot move West\n";
                        }
                        // cout << "Wumpus cannot move west\n";
                    }
                    else{
                        wumpusX -= 1;
                    }
                }
                if (PLAY_AS_HERO == false){
                    gameLogOut << "You are at ("<< wumpusX << ", "<<wumpusY<<").\n";
                }
                else {
                    gameLogOut << "the Wumpus is at ("<< wumpusX << ", "<<wumpusY<<").\n";
                }
            }
        }
    else{wumpusFileIn >> thrown;}
    if (wumpusX == pitX && wumpusY == pitY){
        if (PLAY_AS_HERO == true){
            gameLogOut << "The Wumpus has fallen in the pit.  You win!\n";
            return;
        }
        else{
            gameLogOut << "You have fallen in the pit.  You lose.\n";
            return;
        }
    }
    if (heroX == pitX && heroY == pitY){
        if (PLAY_AS_HERO == false){
            gameLogOut << "You have fallen in the pit.  You lose.\n";
            return;
        }
        else{
            gameLogOut << "The Hero has fallen in the pit.  You win!\n";
            return;
        }
    }
    if (heroX == wumpusX && heroY == wumpusY){
        if (PLAY_AS_HERO == true){
            gameLogOut << "You have killed the Wumpus.  You win!\n";
            return;
        }
        else{
            gameLogOut << "You have been killed by the Hero.  You lose.\n";
            return;
        }
    }
    if (counter == numMoves){
        if (PLAY_AS_HERO == true){
            gameLogOut << "The Wumpus has evaded you.  You lose.\n";
            return;
        }
        else {
            gameLogOut << "You have evaded the Hero.  You win!\n";
            return;
        }
    }
    counter++;
    }
    gameLogOut.close();
}
