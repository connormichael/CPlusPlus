// CS_1C  Hash Table Client
// note that order of includes and prototypes is required by some compilers


#include <iostream>
#include <string>
using namespace std;
#include <vector> 

int main()
{
   vector<int> vect;
   float* asd = new float[100];
}



/*
template <class T>
class PrintString
{
public:
   void operator()(T s)
   {
      cout << s << " ";
   }
};

template <class T>
void showArrayUsingThisFunc( PrintString<T> g )
{
   string myArray[] = {"hi", "mom!", "3", "45", "this is wild"};
   int k;

   for (k = 0; k < sizeof(myArray)/sizeof(myArray[0]); k++)
      g(myArray[k]);
}


int findMin();

int main()
{
   PrintString<string> g;

   g("Does this really work?");
   g("Apparently");
   cout << endl;

   showArrayUsingThisFunc(g);
   cout << endl;

}


int findMin()
{
   if (root == NULL)
      return 0;
   if (root->leftChild == NULL)
      return root;

   findMin(root->leftChild);
}



// ---------------------- FHtree Prototype -------------------------
*/
/* ------------------ RUN -------------

 Does this really work? Apparently
 hi mom! 3 45 this is wild

 -------------------------------------- */

/*
#include <iostream>
#include <string>
using namespace std;
class Employee;
int Hash( const Employee & item );
int Hash(const string & key);
int Hash( int key );

#include "FHhashSC.h"


// Example of an Employee class
class Employee
{
public:
   static const int MAX_LEN = 50;
   Employee( string name = "undefined", int ss = 0);
   const string & getName() const  { return name; }
   int getSS() const  { return ss; }
   bool setName( string name );
   bool setSS( int ss );

   bool operator==( const Employee & rhs ) const
   { return getName() == rhs.getName(); }
   bool operator!=( const Employee & rhs ) const
   { return !( *this == rhs ); }

private:
   string name;
   int    ss;

};

Employee::Employee( string name, int ss)
{
   if (!setName(name))
      name = "(undefined)";
   if (!setSS(ss))
      ss = 0;
}

bool Employee::setName(string name)
{
   if (name.length() > MAX_LEN)
      return false;
   this->name = name;
   return true;
}

bool Employee::setSS(int ss)
{
   if (ss < 0 || ss > 999999999 )
      return false;
   this->ss = ss;
   return true;
}

int main()
{
   // first set of tests --------------------
   FHhashSC<Employee> hashTable;
   Employee e1("Jane Austin", 1), e2("Rene Descartes", 2), e3("John Locke", 3);

   if (  hashTable.insert(e1) )
      cout << "inserted " << e1.getName() << endl;
   if (  hashTable.insert(e1) )
      cout << "inserted " << e1.getName() << endl;
   if (  hashTable.insert(e2) )
      cout << "inserted " << e2.getName() << endl;
   if (  hashTable.insert(e2) )
      cout << "inserted " << e2.getName() << endl;
   if (  hashTable.insert(e3) )
      cout << "inserted " << e3.getName() << endl;
   if (  hashTable.insert(e3) )
      cout << "inserted " << e3.getName() << endl;

   cout << hashTable.size() << endl;

   if (  hashTable.contains(e3) )
      cout << "contains " << e3.getName() << endl;

   if (  hashTable.remove(e1) )
      cout << "removed " << e1.getName() << endl;
   if (  hashTable.remove(e1) )
      cout << "removed " << e1.getName() << endl;
   if (  hashTable.remove(e2) )
      cout << "removed " << e2.getName() << endl;
   if (  hashTable.remove(e2) )
      cout << "removed " << e2.getName() << endl;
   if (  hashTable.remove(e3) )
      cout << "removed " << e3.getName() << endl;
   if (  hashTable.remove(e3) )
      cout << "removed " << e3.getName() << endl;
   cout << hashTable.size() << endl;

   if (  hashTable.contains(e3) )
      cout << "contains " << e3.getName() << endl;

   // second set of tests --------------------

   FHhashSC<string> hashTable2;
   string substrate =
   "asdlkfj asdoiBIUYVuwer slkdjLJfwoe89)B)(798rjMG0293lkJLJ42lk3j)(*";
   string strArray[500];
   int k, limit;

   substrate = substrate + substrate;

   for (k = 0; k < substrate.length() - 6; k++)
      strArray[k] = substrate.substr(k, 5);
   limit = k;

   hashTable2.setMaxLambda(.5);
   for (k = 0; k < limit; k++)
      if ( hashTable2.insert(strArray[k]) )
         cout << "inserted #" << k << " " << strArray[k] << endl;
   cout << "\n#strings generated: " << limit
   << "\n#elements in ht: " << hashTable2.size() << endl;

   return 0;
}

int Hash( const Employee & item )
{
   return Hash( item.getSS() );
}

// a hash routine for strings that admits negative returns
int Hash( const string & key )
{
   unsigned int k, retVal = 0;

   for(k = 0; k < key.length( ); k++ )
      retVal = 37 * retVal + key[k];


   return retVal;
}

int Hash( int key )
{
   return key;
}

*/