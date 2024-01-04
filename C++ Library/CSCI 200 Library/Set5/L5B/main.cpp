/* CSCI 200: Lab5B - Needle in the Haystack
 *
 * Author: Thomas Dowd
 * Resources used: N/A
 *
 * Description:
 *  Function Uses recusive merge sort to sort a given list
 * 
 */
#include "LinkedListFunctions.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    LinkedList unsortedlist1;

    // The following commented out lines provide a randomized solution for a list of random size. 

    // void linked_list_fullprint();
    // if (true){
    //     srand(time(0));
    //     int totalvals = 100;
    //     for (int i = 0; i < totalvals; i++){
    //         unsortedlist1.insert(-1,(unsigned int)(rand() % 50) +1);
    //     }
    // }

    // Adding given ints to a list. 
    unsortedlist1.insert(-1,6);
    unsortedlist1.insert(-1,2);
    unsortedlist1.insert(-1,7);
    unsortedlist1.insert(-1,9);
    unsortedlist1.insert(-1,5);
    unsortedlist1.insert(-1,1);
    unsortedlist1.insert(-1,8);
    unsortedlist1.insert(-1,3);
    unsortedlist1.insert(-1,4);   
    //LinkedList unsortedlist2(unsortedlist1.retHead());
    cout << "Pre Sort" << endl;
    unsortedlist1.linked_list_fullprint();
    Node* editablell = unsortedlist1.retHead();
    mergesort(editablell);
    cout << "Post Sort" << endl;
    while (editablell != NULL) // Priting it 
    {
        cout << editablell->value << " ";
        editablell = editablell->pNext;
    }
    return 0;
}