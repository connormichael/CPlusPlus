//
//  main.cpp
//  Week10_Practice
//
//  Created by Connor Lynch on 12/4/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//


// This program taken from "C++: The Complete Reference"
// by Herbert Schildt



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

template <class T>
class MyVector {
public:
   typedef std::size_t size_type;
   typedef T value_type;
   MyVector(size_type inSize = 0, const value_type& inValue = value_type());
   size_type size() const;
   size_type capacity() const;
   value_type at(size_type i) const;
   void push_back(const value_type& insertMe);
private:
   value_type* items;
   size_type mSize;
   size_type mCapacity;
};


template <class T>
MyVector<T>::MyVector(size_type inSize, const value_type& inValue) {
   mSize = inSize;
   mCapacity = inSize;
   items = new value_type[inSize];
   for (size_type i = 0; i < mSize; i++) {
      items[i] = inValue;
   }
}


template <class T>
typename MyVector<T>::size_type MyVector<T>::size() const {
   return mSize;
}


template <class T>
void MyVector<T>::push_back(const value_type& inValue){
   if (mSize < mCapacity) {
      items[mSize] = inValue;
      mSize++;
   } else {
      if (mCapacity == 0) {
         mCapacity = 1;
      } else {
         mCapacity *= 2;
      }
      value_type* temp = new value_type[mCapacity];
      for (size_type i = 0; i < mSize; i++) {
         temp[i] = items[i];
      }
      temp[mSize] = inValue;
      mSize++;
      delete [] items;
      items = temp;
   }
}



template <class T>
typename MyVector<T>::size_type MyVector::capacity() const {
   return mCapacity;
}



template <class T>
typename MyVector<T>::value_type MyVector::at(size_type i) const
{
   assert(i >= 0 && i < size());
   return items[i];
}




void print(MyVector& printMe);

int main() {
   typedef string value_type;
   value_type x =  "connor";

   MyVector v;
   MyVector::size_type currentSize;

   for (int i = 0; i < 20; i++) {
      v.push_back(i);

      currentSize = v.size();
      cout << "size: " << currentSize << " capacity: " << v.capacity() << endl;
   }

   print(v);
}




void print(MyVector& printMe) {
   for (int i = 0; i < printMe.size(); i++) {
      cout << printMe.at(i) << " ";
   }
   cout << endl;
}





