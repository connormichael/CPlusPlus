/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */

#ifndef Demon_h
#define Demon_h

#include "creature.h"
#include <iostream>
namespace cs_Creature
{
   class Demon: public Creature
   {
   public:
      Demon();
      Demon(int newStrength, int newHitpoints);
      string getSpecies() const;
      int getDamage() const;
   };
}
#endif
