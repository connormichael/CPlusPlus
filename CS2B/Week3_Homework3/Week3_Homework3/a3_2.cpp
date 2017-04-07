//
//  File.cpp
//  Week3_Homework3
//
//  Created by Connor Lynch on 10/16/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
using namespace std;

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main()
{
   //Assignment 3.2
   int size;
   string *names;
   int *scores;

   cout << "\nHow many scores would you like to enter?: ";
   cin >> size;
   names = new string[size];
   scores = new int[size];

   initializeArrays(names, scores, size);
   sortData(names, scores, size);
   displayData(names, scores, size);

   delete [] names;
   delete [] scores;

}






void initializeArrays(string names[], int scores[], int size)
{
   for (int k = 0, j = 1; k < size; k++)
   {
      cout << "Enter the name for score #" << j << ": ";
      cin >> names[k];
      cout << "Enter the score for score #" << j << ": ";
      cin >> scores[k];
   }
}






void sortData(string names[], int scores[], int size)
{
   int tempScore;
   string tempName;

   for (int k = 0; k < size; k++)
   {
      for (int j = k + 1; j < size; j++)
      {
         if (scores[j] > scores[k])
         {
            tempScore = scores[k];
            scores[k] = scores[j];
            scores[j] = tempScore;

            tempName = names[k];
            names[k] = names[j];
            names[j] = tempName;
         }
      }
   }
}






void displayData(const string names[], const int scores[], int size)
{
   cout << "\nTop Scorers:" << endl;
   for (int k = 0; k < size; k++)
   {
      cout << names[k] << ": " << scores[k] << endl;
   }
}