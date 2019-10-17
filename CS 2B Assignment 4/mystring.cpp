/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 10/21/2019
Instructor: Dave Harden
File Name: mystring.cpp
*/

#include "mystring.h"
#include <cctype>      // for toupper()
#include <iostream>
#include <string>
using namespace std;
using namespace cs_mystring;

namespace cs_mystring {
    // Default constructor: No parameter, size of 1, and places empty space
    MyString::MyString()
    {
        description = new char[1];
        strcpy(description, "");
    }
        
    




    /* Constructor: Takes a char that's pointed to and sets inDesc to that data. Adds 1 to string length to allow for a null character to be used */
    MyString::MyString(const char *inDesc)
    {
        description = new char[strlen(inDesc) + 1];
        strcpy(description, inDesc);
    }






    /* Constructor that receives data from MyString and adds 1 to string length to allow for a null character to be used */
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






    /* = operator overloading that takes a MyString value and sets its to a specific MyString position */
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






    /* [] overloading makes sure that values are between 0 and string length of description when using MyString */
    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(description));
        return description[index];
    }






    /* [] overloading makes sure that values are between 0 and string length of description when not using MyString */
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





    
    /* < operator overloading used to compare types MyString left and right. Returns true if left is less than right */
    bool operator<(const MyString& left, const MyString& right)
    {
        return strcmp(left.description, right.description) < 0;
    }






    /* <= operator overloading used to compare types MyString left and right. Returns true if left is less than or equal to right */
    bool operator<=(const MyString& left, const MyString& right)
    {
        return left < right || left == right;
    }






    /* > operator overloading used to compare types MyString left and right. Returns true if left is greater than right */
    bool operator>(const MyString& left, const MyString& right)
    {
        return !(left == right) && !(left < right);
    }






    /* >= operator overloading used to compare types MyString left and right. Returns true if left is greater than or equal to right */
    bool operator>=(const MyString& left, const MyString& right)
    {
        return !(left < right);
    }






    /* == operator overloading used to compare types MyString left and right. Returns true if left and right are equal */
    bool operator==(const MyString& left, const MyString& right)
    {
        return strcmp(left.description, right.description) == 0;
    }






    /* != operator overloading used to compare types MyString left and right. Returns true when left and right are not equal */
    bool operator!=(const MyString& left, const MyString& right)
    {
        return !(left == right);
    }
}






// CLIENT PROGRAM
/*
 * These functions are designed to help you test your MyString objects,
 * as well as show the client usage of the class.
 *
 * The BasicTest function builds an array of strings using various
 * constructor options and prints them out.  It also uses the String
 * stream operations to read some strings from a data file.
 *
 * The RelationTest function checks out the basic relational operations
 * (==, !=, <, etc) on Strings and char *s.
 *
 *
 * The CopyTest tries out the copy constructor and assignment operators
 * to make sure they do a true deep copy.
 *
 * Although not exhaustive, these tests will help you to exercise the basic
 * functionality of the class and show you how a client might use it.
 *
 * While you are developing your MyString class, you might find it
 * easier to comment out functions you are ready for, so that you don't
 * get lots of compile/link complaints.
*/

void BasicTest();
void RelationTest();
void CopyTest();
MyString AppendTest(const MyString& ref, MyString val);
string boolString(bool convertMe);

int main()
{
    BasicTest();
    RelationTest();
    CopyTest();
}





void BasicTest()
{
    MyString s;
    cout << "----- Testing basic String creation & printing" << endl;
    
    const MyString strs[] =
                {MyString("Wow"), MyString("C++ is neat!"),
                 MyString(""), MyString("a-z")};
                         
    for (int i = 0; i < 4; i++){
        cout << "string [" << i <<"] = " << strs[i] << endl;
    }

    cout << endl << "----- Testing access to characters (using const)" << endl;
    const MyString s1("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Whole string is " << s1 << endl;
    cout << "now char by char: ";
    for (int i = 0; i < s1.length(); i++){
        cout << s1[i];
    }

    cout << endl << "----- Testing access to characters (using non-const)" << endl;
    MyString s2("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Start with " << s2;
    for (int i = 0; i < s2.length(); i++){
        s2[i] = toupper(s2[i]);
    }
    cout << " and convert to " << s2 << endl;
}





string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}





void RelationTest()
{
    cout << "\n----- Testing relational operators between MyStrings\n";

    const MyString strs[] =
        {MyString("app"), MyString("apple"), MyString(""),
        MyString("Banana"), MyString("Banana")};

    for (int i = 0; i < 4; i++) {
        cout << "Comparing " << strs[i] << " to " << strs[i+1] << endl;
        cout << "    Is left < right? " << boolString(strs[i] < strs[i+1]) << endl;
        cout << "    Is left <= right? " << boolString(strs[i] <= strs[i+1]) << endl;
        cout << "    Is left > right? " << boolString(strs[i] > strs[i+1]) << endl;
        cout << "    Is left >= right? " << boolString(strs[i] >= strs[i+1]) << endl;
        cout << "    Does left == right? " << boolString(strs[i] == strs[i+1]) << endl;
        cout << "    Does left != right ? " << boolString(strs[i] != strs[i+1]) << endl;
    }
 
    cout << "\n----- Testing relations between MyStrings and char *\n";
    MyString s("he");
    const char *t = "hello";
    cout << "Comparing " << s << " to " << t << endl;
    cout << "    Is left < right? " << boolString(s < t) << endl;
    cout << "    Is left <= right? " << boolString(s <= t) << endl;
    cout << "    Is left > right? " << boolString(s > t) << endl;
    cout << "    Is left >= right? " << boolString(s >= t) << endl;
    cout << "    Does left == right? " << boolString(s == t) << endl;
    cout << "    Does left != right ? " << boolString(s != t) << endl;
    
    MyString u("wackity");
    const char *v = "why";
    cout << "Comparing " << v << " to " << u << endl;
    cout << "    Is left < right? " << boolString(v < u) << endl;
    cout << "    Is left <= right? " << boolString(v <= u) << endl;
    cout << "    Is left > right? " << boolString(v > u) << endl;
    cout << "    Is left >= right? " << boolString(v >= u) << endl;
    cout << "    Does left == right? " << boolString(v == u) << endl;
    cout << "    Does left != right ? " << boolString(v != u) << endl;
}





MyString AppendTest(const MyString& ref, MyString val)
{
    val[0] = 'B';
    return val;
}





void CopyTest()
{
    cout << "\n----- Testing copy constructor and operator= on MyStrings\n";

    MyString orig("cake");
    
    MyString copy(orig);    // invoke copy constructor

    copy[0] = 'f';  // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy << endl;
    
    MyString copy2;      // makes an empty string
    
    copy2 = orig;        // invoke operator=
    copy2[0] = 'f';      // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy2 << endl;
    
    copy2 = "Copy Cat";
    copy2 = copy2;        // copy onto self and see what happens
    cout << "after self assignment, copy is " << copy2 << endl;
    
    cout << "Testing pass & return MyStrings by value and ref" << endl;
    MyString val = "winky";
    MyString sum = AppendTest("Boo", val);
    cout << "after calling Append, sum is " << sum << endl;
    cout << "val is " << val << endl;
    val = sum;
    cout << "after assign,  val is " << val << endl;
}






/*
 Output:
 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z

 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

 ----- Testing relational operators between MyStrings
 Comparing app to apple
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing apple to
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing  to Banana
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing Banana to Banana
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false

 ----- Testing relations between MyStrings and char *
 Comparing he to hello
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing why to wackity
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true

 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is Binky
 val is winky
 after assign,  val is Binky

 */
