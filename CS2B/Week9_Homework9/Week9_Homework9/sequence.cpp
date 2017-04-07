/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 27, 2016
 Professor Dave Harden
 Assignment 9.1
 */

#include "sequence.h"
#include <cassert>

namespace cs_sequence
{
   sequence::sequence()
   {
      headPtr = NULL;
      tailPtr = NULL;
      cursor = NULL;
      precursor = NULL;
      numItems = 0;
   }






   sequence::sequence(const sequence& copySeq)
   {
      copyList(copySeq);
   }






   sequence sequence::operator=(const sequence& rightSeq)
   {
      if (this != &rightSeq)
      {
         deleteList();
         copyList(rightSeq);
      }
      return *this;
   }






   sequence::~sequence()
   {
      deleteList();
   }






   void sequence::start()
   {
      if (headPtr != NULL)
      {
         cursor = headPtr;
      }
   }






   void sequence::advance()
   {
      if ((cursor == NULL) || (cursor == tailPtr))
         cursor = NULL;
      else
      {
         precursor = cursor;
         cursor = cursor->next;
      }
   }






   void sequence::remove_current()
   {
      assert (headPtr != NULL);
      numItems--;
      
      if (headPtr == tailPtr)
      {
         delete cursor;
         cursor = NULL;
         headPtr = NULL;
         tailPtr = NULL;
      }
      else if ((cursor == headPtr) || (precursor == NULL))
      {
         node* currentCursor = cursor;
         cursor = cursor->next;
         headPtr = cursor;
         delete currentCursor;
      }
      else
      {
         node* currentCursor = cursor;
         cursor = cursor->next;
         precursor->next = cursor;
         delete currentCursor;

         if (cursor == NULL)
         {
            tailPtr = precursor;
            precursor = NULL;
         }
      }
   }






   void sequence::attach(const value_type& entry)
   {
      numItems++;
      node* tmpPtr = new node;
      tmpPtr->data = entry;

      if (headPtr == NULL)
      {
         tmpPtr->next = NULL;
         headPtr = tmpPtr;
         tailPtr = tmpPtr;
      }
      else if ((cursor == tailPtr) || (cursor == NULL))
      {
         precursor = tailPtr;
         precursor->next = tmpPtr;
         tmpPtr->next = NULL;
         tailPtr = tmpPtr;
      }
      else
      {
         tmpPtr->next = cursor->next;
         precursor = cursor;
         precursor->next = tmpPtr;
      }
      cursor = tmpPtr;
   }






   void sequence::insert(const value_type& entry)
   {
      numItems++;
      node* tempPtr = new node;
      tempPtr -> data = entry;

      if (headPtr == NULL)
      {
         tempPtr -> next = NULL;
         headPtr = tempPtr;
         tailPtr = tempPtr;
      }
      else if (cursor == NULL || cursor == headPtr)
      {
         tempPtr -> next = headPtr;
         headPtr = tempPtr;
      }
      else
      {
         tempPtr -> next = cursor;
         precursor -> next = tempPtr;
      }
      cursor = tempPtr;
   }






   sequence::size_type sequence::size() const
   {
      size_type count = 0;
      node* tempPtr = headPtr;
      while (tempPtr != NULL)
      {
         count++;
         tempPtr = tempPtr->next;
      }
      return count;
   }






   bool sequence::is_item() const
   {
      return (cursor != NULL);
   }






   sequence::value_type sequence::current() const
   {
      assert (is_item());
      return cursor->data;
   }






   void sequence::copyList(const sequence& copySeq)
   {
      if (copySeq.headPtr == NULL)
      {
         headPtr = NULL;
         cursor = NULL;
         precursor = NULL;
         tailPtr = NULL;
      }
      else
      {
         node* sourcePtr = copySeq.headPtr;
         node* newNode = new node;
         newNode->data = sourcePtr->data;
         newNode->next = NULL;
         headPtr = newNode;
         node* newSeqPtr = headPtr;
         sourcePtr = sourcePtr->next;
         while (sourcePtr != NULL)
         {
            newNode = new node;
            newNode->data = sourcePtr->data;
            newNode->next = NULL;
            newSeqPtr->next = newNode;
            sourcePtr = sourcePtr->next;
            newSeqPtr = newNode;
         }
      }
      tailPtr = copySeq.tailPtr;
      cursor = copySeq.cursor;
      precursor = copySeq.precursor;
      numItems = copySeq.numItems;
   }






   void sequence::deleteList()
   {
      node* tmpPtr = headPtr;
      while (tmpPtr != NULL)
      {
         headPtr = headPtr->next;
         delete tmpPtr;
         tmpPtr = headPtr;
      }
   }
}


