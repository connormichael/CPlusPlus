/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 21, 2016
 Professor Dave Harden
 Assignment 8.2
 */

#include <iostream>

namespace cs_pairs
{
   template <class T>
   class orderedPair {
   public:
      class DuplicateMemberError {};
      typedef T value_type;
      static const value_type DEFAULT_VALUE;
      orderedPair(value_type newFirst = DEFAULT_VALUE,
                  value_type newSecond = DEFAULT_VALUE);
      void setFirst(value_type newFirst);
      void setSecond(value_type newSecond);
      value_type getFirst();
      value_type getSecond();
      orderedPair operator+(const orderedPair<T>& right);
      bool operator<(const orderedPair<T>& right);
      void print();
   private:
      value_type first;
      value_type second;
   };

   template <class T>
   const typename orderedPair<T>::value_type orderedPair<T>::DEFAULT_VALUE = value_type();
}

#include "orderedpair.cpp" 
