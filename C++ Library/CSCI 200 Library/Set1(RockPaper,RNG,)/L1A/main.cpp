/* CSCI 200: Lab 1A (Math Equation Solver): Making a program to solve semi-complex and common equations.
 *
 * Author: Thomas Dowd
 *
 * Making an equation solver for common and tedious equations, seen below are
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // For square roots and such
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.
const double GCONST = .0000000000667;
// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/

  // Average Acceleration Formula.
  // Initializing Variables
  double position_avgAcl = 0;
  double positionInitial_avgAcl = 0;
  double time_avgAcl = 0;
  double timeInitial_avgAcl = 0;
  double averageAcceleration = 0;

  //Getting input values for Average Acceleration Formula.
  cout << "Average Acceleration Formula\n\n";cout << "Position (x) Value: ";
  cin >> position_avgAcl;
  cout << "Position Initial (x0) Value: ";
  cin >> positionInitial_avgAcl;
  cout << "Time (t) Value: ";
  cin >> time_avgAcl;
  cout << "Time Initial (t0) Value: ";
  cin >> timeInitial_avgAcl;

  // Math Portion
  averageAcceleration = (position_avgAcl - positionInitial_avgAcl) / pow((time_avgAcl - timeInitial_avgAcl), 2);
  cout << "The Average Acceleration is: " << averageAcceleration << " Meters Per Second Squared\n";

  // Newton's Law of Universal Gravitational Attraction
  
  double mass1 = 0;
  double mass2 = 0;
  double radius = 0;
  double gravitationalOutput = 0;

  cout << "Newton's Law of Universal Gravitational Attraction\n\n";

  cout << "Value of Mass 1: ";
  cin >> mass1;
  cout << "Value of Mass 2: ";
  cin >> mass2;
  cout << "Value of Radius: ";
  cin >> radius;

  gravitationalOutput = GCONST * ((mass1 * mass2) / pow(radius,2));

  cout << "The Gravitational Attraction is Approximately: " << gravitationalOutput << " Newtons";


  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}