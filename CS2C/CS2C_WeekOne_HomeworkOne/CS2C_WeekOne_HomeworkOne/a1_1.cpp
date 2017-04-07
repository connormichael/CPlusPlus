/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Janunary 14, 2017
 Professor Dave Harden
 Assignment 1.1
 
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
 The following client is written to handling integers, and has a dependency on 
 the newVect class.
 */

#include <iostream>
#include <vector> 
#include "newVect.h"
using namespace std;
using namespace sublist; 

template <typename T>
void findSublists(vector<T> &dataSet, vector<Sublist<T>> &choices, int TARGET);
template <typename T>
bool isMaxSum(vector<T> &dataSet, int TARGET);
template <typename T>
Sublist<T> getMaxList(vector<Sublist<T>> &choices, int TARGET);

int main()
{
   int TARGET = 180;
   vector<int> dataSet, dataSetTwo, dataSetThree;
   vector<Sublist<int>> choices;
   vector<vector<int>> allSets;
   clock_t startTime, stopTime;
   double totalTime;
   startTime = clock();

   dataSet = {20, 12, 22, 15, 25, 19, 29, 18, 11, 13, 17};
   dataSetTwo = {5, 6, 7, 8, 9, 10};
   dataSetThree = {20, 29, 12, 14, 18, 19, 6, 8, 10, 25, 3, 5, 23, 26, 21};
   allSets = {dataSet, dataSetTwo, dataSetThree};

   choices.push_back(Sublist<int>(&dataSet));

   for (int i = 0; i < allSets.size(); i++)
   {
      cout << "\nAnalyzing Set: " << i + 1 << endl;
      dataSet = allSets[i];
      if (!isMaxSum(dataSet, TARGET))
      {
         findSublists(dataSet, choices, TARGET);
         Sublist<int> maxSublist = getMaxList(choices, TARGET);
         stopTime = clock();
         totalTime = double(stopTime - startTime) / CLOCKS_PER_SEC;
         cout << "Total Sublist and Search Algorithm Time: " << totalTime
         << " Seconds." << endl;
         cout << "Target time: " << TARGET << endl;
         maxSublist.showSublist();
      }
   }
   return 0;
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






/*---------------------- Connor's Output ------------------------------

Analyzing Set: 1
Total Sublist and Search Algorithm Time: 0.0027 Seconds.
Target time: 180
Sublist ----------------------------- 
Sum: 179
array[0] = 20, array[1] = 12, array[2] = 15, array[3] = 25, array[4] = 19, array[5] = 29, array[6] = 18, array[7] = 11, array[8] = 13, array[9] = 17, 

Analyzing Set: 2
Target is larger than sum of all elements. Skipping sub-setting algorithm

Analyzing Set: 3
Total Sublist and Search Algorithm Time: 0.003336 Seconds.
Target time: 180
Sublist ----------------------------- 
Sum: 180
array[0] = 20, array[1] = 29, array[2] = 12, array[3] = 14, array[4] = 18, array[5] = 19, array[6] = 6, array[7] = 8, array[8] = 20, 
Program ended with exit code: 0

----------------------------- End -----------------------------------*/