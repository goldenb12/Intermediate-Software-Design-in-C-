#ifndef MYSTRING_H
#define MYSTRING_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 10/21/2019
Instructor: Dave Harden
File Name: mystring.h
 
Program Description: This header file introduces three constructors as public members. MyString() does not have an input paramter, MyString(const char *inDesc) has a string as the input parameter, and MyString(const MyString& right) has the object, MyString, be the input paramter. ~MyString() is introduced as the destructor and it deallocates memory for str. int length() const is introduced as the member function which returns the length of str. There are [] operator overloading operators introduced in this program. char operator[](int index) const takes the input parameter index and returns the value stored str[index]. The index has to be >= 0 and < strlen(str). char& operator[] (int index) takes the input paramter index and returns the reference to str[index]. The index has to be >=0 and strlen(str). friend std::ostream& operator<<(std::ostream& out, const MyString& source) takes two input parameters, std::ostream& out and MyString& source and prints out the string in the source string. friend std::istream& operator>>(std::istream& in, const MyString& target) takes two input parameters, std::istream& in and MyString& target and reads characters from the input stream and stops reading if it places the input string in the private data member. friend bool operator<(const MyString& left, const MyString& right), friend bool operator<=(const MyString& left, const MyString& right), friend bool operator>(const MyString& left, const MyString& right), friend bool operator>=(const MyString& left, const MyString& right), friend bool operator==(const MyString& left, const MyString& right), and friend bool operator!=(const MyString& left, const MyString& right) are the six relational operators that will be supported to be able to compare MyString objects to other MyString objects, as well as MyStrings to c-strings. char *description is the private data member that points to a c-style string.

*/

#include <iostream>
#include <cstring>

namespace cs_mystring {
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
            friend std::ostream& operator<<(std::ostream& out, const MyString& source);
            friend std::istream& operator>>(std::istream& in, MyString& target);
            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator>=(const MyString& left, const MyString& right);
            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator!=(const MyString& left, const MyString& right);
        
        private:
            char *description;
    };
}

#endif
