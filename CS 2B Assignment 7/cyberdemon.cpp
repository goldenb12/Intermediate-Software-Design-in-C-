/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: cyberdemon.cpp
 
Program Description: Creature, is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class. Member functions will be defined for the type, Cyberdemon, in the class, Creature.
*/

#include "cyberdemon.h"
#include "demon.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    // Constructor inherits default constructor of Creature
    Cyberdemon::Cyberdemon() : Demon()
    {
        getStrength();
        getHitpoints();
    }






    // Member function definition
    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints)
    {
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Member function definition
    string Cyberdemon::getSpecies() const
    {
        return "Cyberdemon";
    }
}
