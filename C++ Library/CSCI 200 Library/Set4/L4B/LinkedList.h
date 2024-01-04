#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class LinkedList{

    
    /**
     * @brief pointer to the head node of the list
     * 
     */
    Node* mpHead;
    /**
     * @brief pointer to the tail node of the list
     * 
     */
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
     * @brief Destroy the LinkedList object
     * 
     */
    ~LinkedList();
    /**
     * @brief returns the value of the element at given position. If position doesn't exist, throws a std::out_of_range exception
     * 
     * @param POS Position of element
     * @return int 
     */
    int get(const int POS);
    /**
     * @brief returns the position of the first occurrence of the target. If target doesn't exist, returns -1
     * 
     * @param TARGET 
     * @return int 
     */
    int find(const int TARGET);
    /**
     * @brief inserts a new node with the provided value BEFORE the provided position. That is, the newly created node will point to the current node at the provided position. If the provided position is out of range for the current list, then clamp the position to the head or tail of the list as appropriate
     * 
     * @param POS 
     * @param VALUE 
     */
    void insert(const int POS, const int VALUE);
    /**
     * @brief returns the max value within the list. If the list is empty, throws a std::out_of_range exception
     * 
     * @return int 
     */
    int max();
    /**
     * @brief returns the min value within the list. If the list is empty, throws a std::out_of_range exception
     * 
     * @return int 
     */
    int min();
    /**
     * @brief if the provided position exists in the list, removes and deallocates the associated node. If the provided position is out of range for the current list, then clamp the position to the head or tail of the list as appropriate. If the list is empty, then do nothing
     * 
     * @param POS 
     */
    void remove(const int POS);
    /**
     * @brief if the provided position exists in the list, sets the vale of the associated node. If the provided position is out of range for the current list, do nothing
     * 
     * @param POS 
     * @param VALUE 
     */
    void set(const int POS, const int VALUE);
    /**
     * @brief returns the current number of nodes within the list
     * 
     * @return unsigned int 
     */
    unsigned int size();
    /**
     * @brief creates a node with provided value and null previous & next pointers
     * 
     * @param VALUE 
     * @return Node* 
     */
    Node* mMakeNodeForValue(const int VALUE);

    void linked_list_remove_node_at_back(Node*& pHead, Node*& pTail);
    void linked_list_remove_node_at_front(Node*& pHead, Node*& pTail); 

};




#endif