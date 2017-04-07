/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 27, 2016
 Professor Dave Harden
 Assignment 9.1
 */

#ifndef Sequence_H
#define Sequence_H

#include <iostream>
#include <cstdlib>
#include <cassert>
namespace cs_sequence
{
   class sequence
   {
   public:
      typedef int value_type;
      typedef std::size_t size_type;
      
      sequence();
      sequence(const sequence& copySeq);
      sequence operator=(const sequence& rightSeq);
      ~sequence();
      void start();
      void advance();
      void insert(const value_type& entry);
      void attach(const value_type& entry);
      void remove_current();
      size_type size() const;
      bool is_item() const;
      value_type current() const;

   private:
      void copyList(const sequence& copySeq);
      void deleteList();
      size_type numItems;

      struct node
      {
         value_type data;
         node* next;
      };
      node* headPtr;
      node* tailPtr;
      node* cursor;
      node* precursor;
   };
}
#endif
