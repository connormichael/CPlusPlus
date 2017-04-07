#include<iostream>
#include <string>
using namespace std;

// ---------------- the class prototype ---------------------------------
class Galaxy
{
private:
   string name;
   double magnitude;
public:

   // static constants
   static const double DEFAULT_MAG;
   static const string DEFAULT_NAME;
   static const double MIN_MAG;
   static const double MAX_MAG;
   static const int MIN_STR_LEN = 2;

   // default constructor
   Galaxy();

   // 2-parameter constructor (to be discussed)
   Galaxy(string myName, double myMag);

   // mutators and accessors
   bool setMagnitude(double mag);
   bool setName(string theName);
   string getName();
   double getMagnitude();
};

const double Galaxy::DEFAULT_MAG = 0.0;
const string Galaxy::DEFAULT_NAME = "undefined";
const double Galaxy::MIN_MAG = -3.;
const double Galaxy::MAX_MAG = 30.;

// ------------------ the main method ---------------------------------
int  main()
{
   // declare the objects
   Galaxy gal1, gal2;

   // try to set the data
   gal1.setName("X");
   gal1.setMagnitude(100);
   gal2.setName("Stephan's Third");
   gal2.setMagnitude(13.2);

   // let's see what happened
   cout << "Gal #1 name: " <<  gal1.getName() << endl;
   cout << "Gal #1 mag: " <<  gal1.getMagnitude() << endl;
   cout << "Gal #2 name: " <<  gal2.getName()<< endl;
   cout << "Gal #2 mag: " <<  gal2.getMagnitude()<< endl;

   return 0;
}

// ------------ Galaxy member functions definitions ------------
// default constructor
Galaxy::Galaxy()
{
   name = DEFAULT_NAME;
   magnitude = DEFAULT_MAG;
}

// 2-parameter constructor
Galaxy::Galaxy(string myName, double myMag)
{
   if ( !setName(myName) )
      name = DEFAULT_NAME;
   if ( !setMagnitude(myMag) )
      magnitude = DEFAULT_MAG;
}

// mutators "set" methods
bool Galaxy::setMagnitude(double mag)
{
   if (mag < MIN_MAG || mag > MAX_MAG)
      return false;
   // else
   magnitude = mag;
   return true;
}

bool Galaxy::setName(string theName)
{
   if (theName.length() < MIN_STR_LEN)
      return false;
   // else we fall through
   name = theName;
   return true;
}
// accessor "get" methods
string Galaxy::getName()
{
   return name;
}
double Galaxy::getMagnitude()
{
   return magnitude;
}

/* ------------------ Paste of Run from Above Program ----------

 Gal #1 name: undefined
 Gal #1 mag: 0
 Gal #2 name: Stephan's Third
 Gal #2 mag: 13.2
 Press any key to continue . . .

 ---------------------------------------------------------------- */