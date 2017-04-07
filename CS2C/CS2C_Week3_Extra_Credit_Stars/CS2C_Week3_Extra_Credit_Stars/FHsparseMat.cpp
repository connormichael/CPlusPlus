/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Janunary 19, 2017
 Professor Dave Harden
 Assignment 2.1

 Description:
 The program lays out the method definitions for the SparseMat class. 
 SparseMat objects are composed a vector (using FHvector class), of lists 
 (using FHlsit class) which contain an ordered grouping of MatNode objects. 
 MatNode objects are composed of a integer column value and a data object. 
 Through this implementation the index value of the vector corresponds to 
 the row coordinate and the column value of the MatNode object together 
 compose the coordinates of the data value in the sparse matrix.

 The member functions that are outlined in this file are: SparseMat, get, set, 
 insertNode, deleteRowNode, clear, showSubSquare, setRowSize, setColSize
 which are documented in full detail in the header file.
 */

#include <iostream>
#include "FHvector.h"
#include "FHlist.h"

namespace sparsematrix
{
   //Parameter taking constructor produces a "sparse matrix" with a vector
   //of size r, with a maximum node entries in the vector list of c, and
   //with a default value of defautlVal.
   template <class Object>
   SparseMat<Object>::SparseMat(int r, int c, const Object &defaultVal)
   {
      defVal = defaultVal;
      if (setRowSize(r) && (setColSize(c)))
      {
         for (int i = 0; i < rowSize; i++)
         {
            MatRow tempRow;
            rows.push_back(tempRow);
         }
      }
   }






   //Member function returns the value stored at location (r,c) if (r,c) is
   //within bounds of colSize and rowSize. If no value exists, the default
   //value is returned.
   template <class Object>
   const Object & SparseMat<Object>::get(int r, int c) const
   {
      if ((rowSize < r) || (r < 0 ) || (colSize < c) || (c < 0))
         throw BoundsException();
      else
      {
         for (typename MatRow::const_iterator iter = rows[r].begin();
              iter != rows[r].end(); iter++)
         {
            if ((*iter).getCol() == c)
               return (*iter).data;
         }
         return defVal;
      }
   }






   //Sets object x value at location (r, c) in the sparse matrix if location
   //(r, c) is within bounds. If value of x is default value, node is removed.
   template <class Object>
   bool SparseMat<Object>::set(int r, int c, const Object &x)
   {
      if ((rowSize <= r) || (r < 0 ) || (colSize <= c) || (c < 0))
         return false;
      else
      {
         typename MatRow::iterator iter = rows[r].begin();

         if (x == defVal)
         {
            deleteRowNode(r, c);
         }
         else if (rows[r].size() == 0)
            rows[r].push_back(MatNode<Object>(c, x));
         else if ((*iter).getCol() < c)
            insertNode(r, c, x, iter);
         else
            (*iter).data = x;

         return true;
      }
   }






   //Helper member function inserts object x at location (r, c). Function is
   //called upon if row list has multiple node objects.
   template <class Object>
   void SparseMat<Object>::insertNode(int r, int c, const Object &x,
                                      typename MatRow::iterator iter)
   {
      while (((*iter).getCol() < c) && (iter != rows[r].end()))
         iter++;
      if (iter == rows[r].end())
         rows[r].push_back(MatNode<Object>(c, x));
      else if ((*iter).getCol() == c)
         (*iter).data = x;
      else
         rows[r].insert(iter, MatNode<Object>(c, x));
   }






   //remove node at location (r, c). Helper member function is called if
   //client attempts to set value of node with default value.
   template <class Object>
   void SparseMat<Object>::deleteRowNode(int r, int c)
   {
      for (typename MatRow::iterator searchIter = rows[r].begin();
           searchIter != rows[r].end(); searchIter++)
      {
         if ((*searchIter).getCol() == c)
         {
            rows[r].erase(searchIter);
            break;
         }
      }
   }






   //Member function removes all nodes from all lists in vector.
   template <class Object>
   void SparseMat<Object>::clear()
   {
      for (int row = 0; row < rowSize; row++)
      {
         for (typename MatRow::iterator iter = rows[row].begin();
              iter != rows[row].end(); iter++)
            rows[row].erase(iter);
      }
   }






   //Member function to ouput the values of the nodes stored in the sparse
   //matrix from start to start + size. If no node exists, ouputs default value.
   template <class Object>
   void SparseMat<Object>::showSubSquare(int start, int size)
   {
      int end = start + size;

      for (int row = start; row < end; row++)
      {
         typename MatRow::const_iterator iter = rows[row].begin();

         for (int col = start; col < end; col++)
         {
            if ((*iter).getCol() == col)
            {
               std::cout << (*iter).data << " ";
               iter++;
            }
            else
               std::cout << defVal << " ";
         }
         std::cout << endl;
      }
   }






   //Mutator sets rowSize. Has no default value. Does not allow for constructor
   //of sparse matrix if r <= 0.
   template <class Object>
   bool SparseMat<Object>::setRowSize(int r)
   {
      if (r >= 1)
      {
         rowSize = r;
         return true;
      }
      return false;
   }






   //Mutator sets colSize. Has no default value. Does not allow for constructor
   //of sparse matrix if c <= 0.
   template <class Object>
   bool SparseMat<Object>::setColSize(int c)
   {
      if (c >= 1)
      {
         colSize = c;
         return true;
      }
      return false;
   }
}



