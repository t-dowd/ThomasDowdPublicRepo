#ifndef NODE_HPP
#define NODE_HPP


/**
 * @brief A single element of a linked list or can be implemented into any other another similar function
 * 
 */
template <class T>
struct Node {
    /**
     * @brief the value of this Node
     * 
     */
    T value;
    
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node<T> *pNext;
    
    /**
     * @brief pointer to the previous element of the linked list
     * 
     */
    Node<T> *pPrev;
};

#endif