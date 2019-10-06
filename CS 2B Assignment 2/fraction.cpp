/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 10/7/2019
Instructor: Dave Harden
File Name: fraction.cpp

Program Description: "numerator" and "denominator" integer functions are two of the three private data member functions in the program. The void "simplify()" function is the other private data member function and it's used to reduce a Fraction to its lowest form. To make sure that the denominator is not set to 0, an assert statement, assert(inDenominator != 0), is used. The header used for assert() is #include <cassert>. An overloaded stream operator << is printed in this program. Six relational operators (<, <=, >, >=, ==, !=) will be supported in this program and used to compare Fractions to one another as well as being compared to integers. Either Fractions or integers can appear on either side of the binary operator. One function is used for each operator. Four basic arithmetic operations (+, -, *, /) will be supported in this program and will allow Fractions to be combined with another as well as being combined with integers. Either Fractions or integers can appear on either side of the binary operator. One function is used for each operator. No special handling is needed in the case of dividing by a Fraction that is equal to 0.  The client will get a runtime error if they attempt to handle this case. Shorthand arithmetic operators (+=, -=, *=, /=) will be implemented in this program. Fractions can appear on the left-hand side of the operator, and Fractions or integers can appear on the right-hand side of the operator. The increment and decrement (++, --) operators will be supported in both prefix and postfix form for Fractions.

*/

#include <iostream>
#include "fraction.h"
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
using namespace cs_fraction;

namespace cs_fraction {
    // Stream insertion operator overloading
    ostream& operator<<(ostream& out, const Fraction& second_Fraction)
    {
        if (abs(second_Fraction.numerator) >= abs(second_Fraction.denominator)){
            out << second_Fraction.numerator / second_Fraction.denominator;
            if (second_Fraction.numerator % second_Fraction.denominator != 0){
                out << "+" << abs(second_Fraction.numerator % second_Fraction.denominator) << "/" << second_Fraction.denominator;
            }
        } else if (second_Fraction.numerator == 0){
            out << 0;
        } else {
            out << second_Fraction.numerator << "/" << second_Fraction.denominator;
        }
        return out;
    }






    // Stream insertion operator overloading
    istream& operator>>(istream& in, Fraction& second_Fraction)
    {
        int temp = 0;
        second_Fraction.denominator = 1;
        in >> second_Fraction.numerator;
        
        if (in.peek() == '+'){
            in.ignore();
            temp = second_Fraction.numerator;
            in >> second_Fraction.numerator;
        }
        
        if (in.peek() == '/'){
            in.ignore();
            in >> second_Fraction.denominator;
        }
        
        if (temp < 0){
            second_Fraction.numerator *= -1;
        }
    
        second_Fraction.numerator += temp * second_Fraction.denominator;
        second_Fraction.simplify();
        return in;
    }






    // Operator overloading using a scope resolution operator
    Fraction::Fraction(int inNumerator, int inDenominator)
    {
        assert(inDenominator != 0);
        numerator = inNumerator;
        denominator = inDenominator;
        this->simplify();
    };






    // Relational operator < function overloading
    bool operator<(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        return (first_Fraction.numerator * second_Fraction.denominator < second_Fraction.numerator * first_Fraction.denominator);
    }






    // Relational operator <= function overloading
    bool operator<=(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        return (first_Fraction.numerator * second_Fraction.denominator <= second_Fraction.numerator * first_Fraction.denominator);
    }






    // Relational operator > function overloading
    bool operator>(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        return (first_Fraction.numerator * second_Fraction.denominator > second_Fraction.numerator * first_Fraction.denominator);
    }






    // Relational operator >= function overloading
    bool operator>=(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        return (first_Fraction.numerator * second_Fraction.denominator >= second_Fraction.numerator * first_Fraction.denominator);
    }






    // Relational operator == function overloading
    bool operator==(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        return (first_Fraction.numerator * second_Fraction.denominator == second_Fraction.numerator * first_Fraction.denominator);
    }






    // Relational operator != function overloading
    bool operator!=(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        return (first_Fraction.numerator * second_Fraction.denominator != second_Fraction.numerator * first_Fraction.denominator);
    }






    // Basic arithmetic operator + function overloading
    Fraction operator+(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        Fraction result(first_Fraction.numerator * second_Fraction.denominator + second_Fraction.numerator *                                                  first_Fraction.denominator, first_Fraction.denominator * second_Fraction.denominator);
        return result;
    }






    // Basic arithmetic operator - function overloading
    Fraction operator-(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        Fraction result(first_Fraction.numerator * second_Fraction.denominator - second_Fraction.numerator *                                                  first_Fraction.denominator, first_Fraction.denominator * second_Fraction.denominator);
        return result;
    }






