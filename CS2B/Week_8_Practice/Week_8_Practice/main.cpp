//
//  main.cpp
//  Week_8_Practice
//
//  Created by Connor Lynch on 11/20/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <string>
#include "sets.h" 
using namespace std; 

template <class T>
void search(const T a[], int lowEnd, int highEnd,
            int key, bool& found, int& location);

int main()
{

   sets<int> set1;
   try
   {
      set1.addItem(-1);
   }
   catch (sets<int>::rangeError e)
   {
      cout << "Error" << endl;
   }
   set1.addItem('b');
   set1.printSet(); 

   

   

   /*
   char a[] = {'a','b','c','d'};
   int lowEnd = 0;
   int highEnd = 3;
   char key = 'c';
   bool found = false;
   int location = 0;
   search(a, lowEnd, highEnd, key, &found, &location);
    */

   return 0;
}


//templated version of iterative binary search
template <class T>
void search(const T a[], int lowEnd, int highEnd,
            T key, bool& found, int& location)
{
   int first = lowEnd;
   int last = highEnd;
   int mid;

   found = false;

   while ((first <= last) && !(found))
   {
      mid = (first + last)/2;
      if (key == a[mid])
      {
         found = true;
         location = mid;
      }
      else if (key < a[mid])
      {
         last = mid - 1;
      }
      else if (key > a[mid])
      {
         first = mid + 1;
      }
   }
}






