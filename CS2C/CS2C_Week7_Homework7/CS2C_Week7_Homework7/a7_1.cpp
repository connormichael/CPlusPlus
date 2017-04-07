/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Febuary 25, 2017
 Professor Dave Harden
 Assignment 7.1

 Description: This program impliments a shell sort algorithm, shellSortX(), 
 which along with the array of data to be sorted, is passed a gap sequence, 
 an array of gaps, for which the outer loop of the shell sort algorithm 
 iterates. The client then tests the results of several gap sequences; Shell's
 original gap sequence (powers of 2), an explicit gap seqeunce, Sedgewick's 
 gap sequence, and then an additional attempt of an optimized gap sequence. 
 The resulting timing of the algorithm given the different gap seqeunces is 
 recorded and ouput in a table for examination.
 */


#include <iostream>
#include <time.h>
#include <math.h>
#include "FHvector.h"
using namespace std;


//template function takes three parametes: a FHvector, dataArray, containing
//the data to sort, an array of gap integers, gapArray, and the integer size
//of gapArray, gapArraySize. The function then uses shell sort to order the array
template <typename Comparable>
void shellSortX(FHvector<Comparable> & dataArray, int gapArray[], int gapArraySize)
{
   int k, j, pos, arraySize, gap;
   Comparable tmp;

   arraySize = dataArray.size();

   for (j = 0; j < gapArraySize; j++)
   {
      gap = gapArray[j];
      for (pos = gap; pos < arraySize; pos++)
      {
         tmp = dataArray[pos];
         for (k = pos; k >= gap && tmp < dataArray[k - gap]; k -= gap)
            dataArray[k] = dataArray[k - gap];
         dataArray[k] = tmp;
      }
   }
}






int main()
{
   #define ARRAY_SIZE 31250
   FHvector<int> fhVectorOfInts2;
   clock_t startTime, stopTime;
   int gapArraySize;
   int arrayNumRandIndices [6] = {10000, 20000, 40000, 80000, 160000, 200000};

   cout << "=== Results Table ====" << endl;

   for (int j = 0;
        j < (sizeof(arrayNumRandIndices) / sizeof(*arrayNumRandIndices)); j++)
   {
      srand(2);
      int gapArray[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
         2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288,
         1048576};

      int vectorSize = arrayNumRandIndices[j];
      for (int i = 0; i < vectorSize; i++)
         fhVectorOfInts2.push_back(1 + rand() % 10000);


      //Explict gap array
      gapArraySize = (sizeof(gapArray) / sizeof(*gapArray));
      startTime = clock();
      shellSortX(fhVectorOfInts2, gapArray, gapArraySize);
      stopTime = clock();
      cout << "Explicit #" << vectorSize << ": "
      << (double)(stopTime - startTime) / (double)CLOCKS_PER_SEC << ", ";


      //Shell's gap array
      gapArraySize = log2 (vectorSize);
      int shellGapArray[gapArraySize];

      int gap, index = 0;
      for (gap = vectorSize / 2; gap > 0; gap /= 2, index++)
         shellGapArray[index] = gap;
      startTime = clock();
      shellSortX(fhVectorOfInts2, shellGapArray, gapArraySize);
      stopTime = clock();
      cout << "Shell's #" << vectorSize << ": "
      << (double)(stopTime - startTime) / (double)CLOCKS_PER_SEC << ", ";


      //Sedgewick gap array
      index = 12;
      do
      {
         gap = (9 * pow(4, index) - 9 * pow(2, index) + 1);
         index++;
      }
      while ((gap < vectorSize) && (gap > 0));
      int sedgewickGapArray[index];

      for (; index >= 0; index--)
         sedgewickGapArray[index] = (9 * pow(4, index) - 9 * pow(2, index) + 1);

      startTime = clock();
      shellSortX(fhVectorOfInts2, sedgewickGapArray, gapArraySize);
      stopTime = clock();
      cout << "Sedgewick's #" << vectorSize << ": "
      << (double)(stopTime - startTime) / (double)CLOCKS_PER_SEC << ", ";


      //Custom gap array (Knuth Sequence)
      index = 12;
      do
      {
         gap = ((pow(3, index + 1) -1) / 2);
         index++;
      }
      while ((gap < vectorSize) && (gap > 0));
      int knuthGapArray[index];

      for (; index >= 0; index--)
         knuthGapArray[index] = ((pow(3, index + 1) -1) / 2);

      startTime = clock();
      shellSortX(fhVectorOfInts2, knuthGapArray, gapArraySize);
      stopTime = clock();
      cout << "Knuth's #" << vectorSize << ": "
      << (double)(stopTime - startTime) / (double)CLOCKS_PER_SEC << ", \n";

      fhVectorOfInts2.clear();
   }

   return 0;
}






/*------------------------ Connor's Ouput -------------------------------

=== Results Table ====
Explicit #10000: 0.392751, Shell's #10000: 0.002917, Sedgewick's #10000: 0.001314, Knuth's #10000: 0.001781, 
Explicit #20000: 1.75932, Shell's #20000: 0.005583, Sedgewick's #20000: 0.004353, Knuth's #20000: 0.00509, 
Explicit #40000: 6.46095, Shell's #40000: 0.011544, Sedgewick's #40000: 0.004432, Knuth's #40000: 0.006533, 
Explicit #80000: 27.4258, Shell's #80000: 0.022075, Sedgewick's #80000: 0.014746, Knuth's #80000: 0.017143, 
Explicit #160000: 107.907, Shell's #160000: 0.038922, Sedgewick's #160000: 0.02397, Knuth's #160000: 0.035854, 
Explicit #200000: 166.417, Shell's #200000: 0.048872, Sedgewick's #200000: 0.033818, Knuth's #200000: 0.045606, 
Program ended with exit code: 0

 --------------------------End of Ouput --------------------------------*/






/*------------------------ Answered Questions ---------------------------
 
 1. Why does Shell's gap sequence implied by shellSort1() give a different 
    timing result than the explicit array described above and passed
    to shellSortX()?

 Answer: The explicit array sequence is in the opposite order of Shell's 
         sequence. This causes the first iteration of Shell sort using 
         the explicit array to perform insertation sort. Afer that the 
         passed array is ordered. Therefore you are gaining no benefit 
         from the Shell sort algorithm, and your expected time growth 
         rate can be described as O(N^2), like Shell sort, but the average case 
         is Theta(N^2) which is far worse and can be see emperically. Since you 
         have to iterate through the gap sequence, using Shell sort in this 
         case is actually slower than plain insertion sort.

 2. Which is faster and why?
 
 Answer: Shell's gap sequence produces a faster result. Please see my answer 
         to question one for the explaination.

 -----------------------------------------------------------------------*/
