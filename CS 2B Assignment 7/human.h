#ifndef HUMAN_H
#define HUMAN_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: human.h
 
Program Description: This is the header file for the Human type in the the class, Creature. It is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class.
*/

#include "creature.h"
#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <string>

namespace cs_creature {
    class Human : public Creature {
        public:
            Human();
            Human(int newStrength, int newHitpoints);
            std::string getSpecies() const;
    };
}

#endif
