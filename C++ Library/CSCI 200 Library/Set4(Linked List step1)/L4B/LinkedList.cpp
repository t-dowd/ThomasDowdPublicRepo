#include "LinkedList.h"
#include "Node.h"

#include<exception>
#include<string>
#include<iostream>

LinkedList::LinkedList(){
    mSize = 0;
    mpHead = nullptr;
    mpTail = nullptr;
}
LinkedList::~LinkedList(){
    // size zero
}

void LinkedList::linked_list_remove_node_at_front(Node*& pHead, Node*& pTail) { // MIGHT NOT NEED THIS HERE
    // if list is empty - do nothing
    if(pHead == nullptr) {
        // cout << "HANG ON";
        return;
    }                
    if(pHead->pNext == nullptr){
        // delete pHead;
        // If broken maybe delete pTail?
        pHead = nullptr;
        pTail = nullptr;
        return;
    }
    // store pointer to current head
    Node* pNewNode = pHead;
    
    // advance head

    // if we're now pointing at nothing, list only had one element
    if (pNewNode->pNext == nullptr){
        //  set tail to also be null so it points to nothing
        pTail = nullptr;
    }
    // otherwise, list still has elements
    else{
    pHead = pHead->pNext;
    }
        // set back pointer to be null
    pHead->pPrev = nullptr;
    
    delete pNewNode;
    // delete former head
    
}

void LinkedList::linked_list_remove_node_at_back(Node*& pHead, Node*& pTail) { // MIGHT NOT NEED THIS HERE EITHER
    if(pTail == nullptr) {
        // cout << "HANG ON";
        return;
    }                
    if(pTail->pPrev == nullptr){
        // delete pHead;
        // If broken maybe delete pTail?
        pHead = nullptr;
        pTail = nullptr;
        return;
    }
    // store pointer to current head
    Node* pNewNode = pTail;
    
    // advance head

    // if we're now pointing at nothing, list only had one element
    if (pNewNode->pPrev == nullptr){
        //  set tail to also be null so it points to nothing
        pHead = nullptr;
    }

    else{
    pTail= pTail->pPrev;
    }

    pTail->pNext = nullptr;
    
    delete pNewNode;
}

int LinkedList::get(const int POS){
    Node* pCurrNode = mpHead;
    if((mSize == 1 && mpTail != mpHead)){
        mpTail = mpHead;
        mpTail->pNext = nullptr;
        mpTail->pPrev = nullptr;
    }
    if (mSize <= 0 || mpHead == nullptr || (int) mSize <= POS){
        throw std::out_of_range("ERROR");
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
int LinkedList::find(const int TARGET){
    Node* pCurrNode = mpHead;
    for (unsigned int i = 0; i < mSize; i++){
        if (pCurrNode->value == TARGET){
            return i;
        }
        else{
            pCurrNode = pCurrNode->pNext;
        }
    }
    return -1;
}

void LinkedList::insert(const int POS, const int VALUE){
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


int LinkedList::min(){
    if (mSize == 0){
        throw std::out_of_range("ERROR");
    }
    Node* pCURR_NODE = mpHead;
    int maxVal = pCURR_NODE->value;
    
    for(unsigned int i = 0; i < mSize;i++){
        try{
            int tempVal = LinkedList::get(i);
            if (tempVal < maxVal){
                maxVal = tempVal;
            }
        }
        catch(...){
            return maxVal;
        }
    }
    return maxVal;
}
int LinkedList::max(){
    if (mSize == 0){
        throw std::out_of_range("ERROR");
    }
    Node* pCURR_NODE = mpHead;
    int maxVal = pCURR_NODE->value;
    
    for(unsigned int i = 0; i < mSize;i++){
        try{
            int tempVal = LinkedList::get(i);
            if (tempVal > maxVal){
                maxVal = tempVal;
            }
        }
        catch(...){
            return maxVal;
        }
    }
    return maxVal;
}

void LinkedList::remove(const int POS){
    if(mpHead == nullptr) {
        // do nothing
        return;
    } 
        // if position is before start of list
    else if(POS <= 0) {
        // remove from front
        //linked_list_remove_node_at_front(mpHead, mpTail);
        if(mpHead == nullptr) {
        // do nothing
        return;
        } 
        mpHead = mpHead->pNext;
        if(mpHead == nullptr){
            mpTail = nullptr;
        }
        else{
            mpHead->pPrev = nullptr;
        }
        mSize--;
        return;
    }
    else if (POS >= (int)mSize - 1){
            if(mpTail == nullptr) {
                // mpTail->pPrev->pNext = nullptr;
            return;
        }                
        if(mpTail->pPrev == nullptr){
            // delete pHead;
            // If broken maybe delete pTail?
            mpHead = nullptr;
            mpTail = nullptr;
            mSize--;
            return;
        }
        // store pointer to current head
        Node* pNewNode = mpTail;
        
        // advance head

        // if we're now pointing at nothing, list only had one element
        if (pNewNode->pPrev == nullptr){
            //  set tail to also be null so it points to nothing
            mpHead = nullptr;
            mpTail = nullptr;
            return;
        }

        mpTail->pPrev->pNext = nullptr;
        mSize--;
        delete pNewNode;
    }
     
    else {
        Node* pCurrNode = mpHead;
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        while(POS > counter && pCurrNode != nullptr){
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        if(pCurrNode == mpTail || pCurrNode == nullptr){
            if(mpTail == nullptr){
                return;
            }
            Node* pTemp = mpTail;
            mpTail = pTemp->pPrev;
            if (mpTail == nullptr){
                mpHead = nullptr;
                return;
            }
            else{
                mpTail->pNext = nullptr;
            }
            delete pTemp;
            mSize--;
        }
        else{
        pCurrNode->pPrev->pNext = pCurrNode->pNext;
        pCurrNode->pNext->pPrev = pCurrNode->pPrev;
        mSize--;
        }
    }
}

    
void LinkedList::set(const int POS, const int VALUE){
    Node* pCurrNode = mpHead;
    for (int i = 0; i < (int)mSize; i++){
        if((pCurrNode->pNext == nullptr && i != POS)){
            return;
        }
        if(i == POS){
            pCurrNode->value = VALUE;
            return;
        }
        else{
            pCurrNode = pCurrNode->pNext;
        }
    }
}
   
unsigned int LinkedList::size(){
    return mSize;
}
    
Node* LinkedList::mMakeNodeForValue(const int VALUE){
    Node* Newnode = new Node;
            mSize++;
    Newnode->pNext = nullptr;
    Newnode->pPrev = nullptr;
    Newnode->value = VALUE;
    return Newnode;
}