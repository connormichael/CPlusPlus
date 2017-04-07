//
//  main.cpp
//  Assignment_3
//
//  Created by Connor Lynch on 1/19/16.
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
   const string FOOD_1_NAME = "apple";
   const  int FOOD_1_CALORIES_P100G = 52;  // in calories
   const  int FOOD_1_SODIUM_P100G = 0;   // in milligrams
   const  double FOOD_1_SUGARS_P100G = 10.4;  // in grams
   const  double FOOD_1_TOTAL_FAT_P100G = 0.2;  // in grams


   // food #2 constants
   const  string FOOD_2_NAME = "dorito";
   const  int FOOD_2_CALORIES_P100G = 484;  // in calories
   const  int FOOD_2_SODIUM_P100G = 725;   // in milligrams
   const  double FOOD_2_SUGARS_P100G = 0.1;  // in grams
   const  double FOOD_2_TOTAL_FAT_P100G = 28.2;  // in grams


   // food #3 constants
   const  string FOOD_3_NAME = "carrot";
   const  int FOOD_3_CALORIES_P100G = 41;  // in calories
   const  int FOOD_3_SODIUM_P100G = 69;   // in milligrams
   const  double FOOD_3_SUGARS_P100G = 4.7;  // in grams
   const  double FOOD_3_TOTAL_FAT_P100G = 0.2;  // in grams


   // food #4 constants
   const string FOOD_4_NAME = "cherry";
   const  int FOOD_4_CALORIES_P100G = 49;  // in calories
   const  int FOOD_4_SODIUM_P100G = 0;   // in milligrams
   const  double FOOD_4_SUGARS_P100G = 12.0;  // in grams
   const  double FOOD_4_TOTAL_FAT_P100G = 0.1;  // in grams


   // food #5 constants
   const  string FOOD_5_NAME = "strawberry";
   const  int FOOD_5_CALORIES_P100G = 32;  // in calories
   const  int FOOD_5_SODIUM_P100G = 1;   // in milligrams
   const  double FOOD_5_SUGARS_P100G = 4.9;  // in grams
   const  double FOOD_5_TOTAL_FAT_P100G = 0.3;  // in grams



   // food #6 constants
   const  string FOOD_6_NAME = "almond";
   const  int FOOD_6_CALORIES_P100G = 579;  // in calories
   const  int FOOD_6_SODIUM_P100G = 1;   // in milligrams
   const  double FOOD_6_SUGARS_P100G = 4.3;  // in grams
   const  double FOOD_6_TOTAL_FAT_P100G = 49.9;  // in grams


   const  string INDENT = "   ";

   string recipeName, userInputStr,numberOfServingsStr;
   int userInputInt, numberOfServingsInt;
   double totalCals, totalSodium, totalSugar, totalTotalFat;

   // initialize accumulator variables
   totalSugar  = 0.;
   totalTotalFat = 0.;
   totalSodium = 0;
   totalCals =  0;


   // print menu
   cout << "---------- List of Possible Ingredients ---------" << endl;
   cout << INDENT << "Food #1: " << FOOD_1_NAME << endl;
   cout << INDENT << "Food #2: " << FOOD_2_NAME << endl;
   cout << INDENT << "Food #3: " << FOOD_3_NAME << endl;
   cout << INDENT << "Food #4: " << FOOD_4_NAME << endl;
   cout << INDENT << "Food #5: " << FOOD_5_NAME << endl;
   cout << INDENT << "Food #6: " << FOOD_6_NAME << endl << endl;


   // name of recipe
   cout << "What are you calling this recipe? ";
   getline(cin, recipeName);

   // number of servings
   cout << "How many servings in this recipe? ";
   getline(cin, numberOfServingsStr);
   istringstream(numberOfServingsStr) >> numberOfServingsInt;

   // check for a reasonable number of servings
   if (numberOfServingsInt < 1 || numberOfServingsInt > 10)
   {
      cout  <<"\nPlease specify a serving value between 1 and 10\n";
      return 1;
   }

   // food #1 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_1_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   //checking for a reasonable mass of ingredient 1
   if (userInputInt < 0 || userInputInt > 1000)
   {
      cout  <<"\nPlease specify a value between 0 and 1000\n";
      return 1;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_1_CALORIES_P100G/100.);
   totalSugar  += userInputInt * (FOOD_1_SUGARS_P100G/100.);
   totalTotalFat += userInputInt * (FOOD_1_TOTAL_FAT_P100G/100.);
   totalSodium += userInputInt * (FOOD_1_SODIUM_P100G/100.);

   // food #2 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_2_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   //checking for a reasonable mass of ingredient 2
   if (userInputInt < 0 || userInputInt > 1000)
   {
      cout  <<"\nPlease specify a value between 0 and 1000\n";
      return 1;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_2_CALORIES_P100G/100.);
   totalSugar  += userInputInt * (FOOD_2_SUGARS_P100G/100.);
   totalTotalFat += userInputInt * (FOOD_2_TOTAL_FAT_P100G/100.);
   totalSodium += userInputInt * (FOOD_2_SODIUM_P100G/100.);

   // food #3 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_3_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   //checking for a reasonable mass of ingredient 3
   if (userInputInt < 0 || userInputInt > 1000)
   {
      cout  <<"\nPlease specify a value between 0 and 1000\n";
      return 1;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_3_CALORIES_P100G/100.);
   totalSugar  += userInputInt * (FOOD_3_SUGARS_P100G/100.);
   totalTotalFat += userInputInt * (FOOD_3_TOTAL_FAT_P100G/100.);
   totalSodium += userInputInt * (FOOD_3_SODIUM_P100G/100.);

   // food #4 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_4_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   //checking for a reasonable mass of ingredient 4
   if (userInputInt < 0 || userInputInt > 1000)
   {
      cout  <<"\nPlease specify a value between 0 and 1000\n";
      return 1;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_4_CALORIES_P100G/100.);
   totalSugar  += userInputInt * (FOOD_4_SUGARS_P100G/100.);
   totalTotalFat += userInputInt * (FOOD_4_TOTAL_FAT_P100G/100.);
   totalSodium += userInputInt * (FOOD_4_SODIUM_P100G/100.);

   // food #5 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_5_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   //checking for a reasonable mass of ingredient 5
   if (userInputInt < 0 || userInputInt > 1000)
   {
      cout  <<"\nPlease specify a value between 0 and 1000\n";
      return 1;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_5_CALORIES_P100G/100.);
   totalSugar  += userInputInt * (FOOD_5_SUGARS_P100G/100.);
   totalTotalFat += userInputInt * (FOOD_5_TOTAL_FAT_P100G/100.);
   totalSodium += userInputInt * (FOOD_5_SODIUM_P100G/100.);

   // food #6 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_6_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   //checking for a reasonable mass of ingredient 6
   if (userInputInt < 0 || userInputInt > 1000)
   {
      cout  <<"\nPlease specify a value between 0 and 1000\n";
      return 1;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_6_CALORIES_P100G/100.);
   totalSugar  += userInputInt * (FOOD_6_SUGARS_P100G/100.);
   totalTotalFat += userInputInt * (FOOD_6_TOTAL_FAT_P100G/100.);
   totalSodium += userInputInt * (FOOD_6_SODIUM_P100G/100.);

   //update accumulators per serving
   totalCals /= numberOfServingsInt;
   totalSugar /= numberOfServingsInt;
   totalTotalFat /= numberOfServingsInt;
   totalSodium /= numberOfServingsInt;

   // report results --------------------------------------------------
   cout << "\nThe nutritional value per serving of " << recipeName
   << " is:" << endl;
   cout << INDENT << "Calories: " << totalCals << endl;
   cout << INDENT << "Sodium: " << totalSodium << endl;
   cout << INDENT << "Sugar: " << totalSugar << endl;
   cout << INDENT << "Total Fat: " << totalTotalFat << endl;

   return 0;
}




