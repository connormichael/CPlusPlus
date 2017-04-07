//  main.cpp
//  Assignment 9
//
//  Created by Connor Lynch on 3/6/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//class Student prototype -----------------------
class Student
{
private:
   string lastName;
   string firstName;
   int totalPoints;

public:
   static const string DEFAULT_NAME;
   static const int DEFAULT_POINTS = 0;
   static const int MAX_POINTS = 1000;
   static const int SORT_BY_FIRST = 88;
   static const int SORT_BY_LAST = 98;
   static const int SORT_BY_POINTS = 108;

public:
   //parameter taking constructor
   Student( string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
           long pts = DEFAULT_POINTS);

   // accessors and mutators
   string getLastName() { return lastName; }
   string getFirstName() { return firstName; }
   int getTotalPoints() { return totalPoints; }

   bool setLastName(string last);
   bool setFirstName(string first);
   bool setPoints(int pts);

   static int compareTwoStudents(Student firstStud, Student secondStud,
                                 int sortKey);
   string toString();
   static bool setSortKey(int key);
   static int getSortKey();

private:
   static bool validString( string testStr );
   static bool validPoints( int testPoints );
   //here is my private static int
   static int sortKey;
};

//initilize sortKey here
int Student::sortKey = 88;

// class StudentArrayUtilities prototype -----------------------
class StudentArrayUtilities
{
public:
   static string toString(string title, Student data[], int arraySize);
   static void arraySort(Student array[], int arraySize);
   static double getMedianDestructive(Student array[], int arraySize);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);
};

//static initializations that can't be done in-line
const string Student::DEFAULT_NAME = "zz-error";

int main()
{
   Student  myClassEven[] =
   {
      Student("jackson","michael", 93), Student("kurzweil","ray", 444),
      Student("wasniak","steve", 185),  Student("townsand","pete",168),
      Student("woods","tiger", 117),  Student("davis","miles",225),
      Student("holiday","buddy", 44),  Student("browne","jackson",432),
      Student("smith","will", 290),  Student("lennon","john",391),
      Student("smith","adam", 300),  Student("washington","george",205),
      Student("gates","bill", 14),  Student("tyson","mike",432),
      Student("star","ringo", 280),  Student("harrison","george",341)
   };

   Student myClassOdd[] =
   {
      Student("jackson","michael", 93),
      Student("wasniak","steve", 185),  Student("townsand","pete",168),
      Student("woods","tiger", 117),  Student("davis","miles",225),
      Student("holiday","buddy", 44),  Student("browne","jackson",432),
      Student("smith","will", 290),  Student("lennon","john",391),
      Student("smith","adam", 300),  Student("washington","george",205),
      Student("gates","bill", 14),  Student("tyson","mike",432),
      Student("star","ringo", 280),  Student("harrison","george",341)
   };

   Student myClassOne[] =
   {
      Student("lynch", "connor", 310)
   };

   int arraySize;
   float median;

   //display even length array sorted by initial sortKey (before and after)
   arraySize = sizeof(myClassEven) / sizeof(myClassEven[0]);
   cout << StudentArrayUtilities::toString("Before: ", myClassEven, arraySize);
   StudentArrayUtilities::arraySort(myClassEven, arraySize);
   cout << StudentArrayUtilities::toString("After (Last Name): ",
                                           myClassEven, arraySize);

   //sorting array by first name
   Student::setSortKey(Student::SORT_BY_FIRST);
   StudentArrayUtilities::arraySort(myClassEven, arraySize);
   cout << StudentArrayUtilities::toString("After (First Name): ",
                                           myClassEven, arraySize);

   //sorting array by points
   Student::setSortKey(Student::SORT_BY_POINTS);
   StudentArrayUtilities::arraySort(myClassEven, arraySize);
   cout << StudentArrayUtilities::toString("After (Total Points): ",
                                           myClassEven, arraySize);

   //sorting by first name and getting median
   Student::setSortKey(Student::SORT_BY_FIRST);
   median = StudentArrayUtilities::getMedianDestructive(myClassEven, arraySize);
   cout << "Median of evenClass: " << median << endl;
   cout << "Successfully preserved sortKey: " << Student::getSortKey() << endl;

   //getting medians of two other arrays
   arraySize = sizeof(myClassOdd) / sizeof(myClassOdd[0]);
   median = StudentArrayUtilities::getMedianDestructive(myClassOdd, arraySize);
   cout << "Median of oddClass: " << median << endl;

   arraySize = sizeof(myClassOne) / sizeof(myClassOne[0]);
   median = StudentArrayUtilities::getMedianDestructive(myClassOne, arraySize);
   cout << "Median of oneClass: " << median << endl;
}

// beginning of Student method definitions -------------

// constructor requires parameters - no default supplied
Student::Student( string last, string first, long points)
{
   if ( !setLastName(last) )
      lastName = DEFAULT_NAME;
   if ( !setFirstName(first) )
      firstName = DEFAULT_NAME;
   if ( !setPoints(points) )
      totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last)
{
   if ( !validString(last) )
      return false;
   lastName = last;
   return true;
}

bool Student::setFirstName(string first)
{
   if ( !validString(first) )
      return false;
   firstName = first;
   return true;
}

bool Student::setPoints(int pts)
{
   if ( !validPoints(pts) )
      return false;
   totalPoints = pts;
   return true;
}

bool Student::setSortKey(int key)
{
   if (key == 88 || key == 98 || key == 108)
   {
      sortKey = key;
      return true;
   }
   else
      return false;
}

