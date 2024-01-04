#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "Node.h"


class LinkedList{

    
    /**
     * @brief pointer to the head node of the list
     * 
     */
    Node* mpHead;
    // /**
    //  * @brief pointer to the tail node of the list
    //  * 
    //  */
    // Node* mpTail;
    /**
     * @brief stores the current number of nodes in the list
     * 
     */
    unsigned int mSize;
//  MEMBER FUNCTIONS
    
public:
    /**
     * @brief Construct a new LinkedList object
     * 
     */
    LinkedList();
    /**
     * @brief Construct a new Linked List object
     * 
     */
    LinkedList(Node*);
    /**
     * @brief Destroy the LinkedList object
     * 
     */
    ~LinkedList();
    /**
     * @brief Overloaded Version of Insert, leads to Overload Make node for value.
     * 
     * @param POS 
     * @param VALUE  b
     */
    Node* retHead();
    int retsize();
    void insert(const int POS, unsigned int VALUE); //Take out PLAYERNUM
    Node* mMakeNodeForValue(const int VALUE);
    
    // LinkedList LinkedList::merge(
    void linked_list_fullprint();
    int get(const int POS);
};

void mergesort(Node*&);
int sizefind(Node*);
Node* mergetogether(Node*& node1, Node*& node2);
void split(Node*&,Node*&,Node*&);

#endif