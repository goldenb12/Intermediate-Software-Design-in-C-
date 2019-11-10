#ifndef ELF_H
#define ELF_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: elf.h
 
Program Description: This is the header file for the Elf type in the the class, Creature. It is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class.
*/

#include "creature.h"
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <string>

namespace cs_creature {
    class Elf : public Creature {
        public:
            Elf();
            Elf(int newStrength, int newHitpoints);
            int getDamage();
            std::string getSpecies() const;
    };
}

#endif
