//
//  main.cpp
//  CS2C_WeekOne_Practice
//
//  Created by Connor Lynch on 1/12/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

// Analysis of arrays vs. vectors using various access techniques
// CS 2C, Foothill College, Michael Loceff, creator

#include <iostream>
#include <string>
using namespace std;

#include <vector>

class NewArray
{
public:
   static const long MAX_ARRAY_SIZE = 100000L;
   float *data;
   long size;

   NewArray(int newSize, float newData);
   NewArray(const NewArray& rightArray);
   ~NewArray();
   float &operator[](long index);
   NewArray &operator=(const NewArray& rightArray);

};


int main()
{
   return 0;
}


NewArray::NewArray(int newSize, float newData)
{
   data = new float[newSize];
   data[0] = newData;
}

NewArray::NewArray(const NewArray& rightArray) : data(NULL)
{
   *this = rightArray;  //just use the assignment operator but then you must declare the data null to avoid failure in the assignemtn operator methos
}


NewArray::~NewArray()
{
   delete[] data;
}

float &NewArray::operator[](long index)
{
   static float buffer = 0.0;
   if ((index < 0) || (index >= size))
      return buffer;
   else
      return data[index];
}

NewArray &NewArray::operator=(const NewArray& rightArray)
{
   if (this == &rightArray)
      return *this;
   else
   {
      size = rightArray.size;
      delete[] this;
      data = new float[rightArray.size];
      for (int k = 0; k < rightArray.size; k++)
         data[k] = rightArray.data[k];
   }
   return *this;
}






















