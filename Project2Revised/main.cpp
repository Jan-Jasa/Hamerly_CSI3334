/*
 * Project 2 - Word Melt Shortest-Path Solver
 * File: driver-proj2.cpp
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: September 22, 2023
 * version: 1.0
 *
 * This file contains the driver for Project 2,
 * which solves a word melt, giving the shortest
 * path possible.
 */

#include <iostream>
#include "arrayqueue-student-proj2.h"
#include "arrayqueue-prof-proj2.h"
#include "maze-proj2.h"
#include "location-proj2.h"
#include <map>
#include <set>
#include <stack>

using namespace std;


/**
 * main()
 *
 * This function first takes in a input from the user, and
 * inputs it into a maze object. From the startLocation,
 * the maze is ran through as it checks neighbor words by
 * changing each letter, inserting letters, and deleting letters.
 * Once a word is found that is a valid word (from maze), it is
 * put onto the map, with the predecessor being its value. Once the
 * end word has been found, the solution is outputted with the
 * shortest length possible. If not, no solution is outputted.
 *
 * Parameters:
 *  argc: argument count from command line
 *  argv: argument values from command line
 *
 * Return Value: N/A
 */
int main(int argc, char** argv){
    /*Location currLocation;
    Location endLocation;
    Location neighbor;
    map<Location, Location> m;
    ArrayQueue<Location> queue;
    Maze maze;
    //Location printer[100];
    stack<Location> printer;
    bool flag = false;

    cin >> maze;

    currLocation = maze.getStartLocation();
    m[currLocation] = currLocation;
    queue.add(currLocation);

    //check if end location is in the beginning
    if(maze.isEndLocation(currLocation)){
        flag = true;
        queue.remove();
        endLocation = currLocation;
    }

    //maze solver
    while(!flag && queue.getLength()>0){
        currLocation = queue.getFront();
        currLocation.iterationBegin();
        queue.remove();
        //cout << queue.getLength() << endl; // test

        while(!currLocation.iterationDone() && !flag){
            neighbor = currLocation.iterationCurrent();

            if(maze.isEndLocation(neighbor)) {
                flag = true;
                m[neighbor] = currLocation;
                endLocation = neighbor;
                while (queue.getLength() > 0) {
                    queue.remove();
                }
            }
            else if(m.find(neighbor) == m.end() && maze.isValidLocation(neighbor)){
                queue.add(neighbor);
                m[neighbor] = currLocation;
            }
            currLocation.iterationAdvance();
        }
    }

    //printing
    if(flag==true){
        cout << "Solution found" << endl;
        for(int i=0; !(endLocation==maze.getStartLocation()); i++){
            printer.push(endLocation);
            endLocation = m[endLocation];
        }
        endLocation = m[endLocation];

        cout << maze.getStartLocation() << endl;
        while(!printer.empty()){
            cout << printer.top() << endl;
            printer.pop();
        }
    }
    else{
        cout << "No solution" << endl;
    }*/

    Location loc;
    cin >> loc;
    loc.iterationBegin();
    while(!loc.iterationDone()){
        Location neighbor = loc.iterationCurrent();
        cout << neighbor << endl;
        loc.iterationAdvance();
    }

    return 0;
}
