
#ifndef MYSTRING_H
#define MYSTRING_H

/*
 Name: Brandon Goldenberg
 Class: Foothill College CS 2B
 Date: 10/28/2019
 Instructor: Dave Harden
 File Name: mystring.h

 This is the header file for the class, MyString, which takes C-Strings that are read, printed, and stored using dynamic memory. C-Strings will be compared alphabetically using the relation operators in this program.
 
 MyString();
 pre: This is the default constructor.
 post: Sets the default string in the program to a space of memory size 1.
 
 MyString(const char *inDesc);
 pre: This is a C-String pointer.
 post: It dynamically allocates memory for data and copies that data into MyString.

 MyString(const MyString& right);
 pre: Const C-Strings are stored with dynamic memory allocation.
 post: MyString's argument is copied.
 
 ~MyString();
 pre: None.
 post: Deallocates memory that an object was pointing to.
 
 MyString operator=(const MyString& right);
 pre: The C-String is stored with dynamic memory allocation.
 post: The string's variables that pointer is pointing to are copied by overloading the operator.
 
 MyString operator+=(const MyString& right);
 pre: The C-String is stored with dynamic memory allocation.
 post: The string's variable that the pointer is pointing to are concatenated and assigned (on the right side).
 
 MyString operator+=(const char *right);
 pre: The C-String is stored with dynamic memory allocation.
 post: The character data is added to MyString data using the += operator.
 
 int length() const;
 pre: This is a C-String.
 post: A number of letters within a C-String are returned.
 
 char operator[](int index) const;
 pre: A const object is called and its index is checked within the C-String's bounds.
 post: Specific characters are returned within a C-String and specific letters are returned at the index.
 
 char& operator[](int index);
 pre: A non-const object is called and its index is checked within the C-String's bounds.
 post: The reference to char (changing value) is returned.
 
 friend std::ostream& operator<<(std::ostream& out, const MyString& source);
 pre: A string is read as a C-String and output file stream is out.
 post: Outputs C-String with an insertion operator.
 
 friend std::istream& operator>>(std::istream& in, MyString& target);
 pre: The extraction operator is used to read a C-String from an external file.
 post: A C-String from the external file is returned.
 
 void read(std::istream& inString, char delimiting);
 pre: An input file stream is read and stops at client's specified delimiter.
 post: C-Strings read from the external file is returned.
  
 friend const MyString operator+(const MyString& left, const MyString& right);
 pre: The C-String is stored with dynamic memory allocation.
 post: MyString concatenation is done by using the + operator to handle either MyString objects or C-Strings on either side of the operator.

 friend bool operator<(const MyString& left, const MyString& right);
 pre: Two MyStrings must be used.
 post: Two MyStrings are compared to one another to see if left is less than right. The MyStrings will not change due to the const keyword.
 
 friend bool operator<(const char *left, const MyString& right);
 pre: A char and a MyString must be used.
 post: A function with a char data type is compared to a MyString to if it is less than the right-hand side.

 friend bool operator<(const MyString& left, const char *right);
 pre: A MyString and char must be used.
 post: A MyString is compared to a function with a char data type to see if it is less than the right-hand side.
 
 friend bool operator<=(const MyString& left, const MyString& right);
 pre: Two MyStrings must be used.
 post: Two MyStrings are compared to one another to see if left is less than or equal to right. The MyStrings will not change due to the const keyword.
  
 friend bool operator<=(const char *left, const MyString& right);
 pre: A char and a MyString must be used.
 post: A function with a char data type is compared to a MyString to if it is less than or equal to the right-hand side.

 friend bool operator<=(const MyString& left, const char *right);
 pre: A MyString and char must be used.
 post: A MyString is compared to a function with a char data type to see if it is less than or equal to the right-hand side.
 
 friend bool operator>(const MyString& left, const MyString& right);
 pre: Two MyStrings must be used.
 post: Two MyStrings are compared to one another to see if left is greater than right. The MyStrings will not change due to the const keyword.
  
 friend bool operator>(const char *left, const MyString& right);
 pre: A char and a MyString must be used.
 post: A function with a char data type is compared to a MyString to if it is greater than the right-hand side.

 friend bool operator>(const MyString& left, const char *right);
 pre: A MyString and char must be used.
 post: A MyString is compared to a function with a char data type to see if it is greater than the right-hand side.
 
 friend bool operator>=(const MyString& left, const MyString& right);
 pre: Two MyStrings must be used.
 post: Two MyStrings are compared to one another to see if left is greater than or equal to right. The MyStrings will not change due to the const keyword.
   
 friend bool operator>=(const char *left, const MyString& right);
 pre: A char and a MyString must be used.
 post: A function with a char data type is compared to a MyString to if it is greater than or equal to the right-hand side.

 friend bool operator>=(const MyString& left, const char *right);
 pre: A MyString and char must be used.
 post: A MyString is compared to a function with a char data type to see if it is greater than or equal to the right-hand side.
 
 friend bool operator==(const MyString& left, const MyString& right);
 pre: Two MyStrings must be used.
 post: Two MyStrings are compared to one another to see if left is equal to right. The MyStrings will not change due to the const keyword.
   
 friend bool operator==(const char *left, const MyString& right);
 pre: A char and a MyString must be used.
 post: A function with a char data type is compared to a MyString to if it is equal to the right-hand side.

 friend bool operator==(const MyString& left, const char *right);
 pre: A MyString and char must be used.
 post: A MyString is compared to a function with a char data type to see if it is equal to the right-hand side.
 
 friend bool operator!=(const MyString& left, const MyString& right);
 pre: Two MyStrings must be used.
 post: Two MyStrings are compared to one another to see if left is not equal to right. The MyStrings will not change due to the const keyword.
    
 friend bool operator!=(const char *left, const MyString& right);
 pre: A char and a MyString must be used.
 post: A function with a char data type is compared to a MyString to if it is not equal to the right-hand side.

 friend bool operator!=(const MyString& left, const char *right);
 pre: A MyString and char must be used.
 post: A MyString is compared to a function with a char data type to see if it is not equal to the right-hand side.

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
            MyString operator+=(const MyString& right);
            MyString operator+=(const char *right);
            int length() const;
            char operator[](int index) const;
            char& operator[](int index);
            friend std::ostream& operator<<(std::ostream& out, const MyString& source);
            friend std::istream& operator>>(std::istream& in, MyString& target);
            void read(std::istream& inString, char delimiting);
            friend const MyString operator+(const MyString& left, const MyString& right);
            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator<(const char *left, const MyString& right);
            friend bool operator<(const MyString& left, const char *right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator<=(const char *left, const MyString& right);
            friend bool operator<=(const MyString& left, const char *right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator>(const char *left, const MyString& right);
            friend bool operator>(const MyString& left, const char *right);
            friend bool operator>=(const MyString& left, const MyString& right);
            friend bool operator>=(const char *left, const MyString& right);
            friend bool operator>=(const MyString& left, const char *right);
            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator==(const char *left, const MyString& right);
            friend bool operator==(const MyString& left, const char *right);
            friend bool operator!=(const MyString& left, const MyString& right);
            friend bool operator!=(const char *left, const MyString& right);
            friend bool operator!=(const MyString& left, const char *right);
        
        private:
            char *description;
    };
}

#endif
