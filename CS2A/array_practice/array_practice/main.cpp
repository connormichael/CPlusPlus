//Connor Lynch
// Student Class Work through

#include <iostream>
#include <string> 
#include <sstream>
using namespace std;


class Student
{
private:
   string lastName;
   string firstName;
   int totalPoints;


public:
   //param taking constructor
   Student(string lst, string frst, int points);
};

class StudentArrayUtilities
{
public:
   static void printArray(string title, Student data[0], int arraySize);
   static void arraySort(Student array[], int arraySize);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);

};


int main()
{
   Student  myClass[] =
   {
      Student("smith","fred", 95),  Student("bauer","jack",123),
      Student("jacobs","carrie", 195),  Student("renquist","abe",148),
      Student("3ackson","trevor", 108),  Student("perry","fred",225),
      Student("loceff","fred", 44),  Student("stollings","pamela",452),
      Student("charters","rodney", 295),  Student("cassar","john",321)
   };

   int arraySize = sizeof(myClass)/sizeof(myClass[0]);



   //cout << myClass[0] << endl;
   return 0;
}


Student::Student(string lst, string frst, int points)
{
   lastName = firstName = "zz-error";
   totalPoints = 0;
   if (lst.length() > 0 && isalpha(lst[0]))
      lastName = lst;
   if (frst.length() > 0 && isalpha(frst[0]))
      firstName = frst;
   if (points > 0 && points <= 1000)
      totalPoints = points;
}

