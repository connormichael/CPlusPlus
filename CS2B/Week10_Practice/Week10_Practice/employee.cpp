// this is the file "employee.cpp"

#include "employee.h"
#include <string>
using namespace std;

employee::employee()
{
   netPay = 0;
}

employee::employee(const string& newName, const string& newSsn)
{
   name = newName;
   ssn = newSsn;
   netPay = 0;
}

void employee::changeName(const string& newName)
{
   name = newName;
}

void employee::changeSsn(const string& newSsn)
{
   ssn = newSsn;
}

string employee::getName() const
{
   return name;
}

string employee::getSsn() const
{
   return ssn;
}