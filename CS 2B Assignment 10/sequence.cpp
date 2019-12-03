/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 12/2/2019
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
    // Copy constructor function
    Sequence::Sequence(const Sequence& copyMe) {
        copy(copyMe);
    }






    // Destructor function
    Sequence::~Sequence() {
        clear();
    }






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
         numItems = 0;
         if (inputSequence.headPtr == NULL){
             cursor = NULL;
             precursor = NULL;
             headPtr = NULL;
             tailPtr = NULL;
         } else {
             node* newListPtr = new node;
             numItems++;
             newListPtr->data = inputSequence.headPtr->data;
             headPtr = newListPtr;
             node* sourcePtr = inputSequence.headPtr->next;
             
             while (sourcePtr != NULL) {
                 newListPtr->next = new node;
                 numItems++;
                 newListPtr = newListPtr->next;
                 newListPtr->data = sourcePtr->data;
                 
                 if (sourcePtr == inputSequence.precursor){
                     precursor = sourcePtr;
                     cursor = sourcePtr->next;
                 }
                 
                 if (sourcePtr->next == NULL){
                     tailPtr = sourcePtr;
                 }
                 sourcePtr = sourcePtr->next;
             }
             delete sourcePtr;
             newListPtr->next = NULL;
         }
     }






    // Sequence start function
    void Sequence::start() {
        precursor = NULL;
        cursor = headPtr;
    }






    // Sequence advance function
    void Sequence::advance() {
        if (!is_item()){
            return;
        } else if (cursor->next == NULL) {
            cursor = NULL;
            precursor = NULL;
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






    // Attach function
    void Sequence::attach(const value_type& entry) {
        numItems++;
        node* tempPtr = new node;
        tempPtr->data = entry;
        
        if (!headPtr){
            tempPtr->next = NULL;
            headPtr = tempPtr;
            tailPtr = tempPtr;
            start();
        } else if (cursor == NULL) {
            start();
            while (cursor->next) {
                advance();
            }
            cursor->next = tempPtr;
            tempPtr->next = NULL;
            advance();
        } else if (cursor->next == NULL) {
            cursor->next = tempPtr;
            tempPtr->next = NULL;
            advance();
        } else {
            node* new_node = cursor->next;
            tempPtr->next = new_node;
            cursor->next = tempPtr;
            advance();
        }
    }






    // Remove function
    void Sequence::remove_current() {
        assert(is_item());
        if (is_item()){
            numItems--;
            node* tempPtr = cursor;
            
            if (numItems == 0){
                headPtr = NULL;
                tailPtr = NULL;
                cursor = NULL;
                precursor = NULL;
            } else if (headPtr == cursor) {
                tempPtr = headPtr->next;
                delete headPtr;
                headPtr = tempPtr;
                cursor = headPtr;
            } else if (cursor->next != NULL) {
                precursor->next = cursor->next;
                advance();
                delete tempPtr;
            } else {
                cursor = NULL;
                tailPtr = precursor;
                precursor = NULL;
            }
        }
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






    // Assignment operator function
    Sequence Sequence::operator=(const Sequence& right) {
        if (this != &right){
            clear();
            copy(right);
        }
        return *this;
    }






    // Clear function
    void Sequence::clear() {
        node* tempNode;
        node* new_node;
        
        tempNode = headPtr;
        while (tempNode != NULL) {
            new_node = tempNode->next;
            delete tempNode;
            tempNode = new_node;
        }
        numItems = 0;
    }
}

/*
 Output:
 Running tests for Sequence Class with a linked Sequence

 START OF TEST 1:
 Testing insert, attach, and the constant member functions (4 points).
 Starting with an empty Sequence.
 Testing that size() returns 0 ... Passed.
 Testing that is_item() returns false ... Passed.
 I'll call start() and look at the items one more time...
 All tests passed for this Sequence.

 I am now using attach to put 10 into an empty Sequence.
 Testing that size() returns 1 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 I am now using insert to put 10 into an empty Sequence.
 Testing that size() returns 1 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 I am now using attach to put 10,20,30 in an empty Sequence.
 Then I move the cursor to the start and insert 5.
 Testing that size() returns 4 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 I am now using attach to put 10,20,30 in an empty Sequence.
 Then I move the cursor to the start, advance once, and insert 15.
 Testing that size() returns 4 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [1] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 I am now using attach to put 10,20,30 in an empty Sequence.
 Then I move the cursor to the start and attach 15 after the 10.
 Testing that size() returns 4 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [1] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 All tests of this first function have been passed.
 Test 1 got 4 points out of a possible 4.
 END OF TEST 1.

 4

 START OF TEST 2:
 Testing situations where the cursor goes off the Sequence (4 points).
 Using attach to put 20 and 30 in the Sequence, and then calling
 advance, so that is_item should return false ... passed.
 Inserting 10, which should go at the Sequence's front.
 Then calling advance three times to run cursor off the Sequence ... passed.
 Calling attach to put the numbers 40, 50, 60 ...300 at the Sequence's end.
 Now I will test that the Sequence has 10, 20, 30, ...300.
 All tests of this second function have been passed.
 Test 2 got 4 points out of a possible 4.
 END OF TEST 2.

 8

 START OF TEST 3:
 Testing remove_current (4 points).
 Using attach to build a Sequence with 10,30.
 Insert a 20 before the 30, so entire Sequence is 10,20,30.
 Testing that size() returns 3 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [1] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Remove the 20, so entire Sequence is now 10,30.
 Testing that size() returns 2 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [1] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Remove the 30, so entire Sequence is now just 10 with no cursor.
 Testing that size() returns 1 ... Passed.
 Testing that is_item() returns false ... Passed.
 I'll call start() and look at the items one more time...
 All tests passed for this Sequence.

 Set the cursor to the start and remove the 10.
 Testing that size() returns 0 ... Passed.
 Testing that is_item() returns false ... Passed.
 I'll call start() and look at the items one more time...
 All tests passed for this Sequence.

 Using attach to build another Sequence with 10,30.
 Insert a 20 before the 30, so entire Sequence is 10,20,30.
 Testing that size() returns 3 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [1] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Remove the 20, so entire Sequence is now 10,30.
 Testing that size() returns 2 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [1] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Set the cursor to the start and remove the 10,
 so the Sequence should now contain just 30.
 Testing that size() returns 1 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Remove the 30 from the Sequence, resulting in an empty Sequence.
 Testing that size() returns 0 ... Passed.
 Testing that is_item() returns false ... Passed.
 I'll call start() and look at the items one more time...
 All tests passed for this Sequence.

 Build a new Sequence by inserting 30, 10, 20 (so the Sequence
 is 20, then 10, then 30). Then remove the 20.
 Testing that size() returns 2 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Just for fun, I'll empty the Sequence then fill it up, then
 empty it again. During this process, I'll try to determine
 whether any of the Sequence's member functions access the
 array outside of its legal indexes.
 All tests of this third function have been passed.
 Test 3 got 4 points out of a possible 4.
 END OF TEST 3.

 12

 START OF TEST 4:
 Testing the copy constructor (2 points).
 Copy constructor test: for an empty Sequence.
 Testing that size() returns 0 ... Passed.
 Testing that is_item() returns false ... Passed.
 I'll call start() and look at the items one more time...
 All tests passed for this Sequence.

 Copy constructor test: for a Sequence with cursor at tail.
 Testing that size() returns 60 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [59] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Copy constructor test: with cursor near middle.
 Testing that size() returns 59 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [30] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...
     The item [30] should be 31,
     but it was -310376945 instead.
 Failed.
 Test of the Sequence's items failed.

 Test 4 failed.
 END OF TEST 4.

 12

 START OF TEST 5:
 Testing the assignment operator (2 points).
 Assignment operator test: for an empty Sequence.
 Testing that size() returns 0 ... Passed.
 Testing that is_item() returns false ... Passed.
 I'll call start() and look at the items one more time...
 All tests passed for this Sequence.

 Assignment operator test: cursor at tail.
 Testing that size() returns 60 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [59] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Assignment operator test: with cursor near middle.
 Testing that size() returns 59 ... Passed.
 Testing that is_item() returns true ... Failed.
 Basic test of size() or is_item() failed.

 Test 5 failed.
 END OF TEST 5.

 12

 START OF TEST 6:
 Testing insert/attach for somewhat larger Sequences (2 points).
 Testing to see that attach works correctly when the
 current capacity is exceeded.
 Testing that size() returns 60 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [59] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 Testing to see that insert works correctly when the
 current capacity is exceeded.
 Testing that size() returns 60 ... Passed.
 Testing that is_item() returns true ... Passed.
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 I'll call start() and look at the items one more time...
 The cursor should be at item [0] of the Sequence
 (counting the first item as [0]). I will advance the cursor
 to the end of the Sequence, checking that each item is correct...Passed.
 All tests passed for this Sequence.

 All tests of this sixth function have been passed.
 Test 6 got 2 points out of a possible 2.
 END OF TEST 6.

 14
 If you submit this Sequence to Dora now, you will have
 14 points out of the 18 points from this test program.
 */
