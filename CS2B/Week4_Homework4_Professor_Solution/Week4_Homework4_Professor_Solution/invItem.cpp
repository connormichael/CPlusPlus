//
//  File.cpp
//  Week4_Homework4_Professor_Solution
//
//  Created by Connor Lynch on 10/17/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//


#include "invItem.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

invItem::invItem()
{
   desc = new char[1];
   strcpy(desc, "");
   int DEFAULT_INVENT = 0;
   units = DEFAULT_INVENT;
}






invItem::invItem(const char *inDesc)
{
   int DEFAULT_INVENT = 0;
   units = DEFAULT_INVENT;
   desc = new char[strlen(inDesc) + 1];
   strcpy(desc, inDesc);
}







invItem::invItem(const invItem& right)
{
   units = right.units;
   desc = new char[strlen(right.desc) + 1];
   strcpy(desc, right.desc);
}





invItem::~invItem()
{
   delete [] desc;
}






void invItem::setInfo(const char *inDesc, int inUnits)
{
   units = inUnits;
   delete [] desc;
   desc = new char[strlen(inDesc) +1];
   strcpy(desc, inDesc);
}




void invItem::setUnits(int inUnits)
{
   units = inUnits;
}






ostream& operator<<(std::ostream& out, const invItem& source)
{
   cout << source.units << " " << source.desc;
   return out;
}





invItem invItem::operator=(const invItem& right)
{
   if (this != &right){
      units = right.units;
      delete [] desc;
      desc = new char[strlen(right.desc) + 1];
      strcpy(desc, right.desc);
   }
   return *this;
}






char& invItem::operator[](int index)
{
   assert(index >= 0 && index < strlen(desc));
   return desc[index];
}

char invItem::operator[](int index) const 
{
   assert(index >= 0 && index < strlen(desc));
   return desc[index];
}






istream& operator>>(istream& in, invItem& target)
{
   while (isspace(in.peek()))
   {
      in.ignore();
   }
   char temp[128];
   in.getline(temp, 127, ':');
   delete [] target.desc;
   target.desc = new char[strlen(temp) + 1];
   strcpy(target.desc, temp);

   return in;
}















