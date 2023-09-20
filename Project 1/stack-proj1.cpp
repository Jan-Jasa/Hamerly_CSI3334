/* CSI 3334
 * Project 1 -- DFS Maze Solver
 * Filename: stack-proj1.cpp
 * Student name: Jan Jasa
 * assignment: Project 1
 * due date: September 8, 2023
 *
 * This file contains the code for the Stack class.
 */

#include "stack-proj1.h"


/* LocationStack
 * Constructor for Location class, initializing values
 *
 * Parameters:
 * N/A
 *
 * Return:
 * N/A
 *
*/
LocationStack::LocationStack() {
    this->top = NULL;
}

/* ~LocationStack
* Destructor for Location class
*
* Parameters:
* N/A
*
* Return:
* N/A
*
*/
LocationStack::~LocationStack() {
    delete this->top;
    this->top = NULL;
}

/* push
* Pushes location onto stack
*
* Parameters:
* loc: Location that is to be put onto stack
*
* Return:
* N/A
*
*/
void LocationStack::push(const Location &loc){
    this->top = new LocationStackNode(loc, this->top);
}

/* pop
* removes last location from stack
*
* Parameters:
* N/A
*
* Return:
* N/A
*
*/
void LocationStack::pop(){
    assert(!isEmpty());
    LocationStackNode *temp = this->top;
    this->top = this->top->getNextNode();
    temp->setNextNode(NULL);
    delete temp;
}

/* getTop
* Returns first location from stack
*
* Parameters:
* N/A
*
* Return:
* Most recent location, from the top of the stack
*
*/
const Location& LocationStack::getTop() const{
    return this->top->getLocation();
}

/* isEmpty()
* This function checks the top of the stack,
* and checks if it's null, meaning it's empty.
*
* Parameters:
* N/A
*
* Return:
* True if top of stack is empty, false otherwise
*
*/
bool LocationStack::isEmpty() const {
    return this->top == NULL;
}

/* isOn
* Checks if location is on the stack by comparing
* the given location to all locations found on the
* stack.
*
* Parameters:
* loc: location that is to be checked if in stack
*
* Return:
* True if given location on stack, false if else
*
*/
bool LocationStack::isOn(const Location &loc) const{
    LocationStackNode *temp = this->top;
    while(temp != NULL){
        if(temp->getLocation() == loc){
            return true;
        }
        temp = temp->getNextNode();
    }
    return false;
}
/* operator<<
* Streams out the stack from bottom to top.
*
* Parameters:
* os: reference to ostream
* s: LocationStack object that will be streamed into this stack
*
* Return:
* ostream of all locations from the bottom of the stack
* to the top, using the << operator
*
*/
ostream &operator<<(ostream &os, const LocationStack &s){
    LocationStackNode *curr = s.top;
    LocationStackNode *next = NULL;
    LocationStackNode *prev = NULL;
    while(curr != NULL){
        next = curr->getNextNode();
        curr->setNextNode(prev);
        prev = curr;
        curr = next;
    }
    curr = prev;
    next = prev = NULL;
    while(curr != NULL){
        os << curr->getLocation() << endl;
        next = curr->getNextNode();
        curr->setNextNode(prev);
        prev = curr;
        curr = next;
    }
    curr = prev;
    return os;
}
/* LocationStackNode
* Constructor for the LocationStackNode class, initializing all values
*
* Parameters:
* loc: location object that this will point to
* next: points to next node in the list
*
* Return:
* N/A
*
*/
LocationStackNode::LocationStackNode(const Location &loc, LocationStackNode *next) {
    this->location = loc;
    this->nextNode = next;
}

/* ~LocationStackNode
* Destructor for the LocationStackNode class
*
* Parameters:
* N/A
*
* Return:
* N/A
*
*/
LocationStackNode::~LocationStackNode() {
    delete this->nextNode;
}

/* getLocation
* Returns location of the LocationStackNode
*
* Parameters:
* N/A
*
* Return:
* Location of the LocationStackNode
*
*/
const Location& LocationStackNode::getLocation() const{
    return this->location;
}

/* getNextNode
* Returns the nextNode of the LocationStackNode
*
* Parameters:
* N/A
*
* Return:
* The nextNode of the LocationStackNode
*
*/
LocationStackNode* LocationStackNode::getNextNode() const {
    return this->nextNode;
}

/* setNextNode
* Sets the nextNode of the LocationStackNode
*
* Parameters:
* next: Pointer that will point to the next node
*
* Return:
* N/A
*
*/
void LocationStackNode::setNextNode(LocationStackNode *next) {
    this->nextNode = next;
}