    // Basic arithmetic operator * function overloading
    Fraction operator*(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        Fraction result(first_Fraction.numerator * second_Fraction.numerator, first_Fraction.denominator * second_Fraction.denominator);
        return result;
    }






    // Basic arithmetic operator / function overloading
    Fraction operator/(const Fraction& first_Fraction, const Fraction& second_Fraction)
    {
        Fraction result(first_Fraction.numerator * second_Fraction.denominator, first_Fraction.denominator * second_Fraction.numerator);
        return result;
    }






    // Shorthand arithmetic operator += function overloading
    Fraction Fraction::operator+=(const Fraction& second_Fraction)
    {
        *this = *this + second_Fraction;
        return *this;
    }






    // Shorthand arithmetic operator -= function overloading
    Fraction Fraction::operator-=(const Fraction& second_Fraction)
    {
        *this = *this - second_Fraction;
        return *this;
    }






    // Shorthand arithmetic operator *= function overloading
    Fraction Fraction::operator*=(const Fraction& second_Fraction)
    {
        *this = *this * second_Fraction;
        return *this;
    }






    // Shorthand arithmetic operator /= function overloading
    Fraction Fraction::operator/=(const Fraction& second_Fraction)
    {
        *this = *this / second_Fraction;
        return *this;
    }






    // Increment operator function overloading
    Fraction Fraction::operator++(int)
    {
        Fraction temp(numerator, denominator);
        numerator += denominator;
        return temp;
    }






    // Increment operator function overloading
    Fraction Fraction::operator++()
    {
        numerator += denominator;
        return *this;
    }






    // Decrement operator function overloading
    Fraction Fraction::operator--(int)
    {
        Fraction temp(numerator, denominator);
        numerator -= denominator;
        return temp;
    }






    // Decrement operator function overloading
    Fraction Fraction::operator--()
    {
        numerator -= denominator;
        return *this;
    }






    /* Void Fraction::simplify() function shown here in the first if statement makes sure that the denominator is positive. Simplify() will also check to see i is a prime number or not. It will also look for factors of i. Although recursion is a topic taught later in this course, I went ahead and read information about it. It is an imporant concept in programming, and its utilization in this program is important in being able to find the correct program output. */
    void Fraction::simplify()
    {
        if (denominator < 0){
            numerator *= -1;
            denominator *= -1;
        }
        
        long i = (min(abs(numerator), abs(denominator)));
        if ( i != 0){
            if (numerator % i == 0 && denominator % i == 0){
                numerator /= i;
                denominator /= i;
            } else {
                for (long j = i / 2; j > 1; j--){
                    if (numerator % j == 0 && denominator % j == 0){
                        numerator /= j;
                        denominator /= j;
                        j = (min(numerator, denominator)) / 2;
                    }
                }
            }
        }
    }
}






// CLIENT PROGRAM

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
bool eof(ifstream& in);
string boolString(bool convertMe);


int main()
{
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();
}





void BasicTest()
{
    cout << "\n----- Testing basic Fraction creation & printing\n";
    cout << "(Fractions should be in reduced form, and as mixed numbers.)\n";
    
    const Fraction fr[] = {Fraction(4, 8), Fraction(-15,21),
                           Fraction(10), Fraction(12, -3),
                           Fraction(), Fraction(28, 6), Fraction(0, 12)};
                                                   
    for (int i = 0; i < 7; i++){
        cout << "Fraction [" << i <<"] = " << fr[i] << endl;
    }
        
        
    cout << "\n----- Now reading Fractions from file\n";
    ifstream in("Fraction.txt");
    assert(in);
    while (!eof(in)) {
        Fraction f;
        if (in.peek() == '#') {
            in.ignore(128, '\n');                       //skip this line, it's a comment
        } else {
            in >> f;
            cout << "Read Fraction = " << f << endl;
        }
    }
}


