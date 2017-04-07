//
//  connor_vect.h
//  CS2C Warmup
//
//  Created by Connor Lynch on 12/29/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#ifndef __CS2C_Warmup__connor_vect__
#define __CS2C_Warmup__connor_vect__

#include <iostream>

namespace node
{
   template<class T>
   class Node
   {
   public:
      Node(): link(NULL), data(NULL){};
      Node(Node<T>* theLink, T theData)
           : link(theLink), data(theData){};
      bool setLink(Node<T>* theLink){link = theLink; return true;};
      Node<T>* getLink() const {return link;};
      bool setData(T theData){data = theData; return true;};
      T getData()const {return data;};

   private:
      Node<T>* link;
      T data;

   };

   template<class T>
   class ListIterator
   {
   public:
      ListIterator() : current(NULL) {}
      ListIterator(Node<T>* initial) : current(initial) {}
      ListIterator operator ++()
      {
         current = current->getLink();
         return current;
      }
      ListIterator operator ++(int)
      {
         Node<T>* temp = current;
         current = current->getLink();
         return temp;
      }
      T operator *()
      {
         return current->getData();
      }
      bool operator ==(const ListIterator& rightListIter) const
      {
         return (current == rightListIter.current);
      }

      bool operator !=(const ListIterator& rightListIter) const
      {
         return (current != rightListIter.current);
      }

   private:
      Node<T>* current;
   };

   template<class T>
   class Queue
   {
   public:
      typedef T value_type;
      Queue() : front(NULL), back(NULL){};
      Queue(const Queue& rightQueue);
      Queue<T>& operator =(const Queue<T>& rightQueue);
      virtual ~Queue();
      void add(value_type item);
      value_type remove();
      bool isEmpty();

      ListIterator<T> begin() const
      {
         return ListIterator<T>(front);
      }
      ListIterator<T> end() const
      {
         return ListIterator<T>();
      }


   private:
      Node<T>* front;
      Node<T>* back;

   };
}





//Since the add function always adds to the bottom of the list you
//can just always pop off the tail and delete it
namespace listy
{
   template<class T>
   class list
   {
   public:
      typedef T value_type;
      typedef std::size_t size_type;  //need size_type to ensure that size can be stored in datatyp e

      list();
      virtual ~list();
      list(const list<T>& copyList);
      //void operator=(const list<T>& copyList);
      void add(const value_type& data);
      bool remove(const value_type& theData);
      void insertionSort();
      void print();
      int size();
      value_type pop();


   private:
      struct node
      {
         node* next;
         node* previous;
         value_type data;
      };

      node* headPtr;
      node* tailPtr;
      node* search(value_type theData);
      int numItems;

      void deleteList();
      void copyList(const list& copyList);
      
   };
}

#include "connor_vect.cpp"

#endif 

