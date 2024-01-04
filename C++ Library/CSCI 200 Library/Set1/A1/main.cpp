/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Thomas Dowd
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     I attended Professor Scholten's office hours to learn about makefiles and how to use them
 * 
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream>     // For cin, cout,
#include <cmath>        // For square roots and such
using namespace std;    //

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main(){
    srand(time(0));             // Seeding random with the timestamp
    string playAgain = "Y";     // Play again condition
    bool aiActiveBool = false;  // Boolean for if AI is turned on or not 
    int wins = 0;               
    int loss = 0;               // Wins Loss' and Ties, will be incremented later.
    int tie = 0;
    string aiActiveVar = "";    // Takes the Y/N input and translates its Boolean Equivalent (aiActiveBool)

    cout << "\n\nWelcome To Rock Paper Scissors\n\nPress Y if you are playing against another human (multiplayer)\n\nPress N If you are lonely (singleplayer)\n> ";
    cin >> aiActiveVar;
    if (aiActiveVar == "Y"){    // Takes the Y/N input and translates its Boolean Equivalent (aiActiveBool)
        aiActiveBool = false;
    }
    else{
        aiActiveBool = true;
    }

    while(playAgain == "Y"){    // Main loop of code, revolves around if the player wishes to play again (see line 121)
        string playerOnePick = "";
        string playerTwoPick = "";
        cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)\n"<< endl;
        cout << "Player 1: ";
        cin >> playerOnePick;
        if (playerOnePick == "R"){// Converting Letters into their gampeplay equivilent for use in print statments and comparing for winchecking
                playerOnePick = "Rock";
            }
            else if (playerOnePick == "P"){
                playerOnePick = "Paper";
            }
            else{
                playerOnePick = "Scissors";
            }
            cout << "Player 1 choose " << playerOnePick << endl << endl;
        if (aiActiveBool == true){
            int theRandNumberVar = int(rand() % 3); // Uses the timestamp to create a number between 0-2
            if (theRandNumberVar == 0){
                playerTwoPick = "Rock";
            }
            else if (theRandNumberVar == 1){
                playerTwoPick = "Paper";
            }
            else{
                playerTwoPick = "Scissors";
            }
            cout << "Computer Choose " << playerTwoPick << endl << endl;
        }
        if(aiActiveBool == false){     // if its multiplayer then the code will execute here
            cout << "Player 2: ";
            cin >> playerTwoPick;
            if (playerTwoPick == "R"){ // Converting Letters into their gampeplay equivilent for use in print statments and comparing for winchecking
                playerTwoPick = "Rock";
            }
            else if (playerTwoPick == "P"){
                playerTwoPick = "Paper";
            }
            else{
                playerTwoPick = "Scissors";
            }
            cout << "Player 2 choose " << playerTwoPick << endl << endl;
        }
        // Below is the "if" branches that will execute regardless if the game is set to SinglePlayer or MultiPlayer 
        if (playerOnePick == playerTwoPick){
            cout << "DRAW!!\n";
            tie++; // Counts the ties
        }
        else if (playerOnePick == "Rock"){
            if (playerTwoPick == "Paper"){
                cout << "Paper Beats Rock\n";
                wins++; // Counts wins
                cout << "Player 2/Computer Wins\n";
            }
            else if(playerTwoPick == "Scissors"){
                cout << "Rock Beats Scissors\n";
                loss++;
                cout << "Player 1\n";
            }
        }
        else if (playerOnePick == "Paper"){
            if (playerTwoPick == "Rock"){
                cout << "Paper Beats Rock\n";
                wins++;
                cout << "Player 1 Wins\n";
            }
            else if(playerTwoPick == "Scissors"){
                cout << "Rock Beats Scissors\n";
                loss++;
                cout << "Player 2/Computer Wins\n";
                }
            }
        else if (playerOnePick == "Scissors"){
            if (playerTwoPick == "Rock"){
                cout << "Rock Beats Scissors\n";
                loss++;
                cout << "Player 2/Computer Wins\n";
            }
            else if(playerTwoPick == "Paper"){
                cout << "Scissors Beats Paper\n";
                wins++;
                cout << "Player 1 Wins\n";
                }
            }
    cout << "Do you want to play again?\nY/N > ";
    cin >> playAgain; // Condition to see if the game goes again
    }
cout << "\nThanks for playing!\nPlayer 1 won " << wins<< " time(s) and player two (or AI) won " << loss << " time(s) and tied "<< tie<< " time(s)\n" <<endl;
return 0; // signals the operating system that our program ended OK.
}