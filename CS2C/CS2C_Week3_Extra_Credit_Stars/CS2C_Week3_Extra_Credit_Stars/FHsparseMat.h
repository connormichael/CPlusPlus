/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Janunary 19, 2017
 Professor Dave Harden
 Assignment 2.1

 Description:
 The program lays out the methods for the SparseMat class. SparseMat objects are
 composed a vector (using FHvector class), of lists  (using FHlsit class) which 
 contain an ordered grouping of MatNode objects. MatNode objects are composed 
 of a integer column value and a data object. Through this implementation 
 the index value of the vector corresponds to the row coordinate and the 
 column value of the MatNode object together compose the coordinates of the 
 data value in the sparse matrix.

 Member Functions:
 SparseMat(int r, int c, const Object &defaultVal)
 Precondition: Parameter taking constructor takes an integer row value, an 
   integer column value, and a default value object.
 Postcondition: A sparse matrix which is composed of a vector of lists of nodes 
 of size r by c.

 const Object & get(int r, int c) const
 Precondition: A sparse matrix object exists. Lists do not have to contain 
   values at row r and column c.
 Postcondition: Returns the value stored at row r, column c. If no value is 
   stored at this location, returns the default value.

 bool set(int r, int c, const Object &x)
 Precondition: A sparse matrix object exists. Lists can be empty or completely 
   full.
 Postcondition: If row r, and column c is within the bounds of the matrix, 
   object x is added at that location. If a value already exists, that value 
   is overwritten the new value x. If the value x is the default value, no 
   new node is added.

 void clear()
 Precondition: A sparse matrix exists. All lists in vector can be empty.
 Postcondition: All lists in vector contain no nodes.

 void showSubSquare(int start, int size)
 Precondition: A sparse matrix exists. All lists in vector can be empty.
 Postcondition: The values stored in the sparse matrix are displayed from 
   position start, to position start + size. The matrix is displayed by the 
   diagonal.

 void deleteRowNode(int r, int c)
 Precondition: A node exists at position (r, c) with a non default value, and 
   the user attempts to set this node to the default value.
 Postcondition: The node at position (r, c) is removed from the r list.

 bool setRowSize(int r)
 Precondition: No precondition.
 Postcondition: rowSize is set to r, if r is an acceptable value.

 bool setColSize(int c)
 Precondition: No precondition.
 Postcondition: colSize is set to c, if c is an acceptable value.

 void insertNode(int r, int c, const Object &x, typename MatRow::iterator iter)
 Precondition: A sparse matrix object exists with existing nodes at row, r.
 Postcondition: A node is inserted at position (r, c).

 */

#ifndef __CS2C_WeekTwo_Practice__SparseMatrix__
#define __CS2C_WeekTwo_Practice__SparseMatrix__

#include <iostream>
#include "FHvector.h" 
#include "FHlist.h" 

namespace sparsematrix
{
   template <class Object>
   class MatNode
   {
   protected:
      int col;

   public:
      Object data;
      // we need a default constructor for lists
      MatNode(int cl = 0, Object dt = Object()) : col(cl), data(dt) {}
      int getCol() const { return col; }
      const Object & operator=( const Object &x ) { return (data = x);}
   };

   template <class Object>
   class SparseMat
   {
   protected:
      typedef FHlist< MatNode<Object>> MatRow;
      typedef FHvector<MatRow> MasterCol;
      MasterCol rows;
      Object defVal;
      int rowSize, colSize;
      
   public:
      SparseMat(int r, int c, const Object &defaultVal);
      const Object & get(int r, int c) const;
      bool set(int r, int c, const Object &x);
      void clear();
      void showSubSquare(int start, int size);
      void deleteRowNode(int r, int c);
      bool setRowSize(int r);
      bool setColSize(int c);
      void insertNode(int r, int c, const Object &x,
                      typename MatRow::iterator iter);
      class BoundsException {};
   };
}






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
         std::cout << std::endl;
      }
      std::cout << std::endl << std::endl;
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

//#include "FHsparseMat.cpp"

#endif 






