#include "linked_list_functions.h"

#include <exception>
#include <iostream>
#include <string>

// using namespace std;
Node* linked_list_make_node(const int VALUE) {
    Node* pNode = new Node;
    pNode->value = VALUE;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    return pNode;
}

void linked_list_add_value_to_front(Node*& pHead, Node*& pTail, const int VALUE) {
    // make a new node
    Node* pNewNode = linked_list_make_node(VALUE);
    if (pHead == nullptr){
        pHead = pNewNode;
        pTail = pNewNode;
        pNewNode->pNext = nullptr;
        pNewNode->pPrev = nullptr;
    }                    
    else{   
        Node* pHeadTemp = pHead; 
        pHead->pPrev = pNewNode;
        pNewNode->pNext = pHeadTemp;
        pHead = pNewNode;
    }   

}

int linked_list_get_size(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    int counter = 0;
    if (pCURR_NODE != nullptr){
        while (pCURR_NODE != nullptr){
            pCURR_NODE = pCURR_NODE->pNext;
            counter += 1;
        }
    }
    return counter;
}

int linked_list_get_value_at_position(const Node* const P_HEAD, const Node* const P_TAIL, const int POS) {
    const Node* pCURR_NODE = P_HEAD;
    if (pCURR_NODE == nullptr){
            throw std::out_of_range("OUT OF RANGE");
        }

    int counter = 0;
    bool outofrange = false;

    while (counter != POS && outofrange == false){
        
        if((pCURR_NODE->pNext == nullptr && counter != POS)|| (POS < 0 || POS <= counter) || (pCURR_NODE == nullptr)){
            // throw std::exception();
            throw std::out_of_range("OUT OF RANGE");
        }
        else{
            pCURR_NODE = pCURR_NODE->pNext;
            counter += 1;
        }
    
    }
    
   return pCURR_NODE->value;
}

void linked_list_set_value_at_position(Node* const P_head, Node* const P_tail, const int POS, const int VALUE) {

    int size = linked_list_get_size(P_head,P_tail);
    if (size == 0){
        return;
    }
    if (P_head == nullptr){
        return;
    }
    Node* pCurrNode = P_head;
    int counter = 0;
    // advance through list counting number of jumps and continue until position found or at end
    while (true){
        if ((pCurrNode->pNext == nullptr && counter != POS || counter > POS) || POS < 0){// First one means that nothing went wrong
            // throw std::out_of_range("Out of Range");  // Just is out of range. 
            return;
            }
        if (POS == counter){
            pCurrNode->value = VALUE; // Means everything passes therefore set the value.
            return; 
        }
        else{
            pCurrNode = pCurrNode->pNext;
            counter += 1;
        }
    }
}

