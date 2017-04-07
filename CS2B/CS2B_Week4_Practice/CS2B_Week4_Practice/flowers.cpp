//
//  main.cpp
//  CS2B_Week4_Practice
//
//  Created by Connor Lynch on 10/23/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

/* 
The big three: copy constructor, desctructor, and assignment operator
If we did not fix the assignment operator when dealing with dynamic arrays
 we could easily get memory leaks during reassignemnt since C++ defaults to doing member
 wise assignment
The destructor is necessary since when you create a variable in a function 
 the variable only exists until the function completes executions then they are 
 removed off the stack but we havent removed everything heap so we need the desctor to remove this

The fourth method you need for classes with dynamic variables is a default constructor: 
 + Also C++ just wont let you do this.
 + when the execution reaches the end of a function where an object was declared 
   it will call on the destuctor which will atempt to delete  statement on a pointer
   that
 + 
 
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
#include "flowers.h"
using namespace std;

namespace flowers
{
   Flowers::Flowers()
   {
      pettles = new char[0];

   }






   Flowers::Flowers(const char *inPettles)
   {
      pettles = new char[strlen(inPettles) + 1];
      strcpy(pettles, inPettles);
   }






   Flowers::Flowers(const Flowers& rightFlower)
   {
      pettles = new char[strlen(rightFlower.pettles) + 1];
      strcpy(pettles, rightFlower.pettles);
   }






   Flowers Flowers::operator=(const Flowers& rightFlower)
   {
      if (this != &rightFlower)
      {
         delete [] pettles;
         pettles = new char[strlen(rightFlower.pettles) + 1];
         strcpy(pettles, rightFlower.pettles);
      }
      return *this;
   }






   Flowers::~Flowers()
   {
      delete [] pettles;
   }

   
   



   char& Flowers::operator[](int index) const
   {
      assert(index >= 0 && index < strlen(pettles));
      return pettles[index];
   }





   istream& operator>>(istream& in, Flowers& target)
   {
      while (isspace(in.peek()))
      {
         in.ignore();
      }
      char temp[128];
      in.getline(temp, 127, ':');
      delete [] 

      return in;

   }






}











