//
//  main.cpp
//  CS2C_Trees
//
//  Created by Connor Lynch on 1/2/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

#include <iostream>
#include "Tree.h"
#include "TreeNode.h"
using namespace connor_tree;
using namespace std;

int main()
{
   SearchTree tree = SearchTree();
   tree.addItem(1);
   tree.addItem(5);
   tree.addItem(10);
   tree.addItem(1000);
   //tree.inorderShow();
   cout << tree.findMax() << endl;
   cout << tree.getSubTreeHeight(tree.root, 0); 
   return 0;
}

