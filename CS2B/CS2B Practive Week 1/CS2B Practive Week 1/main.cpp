//=====================================================================================
// Name        : Pointers.cpp
// Author      : CS 2B
// Date          : Spring 2016
// Version     :
// Copyright   : Copyright (C). CS Department Foothill College 2015. All rights reserved.
// Description : Illustration of variables and their memory addresses
//=====================================================================================

#include <iostream>
#include <iomanip>
using namespace std;

class MovieTicket {
private:
   string seat_;
   double price_;
public:
   // construstors/destructor/member functions ...
};

int main() {

   int count = 10;
   double price = 5.99;
   MovieTicket  ticket;





   int * pointer_int = NULL;
   int month = 1;
   pointer_int = &month;
   cout << "The month should be 1 " << month << endl;
   *pointer_int = 2;
   cout << "I changed the month " << month << endl;


   cout << "count's value: " << count << endl;
   cout << "count's memory address: " << &count << endl;

   cout << "price's value: " << fixed << setprecision(2) << price << endl;
   cout << "price's memory address: " << &price << endl;

   cout << "MovieTicket object's memory address: " << &ticket << endl;

   cout << "--------------------------------------------\n\n" ;



   const int  kSize = 4;
   int list[kSize] = { 10,20,30,40 } ;

   cout << "Print array elements' values and memory addresses:"  << endl;
   cout << "--------------------------------------------\n" ;
   cout << "Element\t\tValue\t\tAddress\n";
   cout << "--------------------------------------------\n" ;


   for (int i=0; i< kSize ;++i) {
      cout << setw(3) << "[" << i << "]\t\t" << list[i] << "\t\t" << &list[i] << endl ;
   }


   return 0;
}