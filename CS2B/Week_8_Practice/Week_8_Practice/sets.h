//
//  sets.h
//  Week_8_Practice
//
//  Created by Connor Lynch on 11/20/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#ifndef __Week_8_Practice__sets__
#define __Week_8_Practice__sets__

#include <iostream>

template <class T>
class sets
{
public:
   class rangeError {};
   typedef  std::size_t size_type;
   typedef T value_type;
   sets();
   void addItem(value_type newItem);
   size_type getSize();
   size_type getCap();
   void printSet();

private:
   value_type *setPtr;
   size_type setSize;
   size_type setCap;
};

#include "sets.cpp" 

#endif
