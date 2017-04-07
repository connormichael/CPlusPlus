/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 21, 2016
 Professor Dave Harden
 Assignment 8.2
 */


#include <iostream>
#include "orderedpair.h"
#include <string> 
using namespace std;
using namespace cs_pairs;


int main()
{
   int num1, num2;
   orderedPair<int> myList[10];

   cout << "default value: ";
   myList[0].print();
   cout << endl;

   for (int i = 0; i < 10; i++) {
      myList[i].setFirst(rand() % 50);
      myList[i].setSecond(rand() % 50 + 50);
   }

   myList[2] = myList[0] + myList[1];

   if (myList[0] < myList[1]) {
      myList[0].print();
      cout << " is less than ";
      myList[1].print();
      cout << endl;
   }

   for (int i = 0; i < 10; i++)
   {
      myList[i].print();
      cout << endl;
   }

   cout << "Enter two numbers to use in an orderedPair. Make sure they are different numbers: ";
   cin >> num1 >> num2;

   orderedPair<int> x;

   try
   {
      x.setFirst(num1);
      x.setSecond(num2);
   }
   catch (orderedPair<int>::DuplicateMemberError e)
   {
      x.setFirst(0);
      x.setSecond(0);
   }

   cout << "The resulting orderedPair: ";
   x.print();
   cout << endl;

   //Testing the template class with strings types
   cout << endl;
   cout << "Demonstrate use of template class with ordered strings" << endl;

   string str1, str2;
   orderedPair<string> myList2[10];

   cout << "default value: ";
   myList2[0].print();
   cout << endl;

   for (int i = 0; i < 10; i++)
   {
      string empty = "";
      myList2[i].setFirst(empty + char('a' + rand() % 13));
      myList2[i].setSecond(empty + char('n' + rand() % 13));
   }

   myList2[2] = myList2[0] + myList2[1];

   if (myList2[0] < myList2[1]) {
      myList2[0].print();
      cout << " is less than ";
      myList2[1].print();
      cout << endl;
   }

   for (int i = 0; i < 10; i++)
   {
      myList2[i].print();
      cout << endl;
   }

   cout << "Enter two numbers to use in an orderedPair. Make sure they are different numbers: ";
   cin >> str1 >> str2;

   orderedPair<string> strx;

   try
   {
      strx.setFirst(str1);
      strx.setSecond(str2);
   }
   catch (orderedPair<string>::DuplicateMemberError e)
   {
      string empty = "";
      strx.setFirst(empty);
      strx.setSecond(empty);
   }

   cout << "The resulting orderedPair: ";
   strx.print();
   cout << endl;
}

/*--------------------- Connor's Output ---------------------------
 
 default value: (0, 0)
(7, 99)
(23, 58)
(30, 157)
(44, 78)
(23, 59)
(40, 65)
(42, 92)
(37, 53)
(27, 79)
(40, 62)
Enter two numbers to use in an orderedPair. Make sure they are different numbers: 1 1
The resulting orderedPair: (0, 0)

Demonstrate use of template class with ordered strings
default value: (, )
(f, r) is less than (m, r)
(f, r)
(m, r)
(fm, rr)
(l, y)
(g, s)
(i, r)
(h, y)
(d, s)
(c, q)
(b, u)
Enter two numbers to use in an orderedPair. Make sure they are different numbers: a b
The resulting orderedPair: (a, b)
Program ended with exit code: 0
 
----------------------- End of Output ---------------------------------*/

