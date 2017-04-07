/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 21, 2016
 Professor Dave Harden
 Assignment 4.1
 */ 

#include <iostream>
#include <fstream>
#include <cassert>
#include "mystring.h"
using namespace std;


namespace cs_mystring
{
   MyString::MyString()
   {
      cString = new char[0];
      strcpy(cString, ""); 
   }






   MyString::MyString(const char *String)
   {
      cString = new char[strlen(String) + 1];
      strcpy(cString, String);
   }






   MyString::MyString(const MyString& rightString)
   {
      cString = new char[strlen(rightString.cString) + 1];
      strcpy(cString, rightString.cString);
   }






   MyString::~MyString()
   {
      delete [] cString;
   }






   MyString MyString::operator=(const MyString& rightString)
   {
      if (this != &rightString)
      {
         delete [] cString;
         cString = new char[strlen(rightString.cString) + 1];
         strcpy(cString, rightString.cString);
      }
      return *this;
   }






   long MyString::length() const
   {
      return strlen(cString);
   }






   std::ostream& operator<<(std::ostream& out, const MyString& rightString)
   {
      cout << rightString.cString;
      return out;
   }






   char& MyString::operator[](int index)
   {
      assert(index >= 0 && index < strlen(cString));
      return cString[index]; 
   }






   char MyString::operator[](int index) const
   {
      assert(index >= 0 && index < strlen(cString));
      return cString[index];
   }






   bool operator==(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) == 0;
   }






   bool operator!=(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) != 0;
   }






   bool operator>(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) > 0;
   }






   bool operator<(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) < 0;
   }






   bool operator>=(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) >= 0;
   }






   bool operator<=(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) <= 0;
   }
}






/*---------------- Connor's Output ---------------
 

 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z

 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

 ----- Testing relational operators between MyStrings
 Comparing app to apple
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing apple to
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing  to Banana
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing Banana to Banana
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false

 ----- Testing relations between MyStrings and char *
 Comparing he to hello
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing why to wackity
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true

 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after sElf assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is Binky
 val is winky
 after assign,  val is Binky
 Program ended with exit code: 0



--------------- End of Output ---------------------*/