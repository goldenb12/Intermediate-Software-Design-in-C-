/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: human.cpp
 
Program Description: Creature, is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class. Member functions will be defined for the type, Human, in the class, Creature.
*/

#include "human.h"
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <string>
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    // Constructor inherits default constructor of Creature
    Human::Human() : Creature()
    {
        getStrength();
        getHitpoints();
    }






    // Member function definition
    Human::Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints)
    {
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Member function definition
    string Human::getSpecies() const
    {
        return "Human";
    }
}
