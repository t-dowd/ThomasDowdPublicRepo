/* CSCI 200: Lab 2B - Random Number Generator
 *
 * Author: Thomas Dowd
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     I attended Professor Scholten's office hours to learn about makefiles
 *
 *  This is a program created to generate random number(s) from a given range of two float viables that are given by the user.
 */

#include <iostream>     // 
#include <ctime>        // Gives us acess to time
#include <cstdlib>      //For random things rand()
using namespace std;    // namespace std;

// No constants

int main(){
    /******** INSERT YOUR CODE BELOW HERE ********/

srand(time(0));         //Initialize the RNG
string keepPlaying = "Y";
while (keepPlaying == "Y") { // Makes our game stop when it has to stop
    double minVal = 0; 
    cout << "Enter The Minimum Value: " << endl;
    cin >> minVal;
    double maxVal;
    cout << "Enter The Maximum Value: "<< endl;
    cin >> maxVal;
    double firstQuart = maxVal * .25;
    double secondQuart = maxVal * .5;
    double thirdQuart = maxVal * .75;
    double varOut = 0;

        
    do{ 
        // This do/while branch fixes and issue which somethimes the random number 
        //   generator would spit out answers that where slightly above or below the bounds. 
        varOut = double((rand() % int(maxVal))+double(minVal)) - (double)rand() / (double)RAND_MAX; // First part gives a whole number Seconds Part gets a decimal
    } while (varOut < minVal || varOut > maxVal); 
    
    cout << "The random number generated is: " << varOut << endl;
    if (varOut < firstQuart){
        cout << varOut << "is in the 1st Quartile\n";
    }
    else if (varOut > firstQuart && varOut < secondQuart){
        cout << varOut << " is in the 2nd Quartile\n";
    }
    else if(varOut > secondQuart && varOut < thirdQuart){
        cout << varOut << " is in the 3rd Quartile\n";
    }
    else {
        cout << varOut << "is in the 4th Quartile\n";
    }
    cout << "Would You like To Play Again?\nType Y/N: ";
    cin >> keepPlaying;
    }

    /******** INSERT YOUR CODE ABOVE HERE ********/
return 0;
}
