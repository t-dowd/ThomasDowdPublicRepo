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
    int find(int TARGET);
    /**
     * @brief Overloaded Version of Insert, leads to Overload Make node for value.
     * 
     * @param POS 
     * @param VALUE 
     * @param PLAYERNUM 
     */
    void insert(const int POS, const int VALUE,const int PLAYERNUM);
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

    Node* mMakeNodeForValue(const int VALUE,const int PLAYERNUM);
    /**
     * @brief Returns the Node* of the current player
     * 
     * @param player 
     * @return Node* 
     */
    Node* playerGrabber(int player);

    void linked_list_remove_node_at_back(Node*& pHead, Node*& pTail);
    void linked_list_remove_node_at_front(Node*& pHead, Node*& pTail); 

    // ========== // 
    /**
     * @brief Returns if the game was won or not
     * 
     * @return true 
     * @return false 
     */
    bool wincheck();
    /**
     * @brief Prints the list
     * 
     */
    void linked_list_fullprint();
    /**
     * @brief Makes it a circly linked list
     * 
     */
    void linked_list_to_circle();
    /**
     * @brief Gets the next value
     * 
     * @param currentNoNonsense 
     * @param reverse 
     * @param skip 
     * @return int 
     */
    int nextup(int currentNoNonsense,bool &reverse,int& skip);
    
};
/**
    * @brief Prints Current Game Board and other such things.
    * 
    * @param currentTurn The current turn, passed via reference. 
    */
void gameframe(int& currentTurn,Node*& pCurrentPlayer,bool & reverse, int& skip,int&potval);
/**
 * @brief For making the circly list on startup.
 * 
 * @return LinkedList 
 */
LinkedList printNewGameLoadingScreen();
/**
 * @brief Random Number Generator 
 * 
 * @param roll 
 */
void randomNumberGenerator(int& roll);


#endif