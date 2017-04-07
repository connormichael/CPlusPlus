/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 13, 2016
 Professor Dave Harden
 Assignment 7
*/

#include <iostream>
#include <ctime> 
#include <cstdlib>
#include "creature.h"
#include "human.h"
#include "cyberdemon.h"
#include "balrog.h"
#include "elf.h"
#include "demon.h"
using namespace std;
using namespace cs_Creature;

void battleArena(Creature& Creature1, Creature& Creature2);

int main()
{
   srand((time(0)));

	Elf e(50,50);
	balrog b(50,50);
   Human h(10, 100);
   cyberdemon c(20, 66);

	battleArena(e, b);
   battleArena(h, c);

   e.changeHitpoints(50);
   b.changeHitpoints(50);
   h.changeHitpoints(100);
   c.changeHitpoints(66);

   battleArena(e, h);
   battleArena(b, c);
}






void battleArena(Creature& Creature1, Creature& Creature2)
{
   int creature1HitPoints, creature2HitPoints;

   cout << "Starting a New Battle!" << endl;

   while ((Creature1.getHitpoints() > 0) && (Creature2.getHitpoints() > 0))
   {
      creature2HitPoints = Creature2.getHitpoints() - Creature1.getDamage();
      Creature2.changeHitpoints(creature2HitPoints);
      creature1HitPoints = Creature1.getHitpoints() - Creature2.getDamage();
      Creature1.changeHitpoints(creature1HitPoints);
   }

   if ((Creature1.getHitpoints() <= 0) && (Creature2.getHitpoints() <= 0))
      cout << "The Battle Was a Tie!!!" << endl;
   else if (Creature1.getHitpoints() > 0)
      cout << Creature1.getSpecies() << " Won the Battle!" << endl;
   else
      cout << Creature2.getSpecies() << " Won the Battle!" << endl;
   cout << endl;
}






/*--------------------- Connor's Output ----------------------

Starting a New Battle!
The Elf attacks for 2 points!
The balrog attacks for 28 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 45 additional damage points!
balrog Won the Battle!

Starting a New Battle!
The Human attacks for 7 points!
The cyberdemon attacks for 1 points!
The Human attacks for 1 points!
The cyberdemon attacks for 15 points!
Demonic attack inflicts 50 additional damage points!
The Human attacks for 2 points!
The cyberdemon attacks for 14 points!
Demonic attack inflicts 50 additional damage points!
cyberdemon Won the Battle!

Starting a New Battle!
The Elf attacks for 28 points!
The Human attacks for 7 points!
The Elf attacks for 11 points!
The Human attacks for 10 points!
The Elf attacks for 11 points!
The Human attacks for 10 points!
The Elf attacks for 13 points!
Magical attack inflicts 13 additional damage points!
The Human attacks for 1 points!
The Elf attacks for 30 points!
The Human attacks for 5 points!
Elf Won the Battle!

Starting a New Battle!
The balrog attacks for 31 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 2 additional damage points!
The cyberdemon attacks for 17 points!
balrog Won the Battle!

Program ended with exit code: 0
 
------------------------- End of Ouput ----------------------*/
