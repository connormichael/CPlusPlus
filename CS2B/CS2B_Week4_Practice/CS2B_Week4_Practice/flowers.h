//
//  Flowers.h
//  CS2B_Week4_Practice
//
//  Created by Connor Lynch on 10/23/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>

#ifndef Flowers_h
#define Flowers_h
namespace flowers
{
   class Flowers
   {
   public:
      Flowers(); //Default constructor
      Flowers(const char *inPettles); //parameter taking constructor
      Flowers(const Flowers& rightFlower);  //copy constructor
      Flowers operator=(const Flowers& rightFlower); //assignment operator
      ~Flowers(); //destructor
      char& operator[](int index) const;
      friend std::istream& operator>>(std::istream& in, Flowers& target);

      
   private:
      char *pettles;
   };
}

#endif
