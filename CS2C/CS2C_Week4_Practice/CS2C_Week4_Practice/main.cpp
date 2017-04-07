//
//  main.cpp
//  CS2C_Week4_Practice
//
//  Created by Connor Lynch on 1/31/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

#include <iostream>
using namespace std;



//functor
class PrintString
{
public:
   void operator()(string s)
   {
      cout << s << endl;
   }
};


// advanced prototype for the FHtreeNode to use to declare a friend
template <class Object>
class FHtree;

template <class Object>
class FHtreeNode
{
   friend class FHtree<Object>;

public:
   FHtreeNode(): prev(nullptr), sib(nullptr), next(nullptr), data(0) {};
   FHtreeNode(FHtreeNode* newPrev, FHtreeNode* newSib, FHtreeNode* newNext,
              Object newData): prev(newPrev), sib(newSib), next(newNext),
              data(newData) {};

private:
   FHtreeNode *prev, *sib, *next;
   Object data;
   const FHtreeNode *root;  //used to ensure that a passed node is actually part of the tree
};


template <class Object>
class FHtree
{

private:
   int mSize;
   FHtreeNode<Object> *root;

public:
   
};


void showArrayUsingThisFunc( PrintString g );

int main()
{
   FHtreeNode<int> nody;


   PrintString g;

   g("Does this really work?");
   g("Apparently");

   cout << "Still working" << endl;
   showArrayUsingThisFunc(g);

   return 0;
}



void showArrayUsingThisFunc( PrintString g )
{
   string myArray[] = {"hi", "mom!", "3", "45", "this is wild"};
   int k;

   for (k = 0; k < sizeof(myArray)/sizeof(myArray[0]); k++)
      g(myArray[k]);
}
