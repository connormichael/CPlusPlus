//
//  hourlyemployee.cpp
//  Week10_Practice
//
//  Created by Connor Lynch on 12/8/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include "hourlyemployee.h"


hourlyEmp::hourlyEmp(const string& newName,
                     const string& newSsn,
                     double newPayRate,
                     double newHours)
: employee(newName, newSsn)
{
   payRate = newPayRate;
   hours = newHours;
}