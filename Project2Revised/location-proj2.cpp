/*
 * Project 2 - Word Melt Shortest-Path Solver
 * File: location-proj2.cpp
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: September 15, 2023 (milestone)
 * version: 1.0
 *
 * This file contains the functions for the Location class,
 * including Location(), iterationBegin(), iterationCurrent(),
 * iterationAdvance(), iterationDone(), operator ==, operator >>,
 * operator <<, and operator <.
 */

#include "location-proj2.h"

using namespace std;


/**
 * Location()
 *
 * This function is the constructor for the Location class.
 * It initializes word, iterationMode, indexToChange, and nextLetter.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
Location::Location(){
    this->iterationMode = CHANGE_LETTER;
    this->word = "";
    this->indexToChange = 0;
    this->nextLetter = 'a';
}

/**
 * iterationBegin()
 *
 * This function begins iteration by setting the mode
 * to CHANGE_LETTER (as this is by default the first mode)
 * and initializing all other values. If the first letter of
 * the word is 'a', nextLetter iterates by one.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
void Location::iterationBegin(){
    this->iterationMode = CHANGE_LETTER;
    this->indexToChange = 0;
    this->nextLetter = 'a';
    if(this->word[0] == 'a'){
        this->nextLetter++;
    }
}

/**
 * iterationCurrent()
 *
 * This function creates a copy of the Location class,
 * modifies it depending on the iterationMode, and returns
 * the created neighbor.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: Neighbor location of the next word.
 */
Location Location::iterationCurrent() const{
    Location holder;
    holder.word = this->word;
    //Order of modes iterated: Change, insert, delete
    if(this->iterationMode==CHANGE_LETTER){
        holder.word[this->indexToChange] = this->nextLetter;
    }
    else if(this->iterationMode==INSERT_LETTER){
        holder.word.insert(this->indexToChange,1,this->nextLetter);
    }
    else if(this->iterationMode==DELETE_LETTER){
        holder.word.erase(this->indexToChange,1);
    }

    return holder;
}

/**
 * iterationAdvance()
 *
 * This function iterates forward so the next word
 * can be called. It goes in order of iterationModes,
 * so CHANGE_LETTER -> INSERT_LETTER -> DELETE_LETTER -> DONE.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
void Location::iterationAdvance(){
    //change letter advance (DONE)
    if(this->iterationMode == CHANGE_LETTER){
        if(this->nextLetter != 'z'){
            this->nextLetter++;
        }
        else if(this->word.size() > this->indexToChange){
            this->nextLetter = 'a';
            this->indexToChange++;
            if(this->word[indexToChange]==this->nextLetter){
                this->nextLetter++;
            }
        }

        if(this->word[this->indexToChange]==this->nextLetter){
            this->nextLetter++;
            if(this->nextLetter>'z'){
                this->indexToChange++;
                this->nextLetter = 'a';
                if(this->word[indexToChange]==this->nextLetter){
                    this->nextLetter++;
                }
            }
        }

        if(this->indexToChange>=this->word.size()){
            this->iterationMode = INSERT_LETTER;
            this->indexToChange = 0;
            this->nextLetter = 'a';
        }
    }

    //insert letter advance (GOOD)
    else if(this->iterationMode == INSERT_LETTER){
        if(this->nextLetter != 'z'){
            this->nextLetter++;
        }
        else if(this->indexToChange < this->word.size()){
            this->nextLetter = 'a';
            this->indexToChange++;
        }
        else{
            this->iterationMode = DELETE_LETTER;
            this->indexToChange = 0;
            this->nextLetter = 'a';
        }
    }

    //delete letter advance (GOOD)
    else if(this->iterationMode == DELETE_LETTER) {
        this->indexToChange++;
        if(this->indexToChange >= this->word.size()){
            this->iterationMode = DONE;
            this->indexToChange = 0;
            this->nextLetter = 'a';
        }
    }
}

/**
 * iterationDone()
 *
 * This function checks if iteration is done.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: True if iteration of a word is done,false otherwise
 */
bool Location::iterationDone() const{
    if(this->iterationMode == DONE){
        return true;
    }
    else{
        return false;
    }
}

/**
 * operator==
 *
 * This function checks to see if two locations
 * have the same word.
 *
 * Parameters:
 *  loc: Location object being compared to this location.
 *
 * Return Value: True if both locations are true based off word,
 *  false otherwise.
 */
bool Location::operator==(const Location &loc) const{
    return loc.word == this->word;
}

/**
 * operator<<()
 *
 * This function overrides << for location class,
 * giving it the ability to output its content.
 *
 * Parameters:
 *  os: given ostream, that allows for the output
 *      of loc's word.
 *  loc: Location object that is being passed to
 *      have its word outputted.
 *
 * Return Value: An ostream returning the word inside
 *  the location object
 */
ostream &operator<<(ostream &os, const Location &loc){
    os << loc.word;

    return os;
}

/**
 * operator>>()
 *
 * This function overrides >> for location class,
 * giving it the ability to take input for the location.
 *
 * Parameters:
 *  is: given istream, that allows for the input of data
 *      into a location's "word" variable.
 *  loc: Location object that a string is being
 *      passed into.
 *
 * Return Value: An ostream returning the word inside
 *  the location object
 */
istream &operator>>(istream &is, Location &loc){
    string holder;
    is >> holder;
    loc.word = holder;
    return is;
}

/**
 * operator<
 *
 * This function checks if the passed location
 * is less than this.
 *
 * Parameters:
 *  loc: Location that we are checking against "this," to see
 *      if it is lesser or not.
 *
 * Return Value: True if this is less than loc, false otherwise
 */
bool Location::operator<(const Location &loc) const{
    if(this->word < loc.word){
        return true;
    }
    else{
        return false;
    }
}