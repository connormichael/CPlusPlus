/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 31, 2016
 Professor Dave Harden
 Assignment 5.1

 Description:
 This program lays out the methods for the MyString class. Within this class
 MyString objects are composed of one data member, cString, a dynamic char array.

 The class provides friend and member methods for operator overloading as well
 as those necessary for handling heap memory for the dynamic char array.
 Since cString is implemented as a dynamic array, a copy constructor, default
 constructor, destructor, and overloaded assignment operator are written to
 support memory managment.The operloaded operators include: [] for both const
 and non const variables, =, >>, <<, <, >, >=, <=, ==, !=, +, +=. There is also
 a method, read(), that allows the user to specify the deliminating character
 when reading strings. Operations between integers and MyString objects are
 supported where necessary.
 The member function read, allows for the user to specify the deliminating
 character when reading input.
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
#include "mystring.h"
using namespace std;


namespace cs_mystring
{
   //class default constructor that sets cString to null string value
   MyString::MyString()
   {
      cString = new char[1];
      strcpy(cString, "");
   }






   //Parameter taking class constructor, initilizes cString member data
   MyString::MyString(const char *String)
   {
      cString = new char[strlen(String) + 1];
      strcpy(cString, String);
   }






   //Copy constructor to make deep copy of member data
   MyString::MyString(const MyString& rightString)
   {
      cString = new char[strlen(rightString.cString) + 1];
      strcpy(cString, rightString.cString);
   }






   //Class object destructor to handle heap memory managment
   MyString::~MyString()
   {
      delete [] cString;
   }







   //Overloaded assignent operator to make deep copy of MyString objects
   //since they are composed of a dyanmic array
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







   //Member function that returns the length of a cString array as a long int
   long MyString::length() const
   {
      return strlen(cString);
   }







   //Overloaded stream for output of rightString objects. Outputs all characters
   //stored in cString
   std::ostream& operator<<(std::ostream& out, const MyString& rightString)
   {
      cout << rightString.cString;
      return out;
   }






   //Overloaded [] (index) operator for returning reference to char stored in
   //the index position of cString for non const objects.
   char& MyString::operator[](int index)
   {
      assert(index >= 0 && index < strlen(cString));
      return cString[index];
   }






   //Overloaded [] (index) operator for returned the value of a char stored in
   //the index position of a Cstring for const objects
   char MyString::operator[](int index) const
   {
      assert(index >= 0 && index < strlen(cString));
      return cString[index];
   }






   //Overloaded == (equal to) operator for comparing MyString and c-string objects
   bool operator==(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) == 0;
   }






   //Overloaded != (not equal to) operator for comparing MyString and c-string objects
   bool operator!=(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) != 0;
   }






   //Overloaded > (greater than) operator for comparing MyString and c-string objects
   bool operator>(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) > 0;
   }






   //Overloaded < (less than) operator for comparing MyString and c-string objects
   bool operator<(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) < 0;
   }






   //Overloaded >= (greater than or equal to) operator for comparing MyString
   //and c-string objects
   bool operator>=(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) >= 0;
   }






   //Overloaded <= (less than or equal to) operator for comparing MyString
   //and c-string objects
   bool operator<=(const MyString& leftString, const MyString& rightString)
   {
      return strcmp(leftString.cString, rightString.cString) <= 0;
   }






   //Overloaded addition operator for addition of either two MyString objects
   //or one MyString object and one c-string object
   MyString operator+(const MyString& leftString, const MyString& rightString)
   {
      //local MyString object used to add two other MyString objects
      MyString temp;

      temp.cString = new char[strlen(leftString.cString) + strlen(rightString.cString) + 1];
      strcpy(temp.cString, leftString.cString);
      strcat(temp.cString, rightString.cString);
      return temp;
   }






   //Overloaded addition operator using a single input parameter. Function allows
   //for addition of another MyString or of an c-string
   MyString MyString::operator+=(const MyString& rightString)
   {
      *this = *this + rightString;
      return *this;
   }






   //Overloaded stream extraction operator for input of cStrings
   //Function allows for input of c-strings up to 127 characters long
   std::istream& operator>>(std::istream& in, MyString& rightString)
   {
      //temp: a non dynamic char array for temporarily
      //storing values of in
      char temp[128];
      in >> temp;
      delete [] rightString.cString;
      rightString.cString = new char[strlen(temp) + 1];
      strcpy(rightString.cString, temp);

      return in;
   }






   //Member function that allows for strings to be read with a specified
   //deliminating character. cStrings up to 127 characters can be read.
   void MyString::read(std::istream& in, char delim)
   {
      //temp: a non dynamic char array for temporarily
      //storing values of in
      char temp[128];
      in.getline(temp, 127, delim);
      delete [] cString;
      cString = new char[strlen(temp) + 1];
      strcpy(cString, temp);
   }
}







