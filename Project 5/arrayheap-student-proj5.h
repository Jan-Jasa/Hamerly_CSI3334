/**
 * Project 5: Real-Time Batch Operating System Simulator
 * File: arrayheap-student-proj5.h
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: November 10, 2023
 * version: 1.6
 *
 * This file contains the constructor, copy constructor,
 * destructor for the ArrayHeap class. All the functions
 * for ArrayHeap are included as well:
 * operator=
 * insert()
 * removeMinItem()
 * getMinItem()
 * getNumItems()
 * doubleCapacity()
 * bubbleUp()
 * bubbleDown()
 *
 */

#ifndef PROJECT_5_ARRAYHEAP_STUDENT_PROJ5_H
#define PROJECT_5_ARRAYHEAP_STUDENT_PROJ5_H


#include "arrayheap-prof-proj5.h"
#include <algorithm>
#include <cmath>

using namespace std;


/**
 * ArrayHeap()
 *
 * This function is the constructor for the ArrayHeap class.
 * It will initialize the capacity as 5, and set numItems to 0.
 * Data and heapAndFreeStack is initialized with size capacity,
 * and heapAndFreeStack stores the indexes of data.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <typename T>
ArrayHeap<T>::ArrayHeap(){
    this->numItems = 0;
    this->capacity = 5;
    this->data = new T[this->capacity];
    this->heapAndFreeStack = new int[this->capacity];

    for(int i=0; i<this->capacity; ++i){
        this->heapAndFreeStack[i] = i;
    }
}

/**
 * ArrayHeap(Copy)
 *
 * This function is the copy constructor for the ArrayHeap class.
 * It will copy the variables and parameters of ArrayHeap<T> h.
 * "This" will become a deep copy of h.
 *
 * Parameters:
 *  h: The ArrayHeap of type T that is copied.
 *
 * Return Value: N/A
 */
template <typename T>
ArrayHeap<T>::ArrayHeap(ArrayHeap<T> const &h){
    this->numItems = h.numItems;
    this->capacity = h.capacity;
    this->data = new T[this->capacity];
    this->heapAndFreeStack = new int[this->capacity];

    for(int i=0; i<this->capacity; ++i){
        this->heapAndFreeStack[i] = h.heapAndFreeStack[i];
        this->data[i] = h.data[i];
    }
}

/**
 * ~ArrayHeap()
 *
 * This function is the destructor for the ArrayHeap class.
 * It will delete data and the heapAndFreeStack, setting them
 * to null afterwards and setting capacity & numItems to 0.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <typename T>
ArrayHeap<T>::~ArrayHeap(){
    delete [] this->data;
    delete [] this->heapAndFreeStack;
    this->data = NULL;
    this->heapAndFreeStack = NULL;
    this->capacity=0;
    this->numItems=0;
}

/**
 * getMinItem()
 *
 * This function returns the min item of the heap.
 * As the first element of the heapAndFreeStack holds
 * the min index of data, this will be returned.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: The minimum value in data, of type T.
 */
template <typename T>
T const &ArrayHeap<T>::getMinItem() const{
    return this->data[this->heapAndFreeStack[0]];
}

/**
 * getNumItems()
 *
 * This function returns the number of items
 * that data/the heap currently holds.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: Number of (used) items within ArrayHeap.
 */
template <typename T>
int ArrayHeap<T>::getNumItems() const{
    return this->numItems;
}

/**
 * bubbleUp()
 *
 * This function bubbles the given ndx (for data)
 * up the heap, until it is in the correct position.
 * It's parent must be less than the element,
 * and both children must be greater. If ndx
 * or parent is not valid, return.
 *
 * Parameters:
 *  ndx: heapAndFreeStack element that must be
 *       bubbled up the heap.
 *
 * Return Value: N/A
 */
template <typename T>
void ArrayHeap<T>::bubbleUp(int ndx){
    int parent = floor((ndx-1)/2);

    //if not valid
    if(ndx<=0 || parent<0){
        return;
    }


    if(this->data[this->heapAndFreeStack[ndx]] < this->data[this->heapAndFreeStack[parent]]){
        swap(this->heapAndFreeStack[ndx],this->heapAndFreeStack[parent]);
        this->bubbleUp(parent);
    }
}

