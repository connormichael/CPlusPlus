/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 21, 2016
 Professor Dave Harden
 Assignment 4.1
 */


#ifndef MyString_h
#define MyString_h

#include <iostream>  

namespace cs_mystring
{
   class MyString
   {
   public:
      MyString();
      MyString(const char *String);
      MyString(const MyString& rightString);
      ~MyString();
      long length() const;
      char& operator[](int index);
      char operator[](int index) const;
      MyString operator=(const MyString& rightString);
      friend std::ostream& operator<<(std::ostream& out, const MyString& rightString);
      friend bool operator<(const MyString& leftString, const MyString& rightString);
      friend bool operator>(const MyString& leftString, const MyString& rightString);
      friend bool operator>=(const MyString& leftString, const MyString& rightString);
      friend bool operator<=(const MyString& leftString, const MyString& rightString);
      friend bool operator==(const MyString& leftString, const MyString& rightString);
      friend bool operator!=(const MyString& leftString, const MyString& rightString);
   private:
      char *cString;
   };
}

#endif
