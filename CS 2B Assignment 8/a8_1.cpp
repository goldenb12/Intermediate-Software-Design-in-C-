/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/18/2019
Instructor: Dave Harden
File Name: a8_1.cpp
 
Program Description: A recent high scores program will be rewritten so that each name/score pair is stored in a struct named highscore. The highscore struct will use a Standard Template Library (STL) vector instead of an array (like the one used in the previous program). Three functions that accept the vector of highscore structs that are used are: void initializeData(vector<highscore>& scores), void sortData(vector<highscore>& scores), and void displayData(const vector<highscore>& scores). Iterators will be used to access items in vectors.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

struct highscore
{
    char names[24];
    int scores;
};






// Prototypes for functions
void getVectorSize(int& size);
void initializeData(vector<highscore>& scores);
void sortData(vector<highscore>& scores);
void displayData(const vector<highscore>& scores);
bool compareByScore(const highscore &score1, const highscore &score2);






int main()
{
    int size;
    getVectorSize(size);
    vector<highscore> scores(size);
    initializeData(scores);
    sortData(scores);
    displayData(scores);
}






// getVectorSize function to get the size of the vector
void getVectorSize(int& size)
{
    cout << "How many scores will you enter?: ";
    cin >> size;
}






// initializeData function takes name and score input from the user
void initializeData(vector<highscore>& scores)
{
    int count = 1;
    
    for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++) {
        cout << "Enter the name for score #" << count << ": ";
        cin >> i->names;
        cout << "Enter the score for score #" << count << ": ";
        cin >> i->scores;
        count++;
    }
    cout << endl;
}






// sortData function uses iterators to access items in the vector to sort the scores
void sortData(vector<highscore>& scores)
{
    vector<highscore>::iterator i;
    vector<highscore>::iterator j;
    
    sort(scores.begin(), scores.end(), compareByScore);
    
    for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++) {
        vector<highscore>::iterator j = i;
        
        for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++) {
            if (i->scores < j->scores){
                j = i;
            }
        }
        swap(i, j);
    }
}






// displayData function displays the names and scores used in the program
void displayData(const vector<highscore>& scores)
{
    cout << "Top Scorers: " << endl;
    for (vector<highscore>::const_iterator i = scores.begin(); i != scores.end(); i++) {
        cout << i->names << ": " << i->scores << endl;
    }
}






// compareByScore function compares functions in the program
bool compareByScore(const highscore &score1, const highscore &score2)
{
    return score1.scores > score2.scores;
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

 Top Scorers:
 Kim: 9900
 Armando: 8000
 Suzy: 600
 Tim: 514
 
 */
