/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 15, 2016
 Professor Dave Harden
 Assignment 3.2 Pointers and Dynamic Memory
 
 Program Overview: 
 The program accepts an integar number from the user to specify how many 
 entries they would like to add. The user input is used to then specify 
 the size of two dynamic arrays; one for the names and one for associated
 scores. The names array is a dynamic array of strings. The scores array is a 
 dynamic array of integers. initializeArrays is called to prompt the user to 
 enter information for the name and score of a contestant. Once the user has
 inputed the names and scores for each entry, sortData is then called to order 
 the array in descending order. displayData is then called to output the 
 results of the sorted arrays.

 User input:
 - number of scores to be entered: int
 - name of contestant: string 
 - score of contestant: int

 Program Ouput Example: 
    Top Scorers:
    Kim: 9900
    Armando: 8000
    Suzy: 600
    Tim: 514
 */



#include <iostream>
using namespace std;


void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);


int main()
{
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






//initializeArrays takes two empty dynamic arrays, names and scores, along with
//the size of the arrays. It then prompts the user to enter values for names
//and scores size of the array times.
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






//sortData takes two dynamic arrays and their size and implements Selection
//Sort to order both arrays based on scores in descending order.
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







//displayData akes two sorted dynamic arrays and their size and prints out the
//the contents of both arrays. Since the arrays have been sorted the output
//corresponds to the top scores entered by the user.
void displayData(const string names[], const int scores[], int size)
{
   cout << "\nTop Scorers:" << endl;
   for (int k = 0; k < size; k++)
   {
      cout << names[k] << ": " << scores[k] << endl;
   }
}






/*------------------ Connor's Output -------------------------

How many scores would you like to enter?: 4
Enter the name for score #1: Suzy
Enter the score for score #1: 600
Enter the name for score #2: Kim
Enter the score for score #2: 9900 d
Enter the name for score #3: Armando
Enter the score for score #3: 8000
Enter the name for score #4: Tim
Enter the score for score #4: 514

Top Scorers:
Kim: 9900
Armando: 8000
Suzy: 600
Tim: 514
Program ended with exit code: 0

 ------------------------------------------------------------*/
