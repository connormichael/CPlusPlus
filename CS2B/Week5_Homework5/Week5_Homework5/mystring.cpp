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






/*--------------------- Connor's Output --------------------
 

----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] = 
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next    
Read string = we read whole lines

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

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo
Program ended with exit code: 0

 
------------------------ End of Ouput ----------------------*/


