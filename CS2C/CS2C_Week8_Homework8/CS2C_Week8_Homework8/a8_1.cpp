/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created March 5, 2017
 Professor Dave Harden
 Assignment 8.1


 Description: This program impliments a quick sort algorithm, quickSortX(),
 which along with the vector of data to be sorted, is passed rec_limit, an
 integer value indicating when the internal, recursive quickSortX() stops
 calling itself recursively and uses rec_limit to indicate the vector size
 at which quickSortX stops calling itself recusively and begins using 
 insertionSort instead. The client then tests quickSort x, passing it 
 vectors of randomly generated integers of size range 40000 to 1000000. 
 For each vector size, the client then iterates over a set of ranges from 
 2 to 300 spaced evenly. A table is ouputted demonstrating the effects of 
 rec_limit on total sort time.
 

 Results Analysis:
 For the majority of vector sizes tests, the optimal rec_limit is observed at
 ~40. From there as we continue to decrease rec_limit, we start to see an 
 increase in total sort time as we continue to relie on quickSort to sort 
 increasing short vectors. As we increase rec_limit from 40 we also see an 
 increase in total sort time, resulting from using insertionSort for increasing 
 large vectors which is known to be less efficent to quick sort. The documented 
 optimal rec_limit of 25 can be observed in the ouput table, however since 
 the minimum sort time resulting from rec_limit = 25 and that of rec_limits 
 between 25 - 40 for most vector sizes are less than 5 percent of their 
 proceeding value these values are not reported.

 Also my table looks a lot prettier in the IDE window, but when I paste
 it into the code comment the formatting doesn't look the same.

*/

using namespace std;
#include <iostream>
#include "FHsort.h"
#include <vector>
#include <time.h>
#include <cmath>

//Exception class thrown when rec_limit is less than 2 in quickSortX function
class TooSmallRecLim {};



//interanal template quickSort function takes four arguments, a, left, right,
//and rec_limit. a is a FHvector of comparable object, left and right are the
//start and stop indices of the vector and rec_limit is the size of vector
//when algorithm switches from quicksort to insertion sort. Function
//recursively applies quicksort to a vector on decreasing vector sizes
template <typename Comparable>
void quickSortX(FHvector<Comparable> & a, int left, int right, int rec_limit)
{
   Comparable pivot;
   int i, j;

   if( left + rec_limit <= right )
   {
      pivot = median3(a, left, right);
      for( i = left, j = right - 1; ; )
      {
         while( a[++i] < pivot )
            ;
         while( pivot < a[--j] )
            ;
         if( i < j )
            mySwapFH(a[i], a[j]);
         else
            break;
      }

      mySwapFH(a[i], a[right - 1]);

      quickSortX(a, left, i - 1, rec_limit);
      quickSortX(a, i + 1, right, rec_limit);
   }
   else
      insertionSort(a, left, right);
}






//External template function takes two arguments, a FHvector of comparable
//objects and rec_limit the point in which quickSortX stops calling itself
//recursively. Function calls interanl quickSortX which sorts vector inplace
//with quicksort algorithm and insertion sort
template <typename Comparable>
void quickSortX(FHvector<Comparable> & a , int rec_limit)
{
   if (rec_limit < 2)
      throw TooSmallRecLim();
   quickSortX(a, 0, a.size() - 1, rec_limit);
}






int main()
{
   int vectSizesArray[6] = {40000, 80000, 160000, 250000, 500000, 1000000};
   clock_t startTime, stopTime;
   double currentAlgoTime, prevAlgoTime;
   int counter, vectorSize;

   for (int j = 0; j < sizeof(vectSizesArray)/(sizeof(*vectSizesArray)); j++)
   {

      currentAlgoTime = prevAlgoTime = 0.0;
      counter = 0;
      vectorSize = vectSizesArray[j];

      cout << "Vector Size\t\tRecursion Limit\t\tSort Time" << endl;
      cout << vectorSize << endl;

      for (int rec_limit = 2; rec_limit <= 300; rec_limit += 2)
      {
         srand(4);
         FHvector<int> fhVectorOfInts;
         for (int i = 0; i < vectorSize; i++)
            fhVectorOfInts.push_back(1 + rand() % 1000);

         startTime = clock();
         quickSortX(fhVectorOfInts, rec_limit);
         stopTime = clock();
         currentAlgoTime = \
            (double)(stopTime - startTime) / (double)CLOCKS_PER_SEC;
         //only print values that are greater than 5 percent of the previous
         //value
         if ((abs(1.0 - currentAlgoTime / prevAlgoTime < 0.05)) &&
            (rec_limit > 20))
            counter++;
         else
            cout << "\t\t\t\t\t" << rec_limit << "\t\t\t\t"
            << currentAlgoTime  << endl;
         if (counter == 10)
         {
            cout << "\t\t\t\t\t" <<  rec_limit
            << "\t\t\t\t" << currentAlgoTime  << endl;
            counter = 0;
         }
         prevAlgoTime = currentAlgoTime;
         fhVectorOfInts.clear();
      }
   }

   return 0;
}






