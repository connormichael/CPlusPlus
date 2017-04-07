/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Janunary 14, 2017
 Professor Dave Harden
 Assignment 1.2

 Description:
 The program lays out the methods for the Sublist class. Sublist objects are
 composed a an integer sum, a vector pointer, and a vector of integer
 indices.

 Member Functions:
 Sublist()
 Precondition: No preconditions for default constuctor
 Postcondition: A Sublist object with all three data members initialized

 Sublist<T> addItem( int indexOfItemToAdd )
 Precondition: Calling object as a valid pointer to a vector
 Postcondition: New Sublist object whose array has all the values of the
 calling object, plus the value of pointed array index location

 void showSublist() const
 Precondition: No precondition
 Postcondition: Outputs the array contents of the Sublist object

 int getSum() const
 Precondition: No precondition
 Postcondition: Returns the sum data member for the Sublist object.
 */


#ifndef __CS2C_WeekOne_HomeworkOne__newVect__
#define __CS2C_WeekOne_HomeworkOne__newVect__

#include <iostream>
#include <vector>
namespace sublist
{
   template <class T>
   class Sublist
   {
   public:
      Sublist(std::vector<T> *orig = NULL)
      : sum(0), originalObjects (orig) { }
      Sublist<T> addItem( int indexOfItemToAdd );
      void showSublist() const;
      int getSum() const { return sum; }

   private:
      int sum;
      std::vector<T> *originalObjects;
      std::vector<int> indices;
   };
}
#include "newVect.cpp"

#endif