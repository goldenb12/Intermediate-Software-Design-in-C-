/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 10/28/2019
Instructor: Dave Harden
File Name: mystring.cpp

Program Description: This program will define syntactically correct class, MyString. The "Big-three" member functions will be used since dynamic memory is used in this program. The extraction operator (>>) skips leading spaces and reads characters into a string up to the first whitespace character. 127 characters will be the limit that the function used in the program can read. This allows for a temporary reading into the non-dynamic array and then copied into the dynamic array (data member). The read() function allows the client programmer to specificy the delimiting character. It will be a void function so that it can take two arguments, a stream and the delimiting character, and limit 127 characters imposed on the >> function. The concatenation operator handles either MyString objects or C-Strings on either side of the + operator. The strcpy() function is used to get the left operand into MyString and then the strcat() function is used to append it to the right operand. Concatenation and assignment operators when combined allow for MyStrings being stored on the left-hand side of a += operation, but can have either MyStrings or C-Strings be stored on the right-hand side of a += operation.

*/

#include "mystring.h"
#include <fstream>
#include <cctype>      // for toupper()
#include <string>
#include <cassert>
#include <iostream>
using namespace std;
using namespace cs_mystring;

namespace cs_mystring {
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






    // String concatenation with specific strings
    MyString MyString::operator+=(const MyString& right)
    {
        MyString temp;
        temp = new char[strlen(description) + strlen(right.description) + 1];
        temp = strcat(description, right.description);
        return *this;
    }






