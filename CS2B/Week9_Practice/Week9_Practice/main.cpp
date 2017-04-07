//
//  main.cpp
//  Week9_Practice
//
//  Created by Connor Lynch on 11/20/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <string> 
using namespace std;

class IntNode
{
public:
   IntNode(){}
   IntNode(int theData, IntNode* theLink): data(theData), link(theLink){}
   IntNode* getLink() const {return  link;}
   int getData() const{return data;}
   void setData(int theData) { data = theData; }
   void setLink(IntNode* pointer) {link = pointer; }
private:
   int data;
   IntNode *link;
};
typedef IntNode* IntNodePtr;




class DoublyLinkedIntNode
{
   DoublyLinkedIntNode() {}
   
};


int main()
{
   IntNodePtr head;
   head = new IntNode(3, NULL);
   return 0;
}


