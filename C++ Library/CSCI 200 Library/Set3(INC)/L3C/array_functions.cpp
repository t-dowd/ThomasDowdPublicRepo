/* CSCI 200: Assignment 3: L3C - Array Test Suite
 *
 * Author: Thomas Dowd
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): Office Hours used.
 *
 * This is a progrma used in tandem with Array_Functions.h and
 * makefile. 
 */


#include "array_functions.h"

#include<stdexcept>     //Was Reccomeded to add this after TA office Hours. 
using namespace std;

void array_allocate(int*& pArray, const int INIT_SIZE){ //Allocates an array.
    pArray = new int[INIT_SIZE];
    for (int i = 0; i < INIT_SIZE; i++){
        pArray[i]= 0;
    }
}

int array_get_element_at(const int* const P_ARRAY, const int SIZE, const int POS){
    
    if (POS < 0 || POS > SIZE - 1 || P_ARRAY == nullptr)
    {
        throw std::out_of_range("Out of Range");
    }

    return P_ARRAY[POS];
    
    }  


void array_set_element_at(int* P_array,const int SIZE, const int POS, const int VALUE){
    if(POS > SIZE - 1 || POS < 0 || P_array == nullptr){
        return;
    }
    P_array[POS] = VALUE;
    return;
}

void array_deallocate(int*& pArrayK, int& size){
    delete[] pArrayK;
    pArrayK = nullptr;
    size = 0;
}

void array_insert_at_position(int*& pArray, int &size, const int POS, const int VALUE){
    int* pTemp = new int[size+1]; //Slightly larger array
    if(POS >= size){
        for (int i =0; i < size;  i ++){
            pTemp[i] = pArray[i];
        }
    pTemp[size] = VALUE;
    }
    else if(POS <= 0){
        pTemp[0] = VALUE;
        for (int i =0; i < size;  i ++){
            pTemp[i+1] = pArray[i];
        }
    }
    else{
        bool PastValue = false;
        for (int i =0; i < size+1;  i ++){
            if (i == POS){
                pTemp[i] = VALUE;
                PastValue = true;
            }
            else if(PastValue == false){
                pTemp[i] = pArray[i];
            }
            else if(PastValue == true){
                pTemp[i] = pArray[i-1];
            }
        }
    }
    delete[] pArray;
    pArray = pTemp;
    pTemp = nullptr;
    size += 1;
} 


int array_min(const int* P_ARRAY, const int SIZE){
    if(P_ARRAY == nullptr || SIZE == 0){
        throw std::exception();
    }
    int tempmin = P_ARRAY[0];
        for (int i = 0; i < SIZE; i++){
            if (P_ARRAY[i] < tempmin){
                tempmin = P_ARRAY[i];
            }
        }
        // throw exception();
    return tempmin;
}

int array_max(const int* P_ARRAY, const int SIZE){
    if(P_ARRAY == nullptr || SIZE == 0){
        throw std::exception();
    }
    int tempmin = P_ARRAY[0];
        for (int i = 0; i < SIZE; i++){
            if (P_ARRAY[i] > tempmin){
                tempmin = P_ARRAY[i];
            }
        }

    return tempmin;
}

int array_find(const int* P_AARY, const int SIZE, const int TARGET){
    int varret = -1; // ||<< SOMETHING IS BROKEN HERE >> ||
    for (int i =0; i < SIZE; i++){
        if (P_AARY[i] == TARGET){
            varret = i;
            break;
        }
    }   
    return varret;
}

void array_remove_from_position(int*& pArray,int& size, const int POS){
    if (pArray == nullptr || size <= 0){
        // do nothing and break.
    }
    else if(POS <= 0){
        int* pTemp = new int[size-1];
        for (int i =1; i < size; i++){
            pTemp[i-1] = pArray[i];
        }
        delete[] pArray;
        pArray = pTemp;
        pTemp = nullptr;
        size--;
    }
    else if(POS >= size-1){
        int* pTemp = new int[size-1];
        for (int i =0; i < size-1; i++){
            pTemp[i] = pArray[i];
        }
        delete[] pArray;
        pArray = pTemp;
        pTemp = nullptr;
        size--;
    }
    else{
        int* pTemp = new int[size-1];
            for(int i=0; i < POS; i++){
                pTemp[i] = pArray[i];
            }
            for (int i = POS; i < size; i++){
                pTemp[i] = pArray[i+1];
            }
        delete[] pArray;
        pArray = pTemp;
        pTemp = nullptr;
        size--;
    } 
    
}