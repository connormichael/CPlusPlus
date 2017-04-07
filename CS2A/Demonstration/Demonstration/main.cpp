/*
 
 Lesson 15.8 
 - the header file (aka specification, or interface file) must be located in 
 the same folder as the project 

 

 //Lesson 12 Review: Pointers
 What are three applications of pointers: 
 1. linked data structures
 2. dynamic arrays 
 3. cstrings (implemented as dynamic arrays 
 



 */

#include <iostream>
#include <cstddef>
#include <fstream>
using namespace std;

class invItem {
public:
   invItem();
   invItem(const char *inDesc);
   void setInfo(const char *inDesc, int inUnits);
   void setUnits(int inUnits);
   friend std::ostream& operator<<(std::ostream& out, const invItem& printMe);
   invItem operator=(const invItem& right);
private:
   char *desc;
   int units;
};


int main()
{

   int array[20];
   int sum = 0;
   for (int i =0; i < sizeof(array)/sizeof(array[0]); i++)
      array[i] = 5;
   int *x;
   x = new int;
   *x = 5;

   sum += *x++;
   cout << sum << endl;



   int *w;
   cout << w << endl;
   w + 1;
   cout << w << endl;

   char s[] = "cherry";
   cout << strlen(s);
   char y = '1';

   toupper(y);
   cout << y << endl;



   char z;
   z = 'A';
   if (tolower(z) == 'a')
      cout << "TRUE"; 

}



invItem::invItem(const char *inDesc)
{
   units = 0;
   desc = new char[strlen(inDesc) + 1];
   strcpy(desc, inDesc);
}



invItem invItem::operator=(const invItem& right)
{
   delete [] desc;
   desc = new char[strlen(right.desc) + 1];
   strcpy(desc, right.desc);
   return *this;
}







