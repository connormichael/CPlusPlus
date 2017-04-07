//
//  main.cpp
//  Assignment_2
//
//  Created by Connor Lynch on 1/12/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
   int studID, numLet, intResult;
   double doubleResult;


   studID = 20264485;
   numLet = 5;

   cout << "My last (family) name is Lynch" << endl;
   cout << "My Student ID is " << studID << endl;
   cout << "The number of characters in my last name is " << numLet << endl;

   intResult = studID % 2;
   cout << "\nExpression #1: " << intResult << endl;

   intResult = studID % numLet;
   cout << "\nExpression #2: " << intResult << endl;

   doubleResult = double(studID)/numLet;
   cout << "\nExpression #3: " << doubleResult << endl;

   intResult = 1 + 2 + 3 + 4 + numLet;
   cout << "\nExpression #4: " << intResult << endl;

   doubleResult = double(100000)/
   (99 + (studID - 54321)/((numLet + 30)*(numLet + 30)));
   cout << "\nExpression #5: " << doubleResult << endl;
}


/* ------------ Connor's Run ---------------
 
 My last (family) name is Lynch
 My Student ID is 20264485
 The number of characters in my last name is 5

 Expression #1: 1

 Expression #2: 0

 Expression #3: 4.0529e+06

 Expression #4: 15

 Expression #5: 6.02519
 Program ended with exit code: 0


-------------------------------------------*/