/*----------------------- Connor's Output ----------------------------
Vector Size		Recursion Limit		Sort Time
40000
					2				0.008269
					4				0.007785
					6				0.008344
					8				0.007548
					10				0.007494
					12				0.008224
					14				0.007939
					16				0.007302
					18				0.007898
					20				0.007299
					36				0.007937
					42				0.008168
					44				0.009359
					46				0.008711
					60				0.008984
					68				0.009549
					76				0.010822
					78				0.010169
					92				0.010962
					112				0.012403
					132				0.014
					152				0.015856
					172				0.017179
					176				0.018355
					192				0.018981
					196				0.019353
					212				0.02167
					218				0.021968
					228				0.027361
					230				0.023904
					242				0.0346
					244				0.026357
					248				0.026419
					250				0.024662
					256				0.025172
					264				0.025789
					272				0.02753
					274				0.026707
					290				0.027679
					296				0.028337
Vector Size		Recursion Limit		Sort Time
80000
					2				0.016939
					4				0.016082
					6				0.015758
					8				0.016487
					10				0.015731
					12				0.015145
					14				0.015097
					16				0.015309
					18				0.014894
					20				0.014817
					40				0.015164
					60				0.016426
					80				0.01893
					100				0.021186
					102				0.021184
					122				0.022935
					142				0.025391
					150				0.02695
					164				0.029164
					184				0.031836
					186				0.032033
					206				0.033859
					218				0.036014
					228				0.038122
					248				0.041794
					268				0.047052
					270				0.044576
					278				0.062545
					280				0.046694
					284				0.047174
					296				0.049175
Vector Size		Recursion Limit		Sort Time
160000
					2				0.034587
					4				0.03368
					6				0.032919
					8				0.033632
					10				0.0432
					12				0.034154
					14				0.03131
					16				0.031461
					18				0.030878
					20				0.031125
					34				0.030786
					42				0.030373
					62				0.031391
					70				0.032111
					84				0.033374
					104				0.036152
					122				0.039058
					126				0.040082
					146				0.045466
					154				0.047963
					168				0.051924
					188				0.060785
					208				0.059772
					228				0.062385
					232				0.062945
					248				0.066444
					252				0.067398
					272				0.072731
					278				0.075009
					286				0.078287
					296				0.081488
Vector Size		Recursion Limit		Sort Time
250000
					2				0.055281
					4				0.054198
					6				0.055225
					8				0.052592
					10				0.052538
					12				0.056793
					14				0.05071
					16				0.050319
					18				0.050071
					20				0.048812
					40				0.047708
					60				0.048145
					80				0.049503
					100				0.052369
					120				0.0552
					140				0.058727
					160				0.063298
					166				0.081273
					168				0.067039
					184				0.069846
					190				0.07166
					194				0.07285
					208				0.078414
					216				0.082337
					230				0.088404
					250				0.097764
					270				0.107145
					284				0.128997
					286				0.121404
					288				0.114551
					296				0.118268
Vector Size		Recursion Limit		Sort Time
500000
					2				0.121231
					4				0.112332
					6				0.110085
					8				0.11251
					10				0.108618
					12				0.106317
					14				0.10569
					16				0.107711
					18				0.108221
					20				0.108943
					40				0.098256
					42				0.098325
					62				0.122602
					64				0.107691
					66				0.097419
					84				0.097929
					88				0.098622
					94				0.098558
					110				0.100329
					116				0.101079
					132				0.103484
					134				0.107396
					140				0.104717
					144				0.104999
					150				0.105924
					160				0.113823
					180				0.115532
					188				0.118346
					198				0.12123
					204				0.123314
					208				0.124315
					226				0.131564
					246				0.135306
					266				0.143663
					286				0.147677
Vector Size		Recursion Limit		Sort Time
1000000
					2				0.238275
					4				0.234488
					6				0.228298
					8				0.226861
					10				0.221157
					12				0.224155
					14				0.217315
					16				0.215725
					18				0.214477
					20				0.212015
					40				0.209707
					44				0.210069
					62				0.202499
					64				0.202866
					68				0.20819
					86				0.200897
					106				0.197786
					126				0.204155
					146				0.205959
					158				0.210741
					168				0.212795
					186				0.212627
					190				0.210829
					206				0.215474
					212				0.220008
					232				0.224546
					252				0.236426
					272				0.237022
					292				0.244324
Program ended with exit code: 0

-------------------------- End of Output -----------------------------*/





