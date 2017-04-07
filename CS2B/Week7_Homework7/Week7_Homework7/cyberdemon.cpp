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
#include "cyberdemon.h"
using namespace std;

namespace cs_Creature
{
   cyberdemon::cyberdemon() : Demon()
   {
   }






   cyberdemon::cyberdemon(int newStrength,
                int newHitpoints)
   :Demon(newStrength, newHitpoints)
   {
   }






   string cyberdemon::getSpecies() const
   {
      string species;
      
      species = "cyberdemon";
      return species;
   }
}