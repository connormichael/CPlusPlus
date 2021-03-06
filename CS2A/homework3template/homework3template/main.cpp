//
//  main.cpp
//  homework3template
//
//  Created by Connor Lynch on 1/20/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

// CS 1A Lab 3 Framework

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// main client --------------------------------------------------------
int main()
{
   // food #1 constants
   const string FOOD_1_NAME = "avocado";
   const  int FOOD_1_CALORIES_P100G = 160;  // in calories
   const  double FOOD_1_SOL_FIBER_P100G = 1.75;   // in grams

   // food #2 constants
   const  string FOOD_2_NAME = "tomato";
   const  int FOOD_2_CALORIES_P100G = 18;  // in calories
   const  double FOOD_2_SOL_FIBER_P100G = .12;   // in grams

   // food #3 constants
   const  string FOOD_3_NAME = "buffalo mozzarella";
   const  int FOOD_3_CALORIES_P100G = 282;  // in calories
   const  double FOOD_3_SOL_FIBER_P100G = 0.;   // in grams

   const  string INDENT = "   ";

   string recipeName, userInputStr;
   int userInputInt;
   double totalSolFiber, totalCals;

   // initialize accumulator variables
   totalSolFiber  = 0.;
   totalCals =  0;

   // print menu
   cout << "---------- List of Possible Ingredients ---------" << endl;
   cout << INDENT << "Food #1: " << FOOD_1_NAME << endl;
   cout << INDENT << "Food #2: " << FOOD_2_NAME << endl;
   cout << INDENT << "Food #3: " << FOOD_3_NAME << endl << endl;

   // name of recipe
   cout << "What are you calling this recipe? ";
   getline(cin, recipeName);

   // food #1 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_1_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // update accumulators
   totalCals += userInputInt * (FOOD_1_CALORIES_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_1_SOL_FIBER_P100G/100.);

   // food #2 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_2_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // update accumulators
   totalCals += userInputInt * (FOOD_2_CALORIES_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_2_SOL_FIBER_P100G/100.);

   // food #3 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_3_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // update accumulators
   totalCals += userInputInt * (FOOD_3_CALORIES_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_3_SOL_FIBER_P100G/100.);

   // report results --------------------------------------------------
   cout << "\nNutrition for " << recipeName << "------------" << endl;
   cout << INDENT << "Calories: " << totalCals << endl;
   cout << INDENT << "Soluble Fiber: " << totalSolFiber << endl;
   
   return 0;
}
