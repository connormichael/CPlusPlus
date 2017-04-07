/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 6, 2016
 Professor Dave Harden
 Assignment 6.2 Recursion
 
 Program Overview: 
 This program determines if a user input is palindrome, a string that reads the
 same forward or backward. The program reads in user input as MyString objects, 
 a locally defined class that handles dyanmically created char arrays. 
 isAPalindrome takes a MyString object and two index values and determines if 
 the string object is a palidrome by making recursive calls to isAPalindrome 
 with increasing shorted distance between the upper and lower index. 
 getUserInptut then accepts string input from the console, reading them in as
 MyString objects and calls on IsAPalidrome until the user specifies quit or 
 Quit.
 */

#include <iostream>
#include <cctype>
#include "mystring.h"
using namespace std;
using namespace cs_mystring;


bool isAPalindrome(MyString cstring, int lowerBound, int upperBound);
void getUserInput();

int main()
{
   getUserInput();
}






//Promt the user for console input which is read in as MyString objects.
//IsAPalindrome is then called to determine if the MyString is a palidrome
// and the result is output to the console.
void getUserInput()
{
   //Mystring object to store user input
   MyString temp;

   do
   {
      cout << "Enter a string: ";
      temp.read(cin, '\n');
      if ((temp == "Quit") || (temp == "quit"))
         break;
      else
      {
         if (isAPalindrome(temp, 0, temp.length() - 1))
            cout << temp << " is a palindrome." << endl;
         else
            cout << temp << " is not a palindrome." << endl;
      }
   }
   while ((temp != "Quit") || (temp != "quit"));
}






//Take a MyString object and two index bounds. Ignoring all punctuation
//and spaces, determine if a MyString object is a palindrome by checking the
//equality of the two converted uppercase chars.
bool isAPalindrome(MyString cstring, int lowerBound, int upperBound)
{
   //result to be returned
   bool result = true;

   if (lowerBound >= upperBound)
      return result;
   else
   {
      if (ispunct(cstring[lowerBound]) || (isspace(cstring[lowerBound])))
         lowerBound++;
      if ((ispunct(cstring[upperBound])) || (isspace(cstring[upperBound])))
         upperBound--;
      else if (toupper(cstring[lowerBound]) == toupper(cstring[upperBound]))
      {
         upperBound--;
         lowerBound++;
         result = true;
      }
      else
      {
         upperBound--;
         lowerBound++;
         result = false;
      }
      return result * isAPalindrome(cstring, lowerBound, upperBound);
   }
}






/*----------------------- Connor's Output ---------------------

Enter a string: Able was I, ere I saw Elba
Able was I, ere I saw Elba is a palindrome.
Enter a string: peanut butter
peanut butter is not a palindrome.
Enter a string: quit
Program ended with exit code: 0

----------------------- End of Output -------------------------*/
