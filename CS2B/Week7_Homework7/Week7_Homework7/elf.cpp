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
#include "elf.h"
using namespace std;

namespace cs_Creature
{
   Elf::Elf() : Creature()
   {
   }






   Elf::Elf(int newStrength,
                  int newHitpoints)
   :Creature(newStrength, newHitpoints)
   {
   }






   string Elf::getSpecies() const
   {
      string species;
      
      species = "Elf";
      return species;
   }






   int Elf::getDamage() const
   {
      int damage;
      
      damage = Creature::getDamage();
      if ((rand() % 2) == 0)
      {
         cout << "Magical attack inflicts " << damage <<
            " additional damage points!" << endl;
         damage *= 2;
      }
      return damage;
   }
}