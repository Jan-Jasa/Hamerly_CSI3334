/*
 * Project 2 - Word Melt Shortest-Path Solver
 * File: driver-proj2.cpp
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: September 22, 2023
 * version: 1.0
 *
 */

#include <iostream>
#include "arrayqueue-student-proj2.h"
#include "arrayqueue-prof-proj2.h"
#include "maze-proj2.h"
#include "location-proj2.h"
#include <map>
#include <stack>

using namespace std;

int main(int argc, char** argv){
    Location currLocation;
    Location endLocation;
    Location neighbor;
    map<Location, Location> m;
    ArrayQueue<Location> queue;
    Maze maze;
    set<Location> printer;
    bool flag = false;

    cin >> maze;

    currLocation = maze.getStartLocation();
    m[currLocation] = currLocation;
    queue.add(currLocation);

    if(maze.isEndLocation(currLocation)){
        flag = true;
        queue.remove();
        endLocation = currLocation;
    }

    while(!flag && queue.getLength()>0){
        currLocation = queue.getFront();
        queue.remove();
        currLocation.iterationBegin();
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

    if(flag==true){
        cout << "Solution found" << endl;
        for(int i=0; !(endLocation==maze.getStartLocation()); i++){
            printer.insert(endLocation);
            endLocation = m[endLocation];
        }
        printer.insert(maze.getStartLocation());

        for(auto j=printer.rbegin(); j != printer.rend(); j++){
            cout << *j << endl;
        }
    }
    else{
        cout << "No solution" << endl;
    }

    return 0;
}
