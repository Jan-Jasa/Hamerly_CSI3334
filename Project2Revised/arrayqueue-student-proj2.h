/*
 * Project 2 - Word Melt Shortest-Path Solver
 * File: arrayqueue-student-proj2.h
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: September 22, 2023
 * version: 1.0
 *
 * This file contains the functions for the ArrayQueue class,
 * including ArrayQueue(), ArrayQueue (copy constructor),
 * ~ArrayQueue(), add(), remove(), getFront(), getLength(),
 * operator=, and doubleCapacity().
 */

#ifndef ARRAY_QUEUE_STUDENT_PROJ2_H
#define ARRAY_QUEUE_STUDENT_PROJ2_H

#include "arrayqueue-prof-proj2.h"
#include <cassert>


/**
 * ArrayQueue()
 *
 * This function constructs the ArrayQueue class
 * and initializes variables
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <class Base>
ArrayQueue<Base>::ArrayQueue(){
    this->capacity = 10;
    this->length = 0;
    this->front = 0;
    this->data = new Base[this->capacity];
}

/**
 * ArrayQueue (copy constructor)
 *
 * This function constructs a deep copy
 * of the given ArrayQueue, "q"
 *
 * Parameters:
 *  q: ArrayQueue that data is copied from
 *
 * Return Value: ArrayQueue holding a deep copy of "q"
 */
template <class Base>
ArrayQueue<Base>::ArrayQueue(const ArrayQueue<Base> &q){
    this->capacity = q.capacity;
    this->length = q.length;
    this->front = q.front;
    this->data = new Base[this->capacity];
    for(int i=0; i<this->length; i++){
        this->data[(this->front+i)%capacity] = q.data[(q.front+i)%this->capacity];
    }
}

/**
 * ~ArrayQueue()
 *
 * This function is the destructor for ArrayQueue
 * class, and deletes data.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <class Base>
ArrayQueue<Base>::~ArrayQueue(){
    delete [] this->data;
    this->capacity = 0;
    this->length = 0;
    this->front = 0;
}

/**
 * add()
 *
 * This function adds a variable of type Base
 * into the ArrayQueue.
 *
 * Parameters:
 *  item: item of base type that is added to the ArrayQueue
 *
 * Return Value: N/A
 */
template <class Base>
void ArrayQueue<Base>::add(const Base &item){
    if(this->length >= this->capacity){
        this->doubleCapacity();
    }

    int back = ((this->front + this->length)%this->capacity);
    this->data[back] = item;
    this->length++;
}

/**
 * remove()
 *
 * This function removes the first item from
 * the ArrayQueue, due to its FIFO structure.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <class Base>
void ArrayQueue<Base>::remove(){
    if(this->length>0){
        this->front = ((this->front+1) % this->capacity);
        this->length--;
    }
}

/**
 * getFront()
 *
 * This function searches data for the front item
 * from the ArrayQueue, and returns it.
 *
 * Parameters:
 *  N/a
 *
 * Return Value: returns the front of the ArrayQueue, of type Base.
 */
template <class Base>
const Base &ArrayQueue<Base>::getFront() const{
    return this->data[this->front];
}

/**
 * getLength()
 *
 * This function returns the length of ArrayQueue.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: integer representing length of ArrayQueue.
 */
template <class Base>
int ArrayQueue<Base>::getLength() const{
    return this->length;
}

/**
 * operator=()
 *
 * This function first checks to see if the queue we are assigning to is
 * the same as this, and if not, makes a deep copy of the given queue.
 *
 * Parameters:
 *  q: ArrayQueue that is assigned, and copied from.
 *
 * Return Value: ArrayQueue copy of ArrayQueue "q"
 */
template <class Base>
const ArrayQueue<Base> &ArrayQueue<Base>::operator=(const ArrayQueue<Base> &q){
    if(this != &q){
        delete [] this->data;
        this->capacity = q.capacity;
        this->length = q.length;
        this->front = q.front;
        this->data = new Base[this->capacity];
        for(int i=0; i<this->length; i++){
            this->data[(this->front+i)%capacity] = q.data[(q.front+i)%this->capacity];
        }
    }

    return *this;
}

/**
 * doubleCapacity()
 *
 * This function doubles the capacity of the ArrayQueue
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <class Base>
void ArrayQueue<Base>::doubleCapacity(){
    Base *temp = this->data;
    int tempLength = this->length;
    int tempFront = this->front;

    this->capacity *= 2;
    this->data = new Base[this->capacity];
    this->front = 0;

    for(int i=0; i<this->length; i++){
        this->data[i] = temp[(tempFront+i)%tempLength];
    }

    delete [] temp;
}

#endif //PROJECT2REVISED_ARRAYQUEUE_STUDENT_PROJ2_H
