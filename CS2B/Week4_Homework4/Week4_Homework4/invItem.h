//
//  invItem.h
//  Week4_Homework4
//
//  Created by Connor Lynch on 10/15/16.
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
   void setInfo(const char *inDesc, int inUnits);
   void setUnits(int inUnits);
   friend std::ostream& operator<<(std::ostream& out, const invItem& printMe);
private:
   char *desc;
   int units;
};


#endif
