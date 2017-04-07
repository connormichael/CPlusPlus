/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 6, 2016
 Professor Dave Harden
 Assignment 6.1 Recursion
 
 Program Overview: 
 The program uses a function reverseWithinBounds that reverses any 
 array of characters between to specified bounds. For example if the 
 array has structure: 
 a[0] == 'A'	a[1] == 'B'	a[2] == 'C'	a[3] == 'D'	a[4] == 'E'
 and reverseWithinBounds is passed a lowerBound of 1 and an upperBound 
 of 4 then the array will have a new structure of: 
 a[0] == 'A'	a[1] == 'E'	a[2] == 'D'	a[3] == 'C'	a[4] == 'B'
 This function is then wrapped by reverseCString, which allows 
 for any C-String to be reversed. testReverseCString then demonstrates
 the functionality of reverserCString by interating over several 
 cStrings, reversing them, and then outputing the result.
 */


#include <iostream>
#include <cstring>
using namespace std;

void reverseWithinBounds(char list[], int lowerBound, int upperBound);
void reverseCString(char []);
void testReverseCString();

int main()
{
   testReverseCString();
}






//Instantiate an array of cStrings. Iterate over each C-String output the
//initial value, call on reverseCSting, then output the resulting change in
//the C-String.
void testReverseCString()
{
   char beforeOutput[] = "Here is the string before the reverse: ";
   char afterOuput[] = "Here is the string after the reverse: ";
   char fruit[4][20] = {"apple", "banana", "pineapple", "pears and plums"};

   for (int i =0; i < sizeof(fruit)/sizeof(fruit[0]); i++)
   {
      cout << beforeOutput;
      cout << fruit[i] << endl;
      reverseCString(fruit[i]);
      cout << afterOuput;
      cout << fruit[i] << endl << endl;
   }
}






//Given an array of chars list[], and upper (upperBound) and lower index
//(lowerBound) values, recursively call on the function, swapping the char
//values stored at the lower and upper bounds until lower index is greater
//than upper index value.
void reverseWithinBounds(char list[], int lowerBound, int upperBound)
{
   if (upperBound > lowerBound)
   {
      //temp value to allow for char position swap
      char temp;

      temp = list[lowerBound];
      list[lowerBound] = list[upperBound];
      list[upperBound] = temp;
      reverseWithinBounds(list, lowerBound + 1, upperBound - 1);
   }
}






//Wrapper function for reverseWithinBounds, which allows for any C-String to
//be reversed, take single array of chars cString. 
void reverseCString(char cString[])
{
   reverseWithinBounds(cString, 0, strlen(cString) - 1);
}






/* --------------- Connor's Ouput --------------------
 
Here is the string before the reverse: apple
Here is the string after the reverse: elppa

Here is the string before the reverse: banana
Here is the string after the reverse: ananab

Here is the string before the reverse: pineapple
Here is the string after the reverse: elppaenip

Here is the string before the reverse: pears and plums
Here is the string after the reverse: smulp dna sraep

Program ended with exit code: 0
 
------------------- End of Ouput ---------------------*/



