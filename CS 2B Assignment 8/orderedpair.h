#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/18/2019
Instructor: Dave Harden
File Name: orderedpair.h
 
Program Description: The class, OrderedPair, is converted into a template class. This only works with the operators +, <, and << being overloaded. A programmer-defined exception class named "DuplicateMemberError" will created in addition to an if statement to each of the two mutators to throw this exception if the precondition is not met.
 */

#include <iostream>

/* precondition for setFirst and setSecond: the values of first and second cannot be equal,
except when they are both equal to DEFAULT_VALUE.
*/


namespace cs_pairs {
    template <class T>
    class OrderedPair {
        public:
            class DuplicateMemberError {};
            static const T DEFAULT_VALUE;
            OrderedPair(T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE);
            void setFirst(T newFirst);
            void setSecond(T newSecond);
            T getFirst() const;
            T getSecond() const ;
            OrderedPair<T> operator+(const OrderedPair<T>& right) const;
            bool operator<(const OrderedPair<T>& right) const;
            void print() const;
        
        private:
            T first;
            T second;
    };


    // Leave the following const declaration commented out when you are testing the non-templated version.
    // Uncomment it when you begin converting to a templated version.
    
    // To convert to a templated version you will need a template prefix here above this declaration
    // const int OrderedPair::DEFAULT_VALUE = int();

    template <class T>
    const T OrderedPair<T>::DEFAULT_VALUE = T();

}

#include "orderedpair.cpp"

#endif
