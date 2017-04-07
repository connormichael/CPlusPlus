//
//  Tree.cpp
//  CS2C_Trees
//
//  Created by Connor Lynch on 1/2/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

#include "Tree.h"

namespace connor_tree
{

   SearchTree::~SearchTree()
   {
      deleteSubTree(root);
   }

   void SearchTree::deleteSubTree(TreeNode*& tempRoot)
   {
      if (tempRoot != NULL)
      {
         deleteSubTree(tempRoot->left);
         deleteSubTree(tempRoot->right);
         delete tempRoot;
         tempRoot = NULL;
      }
   }


   void SearchTree::addItem(SearchTree::value_type newItem)
   {
      addItem(newItem, root);
   }


   void SearchTree::addItem(SearchTree::value_type newItem, TreeNode*& subTreeRoot)
   {
      if (subTreeRoot == NULL)
      {
         subTreeRoot = new TreeNode(newItem, NULL, NULL);
      }
      else if (newItem >= subTreeRoot->data)
      {
         addItem(newItem, subTreeRoot->right);
      }
      else if (newItem < subTreeRoot->data)
      {
         addItem(newItem, subTreeRoot->left);
      }

   }

   void SearchTree::inorderShow()
   {
      inorderShow(root);
   }


   void SearchTree::inorderShow(TreeNode*& tempRoot) const
   {
      if (tempRoot != NULL)
      {
         inorderShow(tempRoot->left);
         std::cout << tempRoot->data << " ";
         inorderShow(tempRoot->right); 
      }
   }


   bool SearchTree::inTree(SearchTree::value_type item)
   {
      return inTree(root, item);
   }


   bool SearchTree::inTree(TreeNode*& tempRoot, SearchTree::value_type item)
   {
      if (tempRoot == NULL)
         return false;
      else if (tempRoot->data == item)
         return true;
      else if (tempRoot->data > item)
         return inTree(tempRoot->left, item);
      //else if (tempRoot->data < item)
         return inTree(tempRoot->right, item);
   }


   typename SearchTree::value_type SearchTree::findMax()
   {
      value_type max;
      TreeNode* maxLink = root;
      if (root == NULL)
         max = 0;
      else
      {
         while (maxLink->right != NULL)
            maxLink = maxLink->right;
      max = maxLink->data;
      }
      return max;
   }

   
   bool SearchTree::isEmpty() const
   {
      return root == NULL;
   }



   

   bool SearchTree::checkBalance() const
   {


         return true;
      
   }


   int SearchTree::getSubTreeHeight(TreeNode*& tempRoot, int height) const
   {
      if (tempRoot == NULL)
         return 0;
      else
      {
         std::cout << "height: " << height << std::endl;
         return height += std::max(getSubTreeHeight(tempRoot->left, height),
                            getSubTreeHeight(tempRoot->right, height));
      }
   }


}










