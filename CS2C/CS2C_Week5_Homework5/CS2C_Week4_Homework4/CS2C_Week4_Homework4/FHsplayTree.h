/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Febuary 12, 2017
 Professor Dave Harden
 Assignment 5.1
 
 Description:
 The program lays out the methods for the FHsplayTree class. Objects of this 
 class are Splay trees, modified binary search trees, whose most recently 
 accessed value is located at the root node of the tree. To enable this 
 behavior, rotation of the tree are enabled. Rotations occur during the 
 splay procedure which causes the accesssed/inserted/removed node to be 
 brought to the root of the tree while still maintaining the BST conditions. 
 This template class relies on a single comparator, <, to evaluate the 
 position of the root node. This implementation of splay tree allows for 
 amortized algorithm complexity of O(log(N)) for access/removal for when access/
 removal occurs in repeated nature such that the number of access/removal for 
 the same node occurs N consequetive times.


 Member Functions:
 bool insert(const Comparable &x)
    Precondition: None, if a splay tree is empty, new node is built.
    Postcondition: A new node on the Splay tree is inserted such that the BST 
    conditions are maintained. Duplicates are not inserted.

 bool remove(const Comparable &x)
    Precondition: None, if a splay tree is empty, method returns false
    Postcondition: Node that contained x is removed from tree, tree is splayed 
    such that the node to be removed is brought to root node
 
 bool contains(const Comparable &x)
    Precondition: None, if a splay tree is empty, method returns false
    Postcondition: Tree is splayed such that node containing x value is 
    now the root node
 
 const Comparable & find( const Comparable &x)
    Precondition: None, if a splay tree is empty, throws class exception
    Postcondition: Tree is splayed such that node containing x value is
    now the root node
 
 const Comparable &showRoot()
    Precondition: None, if a splay tree is empty, method return default comparable
    object value
    Postcondition: mRoot is returned to client, no change in splay tree structure

 
 void splay(FHs_treeNode<Comparable> * & root, const Comparable & x)
    Precondition: None, if tree is empty no operations occur
    Postcondition: Tree is restructured such that node containing x is now 
    the root node, BST conditions are maintained
 
 void rotateWithLeftChild( FHs_treeNode<Comparable> * & k2)
    Precondition: k2 is a valid node in a splay tree, k2 is a parent node with
    subtrees of unequal hieght greater than 1
    Postcondition: k2 left node becomes the parent node of k2, k2 is the right
    child of k2's previous left node, k2's previous left node's right child 
    becomes the left child of k2
 
 void rotateWithRightChild( FHs_treeNode<Comparable> * & k2)
    Precondition: k2 is a valid node in a splay tree, k2 is a parent node with
    subtrees of unequal hieght greater than 1
    Postcondition: k2 right node becomes the parent node of k2, k2 is the left
    child of k2's previous right node, k2's previous right node's left child
    becomes the right child of k2
 */

#ifndef FHSPLAYTREE_H
#define FHSPLAYTREE_H
#include "FHsearch_tree.h"


template <class Comparable>
class FHsplayTree : public FHsearch_tree<Comparable>
{
public:
   bool insert(const Comparable &x);
   bool remove(const Comparable &x);
   bool contains(const Comparable &x);
   const Comparable & find( const Comparable &x);
   const Comparable &showRoot();

protected:
   void splay(FHs_treeNode<Comparable> * & root, const Comparable & x);
   void rotateWithLeftChild( FHs_treeNode<Comparable> * & k2);
   void rotateWithRightChild( FHs_treeNode<Comparable> * & k2);

};







//Member fuction allows for removal of node containing value x
//tree is splayed such that x was root prior to removal
template <class Comparable>
bool FHsplayTree<Comparable>::remove(const Comparable &x)
{
   if (this->mRoot == NULL)
      return false;

   splay(this->mRoot, x);

   if ((x < this->mRoot->data) || (this->mRoot->data < x))
      return false;

   FHs_treeNode<Comparable> *newRootNode = NULL;

   if (this->mRoot->lftChild == NULL)
   {
      newRootNode = this->mRoot->rtChild;
   }
   else
   {
      newRootNode = this->mRoot->lftChild;
      splay(newRootNode, x);
      newRootNode->rtChild = this->mRoot->rtChild;
   }
   
   delete this->mRoot;
   this->mRoot = newRootNode;
   this->mSize--;

   return true;
}






