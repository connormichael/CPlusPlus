//
//  main.cpp
//  recurssion
//
//  Created by Connor Lynch on 9/12/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <cmath>
#include <iostream>
using namespace std;

// function prototypes -----------------------
double myPow(double base, long exp);

int main()
{
   cout << myPow(2.4, 4) << " vs. " << pow(2.4, 4) << endl;
   cout << myPow(1.23, 9) << " vs. " << pow(1.23, 9) << endl;
   cout << myPow(5535, -29) << " vs. " << pow(5535., -29) << endl;
}

// -------  My Power --------------
double myPow(double base, long exp)
{
   if (exp == 0)
      return 1.;
   if (exp < 0)
      return 1. / myPow( base, -exp);
   else
      return base * myPow( base, exp-1 );
}