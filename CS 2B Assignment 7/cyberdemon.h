#ifndef CYBERDEMON_H
#define CYBERDEMON_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: cyberdemon.h
 
Program Description: This is the header file for the Cyberdemon type in the the class, Creature. It is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class.
*/

#include "demon.h"
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <string>

namespace cs_creature {
    class Cyberdemon : public Demon {
        public:
            Cyberdemon();
            Cyberdemon(int newStrength, int newHitpoints);
            std::string getSpecies() const;
    };
}

#endif
