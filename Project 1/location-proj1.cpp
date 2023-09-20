/* CSI 3334
 * Project 1 -- DFS Maze Solver
 * Filename: location-proj1.cpp
 * Student name: Jan Jasa
 * assignment: Project 1
 * due date: September 8, 2023
 *
 * This file contains the source code for the Location class.
 */

/* TEST CASES
 *   0 1 2 3
 * 0 E X X X
 * 1 X X X X
 * 2 X X X X
 * 3 X X X s
 * 16
 * 0 0
 * 0 1
 * 0 2
 * 0 3
 * 0 4
 * 1 0
 * 1 1
 * 1 2
 * 1 3
 * 2 0
 * 2 1
 * 2 2
 * 2 3
 * 3 0
 * 3 1
 * 3 2
 * 3 3
 * 0 0
 *
 * Test Case 2
 *   0 1 2 3 4 5 6
 * 0 X   X   X
 * 1 X X X X X
 * 2 X E X   X
 * 3 X X   X X X X
 * 4 X X X X   X X
 * 5 X X X S   X X
 * 6 X   X X X X X
 * 36
 * 0 0
 * 0 2
 * 0 4
 * 1 0
 * 1 1
 * 1 2
 * 1 3
 * 1 4
 * 2 0
 * 2 1
 * 2 2
 * 2 4
 * 3 0
 * 3 1
 * 3 3
 * 3 4
 * 3 5
 * 3 6
 * 4 0
 * 4 1
 * 4 2
 * 4 3
 * 4 5
 * 4 6
 * 5 0
 * 5 1
 * 5 2
 * 5 3
 * 5 5
 * 5 6
 * 6 0
 * 6 2
 * 6 3
 * 6 4
 * 6 5
 * 6 6
 *
 * Test Case 3
 *   -2 -1 0
 * -2 E X X
 * -1 X   S
 *  0 X X X
 *  8
 *  -2 -2
 *  -2 -1
 *  -2 0
 *  -1 -2
 *  -1 0
 *  0 -2
 *  0 -1
 *  0 0
 *
 *  Test Case 4
 *    0 1 2 3
 *  0 E X X S
 *  4
 *  0 0
 *  0 1
 *  0 2
 *  0 3
 *
 *  Test Case 5
 *   0 1 2 3 4 5 6
 * 0 X   X   X
 * 1 X X X X X X
 * 2 X E X   X
 * 3 X X     X X S
 * 18
 * 0 0
 * 0 2
 * 0 4
 * 1 0
 * 1 1
 * 1 2
 * 1 3
 * 1 4
 * 1 5
 * 2 0
 * 2 1
 * 2 2
 * 2 4
 * 3 0
 * 3 1
 * 3 4
 * 3 5
 * 3 6
 *
 * Test Case 6
 *   0 1 2 3
 * 0 E   X
 * 1 X X X X
 * 2 X X X
 * 3 X X   X
 * 4 X X X X
 * 5 X X X S
 * 6 X   X X
 * 7 X X X X
 * 8 X X
 * 29
 * 0 0
 * 0 2
 * 1 0
 * 1 1
 * 1 2
 * 1 3
 * 2 0
 * 2 1
 * 2 2
 * 3 0
 * 3 1
 * 3 3
 * 4 0
 * 4 1
 * 4 2
 * 4 3
 * 5 0
 * 5 1
 * 5 2
 * 5 3
 * 6 0
 * 6 2
 * 6 3
 * 7 0
 * 7 1
 * 7 2
 * 7 3
 * 8 0
 * 8 1
 *
 * Test Case 7
 *   0 1 2 3 4
 * 0 S X X X X
 * 1         X
 * 2 X X X X X
 * 3 X
 * 4 X X X X E
 * 17
 * 0 0
 * 0 1
 * 0 2
 * 0 3
 * 0 4
 * 1 4
 * 2 0
 * 2 1
 * 2 2
 * 2 3
 * 2 4
 * 3 0
 * 4 0
 * 4 1
 * 4 2
 * 4 3
 * 4 4
 *
 * Test Case 8
 *   0 1 2 3 4
 * 0 S
 * 1 X
 * 2 X X X X X
 * 3 X
 * 4 X X X X E
 * 13
 * 0 0
 * 1 0
 * 2 0
 * 2 1
 * 2 2
 * 2 3
 * 2 4
 * 3 0
 * 4 0
 * 4 1
 * 4 2
 * 4 3
 * 4 4
 *
 * Test Case 9
 *   0 1 2 3 4 5 6 7
 * 0   X X X X X
 * 1 X X X X   X X X
 * 2 X         X   X
 * 3 X X X X X X   X
 * 4 E       X     X
 * 5 X       X X X X
 * 6 X X X X X     S
 * 7     X X X X X X
 * 42
 * 0 1
 * 0 2
 * 0 3
 * 0 4
 * 0 5
 * 1 0
 * 1 1
 * 1 2
 * 1 3
 * 1 5
 * 1 6
 * 1 7
 * 2 0
 * 2 5
 * 2 7
 * 3 0
 * 3 1
 * 3 2
 * 3 3
 * 3 4
 * 3 5
 * 3 7
 * 4 0
 * 4 4
 * 4 7
 * 5 0
 * 5 4
 * 5 5
 * 5 6
 * 5 7
 * 6 0
 * 6 1
 * 6 2
 * 6 3
 * 6 4
 * 6 7
 * 7 2
 * 7 3
 * 7 4
 * 7 5
 * 7 6
 * 7 7
 *
 * Test Case 10
 *     -5 -4 -3 -2 -1
 *  -5  X  X  X  X  E
 *  -4  X  X  X
 *  -3     X  X
 *  -2        X  X  S
 *  13
 *  -5 -5
 *  -5 -4
 *  -5 -3
 *  -5 -2
 *  -5 -1
 *  -4 -5
 *  -4 -4
 *  -4 -3
 *  -3 -4
 *  -3 -3
 *  -2 -3
 *  -2 -2
 *  -2 -1
 */

