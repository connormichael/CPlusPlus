//
//  main.cpp
//  Lab 6 Sovlving problems with getline
//
//  Created by Connor Lynch on 2/7/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

//
//  main.cpp
//  Rough Assignment 6
//
//  Created by Connor Lynch on 2/7/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <string>
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
//void display(TripleString, thePull, int winnings);



//Here is my main
int main()
{
   //declaring the string objects
   TripleString string1, string2, string3;

   //setting some values for the string objects
   string1.setStringNameOne("Xasd");
   string1.getStringNameOne();
   cout << string1.getStringNameOne() <<endl;
   string2.setStringNameTwo("Y");
   cout << string2.getStringNameTwo() << endl;

   return 0;
}




//Here are the global-scope method definitions()
int getBet()
{
   int betAmount;

   while(true)
   {
      cout << "Please enter a bet amount between 0 and 50"<< endl;
      getline(cin, betAmount);
   }
}


//Here is the Default Constructor
TripleString::TripleString()  //Does the constructor return anything?
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


bool TripleString::setStringNameOne(string stringName)  //I think i might actually need three of these...
{
   if (!validString(stringName))
      return false;
   string1 = stringName;
   return true;
}

bool TripleString::setStringNameTwo(string stringName)  //I think i might actually need three of these...
{
   if (!validString(stringName))
      return false;
   string2 = stringName;
   return true;
}

bool TripleString::setStringNameThree(string stringName)  //I think i might actually need three of these...
{
   if (!validString(stringName))
      return false;
   string3 = stringName;
   return true;
}


