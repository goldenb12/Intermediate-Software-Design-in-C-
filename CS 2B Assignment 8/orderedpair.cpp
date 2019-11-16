/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/18/2019
Instructor: Dave Harden
File Name: orderedpair.cpp
 
Program Description: This program executes what is being done based on the information in the header file, orderedpair.h.
 */

#include "orderedpair.h"
#include <iostream>
using namespace std;
using namespace cs_pairs;

namespace cs_pairs {
    template <class T>
    OrderedPair<T>::OrderedPair(T newFirst, T newSecond) {
        setFirst(newFirst);
        setSecond(newSecond);
    }

    template <class T>
    void OrderedPair<T>::setFirst(T newFirst) {
        // if statement to throw an exception if precondition not met goes here.
        if (newFirst == second && newFirst != DEFAULT_VALUE){
            throw DuplicateMemberError();
        }
        first = newFirst;
    }

    template <class T>
    void OrderedPair<T>::setSecond(T newSecond) {
        // if statement to throw an exception if precondition not met goes here.
        if (newSecond == first && newSecond != DEFAULT_VALUE){
            throw DuplicateMemberError();
        }
        second = newSecond;
    }

    template <class T>
    T OrderedPair<T>::getFirst() const {
        return first;
    }

    template <class T>
    T OrderedPair<T>::getSecond() const {
        return second;
    }

    template <class T>
    OrderedPair<T> OrderedPair<T>::operator+(const OrderedPair& right) const {
        return OrderedPair(first + right.first, second + right.second);
    }

    template <class T>
    bool OrderedPair<T>::operator<(const OrderedPair& right) const {
        return first + second < right.first + right.second;
    }

    template <class T>
    void OrderedPair<T>::print() const {
        cout << "(" << first << ", " << second << ")";
    }
}
