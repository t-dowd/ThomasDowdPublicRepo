#include "LinkedListFunctions.h"
#include "Node.h"

#include <iostream>
#include <exception>
#include <string>
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
LinkedList::LinkedList(){
    mSize = 0;
    mpHead = nullptr;
    // mpTail = nullptr;
}
LinkedList::LinkedList(Node* abc){
    mSize = 0;//come back later???
    mpHead = abc;
    // mpTail = nullptr;
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
void LinkedList::insert(const int POS, const unsigned int VALUE){ //Take out PLAYERNUM
    Node* pNewNode = mMakeNodeForValue(VALUE);
    if(mpHead == nullptr) {
        mpHead = pNewNode;
        // mpTail = pNewNode;
        
        return;
    }
    else if(POS >= (int)mSize-1){
        Node* pCurrNode = mpHead;
        while (true)
        {
            if(pCurrNode->pNext == nullptr){
                pCurrNode->pNext = pNewNode;
                return;
            }
            pCurrNode = pCurrNode->pNext;
        }
        
    }
    else if( POS <= 0){
        pNewNode->pNext = mpHead;
        // mpHead->pPrev = pNewNode;

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
    }
}
Node* LinkedList::mMakeNodeForValue(const int VALUE){
    Node* Newnode = new Node;
            mSize++;
    Newnode->pNext = nullptr;
    Newnode->value = VALUE;
    return Newnode;
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
    split(top,leftsplit,rightsplit); //Splits the function down the middle
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