//
//  main.cpp
//  Week7_Practice
//
//  Created by Connor Lynch on 11/13/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   int number, secretNumber, count, games = 0, wins = 0, losses = 0;

   srand((time(NULL)));
   cout << "Welcome to the number guessing game! \n";
   cout << "For each game, you have at most 3 chances "
      "to guess a secret number from 1 to 10. \n";
   cout << "Enter a number from 1 to 10. Enter 0 to exit. ";
   cin >> number;
   if (number != 0)
   {
      secretNumber = rand() % 10 + 1;
      cout << secretNumber << endl;
   }
   while (games < 3)
   {
      games++;
      while ((number != secretNumber) || (count < 3))
      {
         cout << "Not correct, try again: ";
         cin >> number;
         count++;
      }

   }
      if (count < 3)
      {
         wins++;
         cout << "Congratulations, Correct! Let's start a new game. ";
      }
      else if (count == 3)
         cout << "Not Correct. You have reached 3 trials. The correct number is "
            << secretNumber << ".\n";
      cout << "Let's start a new game.";
      losses++ ;
      cout << "Enter a number from 1 to 10. Enter 0 to exit: ";
      cin >> number;
   }
   cout << "Here is your game summary: ";
   cout << "Total games: " << games;
   cout << "Total wins: " << wins;
   cout << "Total game losses: " << losses;

   return 0;
}