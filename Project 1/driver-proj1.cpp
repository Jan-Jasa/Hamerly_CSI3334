/* CSI 3334
 * Project 1 -- DFS Maze Solver
 * Filename: driver.cpp
 * Student name: Jan Jasa
 * assignment: Project 1
 * due date: September 8, 2023
 *
 * This file contains the code for the driver, to solve mazes
 */

#include <sstream>
#include "location-proj1.h"
#include "maze-proj1.h"
#include <istream>
#include "stack-proj1.h"

using namespace std;

/* main
 *  parameters:
 *  argc -- the number of arguments from the command line
 *  argv -- the command line argument values
 *  return value: 0 (indicating a successful run)
 *
 *  This function searches through a maze, and finds a path
 *  from beginning to end. The function checks the neighbors
 *  in the order of right, down, left, and up. If there's a valid
 *  path, a solution will be outputted. If not, no solution will
 *  appear.
 */

int main(int argv, char** argc){
    Maze m;
    Location cur;
    Location neighbor;
    LocationStack locationStack;
    bool flag = false;

    cin >> m;
    cur = m.getStartLocation();
    cur.iterationBegin();
    locationStack.push(cur);

    while(!flag && !m.isEndLocation(locationStack.getTop())){
        cur = locationStack.getTop();
        locationStack.pop();

        if(!cur.iterationDone()){
            neighbor = cur.iterationCurrent();
            cur.iterationAdvance();
            neighbor.iterationBegin();
            locationStack.push(cur);
            if(m.isValidLocation(neighbor) && !locationStack.isOn(neighbor)){
                locationStack.push(neighbor);
            }
        }
        else if(locationStack.isEmpty()){
            flag = true;
        }
    }

    if(flag){
        cout << "No solution" << endl;
    }
    else{
        cout << "Solution found" << endl << locationStack;
    }

    return 0;
}
