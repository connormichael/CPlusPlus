//
//  hasher.cpp
//  CS2C Warmup
//
//  Created by Connor Lynch on 12/31/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include "hasher.h"
#include "connor_vect.h"
#include <string>
using std::string; 
using namespace std;

namespace hashing
{


   int HashTable::computeHash(string newItem)
   {
      int hash = 0, divisor = 11;

      for (int i = 0; i < newItem.length(); i++)
      {
         hash += newItem[i] * i;
      }
      hash /= divisor;

      return hash;
   }
}


