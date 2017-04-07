//
//  connor_vect.cpp
//  CS2C Warmup
//
//  Created by Connor Lynch on 12/29/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include "connor_vect.h"
using namespace std;

namespace node
{
   template<class T>
   Queue<T>::Queue(const Queue& rightQueue)
   {
      Queue tempQueue;
      tempQueue.front = rightQueue.front;
      tempQueue.back = rightQueue.back;
      return tempQueue;
   }

   template<class T>
   Queue<T>& Queue<T>::operator =(const Queue<T>& rightQueue)
   {
      if (this != *rightQueue)
      {
         Node<T>* tempPtr = rightQueue.front;
         while (tempPtr != NULL)
         {
            Node<T>* newNode = new Node<T>;
            newNode->setLink(tempPtr->getLink());
            newNode->setData(tempPtr->getData());
            tempPtr = tempPtr->getLink();
         }
         front = rightQueue.front;
         back = rightQueue.back;
      }
   }

 

   template<class T>
   Queue<T>::~Queue()
   {
      Node<T>* tempPtr = front;
      Node<T>* tempPtrTwo;
      while (tempPtr != NULL)
      {
         tempPtrTwo = tempPtr->getLink();
         delete tempPtr;
         tempPtr = tempPtrTwo;
      }
   }

   template<class T>
   void Queue<T>::add(value_type item)
   {
      if (front == NULL)
      {
         front = back = new Node<T>(item, NULL);
      }
      else
      {
         back->link = new Node<T>(item, NULL);
         back = back->link;
      }
   }

   template<class T>
   bool Queue<T>::isEmpty()
   {
      return front == NULL;
   }

}



namespace listy
{
   template<class T>
   list<T>::list()
   {
      headPtr = NULL;
      tailPtr = NULL;
   }

   template<class T>
   void list<T>::add(const list<T>::value_type& data)
   {
      numItems++;
      node* tempPtr = new node;
      tempPtr->data = data;
      tempPtr->next = NULL;

      if (headPtr == NULL)
      {
         tempPtr->previous = NULL;
         tempPtr->next = NULL;
         headPtr = tempPtr;
         tailPtr = headPtr;
      }
      else
      {
         tempPtr->previous = tailPtr; 
         tailPtr->next = tempPtr;
         tailPtr = tempPtr;
         tailPtr->next = NULL;
         //Resort here?
      }
   }

   template<class T>
   bool list<T>::remove(const list<T>::value_type& theData)
   {
      node* tempPtr = search(theData);

      if (tempPtr != nullptr)
      {
         if (tempPtr == headPtr)
         {
            tempPtr = headPtr->next;
            delete headPtr;
            headPtr = tempPtr;
         }
         else if (tempPtr == tailPtr)
         {
            tempPtr = tailPtr->previous;
            tempPtr->next = NULL;
            delete tailPtr;
            tailPtr = tempPtr;
         }
         else
         {
            node* prev = tempPtr->previous;
            node* nex = tempPtr->next;
            prev->next = nex;
            nex->previous = prev;
            delete tempPtr;
         }
         numItems--; 
         return true;
      }
      return false;
   }


   template<class T>
   typename list<T>::node* list<T>::search(list<T>::value_type theData)
   {
      node* tempPtr = headPtr;

      while (tempPtr != NULL)
      {
         if (tempPtr->data == theData)
         {
            return tempPtr;
         }
         else
            tempPtr = tempPtr->next; 
      }
      return nullptr;
   }


   template<class T>
   void list<T>::print()
   {
      node* tempPtr = headPtr;

      while (tempPtr != NULL)
      {
         cout << tempPtr->data << endl;
         tempPtr = tempPtr->next;
      }
   }


   template<class T>
   void list<T>::insertionSort()
   {
      node* currentPtr = headPtr;
      node* evalPtr = headPtr->next;

      while (currentPtr != tailPtr)
      {
         while (evalPtr != NULL)
         {
            if (evalPtr->data < currentPtr->data)
            {
               list<T>::value_type tmpData = currentPtr->data;
               currentPtr->data = evalPtr->data;
               evalPtr->data = tmpData;
            }
            evalPtr = evalPtr->next; 
         }
         currentPtr = currentPtr->next;
         evalPtr = currentPtr->next;
      }
   }

   
   template<class T>
   int list<T>::size()
   {
      return numItems; 
   }


   template<class T>
   list<T>::~list()
   {
      deleteList();
   }
   /*
   template<class T>
   void list<T>::operator=(const list<T>& copyList)
   {
      if (this != &copyList)
      {
         deleteList();
         copyList(copyList);
      }
      return *this;
   }
    */


   template<class T>
   void list<T>::deleteList()
   {
      node* tempPtr = headPtr;
      while (tempPtr != NULL)
      {
         headPtr = headPtr->next;
         delete tempPtr;
         tempPtr = headPtr;
      }
   }



   template<class T>
   void list<T>::copyList(const list<T>& copyList)
   {
      if (copyList.headPtr == NULL)
      {
         headPtr = NULL;
         tailPtr = NULL;
      }
      else
      {
         node* tracker = headPtr;
         node* newNode = newNode;
         newNode->next = headPtr->next;
         newNode->previous = headPtr->previous;
         newNode->data = headPtr->data;

         while (tracker != NULL)
         {
            tracker = tracker->next;
            newNode = new node;
            newNode->previous = tracker->previous;
            newNode->next = tracker->next;
            newNode->data = tracker->data;
         }
         headPtr = copyList.headPtr;
         tailPtr = copyList.tailPtr;
      }
   }


   template<class T>
   list<T>::list(const list<T>& copyList)
   {
      copyList(copyList);
   }


   template<class T>
   typename list<T>::value_type list<T>::pop()
   {
      value_type theData;
      if (tailPtr != NULL)
      {
         node* tempPtr = tailPtr->previous;
         theData = tailPtr->data;
         delete tailPtr;
         tailPtr = tempPtr;
         if (tailPtr != NULL)
            tailPtr->next = NULL;
         return theData;
      }
      else
      {
         cout << "Sorry stack is empty" << endl;
         exit(1);
      }
      return theData;
   }
}







