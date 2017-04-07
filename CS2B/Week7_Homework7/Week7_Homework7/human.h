/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */

#ifndef Human_h
#define Human_h

#include "creature.h"
#include <iostream>

namespace cs_Creature
{
   class Human: public Creature
   {
   public:
      Human();
      Human(int newStrength, int newHitpoints);
      string getSpecies() const;
   };
}
#endif
