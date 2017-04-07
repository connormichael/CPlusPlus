//
//  hasher.h
//  CS2C Warmup
//
//  Created by Connor Lynch on 12/31/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#ifndef __CS2C_Warmup__hasher__
#define __CS2C_Warmup__hasher__

#include <iostream>
#include <string>
using namespace std; 
#include "connor_vect.h"

namespace hashing
{
   int const SIZE = 11;  //must use const if you want an array to be variable lenght you must use dyanmic array
   
   class HashTable
   {
   public:
      HashTable();
      virtual ~HashTable();

   private:
      int computeHash(string newItem);
      string table[SIZE];

   };
}

#endif /* defined(__CS2C_Warmup__hasher__) */
