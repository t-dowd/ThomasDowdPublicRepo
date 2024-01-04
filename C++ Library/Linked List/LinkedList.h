#ifndef LList
#define LList
#include "Node.hpp"

template <class T>
class LinkedList{
    
private:
    /**
     * @brief The Front of the LinkedList
     * 
     */
    Node<T>* mpHead;

    /**
     * @brief The Last Node in Linked List
     * 
     */
    Node<T>* mpTail;
    /**
     * @brief Size of the linked list
     * 
     */
    unsigned int mSize;

    /**
     * @brief Created a Node for the value of @param
     * 
     * @param VALUE The Intended Value 
     * @return Node<T>* 
     */
    Node<T>* MakeNodeForValue(T VALUE);
public: 
/*~ ~ ~ Constructors ~ ~ ~*/ 
    /**
     * @brief Construct a new Linked List object
     * 
     */
    LinkedList();

    // See Copy Const...
    
    
/*~ ~ ~ Big Three ~ ~ ~*/ 
    /**
     * @brief Destroy the Linked List object.
     * 
     */
    ~LinkedList();
    /**
     * @brief Copy assignment operator
     * 
     * @param  
     * @return LinkedList& 
     */
    LinkedList& operator=(const LinkedList<T>&); // New Addition to this file, Normally this is omitted
    /**
     * @brief Copy Operator
     * 
     * @param OTHER linked list object to be constructed
     */
    LinkedList(const LinkedList<T>&);

/*~ ~ ~ Utility Functions ~ ~ ~*/ 
    /**
     * @brief Get the Tail object
     * 
     * @return Node<T>* 
     */
    Node<T>* get_tail();
    
    /**
     * @brief Get the head object
     * 
     * @return Node<T>* 
     */
    Node<T>* get_head();
    
    /**
     * @brief Returns value at given position.
     * 
     * @param POS Position of value to be returned
     * @return Value at position
     */
    T get(const int POS) const;
    
    /**
     * @brief 
     * 
     * @param POS 
     * @param VALUE 
     */
    void set(const int POS, const T VALUE);
    
    void append(const T value);

    /**
     * @brief 
     * 
     * @param POS 
     * @param VALUE 
     */
    void insert(const int POS, const T VALUE);
    
    /**
     * @brief Removes a node from the linked List
     * 
     * @param POS 
     */
    void remove(const int POS);
    
    /**
     * @brief 
     * 
     * @param TARGET 
     * @return int 
     */
    int find(const T TARGET);
    
    /**
     * @brief Finds max value in list.
     * 
     * @return Max out of list
     */
    T max();
    
    /**
     * @brief Finds min value in list.
     * 
     * @return Min out of list
     */
    T min();
    
    /**
     * @brief prints Full Linked list seperated by spaces
     * 
     */
    void fullprint();// Prints the Linked List
   
    /**
     * @brief Checks if the Linked List is Empty
     * 
     * @return true 
     * @return false 
     */
    bool isEmpty();

    int size();
};

#endif
