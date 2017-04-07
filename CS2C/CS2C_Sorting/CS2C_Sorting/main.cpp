//
//  main.cpp
//  CS2C_Sorting
//
//  Created by Connor Lynch on 1/1/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename Comparable>
void insertionSort(vector<Comparable>& a);
template <typename Comparable>
void print(vector<Comparable>& a);

int main()
{
   vector<int> a = {1,5,0,9,10};
   insertionSort(a);
   print(a);

   for (auto & x : a)
   {
      ++x;
      cout << x << endl;
   }

   return 0;
}

template <typename Comparable>
void insertionSort(vector<Comparable>& a)
{
   for(int p = 1; p < a.size(); ++p)  //why use pre-increment here?
   {
      Comparable tmp = std::move(a[p]);  //make this value temporary essentiall

      int j; //why initialize this outside of for loop
      for(j = p; j > 0 && tmp < a[j -1]; --j)
         a[j] = std::move(a[j - 1]);
      a[j] = std::move(tmp);

   }
}

template <typename Comparable>
void print(vector<Comparable>& a)
{
   for(int i = 0; i < a.size(); i++)
      cout << a[i] << endl;
}


