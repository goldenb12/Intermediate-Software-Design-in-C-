#ifndef FRACTION_H
#define FRACTION_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 10/7/2019
Instructor: Dave Harden
File Name: fraction.h

 This is the header file for the class, Fraction. An object this class will have two integer data members, a numerator and a denominator. This program will utilize the four basic arithmetic operations (+, -, *, /) and simplify Fractions. Fractions will be simplified to their lowest forms for the purposes of this program.
 
 Fraction(int inNumerator = 0, int inDenominator = 1);
 pre: Two integers (inNumerator, inDenominator) are input as two parameters for the function.
 post: If there are zero integer arguments, the numerator is set to 0 and the denominator is set to 1.
 
 friend std::ostream& operator<<(std::ostream& out, const Fraction& second_Fraction);
 pre: Two Fractions must be used. The right operand is inserted into the stream and is represented by the left operand.
 post: The left operand is returned (if it is an object of the class) and insertion operator is overloaded.
 
 friend std::istream& operator>>(std::istream& in, Fraction& second_Fraction);
 pre: Two Fractions must be used. The right operand is inserted into the stream and is represented by the left operand.
 post: A valid Fraction will be a mixed Fraction, proper or improper Fraction, a whole number (Fraction), or 0.
 
 friend bool operator<(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are compared to one another to see if first_Fraction is less than second_Fraction. The Fractions will not change due to the const keyword.
 
 friend bool operator<=(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are compared to one another to see if first_Fraction is less than or equal to second_Fraction. The Fractions will not change due to const keyword.
 
 friend bool operator>(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are compared to one another to see if first_Fraction is greater than second_Fraction. The Fractions will not change due to the const keyword.
 
 friend bool operator>=(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are compared to one another to see if first_Fraction is greater than or equal to second_Fraction. The Fractions will not change due to the const keyword.
 
 friend bool operator==(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are compared to one another to see if first_Fraction is equal to second_Fraction. The Fractions will not change due to the const keyword.
 
 friend bool operator!=(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are compared to one another to see if first_Fraction is not equal to second_Fraction. The Fractions will not change due to the const keyword.
 
 friend Fraction operator+(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are added together to find their sum and are then simplified. The Fractions will not change due to the const keyword.
 
 friend Fraction operator-(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are subtracted from another to find their differene and are then simplified. The Fractions will not change due to the const keyword.
 
 friend Fraction operator*(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are multiplied together to find their product and are then simplified. The Fractions will not change due to the const keyword.
 
 friend Fraction operator/(const Fraction& first_Fraction, const Fraction& second_Fraction);
 pre: Two Fractions must be used.
 post: Two Fractions are divided by one another to find their quotient and are then simplified. The Fractions will not change due to the const keyword.
 
 Fraction operator+=(const Fraction& second_Fraction);
 pre: The operator adds the right operand to the left.
 post: The operator returns the value of second_Fraction to the left operand. The Fraction will not change due to the const keyword.
 
 Fraction operator-=(const Fraction& second_Fraction);
 pre: The operator subtracts the right operand from the left.
 post: The operator returns the value of second_Fraction to the left operand. The Fraction will not change due to the const keyword.
 
 Fraction operator*=(const Fraction& second_Fraction);
 pre: The operator multiplies the right operand with the left.
 post: The operator returns the value of second_Fraction to the left operand. The Fraction will not change due to the const keyword.
 
 Fraction operator/=(const Fraction& second_Fraction);
 pre: The operator divides the right operand by the left.
 post: The operator returns the value of second_Fraction to the left operand. The Fraction will not change due to the const keyword.
 
 Fraction operator++(int);
 pre: The operator will call an object in the program.
 post: The dummy parameter (int inserted into the parameter list) tells the compiler that this is the post-increment operator.
 
 Fraction operator++();
 pre: The operator will call an object in the program.
 post: The operand will be incremented (adding one to the data member) and then this new value of the operand will be returned.
 
 Fraction operator--(int);
 pre: The operator will call an object in the program.
 post: The dummy parameter (int inserted into the parameter list) tells the compiler that this is the pre-increment operator.
 
 Fraction operator--();
 pre: The operator will call an object in the program.
 post: The operand will be decremented (subtracting one from the data member) and then this new value of the operand will be returned.
 
 */

#include <iostream>
#include <cassert>
#include <cmath> 

namespace cs_fraction {
    class Fraction {
        public:
            Fraction(int inNumerator = 0, int inDenominator = 1);
            friend std::ostream& operator<<(std::ostream& out, const Fraction& second_Fraction);
            friend std::istream& operator>>(std::istream& in, Fraction& second_Fraction);
            friend bool operator<(const Fraction& first_Fraction, const Fraction& second_Fraction);
            friend bool operator<=(const Fraction& first_Fraction, const Fraction& second_Fraction);
            friend bool operator>(const Fraction& first_Fraction, const Fraction& second_Fraction);
            friend bool operator>=(const Fraction& first_Fraction, const Fraction& second_Fraction);
            friend bool operator==(const Fraction& first_Fraction, const Fraction& second_Fraction);
            friend bool operator!=(const Fraction& first_Fraction, const Fraction&  second_Fraction);
            friend Fraction operator+(const Fraction& first_Fraction, const Fraction& second_Fraction);
            friend Fraction operator-(const Fraction& first_Fraction, const Fraction&   second_Fraction);
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
            void simplify();
    };
}
    
#endif
