/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */

#ifndef balrog_h
#define balrog_h

#include "demon.h"
#include <iostream>

namespace cs_Creature
{
   class balrog: public Demon
   {
   public:
      balrog();
      balrog(int newStrength, int newHitpoints);
      string getSpecies() const;
      int getDamage() const;
   };
}
#endif
