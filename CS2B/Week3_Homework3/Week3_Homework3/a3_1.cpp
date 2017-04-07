/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 15, 2016
 Professor Dave Harden
 Assignment 3.1 Pointers and Dynamic Memory
 
 Program Overview: 
 This program demonstrates the uses of pointers. In the main() there are 
 23 operations that use pointer for various tasks and demonstrate the use of 
 the "Address Of" operator, the Dereference (*) operator, assignment
 of pointers and other operations i.e. use of pointers in arrays. 
 The program requires no user input.
 */

#include <iostream>
using namespace std;

void noNegatives(int *x);
void swap(int *p1, int *p2);

int main()
{
   //1
   int x, y;
   //2
   int *p1;
   //3
   p1 = &x;
   //4
   *p1 = 99;
   //5
   cout << "The value of x is: " << x << endl;
   //6
   cout << "The value of x is: " << *p1 << endl;
   //7
   p1 = &y;
   //8
   *p1 = -300;
   //9
   int temp, *p2;
   p2 = &x;
   //10
   temp = *p1;
   *p1 = *p2;
   *p2 = temp;
   //11 & 12
   noNegatives(&x);
   noNegatives(&y);
   //13
   p2 = &x;
   cout << "x is: " << *p2 << endl;
   p2 = &y;
   cout << "y is: " << *p2 << endl;
   //14
   int a[2];
   p2 = a;
   //15
   *p2 = x;
   //16
   p2 += 1;
   *p2 = y;
   //17
   p2 -= 1;
   cout << "The the address of the first element is a is: " <<  p2 << endl;
   //18
   p2 += 1;
   cout  << "The the address of the second element is a is: " << p2 << endl;
   //19
   p1 = a;
   p2 = &a[1];
   temp = *p1;
   *p1 = *p2;
   *p2 = temp;
   //20
   cout << "The value of a[0]: " << a[0] << endl;
   cout << "The value of a[1]: " << a[1] << endl;
   //21 and 22
   swap(&x, &y);
   cout << "The value of x: " << x << endl;
   cout << "The value of y: " << y << endl;
   //23
   swap(p1, p2);
   cout << "The value of a[0]: " << *p1 << endl;
   cout << "The value of a[1]: " << *p2 << endl;
}






void noNegatives(int *x)
{
   if (*x < 0)
      *x = 0;
}






void swap(int *p1, int *p2)
{
   int temp;
   temp = *p1;
   *p1 = *p2;
   *p2 = temp;
}






/*------------------ Connor's Output -------------------------

The value of x is: 99
The value of x is: 99
x is: 0
y is: 99
The the address of the first element is a is: 0x7fff5fbff760
The the address of the second element is a is: 0x7fff5fbff764
The value of a[0]: 99
The value of a[1]: 0
The value of x: 99
The value of y: 0
The value of a[0]: 0
The value of a[1]: 99
Program ended with exit code: 0

------------------------------------------------------------*/






