/* CSCI 200: Assignment 4: A4 - Wild Left-Center-Right Simulation
 *
 * Author: Thomas Dowd
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Recieved Help hours for L4B.
 *     NOTE: 
 *          Peer Programmed PREVIOUS Assignments L4A and L4B. 
 *          Therefore Many shared functions with AVA COURTNEY, Peer Programmed 
 *          L4A and L4B.
 *          
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#include "LeftRightCenterFunctions.h"   // Header file for Functions
#include "Node.h"                       // Header file for Linked List node

#include <iostream>                     // Input and Output
#include <exception>                    // 
#include <string>                       //

using namespace std;


int main(){
    int starttime = time(0);            //A variable for grabbing the current start time. Added as a last ditch attempt at Extra Credit
    srand(time(0));                     // Seeding Random
    // bool auto_run = false;      //initializing the Auto Run feature 
    bool reverse = false;   // Reverse boolean
    int skip = 0;           // Initalizes how many people to skip
    int potval = 0;         // The value of the center or "Pot"
    int currentturn = -2;   // Current turn, initalizes to -1 as a redundancy
    int totalturn = 0;      //
    int errorcnt = 0;       // Error counter, used for debugging
    LinkedList fullboard = printNewGameLoadingScreen(); // A one time activator and initalizer of number of players.
    try{
        while(fullboard.wincheck() == false){           // Checks if every player has zero chips.
            int e = (int)fullboard.size();              // Gets the size
            if(currentturn + 1 == e){   // makes sure the value is within range
                currentturn = 0;
            }
            else{
                currentturn++;
            }
            int i = fullboard.nextup(currentturn,reverse,skip); // Evaluates conditions such as reverse and skip and retuns a value of the current player 
            try{
                cout << "i = " << i << endl;
                Node* playerOnDeck = fullboard.playerGrabber(i);// Returns the Node* of the current player
                gameframe(i,playerOnDeck,reverse,skip,potval);  // MAIN GAME LOOP        
            }
            catch(...){
                    cout << "We have encountered an unexpected error :(" << endl;
                    fullboard.linked_list_fullprint();
                    errorcnt++;
                    
            }
            
            totalturn++;
        }
    }
    catch(...){
        cout << "Unexpected Wincheck Error" <<endl;
        fullboard.linked_list_fullprint();
        errorcnt++;
    }
    if(fullboard.wincheck() == true){
    Node* bigWinner = fullboard.playerGrabber(fullboard.get(fullboard.find(-1)));
    // fullboard.linked_list_fullprint();
    cout << "Player: " << bigWinner->playernumber << " is tonights WINNER"<<
        "\nWith total of: " << (bigWinner->value) + potval << 
        "\nTaking " << totalturn << " rounds to complete, and " << time(0) - starttime << 
        " seconds to complete the simulation\n" << 
        "With "<< errorcnt << " Errors\n"<< endl;
    }
    return 1;
}
