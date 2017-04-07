/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */

#ifndef cyberdemon_h
#define cyberdemon_h

#include <iostream>
#include "demon.h"

namespace cs_Creature
{
   class cyberdemon: public Demon
   {
   public:
      cyberdemon();
      cyberdemon(int newStrength, int newHitpoints);
      string getSpecies() const;
   };
}
#endif
