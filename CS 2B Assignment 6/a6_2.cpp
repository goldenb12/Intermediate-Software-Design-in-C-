/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/4/2019
Instructor: Dave Harden
File Name: a6_2.cpp
 
Program Description: Using the MyString class created in an earlier program, this program will have a recursive function, isAPalindrome, that takes a single MyString arugment and two arguments that are bounds on array indices. This function will look at the part of the argument between and including the two bounds and return true if that part of the argument is a palindrome. It will return false if it is not a palindrome. To determine if the user-provided string is a palindrome, the function must consider uppercase and lowercase letters to be the same and punctuation and whitespace characters will be ignored.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <fstream>
using namespace std;

class MyString {
    public:
        MyString();
        MyString(const char *inDesc);
        MyString(const MyString& right);
        ~MyString();
        MyString operator=(const MyString& right);
        int length() const;
        char operator[](int index) const;
        char& operator[](int index);
        friend ostream& operator<<(ostream& out, const MyString& source);
        friend istream& operator>>(istream& in, MyString& target);
        void read(istream& inString, char delimiting);
    
    private:
        char *description;
};






// Prototype for isAPalindrome function
bool isAPalindrome(char str[], int bound1, int bound2);






int main()
{
    char str[256];
    int length;
    
    cout << "Enter a string: ";
    cin.getline(str, 256);
    
    while (strcmp(str, "quit") != 0){
        length = strlen(str);
        
        if (isAPalindrome(str, 0, length - 1)){
            cout << str << " is a palindrome." << endl;
        } else {
        cout << str << " is not a palindrome." << endl;
        }
    
        cout << "Enter a string: ";
        cin.getline(str, 256);
    }
    
    cout << endl;
    return 0;
}






// Function to determine if a string is a palindrome or not
bool isAPalindrome(char str[], int bound1, int bound2)
{
    char character1, character2;
    
    if (bound1 > bound2){
        return true;
    }
    
    while (bound1 <= bound2){
        if (ispunct(str[bound1]) || isspace(str[bound1])){
            bound1++;
        } else {
            break;
        }
    }
    
    while (bound2 >= bound1){
        if (ispunct(str[bound2]) || isspace(str[bound2])){
            bound2--;
        } else {
            break;
        }
    }
    
    character1 = str[bound1];
    character1 = toupper(character1);
    
    character2 = str[bound2];
    character2 = toupper(character2);
    
    if (character1 != character2){
        return false;
    }
    
    bound1++;
    bound2--;
    
    return isAPalindrome(str, bound1, bound2);
}






// Default constructor: No parameter, size of 1, and places empty space
MyString::MyString()
{
    description = new char[1];
    strcpy(description, "");
}
    





// Constructor: Takes a char that's pointed to and sets inDesc to that data. Adds 1 to string length to allow for a null character to be used
MyString::MyString(const char *inDesc)
{
    description = new char[strlen(inDesc) + 1];
    strcpy(description, inDesc);
}






// Constructor that receives data from MyString and adds 1 to string length to allow for a null character to be used
MyString::MyString(const MyString& right)
{
    description = new char[strlen(right.description) + 1];
    strcpy(description, right.description);
}






// Desctructor definition for destrucing an object of any length
MyString::~MyString()
{
    delete [] description;
}






// = operator overloading that takes a MyString value and sets its to a specific MyString position
MyString MyString::operator=(const MyString& right)
{
    if (this != &right){
        delete [] description;
        description = new char[strlen(right.description) + 1];
        strcpy(description, right.description);
    }
    return *this;
}






// String length in int is returned in this function
int MyString::length() const
{
    return (int) strlen(description);
}






// [] overloading makes sure that values are between 0 and string length of description when using MyString
char MyString::operator[](int index) const
{
    assert(index >= 0 && index < strlen(description));
    return description[index];
}






// [] overloading makes sure that values are between 0 and string length of description when not using MyString
char& MyString::operator[](int index)
{
    assert(index >= 0 && index < strlen(description));
    return description[index];
}






// Output operator overloading
ostream& operator<<(ostream& out, const MyString& source)
{
    out << source.description;
    return out;
}






// Input operator overloading
istream& operator>>(istream& in, MyString& target)
{
    char temp[127];
    delete [] target.description;
    in >> temp;
    target.description = new char[strlen(temp) + 1];
    strcpy(target.description, temp);
    return in;
}






// Allows client program to read from specific input file
void MyString::read(istream& target, char delimiting)
{
    char temp[127];
    delete [] description;
    target.getline(temp, 127, delimiting);
    description = new char[strlen(temp) + 1];
    strcpy(description, temp);
}

/*
 Output:
 Enter a string: Able was I, ere I saw Elba
 Able was I, ere I saw Elba is a palindrome.
 Enter a string: peanut butter
 peanut butter is not a palindrome.
 Enter a string: quit

 */