int Student::getSortKey()
{
   return sortKey;
}

// could be an instance method and, if so, would take one parameter
int Student::compareTwoStudents( Student firstStud, Student secondStud,
                                int sortKey)
{
   int result;
   string student1Points, student2Points;
   
   if (sortKey == SORT_BY_FIRST)
      result = firstStud.firstName.compare(secondStud.firstName);
   else if (sortKey == SORT_BY_LAST)
      result = firstStud.lastName.compare(secondStud.lastName);
   else if (sortKey == SORT_BY_POINTS)
   {
      if (firstStud.totalPoints < secondStud.totalPoints)
         return -1;
      if (firstStud.totalPoints > secondStud.totalPoints)
         return 1;
      else
         return 0;
   }

   return result;
}

string Student::toString()
{
   string resultString;
   ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;

   cnvrtFirst << firstName;
   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;

   resultString = " "+ cnvrtLast.str()
   + ", " + cnvrtFirst.str()
   + " points: " + cnvrtPoints.str()
   + "\n";
   return resultString;
}

bool Student::validString( string testStr )
{
   if (testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}

bool Student::validPoints( int testPoints )
{
   if (testPoints >= 0 && testPoints <= MAX_POINTS)
      return true;
   return false;
}
// end of Student method definitions  --------------

// beginning of StudentArrayUtilities method definitions -------------

// methods in this class.
string StudentArrayUtilities::toString(string title, Student data[],
                                       int arraySize)
{
   string output = "";

   // build the output string from the individual Students:
   for (int k = 0; k < arraySize; k++)
      output += " "+ data[k].toString();

   output = title + "\n" + output + "\n";

   return output;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize)
{
   for (int k = 0; k < arraySize; k++)
      // compare with method def to see where inner loop stops
      if (!floatLargestToTop(array, arraySize-1-k))
         return;
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
   bool changed = false;
   int key = Student::getSortKey();

   // compare with client call to see where the loop stops
   for (int k =0; k < top; k++)
      if (  Student::compareTwoStudents(data[k], data[k+1], key) > 0)
      {
         mySwap(data[k], data[k+1]);
         changed = true;
      }
   return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b)
{
   Student temp("", "", 0);

   temp = a;
   a = b;
   b = temp;
}

double StudentArrayUtilities::getMedianDestructive(Student array[],
                                                   int arraySize)
{
   int clientSortKey, sortKey, halfArraySize, midArrayLength;
   double midValueOne, midValueTwo, median;

   clientSortKey = Student::getSortKey();
   Student::setSortKey(Student::SORT_BY_POINTS);
   sortKey = Student::getSortKey();

   if (arraySize == 1)
      median = array[0].getTotalPoints();
   else if (arraySize % 2 == 0)
   {
      halfArraySize = (arraySize / 2);
      arraySort(array, arraySize);
      midValueOne = array[halfArraySize - 1].getTotalPoints();
      midValueTwo = array[halfArraySize].getTotalPoints();
      median = ((midValueOne + midValueTwo)/2);
   }
   else
   {
      midArrayLength = (((arraySize + 1)/2));
      arraySort(array, arraySize);
      median = array[midArrayLength].getTotalPoints();
   }

   Student::setSortKey(clientSortKey);

   return median;
}

/* ------------------------------Connor's Run----------------------------

Before: 
  jackson, michael points: 93
  kurzweil, ray points: 444
  wasniak, steve points: 185
  townsand, pete points: 168
  woods, tiger points: 117
  davis, miles points: 225
  holiday, buddy points: 44
  browne, jackson points: 432
  smith, will points: 290
  lennon, john points: 391
  smith, adam points: 300
  washington, george points: 205
  gates, bill points: 14
  tyson, mike points: 432
  star, ringo points: 280
  harrison, george points: 341

After (Last Name): 
  browne, jackson points: 432
  davis, miles points: 225
  gates, bill points: 14
  harrison, george points: 341
  holiday, buddy points: 44
  jackson, michael points: 93
  kurzweil, ray points: 444
  lennon, john points: 391
  smith, will points: 290
  smith, adam points: 300
  star, ringo points: 280
  townsand, pete points: 168
  tyson, mike points: 432
  washington, george points: 205
  wasniak, steve points: 185
  woods, tiger points: 117

After (First Name): 
  smith, adam points: 300
  gates, bill points: 14
  holiday, buddy points: 44
  harrison, george points: 341
  washington, george points: 205
  browne, jackson points: 432
  lennon, john points: 391
  jackson, michael points: 93
  tyson, mike points: 432
  davis, miles points: 225
  townsand, pete points: 168
  kurzweil, ray points: 444
  star, ringo points: 280
  wasniak, steve points: 185
  woods, tiger points: 117
  smith, will points: 290

After (Total Points): 
  gates, bill points: 14
  holiday, buddy points: 44
  jackson, michael points: 93
  woods, tiger points: 117
  townsand, pete points: 168
  wasniak, steve points: 185
  washington, george points: 205
  davis, miles points: 225
  star, ringo points: 280
  smith, will points: 290
  smith, adam points: 300
  harrison, george points: 341
  lennon, john points: 391
  browne, jackson points: 432
  tyson, mike points: 432
  kurzweil, ray points: 444

Median of evenClass: 252.5
Successfully preserved sortKey: 88
Median of oddClass: 280
Median of oneClass: 310
Program ended with exit code: 0

---------------------------------------------------------------------- */