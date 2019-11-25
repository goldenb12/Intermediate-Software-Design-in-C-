/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/25/2019
Instructor: Dave Harden
File Name: sequenceclient.cpp

Program Description: Each of the different functions in this program will test parts of the Sequence class and return a certain number of points to indicate how much of the test passed.  Descriptions and printed statements will show what the result of each tests are.
*/

#include <iostream>
#include <cstdlib>
#include "sequence.h"
using namespace std;
using namespace cs_sequence;

int main() {
    Sequence s;
    for (int i = 0; i < 6; i++) {
        s.insert(i);
    }
    
    for (s.start(); s.is_item(); s.advance()) {
        cout << s.current() << " ";
    }
    
    cout << endl;
}

/*
 Output:
 5 4 3 2 1 0 
 */
