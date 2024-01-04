#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "Node.h"

#include <string>

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
    Node* mpTail;
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
     * @brief Returns the head node
     * 
     * @return Node* 
     */
    Node* retHead();
    /**
     * @brief Returns the size
     * 
     * @return int 
     */
    int retsize();
    /**
     * @brief Inserts A node
     * 
     * @param POS 
     * @param VALUE 
     */
    void insert(const int POS, unsigned int VALUE); //Take out PLAYERNUM
    /**
     * @brief makes Node
     * 
     * @param VALUE 
     * @return Node* 
     */
    Node* mMakeNodeForValue(const int VALUE);
    /**
     * @brief Prints out LLL
     * 
     */
    void linked_list_fullprint();
    /**
     * @brief 
     * 
     * @param POS 
     * @return int 
     */
    int get(const int POS);
    /**
     * @brief 
     * 
     * @param POS 
     * @param pCurrNode 
     * @return int 
     */
    int get(const int POS,Node*& pCurrNode);
    /**
     * @brief 
     * 
     * @param NUMVALS 
     * @param MINVAL 
     * @param MAXVAL 
     */
    void newValuesRandom(const int NUMVALS, const int MINVAL, const int MAXVAL);
    /**
     * @brief Fixes the havoc on linked lists caused by sorting.
     * 
     * @param Node* its a node 
     */
    void fixLinkedList(Node* unchangedhead);
    /**
     * @brief Binary Search
     * 
     * @param VALUE 
     * @param min 
     * @param max 
     * @return int 
     */
    int binarySearch(const int VALUE,int min, int max);
};
/**
 * @brief 
 * 
 */
void mergesort(Node*&);
/**
 * @brief 
 * 
 * @return int 
 */
int sizefind(Node*);
/**
 * @brief 
 * 
 * @param node1 
 * @param node2 
 * @return Node* 
 */
Node* mergetogether(Node*& node1, Node*& node2);
/**
 * @brief 
 * 
 */
void split(Node*&,Node*&,Node*&);


#endif