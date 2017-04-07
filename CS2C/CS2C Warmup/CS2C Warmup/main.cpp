/*
 Connor Lynch
 December 28, 2016 
 Prep for CS2C
 Abstract Data Types: Lists, Stacks, and Queues 
 
 An 

 */

#include <iostream>
#include "connor_vect.h"
#include <string>
using namespace listy;
using namespace node;

int main()
{

   std::cout << "Hello, World!\n";
   list<string> test_list;
   string x = "connor";
   string y = "abbey";
   string z = "ooo";
   test_list.add(x);
   test_list.add(y);
   test_list.add(z);
   test_list.print();
   //test_list.remove(10);
   test_list.insertionSort(); 
   std::cout << "List again" << std::endl;
   test_list.print();
   test_list.pop();


   Queue<char> q;
   q.add('a');
   


   
   return 0;
}







