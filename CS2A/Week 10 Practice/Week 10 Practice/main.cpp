#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

//Square boxes may have more than one correct answer
//Round boxes have only one correct answer

/*
int main()
{
   int num1 = 5;

   double answer;

   answer = (num1 + 1) / 100 ;

   cout << answer << endl;

}
*/


int main()
{
   int age;
   int *pMyAge, *pYourAge;

   pMyAge = &age;
   pMyAge = pYourAge;

   age = 7;

   //cout << age << endl;
   cout << *pMyAge;
   //cout << *pYourAge << endl;

}