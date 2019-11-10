/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: elf.cpp
 
Program Description: Creature, is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class. Member functions will be defined for the type, Elf, in the class, Creature.
*/

#include "elf.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    // Constructor inherits default constructor of Creature
    Elf::Elf() : Creature()
    {
        getStrength();
        getHitpoints();
    }






    // Member function definition
    Elf::Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints)
    {
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Member function definition
    int Elf::getDamage()
    {
        int damage;
        damage = Creature::getDamage();
        // Elves inflict double magical damage with a 50% chance
        if ((rand() % 2) == 0){
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        }
        return damage *= 2;
    }






    // Member function definition
    string Elf::getSpecies() const
    {
        return "Elf";
    }
}
