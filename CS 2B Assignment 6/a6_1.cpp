/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/4/2019
Instructor: Dave Harden
File Name: a6_1.cpp
 
Program Description: This program has a recursive function, reverseWithinBounds, that takes two indices' letters (which are between two bounds) and reverses them. The program also has another recursive function, reverseCstring, that takes a C-String arugment, reverses it, and calls on the recursive function.
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
using namespace std;

// Recursive function prototypes
void reverseWithinBounds(char a[], int bound1, int bound2);
void reverseCstring(char c[]);

int main()
{
    char str[] = "ABCDE";
    reverseWithinBounds(str, 1, 4);
    
    char cString[] = "SOFTWARE DESIGN";
    reverseCstring(cString);
}






// Recursive function that reverses letters within two indices (between two bounds)
void reverseWithinBounds(char a[], int bound1, int bound2)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    char originalEntry[128] = " ";
    
    int bounds = 0;
    bounds = bound2 - bound1;
    int strCount = strlen(a);
    
    strcpy(originalEntry, a);
    
    cout << "Before reversal: " << endl;
    
    while (count1 <= bound2){
        cout << "a[" << count1 << "] == '" << originalEntry[count1] << "' ";
        count1++;
    }
    
    cout << endl;
    
    if (bounds % 2 != 0){
        while (count2 < (bounds / 2) + (bounds % 2)){
            swap(a[bound1 + count2], a[strCount - (count2 + 1)]);
            count2++;
        }
    } else if (bounds % 2 == 0){
        while (count2 < bounds / 2){
            swap(a[bound1 + count2], a[strCount - (count2 + 1)]);
            count2++;
        }
    }
    
    cout << endl << "After reversal: " << endl;
    
    while (count3 <= bound2){
        cout << "a[" << count3 << "] == '" << a[count3] << "' ";
        count3++;
    }
    
    cout << endl;
}






// Recursive function that reverses c-strings then calls on reverseWithinBounds
void reverseCstring(char c[])
{
    int strCount = 0;
    int count1 = 0;
    strCount = strlen(c);
    
    cout << endl;
    cout << "Original C-String: ";
    
    for (int i = 0; i < strCount; i++){
        cout << c[i];
    }
    
    cout << endl;
    cout << "Reversed C-String: ";
    
    if (strCount % 2 != 0){
        while (count1 < (strCount / 2) + (strCount % 2)){
            swap(c[count1], c[strCount - (count1 + 1)]);
            count1++;
        }
    } else if (strCount % 2 == 0){
        while (count1 < strCount / 2){
            swap(c[count1], c[strCount - (count1 + 1)]);
            count1++;
        }
    }
    
    for (int i = 0; i < strCount; i++){
        cout << c[i];
    }
    
    cout << endl << endl;
    
    reverseWithinBounds(c, 1, (strCount - 1));
}

/*
 Output:
 Before reversal:
 a[0] == 'A' a[1] == 'B' a[2] == 'C' a[3] == 'D' a[4] == 'E'

 After reversal:
 a[0] == 'A' a[1] == 'E' a[2] == 'D' a[3] == 'C' a[4] == 'B'

 Original C-String: SOFTWARE DESIGN
 Reversed C-String: NGISED ERAWTFOS

 Before reversal:
 a[0] == 'N' a[1] == 'G' a[2] == 'I' a[3] == 'S' a[4] == 'E' a[5] == 'D' a[6] == ' ' a[7] == 'E' a[8] == 'R' a[9] == 'A' a[10] == 'W' a[11] == 'T' a[12] == 'F' a[13] == 'O' a[14] == 'S'

 After reversal:
 a[0] == 'N' a[1] == 'S' a[2] == 'O' a[3] == 'F' a[4] == 'T' a[5] == 'W' a[6] == 'A' a[7] == 'R' a[8] == 'E' a[9] == ' ' a[10] == 'D' a[11] == 'E' a[12] == 'S' a[13] == 'I' a[14] == 'G'

 */