/*----------------Connor's Run #1 ---------------

---------- List of Possible Ingredients ---------
   Food #1: apple
   Food #2: dorito
   Food #3: carrot
   Food #4: cherry
   Food #5: strawberry
   Food #6: almond

What are you calling this recipe? veggie mix con dorito
How many servings in this recipe? 4
How many grams of apple? 20
How many grams of dorito? 80
How many grams of carrot? 5
How many grams of cherry? 90
How many grams of strawberry? 3
How many grams of almond? 1

The nutritional value per serving of veggie mix con dorito is:
   Calories: 112.625
   Sodium: 145.873
   Sugar: 3.34625
   Total Fat: 5.802
Program ended with exit code: 0


--------------Connor's Run #2 with serving error!-------

---------- List of Possible Ingredients ---------
   Food #1: apple
   Food #2: dorito
   Food #3: carrot
   Food #4: cherry
   Food #5: strawberry
   Food #6: almond

What are you calling this recipe? veggies with no dorito
How many servings in this recipe? 20

Please specify a serving value between 1 and 10
Program ended with exit code: 1


----------------Connor's Run #3 ----------------

---------- List of Possible Ingredients ---------
   Food #1: apple
   Food #2: dorito
   Food #3: carrot
   Food #4: cherry
   Food #5: strawberry
   Food #6: almond

What are you calling this recipe? A Salad 
How many servings in this recipe? 9
How many grams of apple? 0
How many grams of dorito? 0
How many grams of carrot? 40
How many grams of cherry? 20
How many grams of strawberry? 70
How many grams of almond? 5

The nutritional value per serving of A Salad  is:
   Calories: 8.61667
   Sodium: 3.15
   Sugar: 0.880556
   Total Fat: 0.311667
Program ended with exit code: 0


----------------Connor's Run #4 ----------------

---------- List of Possible Ingredients ---------
   Food #1: apple
   Food #2: dorito
   Food #3: carrot
   Food #4: cherry
   Food #5: strawberry
   Food #6: almond

What are you calling this recipe? Fruit Salad 
How many servings in this recipe? 3
How many grams of apple? 50
How many grams of dorito? 0
How many grams of carrot? 0
How many grams of cherry? 900
How many grams of strawberry? 821
How many grams of almond? 6

The nutritional value per serving of Fruit Salad  is:
   Calories: 254.82
   Sodium: 2.75667
   Sugar: 51.229
   Total Fat: 2.15233
Program ended with exit code: 0



-------------Connor's Run #5 with grams error!----

---------- List of Possible Ingredients ---------
   Food #1: apple
   Food #2: dorito
   Food #3: carrot
   Food #4: cherry
   Food #5: strawberry
   Food #6: almond

What are you calling this recipe? Bowl of Doritos 
How many servings in this recipe? 1
How many grams of apple? 0
How many grams of dorito? 4000

Please specify a value between 0 and 1000
Program ended with exit code: 1


------------Connor's Run #6 with grams error!----

---------- List of Possible Ingredients ---------
   Food #1: apple
   Food #2: dorito
   Food #3: carrot
   Food #4: cherry
   Food #5: strawberry
   Food #6: almond

What are you calling this recipe? Bowl of Almonds 
How many servings in this recipe? 5
How many grams of apple? 0
How many grams of dorito? 0
How many grams of carrot? 0
How many grams of cherry? 0
How many grams of strawberry? 0
How many grams of almond? 1001

Please specify a value between 0 and 1000
Program ended with exit code: 1
 
--------------------------------------------------*/
