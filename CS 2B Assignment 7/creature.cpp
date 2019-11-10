/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: creature.cpp
 
Program Description: Creature, is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class. Member functions will be defined for the class, Creature.
*/

#include "creature.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    // Constructor function
    Creature::Creature()
    {
        strength = 10;
        hitpoints = 10;
    }






    // Constructor function
    Creature::Creature(int newStrength, int newHitpoints)
    {
        strength = newStrength;
        hitpoints = newHitpoints;
    }






    // Accessor function
    int Creature::getStrength()
    {
        return strength;
    }






    // Accessor function
    int Creature::getHitpoints()
    {
        return hitpoints;
    }






    // Mutator function
    void Creature::setStrength(int newStrength)
    {
        strength = newStrength;
    }






    // Mutator function
    void Creature::setHitpoints(int newHitpoints)
    {
        hitpoints = newHitpoints;
    }






    // Implementation of the getDamage() function
    int Creature::getDamage()
    {
        int damage;
        
        // All Creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }






    // Implementation of the getSpecies() function
    string Creature::getSpecies() const
    {
        return "Human";
    }
}
