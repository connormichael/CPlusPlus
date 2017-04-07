/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */

#ifndef Creature_h
#define Creature_h

#include <iostream>
#include <string> 
using namespace std;

namespace cs_Creature
{
   class Creature
   {
   private:
      int strength;
      int hitpoints;
   public:
      Creature();
      Creature(int newStrength, int newHitpoints);
      virtual string getSpecies() const = 0;
      virtual int getDamage() const;
      int getStrength() const;
      int getHitpoints() const;
      void changeStrength(const int& newStrength);
      void changeHitpoints(const int& newHitpoints);
   };
}
#endif