//Member function allows for insertion of new node into splay tree containing
//value x, tree is splayed such as new node is root
template <class Comparable>
bool FHsplayTree<Comparable>::insert(const Comparable &x)
{
   if (this->mRoot == NULL)
   {
      FHs_treeNode<Comparable> *newRootNode = new FHs_treeNode<Comparable>();
      newRootNode->data = x;
      newRootNode->rtChild = NULL;
      newRootNode->lftChild = NULL;
      this->mRoot = newRootNode;
      this->mSize++;
      return true;
   }

   splay(this->mRoot, x);

   if (x < this->mRoot->data)
   {
      FHs_treeNode<Comparable> *newRootNode = new FHs_treeNode<Comparable>();
      newRootNode->data = x;
      newRootNode->rtChild = this->mRoot;
      newRootNode->lftChild = this->mRoot->lftChild;
      this->mRoot->lftChild = NULL; 
      this->mRoot = newRootNode;
      this->mSize++;
      return true;
   }

   if (this->mRoot->data < x)
   {
      FHs_treeNode<Comparable> *newRootNode = new FHs_treeNode<Comparable>;
      newRootNode->data = x;
      newRootNode->lftChild = this->mRoot;
      newRootNode->rtChild = this->mRoot->rtChild;
      this->mRoot = newRootNode;
      this->mRoot->rtChild = NULL; 
      this->mSize++;
      return true;
   }

   return false;
}






//Member function restructures tree such that new root is node containing
//value of x, BST tree conditions are maintained after splay
template <class Comparable>
void FHsplayTree<Comparable>::splay(FHs_treeNode<Comparable> * & root,
                                    const Comparable & x)
{
   FHs_treeNode<Comparable> *rightTree = NULL, *leftTree = NULL,
      *rightTreeMin = NULL, *leftTreeMax = NULL;
   
   while (root != NULL)
   {
      if (x < root->data)
      {
         if (root->lftChild == NULL)
            break;
         if (x < root->lftChild->data)
         {
            rotateWithLeftChild(root);
            if (root->lftChild == NULL)
               break;
         }
         //add root to rightTreeMin
         if (rightTree == NULL)
         {
            rightTree = root;
            rightTreeMin = root;
            root = root->lftChild;
         }
         else
         {
            rightTreeMin->lftChild = root;
            rightTreeMin = root;
            root = root->lftChild;
         }
      }

      else if (root->data < x)
      {
         if (root->rtChild == NULL)
            break;
         if (root->rtChild->data < x)
         {
            rotateWithRightChild(root);
            if (root->rtChild == NULL)
               break;
         }
         //add root to leftTreeMax
         if (leftTree == NULL)
         {
            leftTree = root;
            leftTreeMax = root;
            root = root->rtChild;
         }
         else
         {
            leftTreeMax->rtChild = root;
            leftTreeMax = root;
            root = root->rtChild;
         }
      }
      else
         break;
   }

   if (leftTree != NULL)
   {
      leftTreeMax->rtChild = root->lftChild;
      root->lftChild = leftTree;
   }
   if (rightTree != NULL)
   {
      rightTreeMin->lftChild = root->rtChild;
      root->rtChild = rightTree;
   }

   this->mRoot = root;
}






//Member function allows for reordering of tree nodes to resolve condition
//where k2 is parent node of two trees that have unequal heights greater than 1
template <class Comparable>
void FHsplayTree<Comparable>::rotateWithLeftChild(FHs_treeNode<Comparable> * &k2)
{
   FHs_treeNode<Comparable> *k1 = k2->lftChild;
   k2->lftChild = k1->rtChild;
   k1->rtChild = k2;
   k2 = k1;
}






//Member function allows for reordering of tree nodes to resolve condition
//where k2 is parent node of two trees that have unequal heights greater than 1
template <class Comparable>
void FHsplayTree<Comparable>::rotateWithRightChild(FHs_treeNode<Comparable> * &k2)
{
   FHs_treeNode<Comparable> *k1 = k2->rtChild;
   k2->rtChild = k1->lftChild;
   k1->lftChild = k2;
   k2 = k1;
}






//Member function returns value at root, if root node exists, otherwise returns
//default value
template <class Comparable>
const Comparable & FHsplayTree<Comparable>::showRoot()
{
   if (this->mRoot == NULL)
      return Comparable();
   return this->mRoot->data;
}






//Member function allows for client to determine if tree contains node with
//value of x, node containing x is not root after splay call
template <class Comparable>
bool FHsplayTree<Comparable>::contains(const Comparable &x)
{
   try
   {
      find(x);
   }
   catch (const typename FHsearch_tree<Comparable>::NotFoundException e)
   {
      std::cout << "Value not contained in tree" << std::endl;
      return false;
   }
   return true;
}






//Member function allows for client to determine if tree contains node with
//value of x, throws excpetion otherwise, node containing x is not root after
//splay call
template <class Comparable>
const Comparable & FHsplayTree<Comparable>::find( const Comparable &x)
{
   if (this->mRoot == NULL)
      throw typename FHsearch_tree<Comparable>::NotFoundException();

   splay(this->mRoot, x);

   if ((this->mRoot->data < x) || (x < this->mRoot->data))
      throw typename FHsearch_tree<Comparable>::NotFoundException();

   return x;
}

#endif
