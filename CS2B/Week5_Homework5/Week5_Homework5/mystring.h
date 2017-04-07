/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 31, 2016
 Professor Dave Harden
 Assignment 5.1

 
 Description:
 This program lays out the methods for the MyString classs. Within this class 
 MyString objects are composed of a single variable, cString, a C-String. 
 The class provides friend and member methods for operator overloading. 
 Since cString is implemented as a dynamic array, a copy constructor, default 
 constructor, destructor, and overloaded assignment operator are written to 
 support memory managment.
 The operloaded operators include: [] for both const and non const variables, 
 =, >>, <<, <, >, >=, <=, ==, !=, +, +=. There is also a method, read(), that 
 allows the user to specify the deliminating character when reading strings. 
 Operations between integers and MyString objects are supported where 
 necessary.

 Member Functions:
 MyString()
   Precondition: No preconditions for default constructor
   Postcondition: A MyString object with one member data, cString, a dynamic
   array with value set to null string value ""

 MyString(const char *String)
   Precondition: *String is C-string
   Postcondition: A MyString object with one member data, cString, a dynamic 
   array of exact size as the char array pointed to by *String, and with 
   values equal to those in *String

 MyString(const MyString& rightString)
   Precondition: a MyString object reference
   Postcondition: A MyString object with one member data, cString, a dynamic
   array of exact size as the char array in rightString, and with
   values equal to those in the cString of rightString

 ~MyString()
   Precondition: A MyString object exists with one member data, cString, a
   dynamic array
   Postcondition: The memory that a MyString object is pointing to is deallocated 
   off of the heap

 long length() const
   Precondition: A MyString object with a cString of any size
   Postcondition: Returns the number of characters in the cString of a MyString 
   object

 char& operator[](int index)
   Precondition: index, an integer that is greater than or equal to zero and
   less than or equal to one less of length of the cString in the calling object
   Postcondition: Returns reference to a char variable stored in the index location

 char operator[](int index) const
   Precondition: index, an integer that is greater than or equal to zero and
   less than or equal to one less of length of the cString in the calling object
   Postcondition: Returns a value of a char variable stored in the index location

 MyString operator=(const MyString& rightString)
   Precondition: A MyString object passed by reference, either a unique MyString
   object, or the same one for cases of self-assignment.
   Postcondition: Returns a Mystring object that points to a different memory 
   location than that of rightString, whose memory size is that of
   rightString, and whose values are set to those of rightString i.e. a deep 
   copy of rightString

 friend std::ostream& operator<<(std::ostream& out, const MyString& rightString)
   Precondition: rightString is a MyString object storing a C-String. out is a stream.
   Postcondition: Output stream of the all characters stored in rightString's
   dynamic array.

 friend bool operator<(const MyString& leftString, const MyString& rightString)
   Precondition: leftString is either a MyString object or a C-String.
   rightString is either a MyString object or a C-String.
   Postcondition: Returns boolean result, true or false, of whether leftString is
   less than rightString based on the ASCII values of the characters

 friend bool operator>(const MyString& leftString, const MyString& rightString)
   Precondition: leftString is either a MyString object or a C-String.
   rightString is either a MyString object or a C-String.
   Postcondition: Returns boolean result, true or false, of whether leftString is 
   less than rightString

 friend bool operator>=(const MyString& leftString, const MyString& rightString)
   Precondition: leftString is either a MyString object or a C-String.
   rightString is either a MyString object or a C-String.
   Postcondition: Returns boolean result, true or false, of whether leftString is
   greater than or equal to rightString

 friend bool operator<=(const MyString& leftString, const MyString& rightString)
   Precondition: leftString is either a MyString object or a C-String.
   rightString is either a MyString object or a C-String.
   Postcondition: Returns boolean result, true or false, of whether leftString is
   less than or equal to rightString

 friend bool operator==(const MyString& leftString, const MyString& rightString)
   Precondition: leftString is either a MyString object or a C-String.
   rightString is either a MyString object or a C-String.
   Postcondition: Returns boolean result, true or false, of whether leftString is
   equal to rightString

 friend bool operator!=(const MyString& leftString, const MyString& rightString)
   Precondition: leftString is either a MyString object or a C-String.
   rightString is either a MyString object or a C-String.
   Postcondition: Returns boolean result, true or false, of whether leftString is 
   not equal to rightString

 friend MyString operator+(const MyString& leftString, const MyString& rightString)
   Precondition: leftString is either a MyString object or a C-String.
   rightString is either a MyString object or a C-String.
   Postcondition: A MyString object whose array size is equal to the combined
   size of leftString and rightString and whose value is the chars in leftString
   followed by the chars in rightString

 MyString operator+=(const MyString& rightString)
   Precondition: rightString is either a MyString object or a C-String.
   Postcondition: Returns calling MyString object with char array extended by 
   length of rightString and whose value is the char of the calling object 
   followed by the chars in rightString

 friend std::istream& operator>>(std::istream& in, MyString& rightString)
   Precondition: in is a stream. rightString is a MyString object with one member
   data, cString, adynamic array
   Postcondition: returns in, which is then ready to read future data.
   Stores results from in into rightString.

 void read(std::istream& in, char delim)
   Precondition: in is a stream. delim is char type used to specify the deliminating
   character for reading strings.
   Postcondition: calling object cString is set to the string value of in.
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
      friend MyString operator+(const MyString& leftString, const MyString& rightString);
      MyString operator+=(const MyString& rightString);
      friend std::istream& operator>>(std::istream& in, MyString& rightString);
      void read(std::istream& in, char delim);

   private:
      char *cString;
   };
}

#endif
