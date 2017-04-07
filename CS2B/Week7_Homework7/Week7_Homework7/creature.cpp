/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */


#include <iostream> 
#include <string>
#include "creature.h"
using namespace std;

namespace cs_Creature
{
   Creature::Creature()
   {
      strength = 10;
      hitpoints = 10;
   }






   Creature::Creature(int newStrength, int newHitpoints)
   {
      strength = newStrength;
      hitpoints = newHitpoints;
   }






   int Creature::getDamage() const
   {
      int damage;
      
      damage = (rand() % strength) + 1;
      cout << "The " << getSpecies() << " attacks for " <<
         damage << " points!" << endl;
      return damage;
   }






   void Creature::changeStrength(const int& newStrength)
   {
      strength = newStrength;
   }






   void Creature::changeHitpoints(const int& newHitpoints)
   {
      hitpoints = newHitpoints;
   }






   int Creature::getStrength() const
   {
      return strength;
   }






   int Creature::getHitpoints() const
   {
      return hitpoints;
   }
}