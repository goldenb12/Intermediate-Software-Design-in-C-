/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: demon.cpp
 
Program Description: Creature, is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class. Member functions will be defined for the type, Demon, in the class, Creature.
*/

#include "demon.h"
#include "creature.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    // Constructor inherits default constructor of Creature
    Demon::Demon() : Creature()
    {
        getStrength();
        getHitpoints();
    }






    // Member function definition
    Demon::Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints)
    {
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Member function definition
    int Demon::getDamage()
    {
        int damage;
        damage = Creature::getDamage();
        // Demons can inflict damage of 50 with a 25% chance
        if (rand() % 4 == 0){
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }






    // getSpecies() function definition
    string Demon::getSpecies() const
    {
        return "Demon";
    }
}
