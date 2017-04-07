// this is the file "hourlyemp.h"

#ifndef HOURLYEMP_H
#define HOURLYEMP_H
#include "employee.h"
#include <string>
using namespace std;

class hourlyEmp: public employee {
public:
   hourlyEmp();
   hourlyEmp(const string& newName, const string& newSsn,
             double newPayRate, double newHours);
   double getHours() const;
   void setHours(double newHours);
   void giveRaise(double amount);
   void printCheck() const;
private:
   double hours;
   double payRate;
};


#endif
