/*
Name: Brandon Goldenberg
Class: Foothill College CS 2B
Date: 11/11/2019
Instructor: Dave Harden
File Name: a7.cpp

Program Description: In this fantasy role-playing game, four different types of Creatures: Humans, Cyberdemons, Balrogs, and Elves, are created. A Creature base class will be created using inheritance (which will eliminate the "type" variable). The classes Demon, Elf, and Human are derived from Creature and the classes Cyberdemon and Balrog are derived from Demon. A getSpecies() function will be written  so that the four types of Creatures are returned. A getDamage() function will be written so that it outputs and returns the damage a Creature can inflict in one round of combat.
*/

#include "human.h"
#include "elf.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
using namespace cs_creature;

// battleArena function prototype
void battleArena(Creature& Creature1, Creature& Creature2);





// battleArena function definition
void battleArena(Creature& Creature1, Creature& Creature2)
{
    while (Creature2.getHitpoints() >= 0 && Creature1.getHitpoints() >= 0){
        Creature1.setHitpoints(Creature1.getHitpoints() - Creature2.getDamage());
        Creature2.setHitpoints(Creature2.getHitpoints() - Creature1.getDamage());
    }
    
    if (Creature1.getHitpoints() < 0 && Creature2.getHitpoints() < 0){
        cout << "Game is tied." << endl;
    }
        
    if (Creature1.getHitpoints() > 0 && Creature2.getHitpoints() < 0){
        cout << "The " << Creature1.getSpecies() << " wins the game with " << Creature1.getHitpoints() << " hit points remaining." << endl;
    }
    
    if (Creature1.getHitpoints() < 0 && Creature2.getHitpoints() > 0){
        cout << "The " << Creature2.getSpecies() << " wins the game with " << Creature2.getHitpoints() << " hit points remaining." << endl;
    }
}






// CLIENT PROGRAM
int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    Elf e(50,50);
    Balrog b(50,50);
    
    cout << endl << "Battle between The Elf and The Balrog" << endl;
    battleArena(e, b);
    
    Human h(60, 120);
    Cyberdemon c(60, 120);
    
    cout << endl << "Battle between The Human and The Cyberdemon" << endl;
    battleArena(h, c);
    
    Human h2(70, 140);
    Balrog b2(70, 140);
    
    cout << endl << "Battle between The Human and The Balrog" << endl;
    battleArena(h2, b2);
    
    Elf e2(80, 160);
    Cyberdemon c2(80, 160);
    
    cout << endl << "Battle between The Elf and The Cyberdemon" << endl;
    battleArena(e2, c2);
}

/*
 Output:
 
 Battle between The Elf and The Balrog
 The Balrog attacks for 11 points!
 Balrog speed attack inflicts 32 additional damage points!
 The Elf attacks for 4 points!
 The Balrog attacks for 14 points!
 Balrog speed attack inflicts 12 additional damage points!
 The Elf attacks for 35 points!
 Magical attack inflicts 35 additional damage points!
 Game is tied.

 Battle between The Human and The Cyberdemon
 The Cyberdemon attacks for 47 points!
 The Human attacks for 40 points!
 The Cyberdemon attacks for 24 points!
 The Human attacks for 29 points!
 The Cyberdemon attacks for 7 points!
 Demonic attack inflicts 50 additional damage points!
 The Human attacks for 9 points!
 The Cyberdemon wins the game with 42 hit points remaining.

 Battle between The Human and The Balrog
 The Balrog attacks for 18 points!
 Balrog speed attack inflicts 70 additional damage points!
 The Human attacks for 55 points!
 The Balrog attacks for 6 points!
 Balrog speed attack inflicts 51 additional damage points!
 The Human attacks for 24 points!
 The Balrog wins the game with 61 hit points remaining.

 Battle between The Elf and The Cyberdemon
 The Cyberdemon attacks for 32 points!
 The Elf attacks for 77 points!
 The Cyberdemon attacks for 30 points!
 The Elf attacks for 58 points!
 Magical attack inflicts 58 additional damage points!
 The Elf wins the game with 98 hit points remaining.
 
 */
