/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 21, 2016
 Professor Dave Harden
 Assignment 8.2
 */

namespace cs_pairs
{
   template <class T>
   orderedPair<T>::orderedPair(value_type newFirst, value_type newSecond)
   {
      setFirst(newFirst);
      setSecond(newSecond);
   }






   template <class T>
   void orderedPair<T>::setFirst(value_type newFirst)
   {
      if ((newFirst != DEFAULT_VALUE) && (newFirst == second))
         throw DuplicateMemberError();
      first = newFirst;
   }






   template <class T>
   void orderedPair<T>::setSecond(value_type newSecond)
   {
      if ((newSecond != DEFAULT_VALUE) && (newSecond == first))
         throw DuplicateMemberError();
      second = newSecond;
   }






   template <class T>
   typename orderedPair<T>::value_type orderedPair<T>::getFirst()
   {
      return first;
   }






   template <class T>
   typename orderedPair<T>::value_type orderedPair<T>::getSecond()
   {
      return second;
   }






   template <class T>
   orderedPair<T> orderedPair<T>::operator+(const orderedPair<T>& right)
   {
      return orderedPair<T>(first + right.first, second + right.second);
   }






   template <class T>
   bool orderedPair<T>::operator<(const orderedPair<T>& right)
   {
      return first + second < right.first + right.second;
   }






   template <class T> 
   void orderedPair<T>::print()
   {
      std::cout << "(" << first << ", " << second << ")";
   }
}
