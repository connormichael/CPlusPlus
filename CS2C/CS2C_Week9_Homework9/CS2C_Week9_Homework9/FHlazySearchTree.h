/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Febuary 5, 2017
 Professor Dave Harden
 Assignment 4.1
 
 Description:
 The program lays out the methods for the FHsearch_tree class, which 
 impliments lazy deletion to allow for quick "soft" removal of nodes during
 user modification, but then maintain structure over long/less active periods.
 The class builds off the search tree implementation of FHsearch_tree.h, 
 maintining binary search tree ordering.

 Member Functions:
 int sizeHard() const
 Precondition: None
 Postcondition: Returns that value stored in the mSizeHard attribute
 
 FHs_treeNode<Comparable> *findMinHard(FHs_treeNode<Comparable> *root) const
 Precondition: Tree is constructed, can be empty
 Postcondition: Returns the pointer to the node that stores the minimum value
 in the subtree below *root
 
 void removeHard(FHs_treeNode<Comparable> * &root)
 Precondition: Tree is constructed, can be empty
 Postcondition: Recursively goes through subtrees  of *root, removing all 
 nodes whose delete attribute is true. Preserves all nodes who's delete 
 attribute is marked false.
 
 
 void collectGarbage()
 Precondition: Tree is constructed, can be empty
 Postcondition: Function calls on collectGarbage, tree has had all lazy 
 deleted nodes permanantly removed.

 void collectGarbage(FHs_treeNode<Comparable> * &root)
 Precondition: *root points to the root of a subtree that will have all 
 nodes whose delete attribute is true permanently deleted
 Postcondition: Function recursively calls on removeHard, removing all 
 nodes whose delete attribute is true
 */

#ifndef FHSEARCHTREE_H
#define FHSEARCHTREE_H

// ---------------------- FHs_treeNode Prototype --------------------------
template <class Comparable>
class FHs_treeNode
{
public:
   FHs_treeNode( const Comparable & d = Comparable(),
                FHs_treeNode *lt = NULL,
                FHs_treeNode *rt = NULL,
                bool isDeleted = false)
   : lftChild(lt), rtChild(rt), data(d), deleted(isDeleted)
   { }

   FHs_treeNode *lftChild, *rtChild;
   Comparable data;
   bool deleted;

   // for use only with AVL Trees
   virtual int getHeight() const { return 0; }
   virtual bool setHeight(int height) { return true; }
};

// ---------------------- FHsearch_tree Prototype --------------------------
template <class Comparable>
class FHsearch_tree
{
protected:
   int mSize, mSizeHard;
   FHs_treeNode<Comparable> *mRoot;

public:
   FHsearch_tree() { mSize = 0; mSizeHard = 0; mRoot = NULL; }
   FHsearch_tree(const FHsearch_tree &rhs)
   { mRoot = NULL; mSize = 0; mSizeHard = 0; *this = rhs; }
   ~FHsearch_tree() { clear(); }

   const Comparable &findMin() const;
   const Comparable &findMax() const;
   const Comparable &find(const Comparable &x) const;

   bool empty() const { return (mSize == 0); }
   int size() const { return mSize; }
   void clear() { makeEmpty(mRoot); }
   const FHsearch_tree & operator=(const FHsearch_tree &rhs);

   bool insert(const Comparable &x);
   bool remove(const Comparable &x);
   bool contains(const Comparable &x) const { return find(mRoot, x) != NULL; }

