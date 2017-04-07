/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 21, 2016
 Professor Dave Harden
 Assignment 8.1
 */


#include <iostream>
#include <vector>
using namespace std;


struct highscore
{
   int score;
   char name[24];
};


void initializeData(vector<highscore>& scores);
void sortData(vector<highscore>& scores);
void displayData(const vector<highscore>& scores);


int main()
{
   int scoresSize;
   cout << "Please enter the number of scores: ";
   cin >> scoresSize;
   vector<highscore> scores(scoresSize);

   initializeData(scores);
   sortData(scores);
   displayData(scores);
}






void initializeData(vector<highscore>& scores)
{
   int j = 1;

   for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++)
   {
      cout << "Enter the name for score #" << j << ": ";
      cin >> i->name;
      cout << "Enter the score for score #" << j << ": ";
      cin >> i->score;
      j++;
   }
}






void sortData(vector<highscore>& scores)
{
   highscore tempScore;

   for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++)
   {
      for (vector<highscore>::iterator j = i + 1; j != scores.end(); j++)
      {
         if ((i->score) < (j->score))
         {
            tempScore = *j;
            *j = *i;
            *i = tempScore;
         }
      }
   }
}






void displayData(const vector<highscore>& scores)
{
   cout << "\nTop Scorers:" << endl;
   for (vector<highscore>::const_iterator i = scores.begin(); i != scores.end(); i++)
   {
      cout << i->name << ": " << i->score << endl;
   }
}






/*-------------- Connor's Output ---------------------

Please enter the number of scores: 4
Enter the name for score #1: Ryan
Enter the score for score #1: 100
Enter the name for score #2: Connor
Enter the score for score #2: 10
Enter the name for score #3: Kevin
Enter the score for score #3: 1000
Enter the name for score #4: Colleen
Enter the score for score #4: 5

Top Scorers:
Kevin: 1000
Ryan: 100
Connor: 10
Colleen: 5
Program ended with exit code: 0

------------------ End of Ouput ---------------------*/