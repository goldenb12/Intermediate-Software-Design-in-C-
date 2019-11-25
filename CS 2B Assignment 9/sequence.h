#ifndef SEQUENCE_H
#define SEQUENCE_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/25/2019
Instructor: Dave Harden
File Name: sequence.h

Program Description: This is the header file for the Sequence class.  Each of the different functions in this program will test parts of the Sequence class and return a certain number of points to indicate how much of the test passed.  Descriptions and printed statements will show what the result of each tests are.
*/

#include <iostream>
#include <cstdlib>

namespace cs_sequence {
    class Sequence {
        public:
            typedef int value_type;
            typedef std::size_t size_type;
            value_type numItems;
            Sequence();
                // postcondition: The Sequence has been initialized to an empty Sequence.
            void copy(const Sequence& inputSequence);
            void start();
                // postcondition: The first item in the Sequence becomes the current item (but if the
                // Sequence is empty, then there is no current item).
            void advance();
                // precondition: is_item() returns true
                // Postcondition: If the current item was already the last item in the Sequence, then there
                // is no longer any current item. Otherwise, the new current item is the item immediately after
                // the original current item.
            void insert(const value_type& entry);
                // Postcondition: A new copy of entry has been inserted in the Sequence before the
                // current item. If there was no current item, then the new entry has been inserted at the
                // front. In either case, the new item is now the current item of the Sequence.
            size_type size() const;
                // Postcondition: Returns the number of items in the Sequence.
            bool is_item() const;
                // Postcondition: A true return value indicates that there is a valid "current" item that
                // may be retrieved by the current member function (listed below). A false return value
                // indicates that there is no valid current item.
            value_type current() const;
                // Precondition: is_item() returns true
                // Postcondition: The current item in the Sequence is returned.
        
        private:
            struct node {
                value_type data;
                node* next;
            };
            
            node* headPtr;
            node* tailPtr;
            node* cursor;
            node* precursor;
    };
}

#endif
