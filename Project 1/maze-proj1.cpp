/* CSI 3334
 * Project 1 -- DFS Maze Solver
 * Filename: maze-proj1.cpp
 * Student name: Jan Jasa
 * assignment: Project 1
 * due date: September 8, 2023
 *
 * This file contains the source code for the Maze class.
 */

#include "maze-proj1.h"

using namespace std;

/* Maze
 * Constructor for Maze class, initializing values
 *
 * Parameters:
 * N/A
 *
 * Return:
 * N/A
 *
*/
Maze::Maze(){
    this->validLocationCount = 0;
    this->validLocations = NULL;
}

/* ~Maze
 * Destructor for Maze class
 *
 * Parameters:
 * N/A
 *
 * Return:
 * N/A
 *
*/
Maze::~Maze(){
    delete [] this->validLocations;
    this->validLocations = NULL;
    this->validLocationCount = 0;

}

/* getStartLocation
 * Returns the starting location of maze
 *
 * Parameters:
 * N/A
 *
 * Return:
 * Location of starting point
 *
*/
Location Maze::getStartLocation(void) const{
    return this->startLocation;
}

/* isValidLocation
 * Checks to see if loc is a valid location
 *
 * Parameters:
 *      loc: Location that will be checked to see
 *         if it's on the list of valid locations
 *
 * Return:
 *      True if location is valid, false otherwise
 *
*/
bool Maze::isValidLocation(const Location &loc) const{
    for(int i=0; i<this->validLocationCount; i++){
        if(loc == this->validLocations[i]){
            return true;
        }
    }
    return false;
}

/* isEndLocation
 * Check to see if loc is the end location
 *
 * Parameters:
 *      loc: Location that will be checked to see
 *         if its the end of the maze
 *
 * Return:
 *      True if valid, false otherwise
 *
*/
bool Maze::isEndLocation(const Location &loc) const{
    if(loc == this->endLocation){
        return true;
    }
    else{
        return false;
    }
}

/* operator>>
 * This function streams a Maze object in
 *
 * Parameters:
 *      is: reference to istream
 *      m: maze object that is created from is
 *
 * Return:
 * N/A
 *
*/
istream &operator>>(istream &is, Maze &m){
    delete [] m.validLocations;
    is >> m.validLocationCount;
    m.validLocations = new Location[m.validLocationCount];

    for(int i=0; i < m.validLocationCount; i++){
        is >> m.validLocations[i];
    }

    is >> m.startLocation >> m.endLocation;
    return is;
}