    // String concatenation with specified strings and characters
    MyString MyString::operator+=(const char *right)
    {
        MyString temp;
        temp = new char[strlen(description) + strlen(right) + 1];
        temp = strcat(description, right);
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






    // + operator overloading for different parameters
    const MyString operator+(const MyString& left, const MyString& right)
    {
        MyString temp;
        temp = new char[strlen(left.description) + strlen(right.description) + 1];
        strcpy(temp.description, left.description);
        strcat(temp.description, right.description);
        return temp;
    }






    // < operator overloading used to compare types MyString left and right. Returns true if left is less than right
    bool operator<(const MyString& left, const MyString& right)
    {
        return strcmp(left.description, right.description) < 0;
    }






    // < operator overloading used to compare character on the left and type MyString right. Returns true if left is less than right
    bool operator<(const char *left, const MyString& right)
    {
        return strcmp(left, right.description) < 0;
    }






    // < operator overloading used to compare type MyString left and character on the right. Returns true if left is less than right
    bool operator<(const MyString& left, const char *right)
    {
        return strcmp(left.description, right) < 0;
    }






    // <= operator overloading used to compare types MyString left and right. Returns true if left is less than or equal to right
    bool operator<=(const MyString& left, const MyString& right)
    {
        return left < right || left == right;
    }






    // <= operator overloading used to compare character on the left and type MyString right. Returns true if left is less than or equal to right
    bool operator<=(const char *left, const MyString& right)
    {
        return left < right || left == right;
    }






    // <= operator overloading used to compare type MyString left and character on the right. Returns true if left is less than or equal to right
    bool operator<=(const MyString& left, const char *right)
    {
        return left < right || left == right;
    }






    // > operator overloading used to compare types MyString left and right. Returns true if left is greater than right
    bool operator>(const MyString& left, const MyString& right)
    {
        return !(left == right) && !(left < right);
    }






    // > operator overloading used to compare character on the left and type MyString right. Returns true if left is greater than right
    bool operator>(const char *left, const MyString& right)
    {
        return !(left == right) && !(left < right);
    }






    // > operator overloading used to compare type MyString left and character on the right. Returns true if left is greater than right
    bool operator>(const MyString& left, const char *right)
    {
        return !(left == right) && !(left < right);
    }






    // >= operator overloading used to compare types MyString left and right. Returns true if left is greater than or equal to right
    bool operator>=(const MyString& left, const MyString& right)
    {
        return !(left < right);
    }






    /* >= operator overloading used to compare character on the left and type MyString right. Returns true if left is greater than or equal to right */
    bool operator>=(const char *left, const MyString& right)
    {
        return !(left < right);
    }






    /* >= operator overloading used to compare type MyString left and character on the right. Returns true if left is greater than or equal to right */
    bool operator>=(const MyString& left, const char *right)
    {
        return !(left < right);
    }






    // == operator overloading used to compare types MyString left and right. Returns true if left and right are equal
    bool operator==(const MyString& left, const MyString& right)
    {
        return strcmp(left.description, right.description) == 0;
    }






    // == operator overloading used to compare character on the left and type MyString right. Returns true if left and right are equal
    bool operator==(const char *left, const MyString& right)
    {
        return strcmp(left, right.description) == 0;
    }






    // == operator overloading used to compare type MyString left and character on the right. Returns true if left and right are equal
    bool operator==(const MyString& left, const char *right)
    {
        return strcmp(left.description, right) == 0;
    }






    // != operator overloading used to compare types MyString left and right. Returns true when left and right are not equal
    bool operator!=(const MyString& left, const MyString& right)
    {
        return !(left == right);
    }






    // != operator overloading used to compare character on the left and type MyString right. Returns true when left and right are not equal
    bool operator!=(const char *left, const MyString& right)
    {
        return !(left == right);
    }






    // != operator overloading used to compare type MyString left and character on the right. Returns true when left and right are not equal
    bool operator!=(const MyString& left, const char *right)
    {
        return !(left == right);
    }
}






// CLIENT PROGRAM

/*
 * -------------------
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
 * The ConcatTest functions checks the overloaded + and += operators that
 * do string concatenation.
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
 
#include "mystring.h"
#include <fstream>
#include <cctype>      // for toupper()
#include <string>
#include <cassert>
#include <iostream>
using namespace std;
using namespace cs_mystring;

void BasicTest();
void RelationTest();
void ConcatTest();
void CopyTest();
MyString AppendTest(const MyString& ref, MyString val);
string boolString(bool convertMe);


int main()
{
    BasicTest();
    RelationTest();
    ConcatTest();
    CopyTest();
}


string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}


void BasicTest()
{
    MyString s;
    int stringLength;
    cout << "----- Testing basic String creation & printing" << endl;
    
    const MyString strs[] =
                {MyString("Wow"), MyString("C++ is neat!"),
                 MyString(""), MyString("a-z")};
                 
                 
    for (int i = 0; i < 4; i++){
        cout << "string [" << i <<"] = " << strs[i] << endl;
    }



    cout << endl << "----- Now reading MyStrings from file" << endl;
    
    cout << endl << "----- first, word by word" << endl;
    ifstream in("mystring.txt");
    assert(in);
    while (in.peek() == '#'){
        in.ignore(128, '\n');
    }
    in >> s;
    while (in) {
        cout << "Read string = " << s << endl;
        in >> s;
    }
    in.close();

    
   
    cout << endl << "----- now, line by line" << endl;
    ifstream in2("mystring.txt");
    assert(in2);
    while (in2.peek() == '#'){
        in2.ignore(128, '\n');
    }
    s.read(in2, '\n');
    while (in2) {
        cout << "Read string = " << s << endl;
        s.read(in2, '\n');
    }
    in2.close();




    cout << endl << "----- Testing access to characters (using const)" << endl;
    const MyString s1("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Whole string is " << s1 << endl;
    cout << "now char by char: ";
    stringLength = s1.length();
    for (int i = 0; i < stringLength; i++){
        cout << s1[i];
    }



    cout << endl << "----- Testing access to characters (using non-const)" << endl;
    MyString s2("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Start with " << s2;
    stringLength = s2.length();
    for (int i = 0; i < stringLength; i++){
        s2[i] = toupper(s2[i]);
    }
    cout << " and convert to " << s2 << endl;
}









void RelationTest()
{
    cout << "\n----- Testing relational operators between MyStrings\n";

    const MyString strs[] =
        {MyString("app"), MyString("apple"), MyString(""),
        MyString("Banana"), MyString("Banana")};

    for (int i = 0; i < 4; i++) {
        cout << "Comparing " << strs[i] << " to " << strs[i+1] << endl;
        cout << "\tIs left < right? " << boolString(strs[i] < strs[i+1]) << endl;
        cout << "\tIs left <= right? " << boolString(strs[i] <= strs[i+1]) << endl;
        cout << "\tIs left > right? " << boolString(strs[i] > strs[i+1]) << endl;
        cout << "\tIs left >= right? " << boolString(strs[i] >= strs[i+1]) << endl;
        cout << "\tDoes left == right? " << boolString(strs[i] == strs[i+1]) << endl;
        cout << "\tDoes left != right ? " << boolString(strs[i] != strs[i+1]) << endl;
    }
 
    cout << "\n----- Testing relations between MyStrings and char *\n";
    MyString s("he");
    const char *t = "hello";
    cout << "Comparing " << s << " to " << t << endl;
    cout << "\tIs left < right? " << boolString(s < t) << endl;
    cout << "\tIs left <= right? " << boolString(s <= t) << endl;
    cout << "\tIs left > right? " << boolString(s > t) << endl;
    cout << "\tIs left >= right? " << boolString(s >= t) << endl;
    cout << "\tDoes left == right? " << boolString(s == t) << endl;
    cout << "\tDoes left != right ? " << boolString(s != t) << endl;
    
    MyString u("wackity");
    const char *v = "why";
    cout << "Comparing " << v << " to " << u << endl;
    cout << "\tIs left < right? " << boolString(v < u) << endl;
    cout << "\tIs left <= right? " << boolString(v <= u) << endl;
    cout << "\tIs left > right? " << boolString(v > u) << endl;
    cout << "\tIs left >= right? " << boolString(v >= u) << endl;
    cout << "\tDoes left == right? " << boolString(v == u) << endl;
    cout << "\tDoes left != right ? " << boolString(v != u) << endl;

}




void ConcatTest()
{
    cout << "\n----- Testing concatentation on MyStrings\n";
    
    const MyString s[] =
            {MyString("outrageous"), MyString("milk"), MyString(""),
            MyString("cow"), MyString("bell")};
    
    for (int i = 0; i < 4; i++) {
        cout << s[i] << " + " << s[i+1] << " = " << s[i] + s[i+1] << endl;
    }
    
    cout << "\n----- Testing concatentation between MyString and char *\n";
    
    const MyString a("abcde");
    const char *b = "XYZ";
    cout << a << " + " << b << " = " << a + b << endl;
    cout << b << " + " << a << " = " << b + a << endl;
    
    cout << "\n----- Testing shorthand concat/assign on MyStrings\n";
    
    MyString s2[] =
            {MyString("who"), MyString("what"), MyString("WHEN"),
            MyString("Where"), MyString("why")};
    
    for (int i = 0; i < 4; i++) {
        cout << s2[i] << " += " << s2[i+1] << " = ";
        cout << (s2[i] += s2[i+1]) << "and";
        cout << s2[i] << endl;
    }

    cout << "\n----- Testing shorthand concat/assign using char *\n";
    MyString u("I love ");
    const char *v = "programming";
    cout << u << " += " << v << " = ";
    cout << (u += v) << endl;
}









MyString AppendTest(const MyString& ref, MyString val)
{
    val[0] = 'B';
    return val + ref;
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

 ----- Now reading MyStrings from file

 ----- first, word by word
 Read string = The
 Read string = first
 Read string = time
 Read string = we
 Read string = will
 Read string = read
 Read string = individual
 Read string = words,
 Read string = next
 Read string = we
 Read string = read
 Read string = whole
 Read string = lines

 ----- now, line by line
 Read string = The  first  time  we  will
 Read string =     read individual words, next
 Read string = we read whole lines

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

 ----- Testing concatentation on MyStrings
 outrageous + milk = outrageousmilk
 milk +  = milk
  + cow = cow
 cow + bell = cowbell

 ----- Testing concatentation between MyString and char *
 abcde + XYZ = abcdeXYZ
 XYZ + abcde = XYZabcde

 ----- Testing shorthand concat/assign on MyStrings
 who += what = whowhatandwhowhat
 what += WHEN = whatWHENandwhatWHEN
 WHEN += Where = WHENWhereandWHENWhere
 Where += why = WherewhyandWherewhy

 ----- Testing shorthand concat/assign using char *
 I love  += programming = I love programming

 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is BinkyBoo
 val is winky
 after assign,  val is BinkyBoo
 
 */
