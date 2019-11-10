#ifndef CREATURE_H
#define CREATURE_H

/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: creature.h
 
Program Description: This header file shows how the class, Creature, is rewritten using inheritance, where the variable "type" is eliminated. Creature is the base class.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

namespace cs_creature {
    class Creature {
        public:
            Creature();
            Creature(int newStrength, int newHitpoints);
            int getStrength();
            int getHitpoints();
            void setStrength(int newStrength);
            void setHitpoints(int newHitpoints);
            virtual int getDamage();
            virtual std::string getSpecies() const = 0;
        
        private:
            int strength;
            int hitpoints;
    };
}

#endif
