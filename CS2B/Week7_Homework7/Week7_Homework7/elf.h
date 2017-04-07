/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */

#ifndef Elf_h
#define Elf_h


#include "creature.h"
#include <iostream>
namespace cs_Creature
{
   class Elf: public Creature
   {
   public:
      Elf();
      Elf(int newStrength, int newHitpoints);
      string getSpecies() const;
      int getDamage() const;
   };
}
#endif
