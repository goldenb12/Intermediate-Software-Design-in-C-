/*
 Name: Brandon Goldenberg
 Class: Foothill College CS 2B
 Date: 9/30/2019
 Instructor: Dave Harden
 File Name: a1_1.cpp
 
 Program Description: First define the class, Fraction.  Fraction can be constructed from two, one, or zero integer arguments (parameters) as input for the program. There are no pre-conditions for this program. The post-conditions would be: if there are two integer arguments, the numerator is set to the first parameter and the denominator is set to the second parameter; if there is one integer argument, the numerator is set to the parameter and the denominator is set to 1; if there are zero integer arguments, the numerator is set to 0 and the denominator is set to 1. To make sure that the denominator is not set to 0, an assert statement, assert(inDenominator != 0), is used. The header used for assert() is #include <cassert>. An overloaded stream operator << is printed in this program. Six relational operators (<, <=, >, >=, ==, !=) will be supported in this program and used to compare Fractions to one another as well as being compared to integers. Either Fractions or integers can appear on either side of the binary operator. One function is used for each operator. Four basic arithmetic operations (+, -, *, /) will be supported in this program and will allow Fractions to be combined with another as well as being combined with integers. Either Fractions or integers can appear on either side of the binary operator. One function is used for each operator. No special handling is needed in the case of dividing by a Fraction that is equal to 0.  The client will get a runtime error if they attempt to handle this case. Shorthand arithmetic operators (+=, -=, *=, /=) will be implemented in this program. Fractions can appear on the left-hand side of the operator, and Fractions or integers can appear on the right-hand side of the operator. The increment and decrement (++, --) operators will be supported in both prefix and postfix form for Fractions.
 
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Class declaration and data member definitions
class Fraction {
    public:
        Fraction(int inNumerator = 0, int inDenominator = 1);
        friend ostream& operator<<(ostream& out, const Fraction& second_Fraction);
        friend bool operator<(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend bool operator<=(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend bool operator>(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend bool operator>=(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend bool operator==(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend bool operator!=(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend Fraction operator+(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend Fraction operator-(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend Fraction operator*(const Fraction& first_Fraction, const Fraction& second_Fraction);
        friend Fraction operator/(const Fraction& first_Fraction, const Fraction& second_Fraction);
        Fraction operator+=(const Fraction& second_Fraction);
        Fraction operator-=(const Fraction& second_Fraction);
        Fraction operator*=(const Fraction& second_Fraction);
        Fraction operator/=(const Fraction& second_Fraction);
        Fraction operator++(int);
        Fraction operator++();
        Fraction operator--(int);
        Fraction operator--();
    
    private:
        int numerator;
        int denominator;
};






// Stream insertion operator overloading
ostream& operator<<(ostream& out, const Fraction& second_Fraction)
{
    out << second_Fraction.numerator << "/" << second_Fraction.denominator;
    return out;
}






// Operator overloading using a scope resolution operator
Fraction::Fraction(int inNumerator, int inDenominator)
{
    assert(inDenominator != 0);
    numerator = inNumerator;
    denominator = inDenominator;
};






// Relational operator < function overloading
bool operator<(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    if ((first_Fraction.numerator * second_Fraction.denominator) < (second_Fraction.numerator * first_Fraction.denominator)){
        return true;
    }
    return false;
}






// Relational operator <= function overloading
bool operator<=(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    if ((first_Fraction.numerator * second_Fraction.denominator) <= (second_Fraction.numerator * first_Fraction.denominator)){
        return true;
    }
    return false;
}






// Relational operator > function overloading
bool operator>(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    if ((first_Fraction.numerator * second_Fraction.denominator) > (second_Fraction.numerator * first_Fraction.denominator)){
        return true;
    }
    return false;
}






// Relational operator >= function overloading
bool operator>=(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    if ((first_Fraction.numerator * second_Fraction.denominator) >= (second_Fraction.numerator * first_Fraction.denominator)){
        return true;
    }
    return false;
}






// Relational operator == function overloading
bool operator==(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    if ((first_Fraction.numerator * second_Fraction.denominator) == (second_Fraction.numerator * first_Fraction.denominator)){
        return true;
    }
    return false;
}






// Relational operator != function overloading
bool operator!=(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    if ((first_Fraction.numerator * second_Fraction.denominator) != (second_Fraction.numerator * first_Fraction.denominator)){
        return true;
    }
    return false;
}






// Basic arithmetic operator + function overloading
Fraction operator+(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    Fraction result;
    result.numerator = (first_Fraction.numerator * second_Fraction.denominator) + (second_Fraction.numerator * first_Fraction.denominator);
    result.denominator = first_Fraction.denominator * second_Fraction.denominator;
    return result;
}






// Basic arithmetic operator - function overloading
Fraction operator-(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    Fraction result;
    result.numerator = (first_Fraction.numerator * second_Fraction.denominator) - (second_Fraction.numerator * first_Fraction.denominator);
    result.denominator = first_Fraction.denominator * second_Fraction.denominator;
    return result;
}






// Basic arithmetic operator * function overloading
Fraction operator*(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    Fraction result;
    result.numerator = first_Fraction.numerator * second_Fraction.numerator;
    result.denominator = first_Fraction.denominator * second_Fraction.denominator;
    return result;
}






// Basic arithmetic operator / function overloading
Fraction operator/(const Fraction& first_Fraction, const Fraction& second_Fraction)
{
    Fraction result;
    result.numerator = first_Fraction.numerator * second_Fraction.denominator;
    result.denominator = first_Fraction.denominator * second_Fraction.numerator;
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
    Fraction result(numerator, denominator);
    *this = result + (denominator / denominator);
    return result;
}






// Increment operator function overloading
Fraction Fraction::operator++()
{
    *this = *this + (denominator / denominator);
    return *this;
}






// Decrement operator function overloading
Fraction Fraction::operator--(int)
{
    Fraction result(numerator, denominator);
    *this = result - (denominator / denominator);
    return result;
}






// Decrement operator function overloading
Fraction Fraction::operator--()
{
    *this = *this - (denominator / denominator);
    return *this;
}






// CLIENT PROGRAM

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

int main()
{
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();
}






// Function definition for testing basic Fraction creation and printing
void BasicTest()
{
    cout << "\n----- Testing basic Fraction creation & printing\n";
    
    const Fraction fr[] = {Fraction(4, 8), Fraction(-15,21),
                           Fraction(10), Fraction(12, -3),
                           Fraction(), Fraction(28, 6), Fraction(0, 12)};
                                                   
    for (int i = 0; i < 7; i++){
        cout << "Fraction [" << i <<"] = " << fr[i] << endl;
    }
        
        

}






string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}


// Function definition for testing relation operators between Fractions and between Fractions and integers
void RelationTest()
{
    cout << "\n----- Testing relational operators between Fractions\n";

    const Fraction fr[] =  {Fraction(3, 6), Fraction(-15, 30), Fraction(1, 2),
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






// Function definition for testing binary arithmetic between Fractions and between Fractions and integers
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






// Function definition for testing shorthand arithmetic assignments on Fractions and assignments using integers
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
 Fraction [0] = 4/8
 Fraction [1] = -15/21
 Fraction [2] = 10/1
 Fraction [3] = 12/-3
 Fraction [4] = 0/1
 Fraction [5] = 28/6
 Fraction [6] = 0/12

 ----- Testing relational operators between Fractions
 Comparing 3/6 to -15/30
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing -15/30 to 1/2
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
 Comparing 1/10 to 0/1
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing 0/1 to 0/2
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false

 ----- Testing relations between Fractions and integers
 Comparing -3/6 to 2
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
 1/6 + 1/3 = 9/18
 1/6 - 1/3 = -3/18
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 3/6
 1/3 + -2/3 = -3/9
 1/3 - -2/3 = 9/9
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = 3/-6
 -2/3 + 5/1 = 13/3
 -2/3 - 5/1 = -17/3
 -2/3 * 5/1 = -10/3
 -2/3 / 5/1 = -2/15
 5/1 + -4/3 = 11/3
 5/1 - -4/3 = 19/3
 5/1 * -4/3 = -20/3
 5/1 / -4/3 = 15/-4

 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 7/2
 -1/2 - 4 = -9/2
 -1/2 * 4 = -4/2
 -1/2 / 4 = -1/8
 3 + -1/2 = 5/2
 3 - -1/2 = 7/2
 3 * -1/2 = -3/2
 3 / -1/2 = 6/-1

 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4/1 = 25/6
 25/6 -= 4/1 = 1/6
 1/6 *= 4/1 = 4/6
 4/6 /= 4/1 = 4/24
 4/1 += -1/2 = 7/2
 7/2 -= -1/2 = 16/4
 16/4 *= -1/2 = -16/8
 -16/8 /= -1/2 = -32/-8
 -1/2 += 5/1 = 9/2
 9/2 -= 5/1 = -1/2
 -1/2 *= 5/1 = -5/2
 -5/2 /= 5/1 = -5/10

 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 8/3
 8/3 -= 3 = -1/3
 -1/3 *= 3 = -3/3
 -3/3 /= 3 = -3/9

 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 5/3
 Now g = 5/3
 g-- = 5/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3

 */