void linked_list_remove_node_at_front(Node*& pHead, Node*& pTail) {
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
    Node* pNewNode = linked_list_make_node(0);
    pNewNode = pHead;
    
    // advance head

    // if we're now pointing at nothing, list only had one element
    if (pNewNode->pNext == nullptr){
        //  set tail to also be null so it points to nothing
        pTail == nullptr;
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

void linked_list_add_value_to_back(Node*& pHead, Node*& pTail, const int VALUE) {
    Node* pNewNode = linked_list_make_node(VALUE);
    pNewNode->pNext=nullptr;
    if (pHead == nullptr){
        pHead = pNewNode;
        pTail = pNewNode;
        pNewNode->pNext = nullptr;
        pNewNode->pPrev = nullptr;
    }
    // cout << pHead;
        // head and tail are the new node                       
    else{   
        pTail->pNext = pNewNode;
        pNewNode->pPrev = pTail;
        pTail = pNewNode;
    }
}

void linked_list_remove_node_at_back(Node*& pHead, Node*& pTail) {
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
    Node* pNewNode = linked_list_make_node(0);
    pNewNode = pTail;
    
    // advance head

    // if we're now pointing at nothing, list only had one element
    if (pNewNode->pPrev == nullptr){
        //  set tail to also be null so it points to nothing
        pHead == nullptr;
    }

    else{
    pTail= pTail->pPrev;
    }

    pTail->pNext = nullptr;
    
    delete pNewNode;
}

void linked_list_add_value_before_position(Node*& pHead, Node*& pTail, const int POS, const int VALUE) {
    // if position is before the beginning, add to front
    
    if(POS <= 0 || pHead == nullptr) {
        linked_list_add_value_to_front(pHead, pTail, VALUE);
        return;
    } 
    int size = linked_list_get_size(pHead,pTail);
        if (POS > size - 1){
        linked_list_add_value_to_back(pHead, pTail, VALUE);
        return;
    }
    else {
        Node* pCurrNode = pHead;
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        bool posfound = false;
        while(posfound == false){
            if (POS == counter){
                posfound = true; 
            }
            else{
                pCurrNode = pCurrNode->pNext;
                counter += 1;
            }
        }        
        // if we have gone past the end
        if(pCurrNode == nullptr) {
            // add to back
            linked_list_add_value_to_back(pHead, pTail, VALUE);
        } else {
            // otherwise add before target position
            Node* pNewNode = linked_list_make_node(VALUE);
            pCurrNode->pPrev->pNext=pNewNode;
            pCurrNode->pPrev=pNewNode;
            pNewNode->pNext=pCurrNode;
            pNewNode->pPrev=pCurrNode->pPrev;
        }
    }
}

int linked_list_min(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    
    // if list is empty
    if(pCURR_NODE == nullptr) {
        // throw exception
        throw std::out_of_range("list is empty");
    }

    // traverse list tracking min value present
    int minVal = pCURR_NODE->value;
    int size = linked_list_get_size(P_HEAD,P_TAIL);
    for (int i = 0; i < size; i++){
        try{
        int tempVal = linked_list_get_value_at_position(P_HEAD,P_TAIL,i);
        if (tempVal < minVal){
            minVal = tempVal;
        }
        }
        catch(...){
            return minVal;
        }
    }
    return minVal;
}

int linked_list_max(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    
    // if list is empty
    if(pCURR_NODE == nullptr) {
        // throw exception
        throw std::out_of_range("list is empty");
    }

    // traverse list tracking min value present
    int minVal = pCURR_NODE->value;
    int size = linked_list_get_size(P_HEAD,P_TAIL);
    for (int i = 0; i < size; i++){
        try{
        int tempVal = linked_list_get_value_at_position(P_HEAD,P_TAIL,i);
        if (tempVal > minVal){
            minVal = tempVal;
        }
        }
        catch(...){
            return minVal;
        }
    }
    return minVal;
}

int linked_list_find(const Node* const P_HEAD, const Node* const P_TAIL, const int TARGET) {
    const Node* pCURR_NODE = P_HEAD;
    int counter = 0;
    // advance through list until end and target is found or end reached
    if (P_HEAD == nullptr){
        return -1 ;
    }

    // advance through list counting number of jumps and continue until position found or at end
    while (true){ 
            if(pCURR_NODE == P_TAIL){
    
                return -1;
            }
            if ( pCURR_NODE->value == TARGET){
                // pCURR_NODE->value = VALUE;
                return counter;
            }
            else{
                pCURR_NODE = pCURR_NODE->pNext;
                counter += 1;
            }
        
        }
    return -1;
}

void linked_list_remove_node_at_position(Node*& pHead, Node*& pTail, const int POS) {
    // if list is empty
    if(pHead == nullptr) {
        // do nothing
        return;
    } 
        // if position is before start of list
    else if(POS <= 0) {
        // remove from front
        linked_list_remove_node_at_front(pHead, pTail);
        return;
    }
     
    else {
        int size = linked_list_get_size(pHead,pTail);
            if (POS >= size - 1){
                linked_list_remove_node_at_back(pHead,pTail);
                return;
            }
        Node* pCurrNode = pHead;
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        while(POS != counter){
            if ((pCurrNode == nullptr && counter != POS || counter > POS)){// First one means that nothing went wrong
                // throw std::out_of_range("Out of Range");  // Just is out of range. 
                linked_list_remove_node_at_back(pHead,pTail);
                return;
            }
            else{

                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        }
        // Node* pTemp = pCurrNode;
        pCurrNode->pPrev->pNext = pCurrNode->pNext;
        pCurrNode->pNext->pPrev = pCurrNode->pPrev;

    }    
}