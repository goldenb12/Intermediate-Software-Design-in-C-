#ifndef DEMON_H
#define DEMON_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: demon.h
 
Program Description: This is the header file for the Demon type in the the class, Creature. It is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class.
*/

#include "creature.h"
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <string>

namespace cs_creature {
    class Demon : public Creature {
        public:
            Demon();
            Demon(int newStrength, int newHitpoints);
            int getDamage();
            std::string getSpecies() const;
    };
}

#endif
