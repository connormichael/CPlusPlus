//
//  main.cpp
//  Assignment_2.1
//
//  Created by Connor Lynch on 10/2/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(int argc, const char * argv[])
{
   ifstream infile;
   char ch;
   string astring;

   infile.open("test_textfile.txt");
   if (!infile)
      cout << "couldn't open file. " << endl;
   else
   {
      infile.get(ch);
      while (infile)
      {
         cout << ch;
         infile.get(ch);
      }
      infile.close();
   }


   int *intptr;
   intptr = new int;
   *intptr = 5;

   int five;
   intptr = &five; //intptr gets the address of five

   cout << *intptr << endl;

   //in C++ arrays are actually pointer constants
   int array2[10];
   int *ptr;
   ptr = array2; //this is equalivalt to saying ptr = &array2[0];

   for (int i = 0; i < 10; i++)
   {
      ptr[i] = i;
      cout << ptr[i] << endl;
   }

   int *ptr3;
   ptr3 = new int;
   *ptr3 = 20;

   cout << *ptr3 << endl;
   delete ptr3;

   cout << *ptr3 << endl;

   //we cannot reassing array2 because an array name without the square brackets
   //is not just a pointer, but a pointer constant



   return 0;
}





