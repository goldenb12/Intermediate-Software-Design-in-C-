/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/4/2019
Instructor: Dave Harden
File Name: a6_3.cpp
 
Program Description: This program has a recursive function, sortData, which sorts a list of numbers and returns them in ascending order. The helper function, indexOfSmallest, and the function, displayData, print the output.
 */

#include <iostream>
#include <algorithm>
using namespace std;

// Prototypes for functions
void sortData(int scores[], int size);
int indexOfSmallest(int numbers[], int startingIndex, int size);
void displayData(const int numbers[], int size);

int main()
{
    int list[] = {5, 1, 20, 10, 100, 50};
    int size = 6;
    
    sortData(list, size);
    displayData(list, size);
}






// Recursive function definition
void sortData(int numbers[], int size)
{
    int count = 0;
    int index = 0;
    
    if (size == 1){
        cout << numbers[0];
    } else {
        while (count != (size - 1)){
            index = indexOfSmallest(numbers, count, size);
            swap(numbers[index], numbers[count]);
            count++;
        }
    }
}






// Helper function definition
int indexOfSmallest(int numbers[], int count, int size)
{
    int targetIndex = count;
    int count2 = count + 1;
    
    for (int count2 = count + 1; count2 < size; count2++){
        if (numbers[count2] < numbers[targetIndex]){
            targetIndex = count2;
        }
    }
    return targetIndex;
}






// Function definition used for printing the output
void displayData(const int numbers[], int size)
{
    int count = 0;
    while (count != size){
        cout << numbers[count] << endl;
        count++;
    }
}

/*
 Output:
 1
 5
 10
 20
 50
 100
 */
