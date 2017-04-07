//
//  File.h
//  Week10_Practice
//
//  Created by Connor Lynch on 12/4/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

// this is the file "employee.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class employee {
public:
   employee();
   employee(const string& newName, const string& newSsn);
   string getName() const;
   string getSsn() const;
   void changeName(const string& newName);
   void changeSsn(const string& newSsn);
private:
   string name;
   string ssn;
   double netPay;
};

#endif
