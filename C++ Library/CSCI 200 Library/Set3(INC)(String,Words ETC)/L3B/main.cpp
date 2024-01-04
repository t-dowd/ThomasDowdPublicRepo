/* CSCI 200: Assignment 3: L3B - Pointers
 *
 * Author: Thomas Dowd
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): N/A
 *
 * To increase fluency and comfortablilty in using pointers.
 */

#include <iostream>

using namespace std;

int main(){
    int iNum = 9; // use *piNum for the value, use piNum for the memory
    double dNum = 14.25;
    
    // Declaring Pointers

    int *pINum1;
    int *pINum2;
    double *pDNum;

    // assignign a memory value to the pointer

    pINum1 = &iNum;
    cout << "   Step 6\nThe two ways to get the memory location of any varible\n1. Using a Pointer: " << pINum1 <<"\n2. Priting the refrence of the variable directly: " << &iNum << endl;
    cout << "   Step 7\nThe value of iNum using a pointer is: " << *pINum1 << endl;

    // INCORECT CODE
    //  *dNum = pINum2;
    // The error code is an Invalid Type of Argument, this is because dNum is a double and pINum2 is an int.

    pDNum = &dNum;
    cout << "   Step 10\nThe memory location of dNum, using a pointer is: " << pDNum << "\n"  << "The value of dNum using a pointer is: " << *pDNum << endl;

    *pINum1 = 7;
    cout << "   Step 12\nThe value of iNum using a pointer is: "<< *pINum1 << endl;

    pINum2 = pINum1;
    cout << "   Step 15\nThe Memory location of pINum 2 is: " << pINum2 << "\npINum points to: "<< *pINum2 <<endl;

    *pINum2 = 12;

    cout << "   Step 17\nThe value of iNum three times:\n" << "Pointer pINum1 is pointing to iNum: " << *pINum1 << "\nPointer pINum2 is pointing to pINum2 and that is pointing to iNum: " << *pINum2 <<"\nThe value of iNum driectly is: "<< iNum << endl;
    return 1;
}