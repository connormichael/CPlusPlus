/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Janunary 14, 2017
 Professor Dave Harden
 Assignment 1.2

 Program Overview:
 The program uses a function, findSublists, which finds all subsets of a given
 array that are less than or equal to a target value. From these selected
 subsets, the function getMaxList, selects the set with the largest sum.
 isMaxSum, ensures that the total sum of a given data set is not less than
 the target value, ensuring that needless subsetting and searching is not
 performed. The final output of the program is the contents of the selected
 sublist and their total sum.
 All global functions are written as template functions, allowing for their
 use on both standard data types, e.g. integers, as well as custom objects, such
 as iTunesEntry.
 The following client is written to handle iTunesEntry objects, and has a 
 dependency on the iTunes, and newVect classes.
 */

#include <iostream>
using namespace std;

#include "iTunes.h"
#include "newVect.h"
#include "Foothill_Sort.h"
#include <time.h>

template <typename T>
void findSublists(vector<T> &dataSet, vector<Sublist<T>> &choices, int TARGET);
template <typename T>
bool isMaxSum(vector<T> &dataSet, int TARGET);
template <typename T>
Sublist<T> getMaxList(vector<Sublist<T>> &choices, int TARGET);
int operator+(int tunes, iTunesEntry &leftTune);
ostream &operator<<(ostream &out, const iTunesEntry &rightTune);



int main()
{
   int array_size; 
   const int TARGET = 3600;
   vector<iTunesEntry> dataSet;
   vector<Sublist<iTunesEntry>> choices;

   iTunesEntryReader tunes_input("itunes_file.txt");
   if (tunes_input.readError())
   {
      cout << "couldn't open " << tunes_input.getFileName()
      << " for input.\n";
      exit(1);
   }

   // time the algorithm -------------------------
   clock_t startTime, stopTime;
   double totalTime;
   startTime = clock();

   // create a vector of objects for our own use:
   array_size = tunes_input.getNumTunes();
   for (int k = 0; k < array_size; k++)
      dataSet.push_back(tunes_input[k]);

   choices.push_back(Sublist<iTunesEntry>(&dataSet));

   if (!isMaxSum(dataSet, TARGET))
   {
      findSublists(dataSet, choices, TARGET);
      Sublist<iTunesEntry> maxSublist = getMaxList(choices, TARGET);
      stopTime = clock();
      totalTime = double(stopTime - startTime) / CLOCKS_PER_SEC;
      cout << "Total Sublist and Search Algorithm Time: " << totalTime
      << " Seconds." << endl;
      cout << "Target time: " << TARGET << endl;
      maxSublist.showSublist();
   }
   return 0;
}






//Overloaded addition operator to enable addition of integers and iTunesEntry
//objects. Takes two parameters, tunes, and integer value and leftTune, an
//iTunesEntry value. Returns an integer value.
int operator+(int tunes, iTunesEntry &leftTune)
{
   return tunes + leftTune.getTime();
}






//Overloaded << operator takes two parameters, out, and rightTune, an
//iTunesEntry object. This method allows for the underlying data of the
//iTunes object to be ouputted.
ostream &operator<<(ostream &out, const iTunesEntry &rightTune)
{
   out << "Title: " << rightTune.getTitle() << ", " << "Artist: "
   << rightTune.getArtist() << "," << "TuneTime: " << rightTune.getTime() << endl;
   return out;
}





//Given a vector of objects, iterate through the objects and ensure that
//their total sum is not less than the integer TARGET value passed in as the
//second argument. Return true if total sum is less than TARGET, false
//otherwise.
template <typename T>
bool isMaxSum(vector<T> &dataSet, int TARGET)
{
   bool sumTooSmall = false;
   int masterSum = 0;
   for (int k = 0; k < dataSet.size(); k++)
      masterSum = masterSum + dataSet[k];
   if (masterSum < TARGET)
   {
      sumTooSmall = true;
      cout << "Target is larger than sum of all elements. "
      << "Skipping sub-setting algorithm" << endl;
   }
   return sumTooSmall;
}






//Function takes three arguemtns: a vector containing the original data,
//dataSet, a vector with one object, an empty sublist, choices, and an integer
//TARGET value. The function iterates over each item in dataSet and each sublist
//in choices, if the sum of the sublist is less than or equal to the TARGET value
//a new sublist containing the item from dataSet is added to choices
template <typename T>
void findSublists(vector<T> &dataSet, vector<Sublist<T>> &choices, int TARGET)
{

   bool foundPerfect = false;
   for (int k = 0; k < dataSet.size(); k++)
   {
      long currentSize = choices.size();
      for (int j = 0; j < currentSize; j++)
      {
         if (foundPerfect)
            break;
         else if (choices[j].getSum() + dataSet[k] < TARGET)
         {
            Sublist<T> newSub = choices[j].addItem(k);
            choices.push_back(newSub);
         }
         else if (choices[j].getSum() + dataSet[k] == TARGET)
         {
            Sublist<T> newSub = choices[j].addItem(k);
            choices.push_back(newSub);
            foundPerfect = true;
         }
      }
   }
}






//Function takes two arguements, a vector choices, and an integer TARGET value.
//The function takes the sum of each sublist, finding the sublist with the
//max sum in the vector. If a sublist whose sum equals the TARGET value
//the loop breaks. The index for that sublist in the choices vector is returned.
template <typename T>
Sublist<T> getMaxList(vector<Sublist<T>> &choices, int TARGET)
{
   int max_idx = 0;
   for (int k = 1; k < choices.size(); k++)
   {
      if (choices[k].getSum() == TARGET)
      {
         max_idx = k;
         break;
      }
      else if (choices[k].getSum() > choices[max_idx].getSum())
         max_idx = k;
   }
   Sublist<T>  maxSublist = choices[max_idx];
   return maxSublist;
}






/*---------------------- Connor's Output -------------------------
Total Sublist and Search Algorithm Time: 0.740969 Seconds.
Target time: 3600
Sublist ----------------------------- 
Sum: 3600
array[0] = Title: Cowboy Casanova, Artist: Carrie Underwood,TuneTime: 236
array[1] = Title: Quitter, Artist: Carrie Underwood,TuneTime: 220
array[2] = Title: Russian Roulette, Artist: Rihanna,TuneTime: 228
array[3] = Title: Monkey Wrench, Artist: Foo Fighters,TuneTime: 230
array[4] = Title: Pretending, Artist: Eric Clapton,TuneTime: 283
array[5] = Title: Bad Love, Artist: Eric Clapton,TuneTime: 308
array[6] = Title: Everybody's In The Mood, Artist: Howlin' Wolf,TuneTime: 178
array[7] = Title: Well That's All Right, Artist: Howlin' Wolf,TuneTime: 175
array[8] = Title: Samson and Delilah, Artist: Reverend Gary Davis,TuneTime: 216
array[9] = Title: Hot Cha, Artist: Roy Buchanan,TuneTime: 208
array[10] = Title: Green Onions, Artist: Roy Buchanan,TuneTime: 443
array[11] = Title: I'm Just a Prisoner, Artist: Janiva Magness,TuneTime: 230
array[12] = Title: You Were Never Mine, Artist: Janiva Magness,TuneTime: 276
array[13] = Title: Hobo Blues, Artist: John Lee Hooker,TuneTime: 187
array[14] = Title: I Can't Quit You Baby, Artist: John Lee Hooker,TuneTime: 182

Program ended with exit code: 0
----------------------------- End -------------------------------*/