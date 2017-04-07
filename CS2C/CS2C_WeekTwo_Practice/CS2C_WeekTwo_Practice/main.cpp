// Example of timing a simple sort algorithm
#include <iostream>
using namespace std;
#include "Foothill_Sort.h"
#include <time.h>

// --------------- main ---------------
int main()
{
   int k, arraySize;
   clock_t startTime, stopTime;
   double elapsedTime = 0;
   int *arrayOfInts = NULL;

   for (arraySize = 100; elapsedTime < 60; arraySize*=2)
   {
      // allocate array and stuff will values
      arrayOfInts = new int[arraySize];
      for (k = 0; k < arraySize; k++)
         arrayOfInts[k] = rand()%arraySize;

      startTime = clock();    // start timing ---------------

      // sort using a home made bubble sort (in Foothill_Sort.h)
      arraySort(arrayOfInts, arraySize);

      stopTime = clock();      // stop timing ------------------------
      elapsedTime = (double)(stopTime - startTime)/(double)CLOCKS_PER_SEC;
      cout << "\nN: " << arraySize << " Sort Time: "
      << elapsedTime  << " seconds." << endl;

      // release memory
      delete[] arrayOfInts;
   }
   return 0;
}