#include "location-proj1.h"

using namespace std;

/* Location
 * Constructor for location class, initializing values
 *
 * Parameters:
 * N/A
 *
 * Return:
 * N/A
 *
*/
Location::Location(){
    this->row = 0;
    this->col = 0;
    this->nextDirection = RIGHT;
}

/* iterationBegin
 * Initializes iteration for Location object
 *
 * Parameters:
 * N/A
 *
 * Return:
 * N/A
 *
*/

void Location::iterationBegin(){
    this->nextDirection = RIGHT;
}

/* iterationCurrent
 * This function creates a copy of the current Location object,
 * and modifies the copy (called neighbor) to represent a different
 * location, then returns it.
 *
 * Parameters:
 * N/A
 *
 * Return:
 * The location of neighbor
 *
*/

Location Location::iterationCurrent() const{
    Location neighbor;
    neighbor.row = this->row;
    neighbor.col = this->col;
    if(this->nextDirection==RIGHT){
        neighbor.col++;
    }
    else if(this->nextDirection==DOWN){
        neighbor.row++;
    }
    else if(this->nextDirection==LEFT){
        neighbor.col--;
    }
    else{
        neighbor.row--;
    }
    return neighbor;
}

/* iterationAdvance
 * This function moves the iteration forward
 *
 * Parameters:
 * N/A
 *
 * Return:
 * N/A
 *
*/
void Location::iterationAdvance(){
    this->nextDirection++;
}

/* iterationDone
 * This function returns true when all the neighbors
 * have been iterated through.
 *
 * Parameters:
 * N/A
 *
 * Return:
 * True if all neighbors have been checked, false otherwise.
 *
*/
bool Location::iterationDone() const{
    if(this->nextDirection==DONE){
        return true;
    }
    else{
        return false;
    }
}

/* operator==
 * This function checks if two locations have the same
 * row and col values.
 *
 * Parameters:
 * loc: Location object that is being compared to THIS->location
 *
 * Return:
 * If two locations are the same, return true. False otherwise
 *
*/
bool Location::operator==(const Location &loc) const{
    return this->row == loc.row && this->col == loc.col;
}

/* operator<<
 * This function streams a location object out.
 *
 * Parameters:
 * os: reference to an ostream
 * loc: location object that goes into stream
 *
 * Return:
 * the ostream with the row and col values.
 *
*/
ostream &operator<<(ostream &os, const Location &loc){
    os << loc.row << " " << loc.col;
    return os;
}

/* operator>>
 * This function streams a location object in.
 *
 * Parameters:
 * os: reference to an istream
 * loc: location object that goes into stream
 *
 * Return:
 * the istream with row and col values.
 *
*/
istream &operator>>(istream &is, Location &loc){
    is >> loc.row >> loc.col;
    return is;
}