//
//  myvector.cpp
//  Week8_HomeWork8
//
//  Created by Connor Lynch on 11/17/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

template <class T>
MyVector::MyVector<T>(size_type inSize, const value_type& inValue) {
   mSize = inSize;
   mCapacity = inSize;
   items = new value_type[inSize];
   for (size_type i = 0; i < mSize; i++)
   {
      items[i] = inValue;
   }
}




template <class T>
MyVector<T>::size_type MyVector<T>::size() const {
   return typename mSize;
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
MyVector<T>::size_type MyVector<T>::capacity() const {
   return typename mCapacity;
}




template <class T>
MyVector<T>::value_type MyVector<T>::at(size_type i) const {
   assert(i >= 0 && i < size());
   return typename items[i];
}
