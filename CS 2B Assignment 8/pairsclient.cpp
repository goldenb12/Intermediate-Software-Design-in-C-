/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/18/2019
Instructor: Dave Harden
File Name: pairsclient.cpp
 
Program Description: This program has the class, OrderedPair, work with different types and use the templated class (modified from using int as the type parameter), to make it use ordered pairs of strings instead of ints.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "orderedpair.h"
using namespace std;
using namespace cs_pairs;

int main() {
    int num1, num2;
    OrderedPair<int> myList[10];
    
    srand(static_cast<unsigned>(time(0)));
    cout << "default value: ";
    myList[0].print();
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        myList[i].setFirst(rand() % 50);
        myList[i].setSecond(rand() % 50 + 50);
    }
    
    myList[2] = myList[0] + myList[1];
    
    if (myList[0] < myList[1]) {
        myList[0].print();
        cout << " is less than ";
        myList[1].print();
        cout << endl;
    }
    
    for (int i = 0; i < 10; i++) {
        myList[i].print();
        cout << endl;
    }
    
    cout << "Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: ";
    cin >> num1 >> num2;
    OrderedPair<int> x;
    
    /* use this before you've implemented the exception handling in the class:
    
    x.setFirst(num1);
    x.setSecond(num2);
    
    */
    
    // use this after you've implemented the exception handling in the class:
    try {
        x.setFirst(num1);
        x.setSecond(num2);
    } catch (OrderedPair<int>::DuplicateMemberError e) {
        x.setFirst(0);
        x.setSecond(0);
    }
    
    cout << "The resulting OrderedPair: ";
    x.print();
    cout << endl;
    
    string str1, str2;
    OrderedPair<string> myList2[10];
    string empty = "";
    
    cout << "default value: ";
    myList2[0].print();
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        myList2[i].setFirst(empty + char('a' + rand() % 26));
        myList2[i].setSecond(empty + char('A' + rand() % 26));
    }
    
    myList2[2] = myList2[0] + myList2[1];
    
    if (myList2[0] < myList2[1]) {
        myList2[0].print();
        cout << " is less than ";
        myList2[1].print();
        cout << endl;
    }
    
    for (int i = 0; i < 10; i++) {
        myList2[i].print();
        cout << endl;
    }
    
    cout << "Enter two strings to use in an OrderedPair.  Make sure they are different strings: ";
    cin >> str1 >> str2;
    OrderedPair<string> y;
    
    /* use this before you've implemented the exception handling in the class:
    
    y.setFirst(str1);
    y.setSecond(str2);
    
    */
    
    // use this after you've implemented the exception handling in the class:
    try {
        y.setFirst(str1);
        y.setSecond(str2);
    } catch (OrderedPair<string>::DuplicateMemberError e) {
        y.setFirst(OrderedPair<string>::DEFAULT_VALUE);
        y.setSecond(OrderedPair<string>::DEFAULT_VALUE);
    }
    
    cout << "The resulting OrderedPair: ";
    y.print();
    cout << endl;
}

/*
 Output:
 
 default value: (0, 0)
 (44, 77) is less than (45, 94)
 (44, 77)
 (45, 94)
 (89, 171)
 (21, 66)
 (5, 84)
 (5, 80)
 (28, 90)
 (30, 76)
 (33, 94)
 (30, 99)
 Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: 2
 4
 The resulting OrderedPair: (2, 4)
 default value: (, )
 (a, Q) is less than (j, Y)
 (a, Q)
 (j, Y)
 (aj, QY)
 (c, I)
 (n, F)
 (j, R)
 (i, P)
 (g, Y)
 (e, G)
 (u, N)
 Enter two strings to use in an OrderedPair.  Make sure they are different strings: hello goodbye
 The resulting OrderedPair: (hello, goodbye)

 */
