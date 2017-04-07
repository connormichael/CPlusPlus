//
//  Header.h
//  Week4_Homework4_Professor_Solution
//
//  Created by Connor Lynch on 10/17/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#ifndef invItem_h
#define invItem_h

#include <iostream>  //WHY DO I NEED TO IMPORT THIS

class invItem
{
public:
   invItem();
   invItem(const char *inDesc);
   invItem(const invItem& right);
   ~invItem();
   void setInfo(const char *inDesc, int inUnits);
   void setUnits(int inUnits);
   friend std::ostream& operator<<(std::ostream& out, const invItem& printMe);
   invItem operator=(const invItem& right);
   char& operator[](int index);
   char operator[](int index) const;
   friend std::istream& operator>>(std::istream& in, invItem& target);

private:
   char *desc;
   int units;
};


#endif
