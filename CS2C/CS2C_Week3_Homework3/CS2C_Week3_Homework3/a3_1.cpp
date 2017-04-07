/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created Janunary 29, 2017
 Professor Dave Harden
 Assignment 3.1
 
 Program Overview: 
 This program produces a matrix by building an array of float pointers
 that each point to a dynamically allocated array of floats. The program then 
 tests the performance of matrix multiplication between a matrix and itself as 
 the size of the matrix increases symmetrically.


 Complexity of Matrix Multiplication: 
 The upper bounds of time complexity of matrix multiplication
 can be defined as O(N^3), because we must loop through each
 column and each row. Then for each row and column we must loop through their
 contents to do the multiplication and addition for the final dot product. 
 That is, for a symetric matrix of size NxN we must iterate through N columns, 
 and for each column, iterator through N rows, multiplying the each N row element 
 of matrix A, by the N column element of matrix B. Since we are using the 
 same matrix we an assume O(N^3), however, if we have different sized matrices
 (but still properly shaped) then we may have something closer to O(M*N^2). 
 The exact growth rate of the algorithm should also be close to O(N^2) since 
 regardless of the size of the matrix, you still must transverse the contents
 of each row and column. The best case sceniero (little-o) might say that we 
 know that box matrices have each value of 0, so no transversing needs to occur, 
 but this seems a limited case.

 1. The smallest M that gave a non-zero time was 110, however
   this would varying from run to run.
 2. The initial doubling of the data size increased the run time by a factor
   of ten, and with each doubling (200-400-800) that pattern roughly held, until 
   the data size went from 800-1200 where the run time increased by a factor of 
   10.
   Run Results:
   M | Time (s)
   200  0.03
   400  0.34
   600  1.23
   800  3.49
   1200 28.00
 3. The largests matrix I was able to multiply togethr was a 3000 x 3000 matrix
   which took 508.20 seconds to complete. While this did not result in any run-
   time error, it did report that it had maxed out my CPU and cache.

 4. From looking at the results of the table in answer two, it looks to me 
   like the data more closely aligns with a O(N^3) since with each doubling 
   of M, the output time when up by a factor of 10, which is very close to 
   the 8 fold increase in time one would expect from the algorithm.
 

 Please see the comment at the end of this file for results outputs 
 associated with my answers for questions 1-3.
*/

#include <iostream>
#include <iomanip>
using namespace std;


const int MAT_SIZE = 200;
typedef float* DynMat[MAT_SIZE];

void matMultDyn( const DynMat & matA,  const DynMat & matB,
                DynMat & matC, int size);
void matShowDyn( const DynMat & matA, int start, int size);
void insertRand(DynMat & matA);
void cleanUp(DynMat & matA);

int main()
{
   srand (time(NULL));
   DynMat matDyn,  matDynAns;
   clock_t startTime, stopTime;

   for (int i = 0; i < MAT_SIZE; i++)
   {
      matDyn[i] = new float [MAT_SIZE];
      matDynAns[i] = new float [MAT_SIZE];

      for (int c = 0; c < MAT_SIZE; c++)
         matDyn[i][c] = 0.0;
   }

   // generate small% non-default values bet .1 and 10
   int smallPercent = MAT_SIZE / 20. * MAT_SIZE;
   for (int r = 0; r < smallPercent; r++)
      insertRand(matDyn);

   matShowDyn(matDyn, 0, 10);

   startTime = clock();  // ------------------ start
   matMultDyn(matDyn, matDyn, matDynAns, MAT_SIZE);
   stopTime = clock();  // ---------------------- stop

   matShowDyn(matDynAns, 0, 10);
   cout << "\nSize = " <<  MAT_SIZE << " Dyn Array Mult Elapsed Time: "
   << (double)(stopTime - startTime)/(double)CLOCKS_PER_SEC
   << " seconds." << endl << endl;

   cleanUp(matDynAns);
   cleanUp(matDyn);

   return 0;
}






//Function takes three dynamically allocated matrices and their size
//and places the results of the product of matA * matB into matC
void matMultDyn(const DynMat & matA,  const DynMat & matB,
                DynMat & matC, int size)
{
   float sum;

   for (int row = 0; row < size; row++)
   {
      for (int col = 0; col < size; col++)
      {
         sum = 0.0;
         for (int item = 0; item < size; item++)
         {
            sum +=  matA[row][item] *  matB[item][col];
         }
         matC[row][col] = sum;
      }
   }
}






//function takes a dynamically allocated matrices and outputs
//the contents of the matrix from start to start + size
void matShowDyn(const DynMat & matA, int start, int size)
{
   int outputSize = start + size;
   for (int c = start; c < outputSize; c++)
   {
      for (int r = start; r < outputSize; r++)
      {
         cout << fixed << setprecision(2) << matA[c][r] << " ";
      }
      cout << endl;
   }
   cout << endl;
}






