/* CSI 3334
 * Project 0 -- Undo Redo
 * Filename: driver-proj0.cpp
 * Student name: Jan Jasa
 *
 * A simple text editor with typing, undo and redo functions
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* main
 *  parameters:
 *      argc -- the number of arguments from the command line
 *      argv -- the command line argument values
 *  return value: 0 (indicating a successful run)
 *
 *  Takes a number from 1-1000 (inclusive)
 *  Each line will have a command: 't','u', or 'r'
 *  command 't' will type a word onto the stack
 *  command 'u' will undo a word
 *  command 'r' will redo the last undone word
 */

int main(int argc, char **argv) {
    // these are the two stacks used to store the typed & undone words
    stack<string> typing, undo;
    stack<string> typingRev, undoRev;
    int numLines;
    char cmd;
    string word;


    cin >> numLines;

    //inputs typing, undo, or redo command
    for(int i=1; i <= numLines; i++){
        cin >> cmd;
        switch(cmd){
            case 't':
                cin >> word;
                typing.push(word);
                break;
            case 'u':
                if(typing.empty()){
                    cout << "nothing to undo on command " << i << endl;
                    break;
                }
                else{
                    word = typing.top();
                    typing.pop();
                    undo.push(word);
                    break;
                }
            case 'r':
                if(undo.empty()){
                    cout << "nothing to redo on command " << i << endl;
                    break;
                }
                else{
                    word = undo.top();
                    undo.pop();
                    typing.push(word);
                    break;
                }
        }
    }

    //output method: reverse stack and print
    while(!typing.empty()){
        typingRev.push(typing.top());
        typing.pop();
    }
    while(!undo.empty()){
        undoRev.push(undo.top());
        undo.pop();
    }

    while(!typingRev.empty()){
        cout << typingRev.top();
        typingRev.pop();
        if(!typingRev.empty()){
            cout << " ";
        }
    }
    cout << endl;
    while(!undoRev.empty()){
        cout << undoRev.top();
        undoRev.pop();
        if(!undoRev.empty()){
            cout << " ";
        }
    }
    cout << endl;


    return 0;
}

