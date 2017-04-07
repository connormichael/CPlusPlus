/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
 */

#include <iostream>
#include <string>
#include "demon.h"
#include "balrog.h"
using namespace std;

namespace cs_Creature
{
   balrog::balrog() : Demon()
   {
   }






   balrog::balrog(int newStrength,
                int newHitpoints)
   :Demon(newStrength, newHitpoints)
   {
   }






   string balrog::getSpecies() const
   {
      string species;
      
      species = "balrog";
      return species;
   }






   int balrog::getDamage() const
   {
      int damage;
      int strength = getStrength();

      damage = Demon::getDamage();
      int damage2 = (rand() % strength) + 1;
      cout << "Balrog speed attack inflicts " << damage2 <<
         " additional damage points!" << endl;
      damage += damage2;
      return damage;
   }
}