//function takes a dynamically allocated matrix and inserts a float value
//between 0 and 1.0 in a random location within the matrix
void insertRand(DynMat & matA)
{

   int randRow = rand() % MAT_SIZE;
   int randCol = rand() % MAT_SIZE;
   float randFrac = rand() / static_cast<float>(RAND_MAX);
   matA[randRow][randCol] = randFrac;
}






//function returns the memory use for row arrays back to heap memory
void cleanUp(DynMat & matA)
{
   for (int row = 0; row < MAT_SIZE; row++)
      delete [] matA[row];
}






/*----------------------Connor's Output------------------

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.72 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.87 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.32 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.22 0.00 0.00 
0.00 0.00 0.00 0.24 0.93 0.05 0.01 0.00 0.51 0.08 
0.00 0.86 0.06 0.17 0.56 0.00 0.25 1.18 0.00 0.07 
0.00 0.59 0.00 0.65 0.00 0.00 0.23 0.10 0.07 0.44 
0.00 0.11 0.00 0.00 0.00 0.00 0.02 0.00 0.07 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.02 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.29 0.00 0.00 0.64 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.11 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.35 0.39 0.00 
0.00 0.00 0.00 0.43 0.27 0.00 0.00 0.00 0.36 0.00 


Size = 200 Dyn Array Mult Elapsed Time: 0.03 seconds.

Program ended with exit code: 0
 
 

---------------Output Results for HW Questions----------

1. The smallest M that gave a non-zero time was 110, however
this would varying from run to run. Below is the run ouput:

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 1.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.30 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.82 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.02 0.00 0.00 0.00 0.26 0.00 
0.00 0.00 0.00 0.04 0.00 0.00 0.33 0.00 0.00 0.00 
0.00 0.62 0.37 0.00 0.00 0.51 0.02 0.00 0.10 0.00 
0.00 0.00 0.00 0.00 0.00 0.89 0.33 0.00 0.27 0.15 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.93 0.00 0.00 
0.00 0.00 0.00 0.11 0.13 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.23 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.82 0.00 0.06 0.00 
0.21 0.31 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.22 


Size = 110 Dyn Array Mult Elapsed Time: 0.01 seconds.

Program ended with exit code: 0
 
2. Results from doubling, tripling and quadruapling matrix size:

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
0.00 0.26 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.30 0.00 0.00 0.00 0.00 0.23 0.00 0.46 
0.00 0.07 0.78 0.35 0.09 0.00 0.00 0.00 0.31 0.04 
0.00 0.42 0.00 0.00 0.93 0.00 0.00 0.00 0.00 0.00 
0.00 0.52 0.00 0.00 0.00 0.00 0.11 0.00 0.00 0.00 
0.00 0.00 0.10 0.00 0.05 0.00 0.55 0.00 0.00 0.00 
0.00 0.00 0.79 0.00 0.10 0.60 0.00 0.57 0.00 0.23 
0.00 0.19 0.00 0.00 0.00 0.00 0.05 0.00 0.00 0.00 
0.00 0.97 0.10 0.00 0.10 0.00 0.00 0.28 0.00 0.50 
0.00 0.00 0.00 0.00 0.21 0.00 0.30 0.01 0.00 0.25 
0.00 0.00 0.00 0.00 0.16 0.00 0.00 0.00 0.37 0.09 


Size = 200 Dyn Array Mult Elapsed Time: 0.03 seconds.

Program ended with exit code: 0

0.00 0.00 0.00 0.00 0.00 0.19 0.00 0.00 0.00 0.46 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.52 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.71 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.92 0.00 0.00 
0.00 0.00 0.78 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.81 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

0.08 0.00 0.37 0.86 0.69 0.94 0.37 0.63 1.07 0.00 
0.14 0.00 0.53 0.00 0.08 0.00 0.00 0.00 0.11 0.03 
0.00 0.35 0.00 0.15 0.00 0.00 0.00 0.48 0.20 0.00 
0.58 0.00 0.00 0.33 0.00 0.44 0.00 0.48 1.60 0.00 
0.69 0.22 0.00 0.35 0.00 0.00 0.00 0.00 0.47 0.00 
0.36 0.02 0.00 0.41 0.29 0.15 0.38 0.26 0.82 0.32 
0.00 0.00 0.00 0.00 0.00 1.16 0.00 0.55 0.00 0.00 
1.60 0.00 0.13 0.00 0.00 0.31 0.59 0.87 0.88 0.00 
0.68 0.00 0.00 0.00 0.21 0.00 0.00 0.56 0.61 0.00 
0.00 0.16 0.00 0.00 0.00 0.65 0.21 0.90 0.00 0.03 


Size = 400 Dyn Array Mult Elapsed Time: 0.34 seconds.
 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.09 0.00 0.07 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.40 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.92 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

0.74 0.22 0.88 0.00 0.00 0.32 0.00 1.10 0.00 0.00 
1.07 0.00 0.62 0.41 0.45 0.00 0.08 0.00 2.02 0.02 
0.29 0.44 1.02 0.00 0.21 1.07 0.29 0.62 0.01 1.04 
1.33 0.56 0.68 0.89 0.08 0.24 0.97 0.49 0.00 0.00 
0.36 0.22 0.28 0.51 0.00 0.00 0.00 0.80 0.43 0.43 
0.08 0.00 0.00 0.01 0.00 0.16 0.62 0.00 0.87 0.41 
1.00 1.28 0.81 0.86 0.18 0.23 0.22 0.03 0.78 0.00 
0.69 0.32 0.51 1.22 0.31 0.77 0.67 0.28 0.60 0.81 
0.07 0.00 0.11 0.61 0.01 0.48 0.04 0.52 0.00 0.04 
0.93 0.00 0.49 0.11 0.00 0.02 0.58 0.00 0.08 0.00 


Size = 600 Dyn Array Mult Elapsed Time: 1.23 seconds.

Program ended with exit code: 0

0.55 0.00 0.00 0.00 0.42 0.24 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.38 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.26 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

0.74 0.68 0.11 0.39 0.39 1.63 0.00 0.06 0.26 0.35 
0.32 0.04 0.77 0.36 0.00 0.15 0.04 1.28 0.00 0.53 
0.00 1.17 0.84 0.38 1.81 0.19 0.00 0.07 2.10 0.00 
0.18 0.38 1.01 0.19 0.32 0.00 1.89 0.09 0.29 0.74 
0.00 0.33 0.86 0.00 0.55 0.00 0.62 1.22 0.00 0.12 
0.13 0.68 0.40 0.01 0.03 0.51 0.07 0.38 1.05 0.28 
1.26 1.00 0.00 0.01 0.00 0.12 0.09 0.37 0.66 0.44 
0.13 0.26 0.00 0.50 0.20 0.28 0.32 0.75 0.78 0.00 
0.01 0.83 0.63 0.43 0.00 0.45 1.08 0.43 0.49 0.00 
0.45 0.75 0.00 0.36 0.00 0.67 0.31 0.09 0.29 0.47 


Size = 800 Dyn Array Mult Elapsed Time: 3.49 seconds.

Program ended with exit code: 0
 

0.75 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.56 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.34 0.00 0.00 0.00 0.00 
0.70 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

1.01 0.00 0.45 0.22 0.22 0.01 0.59 0.03 0.49 1.48 
0.89 0.00 0.60 0.00 0.44 0.99 0.93 0.00 0.04 1.22 
0.96 0.69 0.68 0.52 1.59 0.14 0.00 1.85 1.49 0.22 
0.48 0.00 0.09 0.74 0.67 0.91 1.23 0.59 0.50 0.82 
0.16 0.63 1.87 0.85 0.28 0.92 0.25 0.01 1.37 0.46 
0.39 1.22 2.27 0.89 0.18 1.11 0.06 0.35 0.26 0.36 
0.84 0.18 1.48 0.90 0.16 0.00 0.00 1.23 0.87 1.69 
1.08 1.40 0.71 0.00 0.57 0.44 0.09 0.56 0.00 0.08 
0.56 0.65 0.70 0.20 0.56 0.26 1.86 0.99 1.79 2.20 
1.53 0.34 1.23 1.23 0.92 0.01 1.09 1.06 0.96 0.35 


Size = 1200 Dyn Array Mult Elapsed Time: 28.00 seconds.

Program ended with exit code: 0
 

3. The largest value that Xcode would allow me to run due to memory/time:

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.64 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.99 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.93 0.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 0.28 0.00 0.00 0.00 0.00 0.00 0.02 0.00 0.00 

1.80 3.27 2.79 2.39 1.98 0.49 1.58 2.77 2.72 2.35 
0.64 0.78 2.11 1.71 1.87 0.29 1.99 1.70 2.84 1.95 
3.08 2.23 3.57 2.81 1.41 2.75 2.31 1.53 1.59 1.62 
2.36 0.54 3.62 0.67 1.32 1.05 1.86 2.54 3.07 2.13 
2.98 2.63 1.19 2.07 0.75 1.43 2.00 3.52 2.37 2.08 
3.73 1.48 3.24 2.57 1.03 2.96 2.51 1.75 1.40 2.63 
2.98 1.29 2.25 2.59 3.46 1.58 3.15 1.57 1.24 1.76 
2.24 2.39 2.26 4.05 2.41 2.16 0.66 1.12 2.87 2.64 
2.07 1.85 4.21 2.69 2.37 1.62 1.28 1.99 3.00 0.75 
1.01 1.08 1.93 1.58 2.19 2.08 1.74 2.37 3.49 0.54 


Size = 3000 Dyn Array Mult Elapsed Time: 508.20 seconds.

Program ended with exit code: 0
 

--------------------------End of Output-----------------*/