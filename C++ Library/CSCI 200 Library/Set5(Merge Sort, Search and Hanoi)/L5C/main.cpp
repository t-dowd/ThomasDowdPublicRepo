/* CSCI 200: Lab5B - Needle in the Haystack
 *
 * Author: Thomas Dowd
 * Resources used: N/A
 *
 * Description:
 *  Function Uses recusive merge sort to sort a given list then search it via Binary Search
 * 
 */


#include "LinkedListFunctions.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
    LinkedList unsortedlist1;
    LinkedList sortedLinkedList;
    int numberofints =0; int minval = 0; int maxval = 0;
    cout << "number of ints: "; cin >> numberofints; cout << "\nMin: "; cin >> minval; cout << "\nMax: "; cin >> maxval; cout << endl;
    unsortedlist1.newValuesRandom(numberofints * 10,minval,maxval);
    unsortedlist1.linked_list_fullprint();
    Node* editablell = new Node;
    editablell = unsortedlist1.retHead();
    mergesort(editablell);
    Node* headListUnchanged = editablell;
    sortedLinkedList.fixLinkedList(headListUnchanged);
    unsortedlist1.~LinkedList();
    editablell = headListUnchanged;
    sortedLinkedList.linked_list_fullprint();
    int timessearch = 1;
    cout << "How many intigers do you need to search: " << endl;
    cin >> timessearch;
    int search;
    for (int i = 0; i < timessearch; i++){
        cout << "What number do you want to find: " << endl; cin >> search;
        int x = sortedLinkedList.binarySearch(search,0,sortedLinkedList.retsize());
        if (x == -1){
            cout << "No Value Found" <<  endl;
        }
        else{
            cout << "Value Found at Index: " << x << endl;
        }
    }
    return 0;
}