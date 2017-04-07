//
//  Hashing.h
//  CS2C_Week6_Homework6
//
//  Created by Connor Lynch on 2/17/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

#ifndef __CS2C_Week6_Homework6__Hashing__
#define __CS2C_Week6_Homework6__Hashing__

#include <iostream>


// File FHhashSC.h
// Template definitions for FHhashSC.
// Separate Chaining Hash Table
#ifndef FHHASHSC_H
#define FHHASHSC_H
#include "FHvector.h"
#include "FHlist.h"
#include <cmath>
using namespace std;

// ---------------------- FHhashSC Prototype --------------------------
template <class Object>
class FHhashSC
{
protected:
   static const int INIT_TABLE_SIZE = 97;
   static const float INIT_MAX_LAMBDA;
   FHvector< FHlist<Object> > mLists;
   int mSize;
   int mTableSize;
   float mMaxLambda;

public:
   FHhashSC(int tableSize = INIT_TABLE_SIZE);
   bool contains(const Object & x) const;
   void makeEmpty();
   bool insert(const Object & x);
   bool remove(const Object & x);
   static long nextPrime(long n);
   int size() const { return mSize; }
   bool setMaxLambda( float lm );

protected:
   void rehash();
   int myHash(const Object & x) const;
};

template <class Object>
const float FHhashSC<Object>::INIT_MAX_LAMBDA = 1.5;


#endif /* defined(__CS2C_Week6_Homework6__Hashing__) */








