/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Febuary 19, 2017
 Professor Dave Harden
 Assignment 6.1

 Description: This class lays out the needed methods for a quadratic probing 
 hash table to have a find capability. Inheriting from FHHashQP, this class
 provides several additional methods, find, myHashKey, and findPosKey that 
 allows the client to pass in a key and return the object stored in the 
 hash table. Unlike the contains method, the client no longer needs to pass 
 in an object to find an object.

 Member Functions:
 const Object find(const KeyType & key)
   Precondition: A hash table exists where items can be mapped to locations using
      the KeyType key paramater
   Postcondition: If an item that maps to the passed key can be found in the hash
      table returns that object, otherwise throws not found exception

 int myHashKey(const KeyType & key) const
   Precondition: key of type KeyType can be mapped to an integer index value in the 
      hash table.
   Postcondition: Returns integer index value calculated from key to place item
      in hash table.

 int findPosKey( const KeyType & key ) const
   Precondition: A hash table exists such that key can be mapped to an integer
      value within the table
   Postcondition: The integer index value of the item in the hash table that
      maps to the provided key is returned.
*/

#ifndef FHhashQPwFind_H_
#define FHhashQPwFind_H_

#include "FHhashQP.h"
#include <iostream>

template <class Object, typename KeyType>
class FHhashQPwFind : public FHhashQP<Object>
{
public:
   const Object find(const KeyType & key);
   class NotFoundException {};

protected:
   int myHashKey(const KeyType & key) const;
   int findPosKey( const KeyType & key ) const;

private:

};






//Member function that takes a key value of type KeyType and returns the
//data stored in the hash table at that key or throws an exception if
//item is not in active state
template <class Object, typename KeyType>
const Object FHhashQPwFind<Object, KeyType>::find(const KeyType & key)
{
   int index = findPosKey(key);

   if (this->mArray[index].state == FHhashQP<Object>::ACTIVE)
      return this->mArray[index].data;
   else
      throw NotFoundException();
}






//Member function that takes a key value of type KeyType and returns and
//returns the integer hash value for the key
template <class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::myHashKey(const KeyType & key) const
{
   int hashVal = Hash(key) % this->mTableSize;
   if(hashVal < 0)
      hashVal += this->mTableSize;

   return hashVal;
}






//Member function that takes a key value of type KeyType and returns the integer
//index location of the item in the hash table if it exists
template <class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::findPosKey( const KeyType & key ) const
{
   int kthOddNum = 1;
   int index = myHashKey(key);

   while ( this->mArray[index].state != FHhashQP<Object>::EMPTY
          && Hash(this->mArray[index].data) != Hash(key))
   {
      index += kthOddNum;
      kthOddNum += 2;
      if (index >= this->mTableSize)
         index -= this->mTableSize;
   }

   return index;
}

#endif
