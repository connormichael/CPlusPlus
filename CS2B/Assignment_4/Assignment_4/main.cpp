//
//  main.cpp
//  Assignment_4
//
//  Created by Connor Lynch on 1/24/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//


#include <iostream>
#include <sstream>
#include <string> 
using namespace std;

int main()
{
   int stampBalance, numYogurtsInt;
   const int NUM_STAMPS_FOR_REWARD = 10;
   string userInput, numYogurtsString, freeYogurtInput;
   char userInputLetter, freeYogurtInputLetter;

   stampBalance = 0;
   while (true)
   {
      cout << "\nMenu:\n   P (process Purchase)\n   S (Shut down)\n" << endl;
      getline(cin, userInput);
      cout << "Your Choice: " << userInput << endl;

      userInputLetter = toupper(userInput[0]);

      if (userInputLetter == 'S')
      {
         cout << "\nYou have said you wish to Shut Down. Have a nice day!\n";
         break;
      }
      if (userInputLetter != 'S' && userInputLetter != 'P')
      {
         cout << "\n *** Use P or S, please. ***\n";
         continue;
      }
      if (stampBalance < NUM_STAMPS_FOR_REWARD)
      {
         cout << "\nHow many yogurts would you like dear customer"
            << " (Please be reasonable) ";
         getline(cin,numYogurtsString);
         istringstream(numYogurtsString) >> numYogurtsInt;
         if (numYogurtsInt > 0 && numYogurtsInt < 100)
         {
            stampBalance += numYogurtsInt;
            cout << "\nYou just earned " << numYogurtsInt
               << " stamps and have a total of "
               << stampBalance << " to use" << endl;
            continue;
         }
         else
            cout << "\nNext time please choose a number "
               << "or one less than 100\n";
            continue;
      }

      cout << "\nYou qualify for a free yogurt! "
         << "Would you like to use your credits? (Y or N) ";
      getline(cin, freeYogurtInput);
      freeYogurtInputLetter = toupper(freeYogurtInput[0]);

      if (freeYogurtInputLetter == 'N')
      {
         cout << "\nHow many yogurts would you "
            << "like dear customer (Please be reasonable) ";
         getline(cin,numYogurtsString);
         istringstream(numYogurtsString) >> numYogurtsInt;
         if (numYogurtsInt > 0 && numYogurtsInt < 100)
         {
            stampBalance += numYogurtsInt;
            cout << "\nYou just earned " << numYogurtsInt
               << " stamps and have a total of "
               << stampBalance << " to use" << endl;
            continue;
         }
         else
            cout << "\nNext time please choose a number "
               << " or less than 100\n";
            continue;
      }
      if (freeYogurtInputLetter == 'Y')
      {
         cout << "\nHere is your free yogurt\n";
         stampBalance -= 10;
      }
      else if (freeYogurtInputLetter != 'Y' || freeYogurtInputLetter != 'N')
      {
         cout << "\nNext time please enter Y or N for your response\n";
         continue;
      }
   }
}


/*---------------Connor's Run #1 ------------------
Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

How many yogurts would you like dear customer (Please be reasonable) 6

You just earned 6 stamps and have a total of 6 to use

Menu:
   P (process Purchase)
   S (Shut down)

what? 
Your Choice: what? 

 *** Use P or S, please. ***

Menu:
   P (process Purchase)
   S (Shut down)

PURCHASE
Your Choice: PURCHASE

How many yogurts would you like dear customer (Please be reasonable) 8

You just earned 8 stamps and have a total of 14 to use

Menu:
   P (process Purchase)
   S (Shut down)

process
Your Choice: process

You qualify for a free yogurt! Would you like to use your credits? (Y or N) Y

Here is your free yogurt

Menu:
   P (process Purchase)
   S (Shut down)

P
Your Choice: P

How many yogurts would you like dear customer (Please be reasonable) 10000

Next time please choose a number or one less than 100

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

How many yogurts would you like dear customer (Please be reasonable) kl

Next time please choose a number or one less than 100

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

How many yogurts would you like dear customer (Please be reasonable) 8

You just earned 8 stamps and have a total of 12 to use

Menu:
   P (process Purchase)
   S (Shut down)

Process
Your Choice: Process

You qualify for a free yogurt! Would you like to use your credits? (Y or N) yes

Here is your free yogurt

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

How many yogurts would you like dear customer (Please be reasonable) 80

You just earned 80 stamps and have a total of 82 to use

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) no

How many yogurts would you like dear customer (Please be reasonable) 3

You just earned 3 stamps and have a total of 85 to use

Menu:
   P (process Purchase)
   S (Shut down)

shutitdown
Your Choice: shutitdown

You have said you wish to Shut Down. Have a nice day!
Program ended with exit code: 0
 
 


-----------------Connor's Run #2 --------------------

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

How many yogurts would you like dear customer (Please be reasonable) 80

You just earned 80 stamps and have a total of 80 to use

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) nope

How many yogurts would you like dear customer (Please be reasonable) 8

You just earned 8 stamps and have a total of 88 to use

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) Yes!!!!

Here is your free yogurt

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) what

Next time please enter Y or N for your response

Menu:
   P (process Purchase)
   S (Shut down)

huh? 
Your Choice: huh? 

 *** Use P or S, please. ***

Menu:
   P (process Purchase)
   S (Shut down)

how about this? 
Your Choice: how about this? 

 *** Use P or S, please. ***

Menu:
   P (process Purchase)
   S (Shut down)

X
Your Choice: X

 *** Use P or S, please. ***

Menu:
   P (process Purchase)
   S (Shut down)

9
Your Choice: 9

 *** Use P or S, please. ***

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) yes

Here is your free yogurt

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) no thanks

How many yogurts would you like dear customer (Please be reasonable) 10

You just earned 10 stamps and have a total of 78 to use

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) n

How many yogurts would you like dear customer (Please be reasonable) 10000

Next time please choose a number  or less than 100

Menu:
   P (process Purchase)
   S (Shut down)

p
Your Choice: p

You qualify for a free yogurt! Would you like to use your credits? (Y or N) ya

Here is your free yogurt

Menu:
   P (process Purchase)
   S (Shut down)

Shut down 
Your Choice: Shut down 

You have said you wish to Shut Down. Have a nice day!
Program ended with exit code: 0


------------------------------------------------------------*/

