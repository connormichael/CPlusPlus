/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created November 6, 2016
 Professor Dave Harden
 Assignment 6.3 Recursion
 
 Program Overview:
 Program sorts an array of values by ascending order by making recursive 
 calls on sortArray with increasingly larger firstIndex values until 
 firstIndex is equal to the max index value of the array. sortArray 
 uses getMinIndex to determine the position of the minimum value of the 
 remaining array with each function call. sortArray then swaps the first 
 value in the remaining array with that at the minimume index. 
 displayArray prints all the elements in the array to demonstrate the 
 functionallity of sortArray.
 */

#include <iostream>
using namespace std;


void sortArray(int array[], int firstIndex, int arraySize);
int getMinIndex(int array[], int firstIndex, int arraySize);
void displayArray(int array[], int firstIndex, int arraySize);


int main()
{
   //Test arrays
   int arrayOne[] = {5, 4, 3, 7, 1, 6, 2};
   int arrayTwo[] = {1, 10, 20, 0, -9, 20, 20};

   cout << "Before Sort: ";
   displayArray(arrayOne, 0, sizeof(arrayOne) / sizeof(arrayOne[0]));
   sortArray(arrayOne, 0, sizeof(arrayOne) / sizeof(arrayOne[0]));
   cout << "After Sort: ";
   displayArray(arrayOne, 0, sizeof(arrayOne) / sizeof(arrayOne[0]));
   cout << endl;
   cout << "Before Sort: ";
   displayArray(arrayTwo, 0, sizeof(arrayTwo) / sizeof(arrayTwo[0]));
   sortArray(arrayTwo, 0, sizeof(arrayTwo) / sizeof(arrayTwo[0]));
   cout << "After Sort: ";
   displayArray(arrayTwo, 0, sizeof(arrayTwo) / sizeof(arrayTwo[0]));
   cout << endl;
}






//Display all the values in an array of integars on the same line
//to demonstrate if the array is sorted.
void displayArray(int array[], int firstIndex, int arraySize)
{
   for (int i = firstIndex; i < arraySize; i++)
      cout << array[i] << " ";
   cout << endl;
}






//Given an array of integers, sort the array by making recurisvely calls
//to sortArray each time placing the minimum value in the remaining array
//at index position 0.
void sortArray(int array[], int firstIndex, int arraySize)
{
   if (firstIndex < arraySize -1)
   {
      int minIndex = getMinIndex(array, firstIndex, arraySize);
      int temp = array[firstIndex];

      array[firstIndex] = array[minIndex];
      array[minIndex] = temp;
      sortArray(array, firstIndex + 1, arraySize);
   }
}






//Iterate over an array between a set indexed point and the
//end of the array to determine the index location of the
//minimum value.
int getMinIndex(int array[], int firstIndex, int arraySize)
{
   //stored first index 
   int minIndex = firstIndex;

   for (int i = firstIndex; i < arraySize; i++)
      if (array[i] < array[minIndex])
         minIndex = i;

   return minIndex;
}






/*--------------- Connor's Ouput ----------------

Before Sort: 1 5 3 7 8 6 
After Sort: 1 3 5 6 7 8 

Before Sort: 1 10 20 0 -9 20 20 
After Sort: -9 0 1 10 20 20 20 

Program ended with exit code: 0

------------------- End of Ouput --------------*/





