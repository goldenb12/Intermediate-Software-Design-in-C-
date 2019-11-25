/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/25/2019
Instructor: Dave Harden
File Name: sequence.cpp

Program Description: Each of the different functions in this program will test parts of the Sequence class and return a certain number of points to indicate how much of the test passed.  Descriptions and printed statements will show what the result of each tests are.
*/

#include "sequence.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stddef.h>
using namespace std;
using namespace cs_sequence;

namespace cs_sequence {
    // Default Constructor function
    Sequence::Sequence() {
        numItems = 0;
        cursor = nullptr;
        headPtr = nullptr;
        precursor = nullptr;
        tailPtr = nullptr;
    }






     // Copy constructor node movement function
     void Sequence::copy(const Sequence& inputSequence) {
         node* tempPtr = inputSequence.headPtr;
         node* tempCursorPtr = inputSequence.cursor;
         node* tempPrecursorPtr = inputSequence.precursor;
         node* tempTailPtr = inputSequence.tailPtr;
         
         if (tempPtr == NULL){
             headPtr = new node;
             node* currentPtr = headPtr;
             currentPtr->data = tempPtr->data;
             headPtr = headPtr->next;
             while (headPtr != NULL) {
                 currentPtr->next = new node;
                 currentPtr = currentPtr->next;
                 currentPtr->data = tempPtr->data;
                 tempPtr = tempPtr->next;
             }
         } else {
             headPtr = NULL;
         }
     }






    // Sequence start function
    void Sequence::start() {
        if (headPtr == NULL){
            cursor = NULL;
        } else {
            cursor = headPtr;
        }
    }






    // Sequence advance function
    void Sequence::advance() {
        assert(is_item());
        if (cursor == precursor){
            cursor = NULL;
        } else {
            precursor = cursor;
            cursor = cursor->next;
        }
    }






    // Insert node movement function
    void Sequence::insert(const value_type& entry) {
        node* new_node = new node;
        new_node->data = entry;
        numItems++;
        
        if (cursor == headPtr || cursor == nullptr) { // insert at front (or into empty list).
            new_node->next = headPtr;                 // precursor remains nullptr.
            headPtr = new_node;
            if (numItems == 1) {
                tailPtr = new_node;
            }
        } else {                                       // inserting anywhere else
            new_node->next = cursor;                   // tailPtr, headPtr and precursor don't change.
            precursor->next = new_node;
        }
        
        cursor = new_node;
    }






    // Sequence size function
    Sequence::size_type Sequence::size() const {
        return numItems;
    }






    // Boolean value for sequence function
    bool Sequence::is_item() const {
        return (cursor != NULL);
    }






    // Value_type of the current node function
    Sequence::value_type Sequence::current() const {
        return cursor->data;
    }
}
