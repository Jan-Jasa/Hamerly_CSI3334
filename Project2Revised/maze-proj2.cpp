/*
 * Project 2 - Word Melt Shortest-Path Solver
 * File: maze-proj2.cpp
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: September 22, 2023 (milestone)
 * version: 1.0
 *
 * This file contains the functions for the Maze class,
 * including Maze(), getStartLocation(), isValidLocation(),
 * isEndLocation(), and operator>>
 */

#include "maze-proj2.h"

/**
 * Maze()
 *
 * This function constructs the maze class
 * and initializes the set, validLocations
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
Maze::Maze(){
    this->validLocations.clear();
}

/**
 * getStartLocation()
 *
 * This function returns the starting location
 * of the maze object
 *
 * Parameters:
 *  N/A
 *
 * Return Value: The starting location of maze
 */
Location Maze::getStartLocation() const{
    return this->startLocation;
}

/**
 * isValidLocation()
 *
 * This function checks if the passed location
 * is valid, by checking it against .end() and
 * making sure it does not point to somewhere outside
 * the set.
 *
 * Parameters:
 *  loc: Location that we are checking for validity
 *
 * Return Value: True if location is valid, false otherwise
 */
bool Maze::isValidLocation(const Location &loc) const{
    if(this->validLocations.find(loc) != this->validLocations.end()){
        return true;
    }
    else{
        return false;
    }
}

/**
 * isEndLocation()
 *
 * This function checks if the passed location
 * is equivalent to the end location, marking the
 * end of the process as well.
 *
 * Parameters:
 *  loc: Location that we are checking for validity
 *
 * Return Value: True if location is the end, false otherwise
 */
bool Maze::isEndLocation(const Location &loc) const{
    if(loc == this->endLocation){
        return true;
    }
    else{
        return false;
    }
}

/**
 * operator>>
 *
 * This function inputs data into a maze,
 * overriding the >> operator
 *
 * Parameters:
 *  is: given istream, to allow input into a maze object by streaming
 *      in the size, locations, and start/end location of the maze
 *  m: maze class that data is put into
 *
 * Return Value: an istream that carries the inputted values to the maze
 */
istream &operator>>(istream &is, Maze &m){
    m.validLocations.clear();
    int n;
    Location holder;

    is >> n;
    for(int i=0; i<n; i++){
        is >> holder;
        m.validLocations.insert(holder);
    }

    is >> m.startLocation;
    is >> m.endLocation;

    return is;
}
