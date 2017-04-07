//
//  main.cpp
//  Week4_Homework4_Professor_Solution
//
//  Created by Connor Lynch on 10/17/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "invItem.h"
using namespace std;


#include <cmath>


void f(invItem item1);

int main()
{
   invItem item1;
   invItem item2("hammer");

   cout << "item1 is " << item1 << endl;
   cout << "item2 is " << item2 << endl;

   item1.setInfo("screwdriver", 5);
   item2.setUnits(9);

   cout << "item1 is " << item1 << endl;
   cout << "item2 is " << item2 << endl << endl;

   item1 = item2;
   cout << "after item1 = item2, " << endl;
   cout << "item1 is " << item1 << endl;
   cout << "item2 is " << item2 << endl << endl;

   item2.setInfo("lawn mower", 14);
   cout << "after item2.setInfo(\"lawn mower\", 14), " << endl;
   cout << "item1 is " << item1 << endl;
   cout << "item2 is " << item2 << endl << endl;

   item1 = item1;
   cout << "after item1 = item1, ";
   cout << "item1 is " << item1 << endl << endl;

   f(item1);
   cout << "after being used as an argument to pass-by-value parameter, ";
   cout << endl << "item1 is still " << item1 << endl << endl;


   invItem item3 = item1;
   // this is exactly equivalent to: invItem item3(item1);
   cout << "after invItem item3 = item1;" << endl;
   cout << "item1 is " << item1 << endl;
   cout << "item3 is " << item3 << endl << endl;

   item3.setInfo("ice cream", 962);
   cout << "after item3.setInfo(\"ice cream\", 962);" << endl;
   cout << "item1 is " << item1 << endl;
   cout << "item3 is " << item3 << endl << endl;
}

void f(invItem item1)
{
   item1.setInfo("pizza", 67);
}

