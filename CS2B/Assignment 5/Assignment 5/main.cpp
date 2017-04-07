//
//  main.cpp
//  Assignment 5
//
//  Created by Connor Lynch on 1/31/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// method prototypes
char getKeyLetter();
string getString();
string maskLetter(string theString, char keyLetter);
string removeLettter(string theString, char keyLetter); //STILL NEED TO DO THIS FUNCTION
int countKey(string theString, char keyLetter);


int main()
{
   string finalOutput;
   char letter;
   string phrase;

   letter = getKeyLetter();
   phrase = getString();
   maskLetter(phrase, letter);

   countKey(phrase,letter);

   cout << "\nWorking so far\n";
}


//IMPORTANT do I need to look for any other user input failurs such as numerics here?
char getKeyLetter()
{
   char blah;
   int charLength;
   string userInputCharacter;

   while(true)
   {
      cout << "\nPlease enter a single character: " << endl;
      getline(cin, userInputCharacter);
      charLength = userInputCharacter.length();

      if (charLength != 1)
      {
         cout << "\nError: Please enter a single character\n";
         continue;
      }
      else
      {
         cout << "Great your search character is " << userInputCharacter
            << endl;
         blah = userInputCharacter[0];
         return blah;    //make sure this is the best way to return this
         break;
      }
   }
}


//Again you need to check to see if you need to add any other filters here
//right now you can add a whole string of numbers...
string getString()
{
   string userInputString;
   int stringLength;

   while(true)
   {
      cout << "\nPlease enter a phrase or sentence: " << endl;
      getline(cin, userInputString);
      stringLength = userInputString.length();

      if (stringLength < 4)  //ANY other filters?
      {
         cout << "\nError: Please enter a longer string\n";
         continue;
      }
      else
      {
         cout << "Great your search sentence is " << userInputString
         << endl;

         return userInputString;    //make sure this is the best way to return this
         break;
      }
   }
}


string maskLetter(string theString, char keyLetter)
{
   string example = "lovelife";
   string stringOutput;
   int i;
   char dash;

   dash = '-';

   for (i = 0; i < theString.length(); i++)
      if (theString[i] == keyLetter)
         theString[i] = dash;

   stringOutput = theString;  //THIS IS PROBABLY NOT THE BEST way to do this
   cout << "\nString with '" << keyLetter << "' masked: \n" << stringOutput << endl;

   return stringOutput;
}




int countKey(string theString, char keyLetter)
{
   int count;
   int k;

   count = 0;

   for (k = 0; k < theString.length(); k++)  //Im allowed to use k here in a for loop right?
      if (theString[k] == keyLetter)
         count++;

   return count;
}






