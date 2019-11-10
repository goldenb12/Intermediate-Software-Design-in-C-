/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: balrog.cpp
 
Program Description: Creature, is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class. Member functions will be defined for the type, Balrog, in the class, Creature.
*/

#include "balrog.h"
#include "demon.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    // Constructor inherits default constructor of Creature
    Balrog::Balrog() : Demon()
    {
        getStrength();
        getHitpoints();
    }






    // Member function definition
    Balrog::Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints)
    {
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Member function definition
    int Balrog::getDamage()
    {
        int damage;
        // Balrogs are so fast they get to attack twice
        damage = Demon::getDamage();
        int damage2 = (rand() % Demon::getStrength()) + 1;
        damage += damage2;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        return damage;
    }






    // Member function definition
    string Balrog::getSpecies() const
    {
        return "Balrog";
    }
}