   template <class Processor>
   void traverse(Processor func) const { traverse(mRoot, func); }
   int showHeight() const { return findHeight(mRoot); }
   int sizeHard() const { return mSizeHard; }
   void collectGarbage();

protected:
   FHs_treeNode<Comparable> *clone( FHs_treeNode<Comparable> *root) const;
   FHs_treeNode<Comparable> *findMin(FHs_treeNode<Comparable> *root) const;
   FHs_treeNode<Comparable> *findMax(FHs_treeNode<Comparable> *root) const;
   FHs_treeNode<Comparable> *find(FHs_treeNode<Comparable> *root,
                                  const Comparable &x) const;
   bool insert(FHs_treeNode<Comparable> * &root,
               const Comparable &x);
   bool remove(FHs_treeNode<Comparable> * &root, const Comparable &x);
   void makeEmpty(FHs_treeNode<Comparable> * &subtreeToDelete);
   template <class Processor>
   void traverse(FHs_treeNode<Comparable> *treeNode,
                 Processor func, int level = -1) const;
   int findHeight(FHs_treeNode<Comparable> *treeNode, int height = -1) const;
   FHs_treeNode<Comparable> *findMinHard(FHs_treeNode<Comparable> *root) const;
   void collectGarbage(FHs_treeNode<Comparable> * &root);
   void removeHard(FHs_treeNode<Comparable> * &root);

public:
   // for exception throwing
   class EmptyTreeException {};
   class NotFoundException {};
};

// FHsearch_tree public method definitions -----------------------------
//member function produces a new Sublist object with an item from the vector
template <class Comparable>
void FHsearch_tree<Comparable>::collectGarbage()
{
   if (mRoot == NULL)
      throw EmptyTreeException();
   collectGarbage(mRoot);
}

template <class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMin() const
{
   if (mRoot == NULL)
      throw EmptyTreeException();
   return findMin(mRoot)->data;
}

template <class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMax() const
{
   if (mRoot == NULL)
      throw EmptyTreeException();
   return findMax(mRoot)->data;
}

template <class Comparable>
const Comparable &FHsearch_tree<Comparable>::find(
                                                  const Comparable &x) const
{
   FHs_treeNode<Comparable> *resultNode;

   resultNode = find(mRoot, x);
   if (resultNode == NULL)
      throw NotFoundException();
   return resultNode->data;
}

template <class Comparable>
const FHsearch_tree<Comparable> &FHsearch_tree<Comparable>::operator=
(const FHsearch_tree &rhs)
{
   if (&rhs != this)
   {
      clear();
      mRoot = clone(rhs.mRoot);
      mSize = rhs.size();
      mSizeHard = rhs.sizeHard();
   }
   return *this;
}

template <class Comparable>
bool FHsearch_tree<Comparable>::insert(const Comparable &x)
{
   if (insert(mRoot, x))
   {
      mSize++;
      mSizeHard++;
      return true;
   }
   return false;
}

template <class Comparable>
bool FHsearch_tree<Comparable>::remove(const Comparable &x)
{
   if (remove(mRoot, x))
   {
      mSize--;
      return true;
   }
   return false;
}

template <class Comparable>
template <class Processor>
void FHsearch_tree<Comparable>::traverse( FHs_treeNode<Comparable> *treeNode,
                                         Processor func, int level) const
{
   if (treeNode == NULL)
      return;
   // we're not doing anything with level but its there in case we want it
   traverse(treeNode->lftChild, func, level + 1);
   if (!treeNode->deleted)
      func(treeNode->data);
   traverse(treeNode->rtChild, func, level + 1);
}


// FHsearch_tree private method definitions -----------------------------
template <class Comparable>
void FHsearch_tree<Comparable>::collectGarbage(FHs_treeNode<Comparable> * &root)
{
   if (root == NULL)
      return;

   collectGarbage(root->lftChild);
   collectGarbage(root->rtChild);

   if (root->deleted)
   {
      removeHard(root);
      mSizeHard--;
   }
}


template <class Comparable>
void FHsearch_tree<Comparable>::removeHard(FHs_treeNode<Comparable> * &root)
{
   if (root->lftChild != NULL && root->rtChild != NULL)
   {
      FHs_treeNode<Comparable> *minNode = findMinHard(root->rtChild);
      root->data = minNode->data;
      root->deleted = minNode->deleted;
      removeHard(root->rtChild);
   }
   else
   {
      FHs_treeNode<Comparable> *nodeToRemove = root;
      root = (root->lftChild != NULL)? root->lftChild : root->rtChild;
      delete nodeToRemove;
   }
}


