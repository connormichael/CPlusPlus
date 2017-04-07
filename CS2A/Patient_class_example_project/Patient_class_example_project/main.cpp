//
//  main.cpp
//  Patient_class_example_project
//
//  Created by Connor Lynch on 9/9/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <string> 
#include <sstream>
using namespace std;

class Patient
{
private:
   string name;
   int id;
   double temperature;

public:
   //Some public defaults for the constructor
   static const string DEFAULT_NAME;
   static const int DEFAULT_ID;
   static const double DEFAULT_TEMP;
   static const int MIN_LENGTH;
   static const int MAX_LENGTH;
   static const int MIN_ID;
   static const int MAX_ID;
   static const double MIN_TEMP;
   static const double MAX_TEMP;
   static const double ALARM_TEMP;

   //Default constructor
   Patient();
   //Parameter taking constructor
   Patient(string theName, int theId, double theTemp);

   //Accessors and Mutators
   bool setName(string theName);
   bool setId(int theId);
   bool setTemp(double theTemp);
   string getName();
   int getId();
   double getTemp();

   //Methods
   void display();

};
const string Patient::DEFAULT_NAME = "none";
const int Patient::DEFAULT_ID = 0;
const double Patient::DEFAULT_TEMP = 98.5;
const int Patient::MIN_LENGTH = 2;
const int Patient::MAX_LENGTH = 40;
const int Patient::MIN_ID = 0;
const int Patient::MAX_ID = 9999;
const double Patient::MIN_TEMP = 88.0;
const double Patient::MAX_TEMP = 111.0;
const double Patient::ALARM_TEMP = 103.5;

//Here's where method prototypes go
string getPatientName();
int getPatientId();
double getPatientTemp();

int main()
{
   Patient p1, p2, p3("blah", 1111, 101.1);
   p1.setName("Fred");
   p1.setId(1234);
   p1.setTemp(100.3);
   p2.setName("Janis");
   p2.setId(5555);
   p2.setTemp(103.7);

   p1.display();
   p2.display();
   p3.display();

   if (!p1.setTemp(333.))
      cout << "can't set temp" <<endl;
   else
      cout << "set set to 333" << endl;
   return 0;
}

//main method definitions follow right after main
string getPatientName()
{
   string strIn, patientName;
   cout << "please enter a patient name " << endl;
   getline(cin, strIn);
   patientName = strIn;
   return patientName;
}

int getPatientId()
{
   string strIn;
   int patientId;
   cout << "please enter patient id " << endl;
   getline(cin, strIn);
   istringstream(strIn) >> patientId;
   return patientId;
}

double getPatientTemp()
{
   string strIn;
   double patientTemp;
   cout << "please enter patient " << endl;
   getline(cin, strIn);
   istringstream(strIn) >> patientTemp;
   return patientTemp;
}

Patient::Patient()
{
   name = DEFAULT_NAME;
   id = DEFAULT_ID;
   temperature = DEFAULT_TEMP;
}

Patient::Patient(string theName, int theId, double theTemp)
{
   if (!setName(theName))
      name = DEFAULT_NAME;
   if (!setId(theId))
      id = DEFAULT_ID;
   if (!setTemp(theTemp))
      temperature = DEFAULT_TEMP;
}

void Patient::display()
{
   cout << name << " "
   << id << " " <<
   temperature << endl;
}

bool Patient::setName(string theName)
{
   if (theName.length() < MIN_LENGTH || theName.length() > MAX_LENGTH)
      return false;
   name = theName;
   return true;
}
bool Patient::setId(int theId)
{
   if (theId < MIN_ID || theId > MAX_ID)
      return false;
   id = theId;
   return true;
}
bool Patient::setTemp(double theTemp)
{
   if (theTemp < MIN_TEMP || theTemp > MAX_TEMP)
      return false;
   temperature = theTemp;
   return true;
}

string Patient::getName()
{
   return name;
}

int Patient::getId()
{
   return id;
}

double Patient::getTemp()
{
   return temperature;
}