/**
 * bubbleDown()
 *
 * This function bubbles the given ndx (for data)
 * down the heap, until it is in the correct position.
 * It's child is greater than the value within ndx,
 * the two will swap within heap. If the ndx or
 * child1 doesn't exist, return.
 *
 * Parameters:
 *  ndx: heapAndFreeStack element that must be
 *       bubbled down the heap.
 *
 * Return Value: N/A
 */
template <typename T>
void ArrayHeap<T>::bubbleDown(int ndx){
    int child1 = 2*ndx+1;
    int child2 = 2*ndx+2;
    int least = child1;

    //children don't exist, don't edit heap.
    if(child1>=this->numItems){
        return;
    }

    //if right child is smaller number, switch "least" variable
    if(child2 < this->numItems){
        if(this->data[this->heapAndFreeStack[child2]] < this->data[this->heapAndFreeStack[child1]]){
            least = child2;
        }
    }

    //if parent is greater than child, swap
    if(this->data[this->heapAndFreeStack[least]] < this->data[this->heapAndFreeStack[ndx]]){
        swap(this->heapAndFreeStack[ndx],this->heapAndFreeStack[least]);
        this->bubbleDown(least);
    }
}

/**
 * insert()
 *
 * This function will insert the item of
 * type T into the end of the heapAndFreeStack,
 * and will call bubble up afterwards to place it
 * in the correct location in the heap.
 *
 * Parameters:
 *  item: Item of type T that is being inserted
 *        into the heap.
 *
 * Return Value: N/A
 */
template <typename T>
void ArrayHeap<T>::insert(T const &item){
    if(this->numItems == this->capacity){
        this->doubleCapacity();
    }

    this->data[this->heapAndFreeStack[numItems]] = item;
    this->numItems++;
    this->bubbleUp(this->numItems-1);
}

/**
 * doubleCapacity()
 *
 * This function will double the capacity of both
 * data and heapAndFreeStack. It will initialize
 * temp holders for each array, and copy the values
 * from the original "this." Afterwards, "this" data
 * and heapAndFreeStack are set to temp.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <typename T>
void ArrayHeap<T>::doubleCapacity() {
    int newCapacity = this->capacity * 2;
    T *tempData = new T[newCapacity];
    int *tempHeapAndFreeStack = new int[newCapacity];

    //copy data from "this"
    for(int i=0; i<this->capacity; i++){
        tempHeapAndFreeStack[i] = this->heapAndFreeStack[i];
        tempData[i] = this->data[i];
    }

    //for heap, initialize w/ all indexes of data
    for(int j=this->capacity; j<this->capacity*2; j++){
        tempHeapAndFreeStack[j] = j;
    }

    this->capacity*=2;
    delete [] this->heapAndFreeStack;
    delete [] this->data;
    this->heapAndFreeStack = tempHeapAndFreeStack;
    this->data = tempData;

}

/**
 * removeMinItem()
 *
 * This function will remove the item at the
 * beginning of the heapAndFreeStack, as it is
 * the minimum item. This will then cause the last
 * element in the heap to take place of the removed
 * element. This is then bubbled down to be
 * in the correct place within heap.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <typename T>
void ArrayHeap<T>::removeMinItem() {
    if(this->numItems>0){
        swap(this->heapAndFreeStack[0],this->heapAndFreeStack[this->numItems-1]);
        this->numItems--;
        this->bubbleDown(0);
    }
    else{
        return;
    }
}

/**
 * operator=()
 *
 * This function will copy ArrayHeap<T> ah,
 * if this isn't the same. "This" will have
 * its data deleted, then make a deep copy
 * of ah and its variables.
 *
 * Parameters:
 *  ah: ah is the ArrayHeap of type T that "this"
 *      will copy data and heapAndFreeStack from.
 *
 * Return Value: A deep copy of ArrayHeap<T> ah in "this"
 */
template <typename T>
ArrayHeap<T> const &ArrayHeap<T>::operator=(ArrayHeap<T> const &ah){
    if(this != &ah){
        //delete data
        delete [] this->data;
        delete [] this->heapAndFreeStack;

        //copy ah variables
        this->numItems = ah.numItems;
        this->capacity = ah.capacity;
        this->data = new T[ah.capacity];
        this->heapAndFreeStack = new int[ah.capacity];

        //copy ah content
        for(int i=0; i<this->capacity; i++){
            this->data[i] = ah.data[i];
            this->heapAndFreeStack[i] = ah.heapAndFreeStack[i];
        }
    }

    return *this;
}

#endif //PROJECT_5_ARRAYHEAP_STUDENT_PROJ5_H