template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMinHard(FHs_treeNode<Comparable> *root) const
{
   if (root == NULL)
      return NULL;
   if (root->lftChild == NULL)
      return root;
   return findMin(root->lftChild);
}


template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::clone(
                                                           FHs_treeNode<Comparable> *root) const
{
   FHs_treeNode<Comparable> *newNode;
   if (root == NULL)
      return NULL;

   newNode =  new FHs_treeNode<Comparable>(
                                           root->data,
                                           clone(root->lftChild), clone(root->rtChild));
   return newNode;
}

template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMin(
                                                             FHs_treeNode<Comparable> *root) const
{
   if (root == NULL)
      return NULL;
   if ((root->lftChild == NULL) && (!root->deleted))
      return root;
   if ((root->lftChild->deleted) && (root->lftChild->lftChild == NULL))
      return root;

   if (root->lftChild->deleted)
      return findMin(root->lftChild->lftChild);
   return findMin(root->lftChild);
}

template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMax(
                                                             FHs_treeNode<Comparable> *root) const
{
   if (root == NULL)
      return NULL;
   if ((root->rtChild == NULL) && (!root->deleted))
      return root;
   if ((root->rtChild->deleted) && (root->rtChild->rtChild == NULL))
      return root;

   if (root->rtChild->deleted)
      return findMax(root->rtChild->rtChild);
   return findMax(root->rtChild);
}

template <class Comparable>
FHs_treeNode<Comparable>* FHsearch_tree<Comparable>::find(
                                                          FHs_treeNode<Comparable> *root, const Comparable &x) const
{
   if (root == NULL)
      return NULL;

   if (x < root->data)
      return find(root->lftChild, x);
   if (root->data < x)
      return find(root->rtChild, x);
   if (root->deleted)
      return NULL;
   return root;
}

template <class Comparable>
bool FHsearch_tree<Comparable>::insert(
                                       FHs_treeNode<Comparable> * &root, const Comparable &x)
{
   if (root == NULL)
   {
      root = new FHs_treeNode<Comparable>(x, NULL, NULL);
      return true;
   }
   else if (x < root->data)
      return insert(root->lftChild, x);
   else if (root->data < x)
      return insert(root->rtChild, x);
   else if (root->deleted)
   {
      root->deleted = false;
      mSize++;
   }
   return false; // duplicate
}

template <class Comparable>
bool FHsearch_tree<Comparable>::remove(
                                       FHs_treeNode<Comparable> * &root, const Comparable &x)
{
   if (root == NULL)
      return false;
   if (x < root->data)
      return remove(root->lftChild, x);
   if (root->data < x)
      return remove(root->rtChild, x);

   if (root->deleted)
      return false;
   root->deleted = true;

   return true;
}

template <class Comparable>
void FHsearch_tree<Comparable>::makeEmpty(
                                          FHs_treeNode<Comparable> * &subtreeToDelete)
{
   if (subtreeToDelete == NULL)
      return;

   // remove children
   makeEmpty(subtreeToDelete->lftChild);
   makeEmpty(subtreeToDelete->rtChild);
   
   // clear client's pointer
   delete subtreeToDelete;
   subtreeToDelete = NULL;
   --mSize;
}

template <class Comparable>
int FHsearch_tree<Comparable>::findHeight( FHs_treeNode<Comparable> *treeNode,
                                          int height ) const
{
   int leftHeight, rightHeight;
   
   if (treeNode == NULL)
      return height;
   height++;
   leftHeight = findHeight(treeNode->lftChild, height);
   rightHeight = findHeight(treeNode->rtChild, height);
   return (leftHeight > rightHeight)? leftHeight : rightHeight;
}

#endif