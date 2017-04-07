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
#include "demon.h"
using namespace std;

namespace cs_Creature
{
   Demon::Demon() : Creature()
   {
   }






   Demon::Demon(int newStrength,
            int newHitpoints)
   :Creature(newStrength, newHitpoints)
   {
   }






   string Demon::getSpecies() const
   {
      string species;
      
      species = "demon";
      return species;
   }






   int Demon::getDamage() const
   {
      int damage;
      damage = Creature::getDamage();
      if (rand() % 4 == 0)
      {
         damage = damage + 50;
         cout << "Demonic attack inflicts 50 additional damage points!" << endl;
      }
      return damage;
   }
}

