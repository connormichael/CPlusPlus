//
//  main.cpp
//  Tester
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
string removeLettter(string theString, char keyLetter);
int countKey(string theString, char keyLetter);


int main()
{
   char letter;
   string phrase;

   letter = getKeyLetter();
   phrase = getString();
   maskLetter(phrase, letter);
   removeLettter(phrase, letter);
   countKey(phrase,letter);
}

char getKeyLetter()
{
   char searchLetter;
   int charLength;
   string userInputCharacter;

   while(true)
   {
      cout << "\nPlease enter a single character to act as a key: " << endl;
      getline(cin, userInputCharacter);
      charLength = userInputCharacter.length();

      if (charLength != 1)
      {
         cout << "\nError: Please enter a SINGLE character\n";
         continue;
      }
      else
      {
         cout << "\nGreat your search character is: \n" << userInputCharacter
         << endl;
         searchLetter = userInputCharacter[0];
         return searchLetter;
         break;
      }
   }
}

string getString()
{
   string userInputString;
   int stringLength;

   while(true)
   {
      cout << "\nPlease enter a phrase or sentence >= 4 letters: \n" << endl;
      getline(cin, userInputString);
      stringLength = userInputString.length();

      if (stringLength < 4)
      {
         cout << "\nError: Please enter a longer string\n";
         continue;
      }
      else
      {
         cout << "\nGreat your search sentence is \n" << userInputString
         << endl;

         return userInputString;
         break;
      }
   }
}

string maskLetter(string theString, char keyLetter)
{
   string maskedOutput;
   int i;
   char replacementDash;

   replacementDash = '-';
   maskedOutput = "";

   for (i = 0; i < theString.length(); i++)
      if (theString[i] == keyLetter)
         maskedOutput += replacementDash;
      else
         maskedOutput += theString[i];

   cout << "\nString with '" << keyLetter << "' masked: "
      << "\n" << maskedOutput << endl;

   return maskedOutput;
}


string removeLettter(string theString, char keyLetter)
{
   string removedOutput;
   int i;

   removedOutput = "";

   for (i = 0; i < theString.length(); i++)
      if (theString[i] != keyLetter)
         removedOutput += theString[i];

   cout << "\nString with '" << keyLetter << "' removed: "
      << "\n" << removedOutput << endl;

   return removedOutput;
}


int countKey(string theString, char keyLetter)
{
   int letterCount;
   int k;

   letterCount = 0;

   for (k = 0; k < theString.length(); k++)
      if (theString[k] == keyLetter)
         letterCount++;
   cout << "\nthe number of occurances of '" << keyLetter
      << "' is " << letterCount << endl;

   return letterCount;
}




/*------------Connor's Run #1--------------
 

Please enter a single character to act as a key: 
sdf

Error: Please enter a SINGLE character

Please enter a single character to act as a key: 
sd

Error: Please enter a SINGLE character

Please enter a single character to act as a key: 
;aslkdjf

Error: Please enter a SINGLE character

Please enter a single character to act as a key: 
e

Great your search character is: 
e

Please enter a phrase or sentence >= 4 letters: 

learning C++ is fun and rewarding!

Great your search sentence is 
learning C++ is fun and rewarding!

String with 'e' masked: 
l-arning C++ is fun and r-warding!

String with 'e' removed: 
larning C++ is fun and rwarding!

the number of occurances of 'e' is 2
Program ended with exit code: 0
 

--------------Connor's Runs #2-------------


Please enter a single character to act as a key: 
a

Great your search character is: 
a

Please enter a phrase or sentence >= 4 letters: 

as

Error: Please enter a longer string

Please enter a phrase or sentence >= 4 letters: 

sda

Error: Please enter a longer string

Please enter a phrase or sentence >= 4 letters: 

green apples, red apples, blue apples

Great your search sentence is 
green apples, red apples, blue apples

String with 'a' masked: 
green -pples, red -pples, blue -pples

String with 'a' removed: 
green pples, red pples, blue pples

the number of occurances of 'a' is 3
Program ended with exit code: 0


--------------Connor's Runs #3-------------


Please enter a single character to act as a key: 
al;skdfj

Error: Please enter a SINGLE character

Please enter a single character to act as a key: 
this? 

Error: Please enter a SINGLE character

Please enter a single character to act as a key: 
how about this? 

Error: Please enter a SINGLE character

Please enter a single character to act as a key: 
a

Great your search character is: 
a

Please enter a phrase or sentence >= 4 letters: 

fast, faster FASTEST!!!

Great your search sentence is 
fast, faster FASTEST!!!

String with 'a' masked: 
f-st, f-ster FASTEST!!!

String with 'a' removed: 
fst, fster FASTEST!!!

the number of occurances of 'a' is 2
Program ended with exit code: 0

--------------Connor's Runs #4-------------

Please enter a single character to act as a key: 


Error: Please enter a SINGLE character

Please enter a single character to act as a key: 
W

Great your search character is: 
W

Please enter a phrase or sentence >= 4 letters: 

what in the world am I doing? 

Great your search sentence is 
what in the world am I doing? 

String with 'W' masked: 
what in the world am I doing? 

String with 'W' removed: 
what in the world am I doing? 

the number of occurances of 'W' is 0
Program ended with exit code: 0

-------------------------------------------*/


