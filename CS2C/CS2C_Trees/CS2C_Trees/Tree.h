//
//  Tree.h
//  CS2C_Trees
//
//  Created by Connor Lynch on 1/2/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

#ifndef __CS2C_Trees__Tree__
#define __CS2C_Trees__Tree__

#include <iostream>
#include "TreeNode.h"

/*
 What that a tree needs? Similiar to a linked list 
 1. show it 
 2. check if item exits 
 3. add items 

 */
namespace connor_tree
{
   class SearchTree
   {
   public:
      typedef int value_type;
      friend class TreeNode; 
      SearchTree() : root(NULL) {};
      //SearchTree(SearchTree& copyTree);
      SearchTree operator =(SearchTree& rightTree);
      virtual ~SearchTree();
      void addItem(value_type newItem);
      void inorderShow();
      bool inTree(value_type item);
      bool isEmpty() const;
      value_type findMax();
      bool checkBalance() const;
      int getSubTreeHeight(TreeNode*& tempRoot, int height) const;
      
   private:
      void addItem(value_type newItem, TreeNode*& root);
      void inorderShow(TreeNode*& tempRoot) const;
      bool inTree(TreeNode*& tempRoot, value_type item);
      void deleteSubTree(TreeNode*& tempRoot);

   public: 
      TreeNode* root;
   };
}

#endif /* defined(__CS2C_Trees__Tree__) */
