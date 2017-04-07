//
//  main.cpp
//  Conditionals
//
//  Created by Connor Lynch on 1/17/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

int  main()
{
   // user-provided values
   double gasMilage;
   int milesDriven;
   double savings;
   double gasPrice1, gasPrice2, gasPrice3;

   gasPrice1 = 1.75;
   gasPrice2 = 2.00;
   gasPrice3 = 2.35;

   cout << "Type in an MPG: ";
   cin >> gasMilage;

   cout << "Type in How far Foothill is: ";
   cin >> milesDriven;

   cout << "You get " << gasMilage << " MPG, city ,and you drive " <<
   milesDriven << " miles round trip each time you come to campus.";

   if (gasMilage < 0 || milesDriven < 0)
   {
      cout << "You fucked up son";
      return 1;
   }

   cout << "No one was a dumb shit so lets keep going \n";

   savings = (2*12*milesDriven*gasPrice1)/gasMilage;
   cout << "This is how much you are saving per quarter " << savings;

   savings = (2*12*milesDriven*gasPrice2)/gasMilage;
   savings = (2*12*milesDriven*gasPrice3)/gasMilage;
   return 0;





}





