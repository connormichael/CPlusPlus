//
//  main.cpp
//  Practice Statements
//
//  Created by Connor Lynch on 1/10/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//



#include <iostream>
using namespace std;

int main()
{
   int priniple, numberOfMonths;
   double monthlyInterst, monthlyPayment;

   priniple = 465253;
   monthlyInterst = 1.005;
   monthlyPayment = 3248;
   numberOfMonths = 0;

   while(priniple > 0)
   {
      priniple *= monthlyInterst;
      priniple -= monthlyPayment;
      numberOfMonths++;
   }
   cout << "Total number of months: " << numberOfMonths;
   cout << "\nTotal number of years: " << numberOfMonths/12;

}
