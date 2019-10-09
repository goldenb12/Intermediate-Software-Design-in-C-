/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 10/14/2019
Instructor: Dave Harden
File Name: a3_2.cpp

Program Description: This program will record high-score data for a fictitous game. The program will ask the user to enter the number of scores, create two dynamic arrays of a particular size, ask the user to enter the indicated number of names and scores, and then print the names and scores sorted by score in descending order.
 
*/

#include <iostream>
#include <string>
using namespace std;

// Prototypes for functions
void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main()
{
    const int size = 4;
    cout << "How many scores will you enter?: " << size << endl;
    string names[size];
    int scores[size];
    
    // Initialize arrays
    initializeArrays(names, scores, size);
    
    // Sort arrays
    sortData(names, scores, size);
    
    // Output arrays
    displayData(names, scores, size);
    
    return 0;
}






// initializeArrays function: User will enter name and score for each of the scores
void initializeArrays(string names[], int scores[], int size)
{
    for (int i = 0; i < size; i++){
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> names[i];

        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i];
    }
}






// sortData function: Both arrays will be sorted by score in descending order
void sortData(string names[], int scores[], int size)
{
    string tempName;
    int tempScore;
    bool swapped;

    do{
        swapped = false;
        for (int i = 0; i < size - 1; i++){
            if (scores[i] < scores[i + 1]){
                tempScore = scores[i];
                scores[i] = scores[i + 1];
                scores[i + 1] = tempScore;

                tempName = names[i];
                names[i] = names[i + 1];
                names[i + 1] = tempName;

                swapped = true;
            }
        }
    }
    while (swapped == true);
}






// displayData function: The final list of names and scores will be displayed
void displayData(const string names[], const int scores[], int size)
{
    cout << endl << "Top Scorers: " << endl;

    for (int i = 0; i < size; i++){
        cout << names[i] << ": " << scores[i] << endl;
    }
}

/*
 Output:
 
 How many scores will you enter?: 4
 Enter the name for score #1: Suzy
 Enter the score for score #1: 600
 Enter the name for score #2: Kim
 Enter the score for score #2: 9900
 Enter the name for score #3: Armando
 Enter the score for score #3: 8000
 Enter the name for score #4: Tim
 Enter the score for score #4: 514

 Top scorers:
 Kim: 9900
 Armando: 8000
 Suzy: 600
 Tim: 514
 
 */
