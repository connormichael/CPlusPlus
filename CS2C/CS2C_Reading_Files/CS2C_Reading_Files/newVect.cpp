/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Janunary 14, 2017
 Professor Dave Harden
 Assignment 1.2


 Description:
 The program lays out the methods for the Sublist class. Sublist objects are
 composed a an integer sum, a vector pointer, and a vector of integer
 indices.

 addItem, takes a given sublist and adds a item from the vector that the
 pointer orginalObjects points too and returns a new subList object.
 showSublist, outputs the contents of a given sublist vector as well as
 the sum of all its items.
 */


//member function produces a new Sublist object with an item from the vector
//pointed to by originalObjects, which is specified by the passed variable,
//indexOfItemToAdd
namespace sublist
{
   template <class T>
   Sublist<T> Sublist<T>::addItem(int indexOfItemToAdd)
   {
      Sublist newSublist = *this;
      newSublist.sum = sum + (*originalObjects)[indexOfItemToAdd];
      newSublist.indices.push_back(indexOfItemToAdd);
      return newSublist;
   }






   //member function taking no parameters. Outputs the contents of the vector in
   //the Sublist object as well as the sum of all the items in the vector.
   template <class T>
   void Sublist<T>::showSublist() const
   {
      std::cout << "Sublist ----------------------------- " << std::endl;
      std::cout << "Sum: " << sum << std::endl;
      for (int i = 0; i < indices.size(); i++)
      {
         std::cout << "array[" << i << "] = " << (*originalObjects)[indices[i]] << ", ";
      }
      std::cout << std::endl;
   }
}