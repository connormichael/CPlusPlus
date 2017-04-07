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
#include "human.h"
using namespace std;

namespace cs_Creature
{
   Human::Human() : Creature()
   {
   }






   Human::Human(int newStrength,
                int newHitpoints)
   :Creature(newStrength, newHitpoints)
   {
   }






   string Human::getSpecies() const
   {
      string species;
      
      species = "Human";
      return species;
   }
}