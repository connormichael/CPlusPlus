//  main.cpp
//  Rough Assignment 6
//
//  Created by Connor Lynch on 2/7/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Here is my class prototype
class TripleString
{
private:
   string string1;
   string string2;
   string string3;
   bool validString(string str);

public:
   //default constructor
   TripleString();

   //define static constant
   const static int MAX_LEN = 20;

   //mutators and accessors
   bool setStringNameOne(string str);
   bool setStringNameTwo(string str);
   bool setStringNameThree(string str);
   string getStringNameOne();
   string getStringNameTwo();
   string getStringNameThree();
};

//Here are the global-scope method prototypes
int getBet();
TripleString pull();
string randString();
int getPayMultiplier(TripleString thePull);
void display(TripleString thePull, int winnings);

//Here is my main
int main()
{
   //declaring the string objects
   TripleString string1, string2, string3, pullString;
   int bet, multiplier, winnings;

   bet = getBet();

   while (bet)
   {
      pullString = pull();
      multiplier = getPayMultiplier(pullString);
      winnings = bet*multiplier;
      display(pullString, winnings);
      bet = getBet();
   }
}

//Here are the global-scope method definitions()
int getBet()
{
   int betAmount;

   while(true)
   {
      cout << "\nPlease enter a bet amount between 1 and 50 (or 0 to quit) "
      << endl;
      cin >> betAmount;

      if (betAmount < 0 || betAmount >= 50)
      {
         cout << "\nPlease make sure your bet amount is greater than 0 "
            "and less than 50" << endl;
         continue;
      }
      else
      {
         return betAmount;
      }
   }
}

TripleString pull()
{
   TripleString thePull;

   thePull.setStringNameOne(randString());
   thePull.setStringNameTwo(randString());
   thePull.setStringNameThree(randString());

   return thePull;
}

string randString()
{
   string cherries = "cherries";
   string bar = "BAR";
   string space = "(space)";
   string seven = "7";
   int randomNumber;

   randomNumber = rand() % 100 + 1;

   if (randomNumber <= 40)
      return bar;
   else if (randomNumber <= 70)
      return cherries;
   else if (randomNumber <= 75)
      return space;
   else
      return seven;
}

int getPayMultiplier(TripleString thePull)
{
   int multiplier;

   if (thePull.getStringNameOne() == "cherries" &&
      thePull.getStringNameTwo() != "cherries")
      multiplier = 5;
   else if (thePull.getStringNameOne() == "cherries" &&
      thePull.getStringNameTwo() == "cherries" &&
      thePull.getStringNameThree() != "cherries")
      multiplier = 15;
   else if (thePull.getStringNameOne() == "cherries" &&
      thePull.getStringNameTwo() == "cherries" &&
      thePull.getStringNameThree() == "cherries")
      multiplier = 30;
   else if (thePull.getStringNameOne() == "BAR" &&
      thePull.getStringNameTwo() == "BAR" &&
      thePull.getStringNameThree() == "BAR")
      multiplier = 50;
   else if (thePull.getStringNameOne() == "7"
      && thePull.getStringNameTwo() == "7"
      && thePull.getStringNameThree() == "7")
      multiplier = 100;
   else
      multiplier = 0;

   return multiplier;
}

void display(TripleString thePull, int winnings)
{
   cout << "spin spiny spin.....and your pull is....\n"
   << thePull.getStringNameOne() << "  " << thePull.getStringNameTwo() << "  "
   << thePull.getStringNameThree() << endl;

   if (winnings <= 0)
      cout << "sorry you lose \n";
   else
      cout << "congratulations, you win: " << winnings << endl;
}

//Here is the Default Constructor
TripleString::TripleString()
{
   string1 = "";
   string2 = "";
   string3 = "";
}

bool TripleString::validString(string str)
{
   if (str.length() <= MAX_LEN)
      return true;
   else
      return false;
}

//Here is the method definition section
string TripleString::getStringNameOne()
{
   return string1;
}

string TripleString::getStringNameTwo()
{
   return string2;
}

string TripleString::getStringNameThree()
{
   return string3;
}

bool TripleString::setStringNameOne(string stringName)
{
   if (!validString(stringName))
      return false;
   string1 = stringName;
   return true;
}

bool TripleString::setStringNameTwo(string stringName)
{
   if (!validString(stringName))
      return false;
   string2 = stringName;
   return true;
}

bool TripleString::setStringNameThree(string stringName)
{
   if (!validString(stringName))
      return false;
   string3 = stringName;
   return true;
}

/*

pull groups #6, #33, #43, #53 resulted in all BARs 
pull group #44 results in all cherries

*/


/*-----------------------Connor's Sample Run--------------------------

Please enter a bet amount between 1 and 50 (or 0 to quit) 
70000

Please make sure your bet amount is greater than 0 and less than 50

Please enter a bet amount between 1 and 50 (or 0 to quit) 
-90

Please make sure your bet amount is greater than 0 and less than 50

Please enter a bet amount between 1 and 50 (or 0 to quit) 
-1

Please make sure your bet amount is greater than 0 and less than 50

Please enter a bet amount between 1 and 50 (or 0 to quit) 
39393

Please make sure your bet amount is greater than 0 and less than 50

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  (space)
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  (space)
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  7  BAR
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  cherries  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  BAR  BAR
congratulations, you win: 250

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  BAR
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  cherries
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  7
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  BAR
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  cherries  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  (space)
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  7
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  cherries  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  cherries
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  7  BAR
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  BAR  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  7  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  BAR  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  7  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  cherries  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  BAR  BAR
congratulations, you win: 250

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  BAR  7
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
(space)  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  7  7
congratulations, you win: 25

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  7  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  cherries  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  cherries  7
congratulations, you win: 75

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  7  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  BAR  BAR
congratulations, you win: 250

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
cherries  cherries  cherries
congratulations, you win: 150

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  cherries  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  7  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
(space)  BAR  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  BAR  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  7  cherries
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  BAR  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
(space)  7  7
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  cherries  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
7  cherries  BAR
sorry you lose 

Please enter a bet amount between 1 and 50 (or 0 to quit) 
5
spin spiny spin.....and your pull is....
BAR  BAR  BAR
congratulations, you win: 250

Please enter a bet amount between 1 and 50 (or 0 to quit) 
0
Program ended with exit code: 0

----------------------------------------------------------------*/
