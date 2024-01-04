#ifndef Array_HPP
#define Array_HPP
#include <exception>
#include <iostream>
#include "Node.hpp"
#include "List.hpp"
#include <list>
template <class T>
struct NodeArray {
    T value;
};
template <class T>
class Array : public List<T>{
    private:
    unsigned int mSize;
    NodeArray<T>* ImbededArray[];
    // NodeArray<T>* ImbededCOPYArray[];
    // void mMakeNodeForValue(const T VALUE);
    public:
    Array();
    ~Array();
    Array(const T Value);
    // Array<T>& Array<T>::operator=(const Array<T>& COPY);
    T get(const int POS) const;
    void set(const int POS, const T VALUE);
    void insert(const int POS, const T VALUE);
    void remove(const int POS);
    void fullprint();
    int find(const T TARGET);
    Array& operator=(const Array<T>& OTHER);
};
// Array<T>& Array<T>::operator=(const Array<T>& OTHER)
template<class T>
Array<T>::Array(){
    mSize = 0;
}
template<class T>
Array<T>::~Array(){
}
template<class T>
Array<T>::Array(const T Value){

}
template<class T>
T Array<T>::get(const int POS)const{
    for (int i = 0; i < mSize; i++){
        if (i == POS){
            return i;
        }
    }
    return -1;
}
template<class T>
void Array<T>::set(const int POS, const T VALUE){
    for (int i = 0; i < mSize; i++){
        if (i == POS){
            return;
        }
    }
}
template<class T>
void Array<T>::insert(const int POS, const T VALUE){
    NodeArray <int>* tempnode = new NodeArray<int>;
    tempnode->value = VALUE;
    if (mSize == 0){
        ImbededArray[0] = tempnode;
        mSize++;
    }
    else{
        // Loop through list and copy all instancies into a a seperate Array
        for (int i = 0; i < POS; i++){
            // Copy
            mSize++;
            //Delete 
        }
    }
}
template<class T>
void Array<T>::remove(const int POS){
    for (int i = 0; i < POS; i++){
        if (i == POS && i < mSize){
            mSize--;
        }
    }
}
template<class T>
int Array<T>::find(const T TARGET){
    for (int i = 0; i < mSize; i++){
        if (i == TARGET){
            return i;
        }
    }
}
template<class T>
void Array<T>::fullprint(){

}
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& OTHER){
    //delete everything in list
    while(mSize > 0){
        remove(0);
    }

    //iterate through other linked list and assign
    NodeArray<T>* pOTHERCurr = OTHER.mpHead;
    int counter = 0;
    while(pOTHERCurr != nullptr){
        insert(counter, pOTHERCurr->value);
        pOTHERCurr = pOTHERCurr->pNext;
        counter += 1;
    }
    return *this;
}

#endif