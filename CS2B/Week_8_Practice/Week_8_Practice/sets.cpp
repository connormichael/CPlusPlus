//  sets.cpp
//  Week_8_Practice
//
//  Created by Connor Lynch on 11/20/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <string> 
using namespace std;

template <class T>
sets<T>::sets()
{
   setSize = 0;
   setCap = 0;
   setPtr = new value_type[0];
}







template <class T>
void sets<T>::addItem(value_type newItem)
{
   if (setCap == 0)
      setCap = 1;
   else if (setSize == setCap)
      setCap *= 2;

   if (newItem < 0)
      throw rangeError();
   setPtr[setSize] = newItem;
   setSize++;
}






template <class T>
typename sets<T>::size_type sets<T>::getSize()
{
   return setSize;
}






template <class T>
typename sets<T>::size_type sets<T>::getCap()
{
   return setCap;
}






template <class T>
void sets<T>::printSet()
{
   for (int i = 0; i < setSize; i++)
   {
      std::cout << setPtr[i] << std::endl;
   }
}