bool eof(ifstream& in)
{
    char ch;
    in >> ch;
    in.putback(ch);
    return !in;
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
    cout << "\n----- Testing relational operators between Fractions\n";

    const Fraction fr[] =  {Fraction(3, 6), Fraction(-15,30), Fraction(1,2),
                            Fraction(1,10), Fraction(0,1), Fraction(0,2)};

    for (int i = 0; i < 5; i++) {
          cout << "Comparing " << fr[i] << " to " << fr[i+1] << endl;
          cout << "\tIs left < right? " << boolString(fr[i] < fr[i+1]) << endl;
          cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i+1]) << endl;
          cout << "\tIs left > right? " << boolString(fr[i] > fr[i+1]) << endl;
          cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i+1]) << endl;
          cout << "\tDoes left == right? " << boolString(fr[i] == fr[i+1]) << endl;
          cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i+1]) << endl;
    }
 
    cout << "\n----- Testing relations between Fractions and integers\n";
    Fraction f(-3,6);
    int num = 2;
    cout << "Comparing " << f << " to " << num << endl;
    cout << "\tIs left < right? " << boolString(f < num) << endl;
    cout << "\tIs left <= right? " << boolString(f <= num) << endl;
    cout << "\tIs left > right? " << boolString(f > num) << endl;
    cout << "\tIs left >= right? " << boolString(f >= num) << endl;
    cout << "\tDoes left == right? " << boolString(f == num) << endl;
    cout << "\tDoes left != right ? " << boolString(f != num) << endl;
    
    Fraction g(1,4);
    num = -3;
    cout << "Comparing " << num << " to " << g << endl;
    cout << "\tIs left < right? " << boolString(num < g) << endl;
    cout << "\tIs left <= right? " << boolString(num <= g) << endl;
    cout << "\tIs left > right? " << boolString(num > g) << endl;
    cout << "\tIs left >= right? " << boolString(num >= g) << endl;
    cout << "\tDoes left == right? " << boolString(num == g) << endl;
    cout << "\tDoes left != right ? " << boolString(num != g) << endl;
}





void BinaryMathTest()
{
    cout << "\n----- Testing binary arithmetic between Fractions\n";
    
    const Fraction fr[] = {Fraction(1, 6), Fraction(1,3),
                           Fraction(-2,3), Fraction(5), Fraction(-4,3)};

    for (int i = 0; i < 4; i++) {
          cout << fr[i] << " + " << fr[i+1] << " = " << fr[i] + fr[i+1] << endl;
          cout << fr[i] << " - " << fr[i+1] << " = " << fr[i] - fr[i+1] << endl;
          cout << fr[i] << " * " << fr[i+1] << " = " << fr[i] * fr[i+1] << endl;
          cout << fr[i] << " / " << fr[i+1] << " = " << fr[i] / fr[i+1] << endl;
    }

    cout << "\n----- Testing arithmetic between Fractions and integers\n";
    Fraction f(-1, 2);
    int num = 4;
    cout << f << " + " << num << " = " << f + num << endl;
    cout << f << " - " << num << " = " << f - num << endl;
    cout << f << " * " << num << " = " << f * num << endl;
    cout << f << " / " << num << " = " << f / num << endl;
     
    Fraction g(-1, 2);
    num = 3;
    cout << num << " + " << g << " = " << num + g << endl;
    cout << num << " - " << g << " = " << num - g << endl;
    cout << num << " * " << g << " = " << num * g << endl;
    cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{
    cout << "\n----- Testing shorthand arithmetic assignment on Fractions\n";
    
    Fraction fr[] = {Fraction(1, 6), Fraction(4),
                     Fraction(-1,2), Fraction(5)};

    for (int i = 0; i < 3; i++) {
          cout << fr[i] << " += " << fr[i+1] << " = ";
          cout << (fr[i] += fr[i+1]) << endl;
          cout << fr[i] << " -= " << fr[i+1] << " = ";
          cout << (fr[i] -= fr[i+1]) << endl;
          cout << fr[i] << " *= " << fr[i+1] << " = ";
          cout << (fr[i] *= fr[i+1]) << endl;
          cout << fr[i] << " /= " << fr[i+1] << " = ";
          cout << (fr[i] /= fr[i+1]) << endl;
    }
   
    cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
    Fraction f(-1, 3);
    int num = 3;
    cout << f << " += " << num << " = ";
    cout << (f += num) << endl;
    cout << f << " -= " << num << " = ";
    cout << (f -= num) << endl;
    cout << f << " *= " << num << " = ";
    cout << (f *= num) << endl;
    cout << f << " /= " << num << " = ";
    cout << (f /= num) << endl;

    cout << "\n----- Testing increment/decrement prefix and postfix\n";
    Fraction g(-1, 3);
    cout << "Now g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "Now g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "Now g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "Now g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "Now g = " << g << endl;
}






/*
 Output:
 
 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10
 Fraction [3] = -4
 Fraction [4] = 0
 Fraction [5] = 4+2/3
 Fraction [6] = 0

 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6
 Read Fraction = 5
 Read Fraction = -8
 Read Fraction = 1+2/5
 Read Fraction = -16+2/3
 Read Fraction = 1+1/4
 Read Fraction = 2
 Read Fraction = -4+1/4
 Read Fraction = -10+5/6

 ----- Testing relational operators between Fractions
 Comparing 1/2 to -1/2
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing -1/2 to 1/2
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing 1/2 to 1/10
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing 1/10 to 0
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing 0 to 0
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false

 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing -3 to 1/4
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true

 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4

 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6

 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2

 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3

 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3


 */
