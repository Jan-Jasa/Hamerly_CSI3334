/*
 * Project 4: Balanced tree-based encryption and decryption
 * File: driver.cpp
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: October 27, 2023
 * version: 1.4
 *
 * This file contains main(), which is used
 * to actually use the Encryption Tree program.
 * It will take input from the user and either,
 * i: insert into the tree
 * r: remove from the tree
 * e: encrypt the word
 * d: decrypt the path
 * p: print the tree in preorder
 * l: print the tree in level order
 * q: quit the program, and end it
 *
 * Note: if the encrypted word or decrypted path is
 *       not found, it will return "?"
 */

#include <iostream>
#include "avl-tree-prof-proj4.h"
#include "avl-tree-student-proj4.h"

using namespace std;

/**
 * main()
 *
 * This function takes in an input from a user, with each command
 * doing a different function upon a AVL tree. The AVL tree is used for an
 * "encryption tree." Until the input/command is "q", main() will
 * continue running. The different commands are as follow:
 * i: Inserts an item of type <base> into the BST tree.
 *    (Will not enter a duplicate item into the tree.)
 *
 * r: Removes an item of type <base> from the BST tree.
 *    (Will not remove a nonexistent item from the tree.)
 *
 * e: Encrypts the input from the user, if it exists in the tree.
 *    It will be encrypted in the format "r" for root, followed
 *    by either a 0 if its path is found on the left. Otherwise,
 *    the encryption will have a 0 added if its path is found on
 *    the right. If the input of type <Base> isn't found on the BST,
 *    it will return "?" during it's run in main().
 *
 * d: Decrypts the path input from the user. It follows the same
 *    format described above in encrypt. This will return a "?" if
 *    the path isn't valid/not found.
 *
 * p: Prints the AVL tree in preorder.
 *
 * l: Prints the AVL tree in level order.
 *
 * q: Quits, and exits the program.
 *
 *
 * Parameters:
 *  argc: argument count from command line
 *  argv: argument values from command line
 *
 * Return Value: Return 0 for a successful run.
 */
int main(int argc, char *argv[]) {
    string input;
    string tempWord;
    char tempChar;
    //string *decrypter;
    EncryptionTree<string> tree;

    cin >> input;

    while(input != "q"){
        if(input == "i"){
            cin >> input;
            tree.insert(input);
        }
        else if(input=="r"){
            cin >> input;
            tree.remove(input);
        }
        else if(input=="e"){
            bool quotation = false;
            cin >> tempChar;
            while(!quotation){
                cin >> tempWord;
                if(!(tempWord[tempWord.length()-1]=='\'')){
                    cout << tree.encrypt(tempWord) << " ";
                }
                else{
                    quotation=true;
                }
            }
            cout << tree.encrypt(tempWord.substr(0,tempWord.size()-1)) << endl;
        }
        else if(input=="d"){
            bool quotation = false;
            cin >> tempChar;
            while(!quotation){
                cin >> tempWord;
                if(!(tempWord[tempWord.length()-1]=='\'')){
                    if(tree.decrypt(tempWord)!=NULL){
                        cout << *tree.decrypt(tempWord) << " ";
                    }
                    else{
                        cout << "?" << " ";
                    }
                }
                else{
                    quotation=true;
                }
            }
            //substr so we don't take a quotation as well, make sure not NULL too
            if(tree.decrypt(tempWord.substr(0,tempWord.size()-1)) != NULL){
                cout << *tree.decrypt(tempWord.substr(0,tempWord.size()-1)) << endl;
            }
            else{
                cout << "?" << endl;
            }
        }
        else if(input=="p"){
            tree.printPreorder();
        }
        else if(input=="l"){
            tree.printLevelOrder();
        }
        cin >> input;
    }

    return 0;
}
