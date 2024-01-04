#include "LinkedListFunctions.h"
#include "Node.h"

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void LinkedList::linked_list_fullprint(){ // Prints the clined list
        const Node* pCURR_NODE = mpHead;
        cout << "#  Printing    #" << 
            "\n[";
        if (pCURR_NODE == nullptr){
                cout << "NULLPNTRHEAD";
                return;
        }
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        while(true){
            if (pCURR_NODE->pNext == nullptr || pCURR_NODE == nullptr){
                cout << " " << 
                    pCURR_NODE->value <<
                    "]"<<
                    endl;
                return;
            }
            else{
                cout << " " <<
                    pCURR_NODE->value; 
                pCURR_NODE = pCURR_NODE->pNext;
                counter += 1;
            }
        }
    }
void LinkedList::fixLinkedList(Node* reqNode){
    while (reqNode != nullptr){
        this->insert(mSize+3,reqNode->value);
        reqNode = reqNode->pNext;
    }
}
LinkedList::LinkedList(){
    mSize = 0;
    mpHead = nullptr;
    mpTail = nullptr;
}
LinkedList::LinkedList(Node* abc){
    mSize = 0;//come back later???
    mpHead = abc;
    mpTail = nullptr;
}
LinkedList::~LinkedList(){
    Node* pNewNode = mpHead;
    while (mpHead->pNext != nullptr){
        pNewNode = mpHead;
        mpHead = mpHead->pNext;
        delete pNewNode;
    }
    delete mpHead;
}
int LinkedList::retsize(){
    return this->mSize;
}
int LinkedList::get(const int POS){
    Node* pCurrNode = mpHead;
    if ((int)mSize <= 0 || mpHead == nullptr || (int)mSize <= (int)POS){
        // throw std::out_of_range("ERROR");

    }
    else{
        int counter = 0;
        while(true){
            if(counter == POS){
                return pCurrNode->value;
            }
            if((pCurrNode->pNext == nullptr && counter != POS)|| (POS < 0 || POS <= counter) || (pCurrNode == nullptr)){
            // throw std::exception();
                throw std::out_of_range("OUT OF RANGE");
            }
            else{
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        }
    }
    throw std::out_of_range("ERROR");
}
int LinkedList::get(const int POS,Node*& pCurrNode){
    pCurrNode = mpHead;
    if ((int)mSize <= 0 || mpHead == nullptr || (int)mSize <= (int)POS){
        // throw std::out_of_range("ERROR");

    }
    else{
        int counter = 0;
        while(true){
            if(counter == POS){
                // return pCurrNode->value;
                return pCurrNode->value;
            }
            if((pCurrNode->pNext == nullptr && counter != POS)|| (POS < 0 || POS <= counter) || (pCurrNode == nullptr)){
            // throw std::exception();
                throw std::out_of_range("OUT OF RANGE");
            }
            else{
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        }
    }
    throw std::out_of_range("ERROR");
}
void LinkedList::insert(const int POS, const unsigned int VALUE){ //Take out PLAYERNUM
    Node* pNewNode = mMakeNodeForValue(VALUE);
        if(mpHead == nullptr) {
            mpHead = pNewNode;
            mpTail = pNewNode;
            return;
        }
        else if(POS >= (int)mSize-1){
            mpTail->pNext = pNewNode;
            pNewNode->pPrev=mpTail;

            mpTail = pNewNode;
        }
        else if( POS <= 0){
            pNewNode->pNext = mpHead;
            mpHead->pPrev = pNewNode;

            mpHead = pNewNode;
        }
        else{
            Node* pCurrNode = mpHead;
            int counter = 0;
            while(counter < POS){
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        pNewNode->pNext=            pCurrNode;
        pNewNode->pPrev=            pCurrNode->pPrev;
        pCurrNode->pPrev->pNext=    pNewNode;
        pCurrNode->pPrev=           pNewNode;
        
        
        }
}
Node* LinkedList::mMakeNodeForValue(const int VALUE){
    Node* Newnode = new Node;
            mSize++;
    Newnode->pNext = nullptr;
    Newnode->value = VALUE;
    return Newnode;
}
int LinkedList::binarySearch(const int VALUE,int min, int max){ //* The main binary seach algorithm,
//                                                              //* Uses three intigers to mark the front, middle and tail
//                                                              //* of the divided list. Is Iterative. 
    Node* pCurrNode = mpHead; // Current node
    if (VALUE == mpHead->value){
        return 0; // If its the first element just return immediatly.
    }
    if (VALUE == mpTail->value){
        return (this->mSize)-1; // If its the last one return immediatly.
    }
    for (unsigned int i = 0; i < (this->mSize)/2; i++){
            pCurrNode = pCurrNode->pNext;       // Starts with the pointer in the center of list.
    }
    while (min <= max){ // If the min and max cross end, something went wrong. 
        int middleIndex = min + (max - min)/ 2;
        if (this->get(middleIndex,pCurrNode) == VALUE){
            return middleIndex;
        }
        if (this->get(middleIndex,pCurrNode) < VALUE){
            middleIndex++;
            min = middleIndex;
        }
        else{
            middleIndex--;
            max = middleIndex;
        }
    }
    return -1;
}

void split(Node*& topper,Node*& left,Node*& right){
    int expectedsize = sizefind(topper);
    right = topper;
    for (int i =0; i < expectedsize/2; i++){ // Finds the middle of the list and cuts the rest of it off. 
        left = right;                        // I chose this stratigy rather than the "fast, slow" version becase
        right = right->pNext;                // I felt it (whatever this method is called) has a better ability to bookeep and 
    }                                        // also includes less while loops and less chance for an exception.
    left->pNext = nullptr;
    left = topper;
}
void mergesort(Node*& top){
    if (top->pNext==nullptr||top == nullptr) {
        return; //All done recurring time to merge!
    }
    Node* rightsplit,*leftsplit;
    split(top,leftsplit,rightsplit);
    mergesort(leftsplit);
    mergesort(rightsplit);
    top = mergetogether(leftsplit,rightsplit);
}
Node* LinkedList::retHead(){
    return this->mpHead;
}
int sizefind(Node* head){
    int counter = 1;
    Node* pCurrentNode = head;
    while(pCurrentNode->pNext != nullptr){
        pCurrentNode = pCurrentNode->pNext;
        counter++;
    }
    return counter;
}
Node* mergetogether(Node*& node1, Node*& node2){ // Puts the lists back together in a sorted and comprehensible form.
    Node* pCurrNode;
	if(node1==NULL){ //This means the compared value is size 0, therefore returning the other value
        return node2;
    }
	else if(node2 ==NULL) { ////This means the compared value is size 0, therefore returning the other value
        return node1;
    }
	if(node1->value >= node2->value){ // If flipped will change from ascending to decending. 
		pCurrNode = node2;
		pCurrNode->pNext = mergetogether(node1,node2->pNext);

	}
	else{
		pCurrNode = node1;
		pCurrNode->pNext = mergetogether(node1->pNext,node2);
	}
	
	return pCurrNode;
}
void LinkedList::newValuesRandom(const int NUMVALS, const int MINVAL, const int MAXVAL){
    srand(time(0));
        // int totalvals = (int)(rand() %1000) + 1;
        for (int i = 0; i < NUMVALS; i++){
            this->insert(-1,(unsigned int)(rand() % MAXVAL) + MINVAL);
        }
}