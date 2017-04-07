//  main.cpp
//  Assignment 8
//  Created by Connor Lynch on 2/27/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.

#include <iostream>
#include <sstream> 
#include <string> 
using namespace std;

//Class prototype
class DataProfile
{
private:
   char gender;
   char searchGender;
   int romance;
   int finance;
   string name;

public:
   static const int MIN_ROMANCE_NUM = 1;
   static const int MAX_ROMANCE_NUM = 10;
   static const int MIN_FINANCE_NUM = 1;
   static const int MAX_FINANCE_NUM = 10;
   static const int MIN_NAME_LENGTH = 1;
   static const int MAX_NAME_LENGTH = 30;
   static const char DEFAULT_GENDER = 'W';
   static const char DEFAULT_SEARCH_GENDER = 'M';
   static const int DEFAULT_ROMANCE = 5;
   static const int DEFAULT_FINANCE = 5;
   static const string DEFAULT_NAME;

public:
   //Here are the accessor prototypes
   char getGender();
   char getSearchGender();
   int getRomance();
   int getFinance();
   string getName();

   //Here are the mutator prototypes
   bool setGender(char gender);
   bool setSearchGender(char searchGender);
   bool setRomance(int romance);
   bool setFinance(int finance);
   bool setName(string name);

   //Here are the public method prototypes
   void setAll(char gender, char searchGender, int romance,
      int finance, string name);
   void setDefaults();
   double fitValue(DataProfile partner);

   //Here are the constructor prototypes
   DataProfile();
   DataProfile(char gender, char searchGender, int romance,
      int finance, string name);

private:
   double determineGenderFit(DataProfile partner);
   double determineRomanceFit(DataProfile partner);
   double determineFinanceFit(DataProfile partner);
};

//initialize string const
const string DataProfile::DEFAULT_NAME = "(undefined)";

//Global-scope method prototypes
void displayTwoProfiles(DataProfile profile1, DataProfile profile2);

int main()
{
   DataProfile profile1, profile2, profile3, profile4;

   profile1.setAll('M', 'W', 10, 1, "Ernest Hemmingway");
   profile2.setAll('W', 'M', 1, 10, "Ayn Rand");
   profile3.setAll('W', 'M', 8, 3, "Beyonce");
   profile4.setAll('M', 'W', 5, 5, "Wes McKinney");

   displayTwoProfiles(profile1, profile1);
   displayTwoProfiles(profile1, profile2);
   displayTwoProfiles(profile1, profile3);
   displayTwoProfiles(profile1, profile4);
   displayTwoProfiles(profile2, profile1);
   displayTwoProfiles(profile2, profile2);
   displayTwoProfiles(profile2, profile3);
   displayTwoProfiles(profile2, profile4);
   displayTwoProfiles(profile3, profile1);
   displayTwoProfiles(profile3, profile2);
   displayTwoProfiles(profile3, profile3);
   displayTwoProfiles(profile3, profile4);
   displayTwoProfiles(profile4, profile1);
   displayTwoProfiles(profile4, profile2);
   displayTwoProfiles(profile4, profile3);
   displayTwoProfiles(profile4, profile4);

   return 0;
}

//Here is my global scope method definition
void displayTwoProfiles(DataProfile profile1, DataProfile profile2)
{
   string displayString;
   float fitScore;

   fitScore = profile1.fitValue(profile2);
   displayString = "Fit between " + profile1.getName() + " and "
      + profile2.getName() + ":";
   cout << displayString << endl << "   " <<fitScore  << endl;
}

//Here is the default constructor
DataProfile::DataProfile()
{
   setDefaults();
}

//Here is the parameter taking constructor
DataProfile::DataProfile(char gender, char searchGender,
   int romance, int finance, string name)
{
   if (!setGender(gender))
      setGender(DEFAULT_GENDER);
   if (!setSearchGender(searchGender))
      setSearchGender(DEFAULT_SEARCH_GENDER);
   if (!setRomance(romance))
      setRomance(DEFAULT_ROMANCE);
   if (!setFinance(finance))
      setFinance(DEFAULT_FINANCE);
   if (!setName(name))
      setName(DEFAULT_NAME);
}

void DataProfile::setAll(char gender, char searchGender, int romance,
   int finance, string name)
{
   setGender(gender);
   setSearchGender(searchGender);
   setRomance(romance);
   setFinance(finance);
   setName(name);
}

void DataProfile::setDefaults()
{
   setGender(DEFAULT_GENDER);
   setSearchGender(DEFAULT_SEARCH_GENDER);
   setRomance(DEFAULT_ROMANCE);
   setFinance(DEFAULT_FINANCE);
   setName(DEFAULT_NAME);
}

double DataProfile::fitValue(DataProfile partner)
{
   double fitAverge;

   if (determineGenderFit(partner) == 1.0)
   {
      fitAverge = (determineFinanceFit(partner) +
         determineRomanceFit(partner))/2;
      return fitAverge;
   }
   else
      return 0.0;
}

double DataProfile::determineGenderFit(DataProfile partner)
{
   if (getGender() != partner.getSearchGender() ||
       getSearchGender() != partner.getGender())
      return 0.0;
   else
      return 1.0;
}

double DataProfile::determineFinanceFit(DataProfile partner)
{
   int financeDifference;
   financeDifference = (getFinance() - partner.getFinance());

   if (financeDifference == 0)
      return 1.0;
   if (financeDifference == 8 || financeDifference == -8 )
      return 0.2;
   if (financeDifference == 7 || financeDifference == -7 )
      return 0.3;
   if (financeDifference == 6 || financeDifference == -6)
      return 0.4;
   if (financeDifference == 5 || financeDifference == -5)
      return 0.5;
   if (financeDifference == 4 || financeDifference == -4)
      return 0.6;
   if (financeDifference == 3 || financeDifference == -3)
      return 0.7;
   if (financeDifference == 2 || financeDifference == -2)
      return 0.8;
   if (financeDifference == 1 || financeDifference == -1)
      return 0.9;
   else
      return 0.1;
}

double DataProfile::determineRomanceFit(DataProfile partner)
{
   int romanceDifference;
   romanceDifference = (getRomance() - partner.getRomance());

   if (romanceDifference == 0)
      return 1.0;
   if (romanceDifference == 8 || romanceDifference == -8 )
      return 0.2;
   if (romanceDifference == 7 || romanceDifference == -7 )
      return 0.3;
   if (romanceDifference == 6 || romanceDifference == -6)
      return 0.4;
   if (romanceDifference == 5 || romanceDifference == -5)
      return 0.5;
   if (romanceDifference == 4 || romanceDifference == -4)
      return 0.6;
   if (romanceDifference == 3 || romanceDifference == -3)
      return 0.7;
   if (romanceDifference == 2 || romanceDifference == -2)
      return 0.8;
   if (romanceDifference == 1 || romanceDifference == -1)
      return 0.9;
   else
      return 0.1;
}

//Here are the mutator method definitions
bool DataProfile::setGender(char gender)
{
   gender = toupper(gender);
   if (gender == 'W' || gender == 'M')
   {
      this->gender = gender;
      return true;
   }
   else
      return false;
}

bool DataProfile::setSearchGender(char searchGender)
{
   searchGender = toupper(searchGender);
   if (searchGender == 'W' || searchGender == 'M')
   {
      this->searchGender = searchGender;
      return true;
   }
   else
      return false;
}

bool DataProfile::setRomance(int romance)
{
   if (romance < MIN_ROMANCE_NUM || romance > MAX_ROMANCE_NUM)
      return false;
   else
   {
      this->romance = romance;
      return true;
   }
}

bool DataProfile::setFinance(int finance)
{
   if (finance < MIN_FINANCE_NUM || finance > MAX_FINANCE_NUM)
      return false;
   else
   {
      this->finance = finance;
      return true;
   }
}

bool DataProfile::setName(string name)
{
   if (name.length() < MIN_NAME_LENGTH || name.length() > MAX_NAME_LENGTH)
      return false;
   else
   {
      this->name = name;
      return true;
   }
}

//Here are the accessor methods
char DataProfile::getGender()
{
   return gender;
}

char DataProfile::getSearchGender()
{
   return searchGender;
}

int DataProfile::getRomance()
{
   return romance;
}

int DataProfile::getFinance()
{
   return finance;
}

string DataProfile::getName()
{
   return name;
}


/*---------------------Connor's Run-----------------------------

Fit between Ernest Hemmingway and Ernest Hemmingway:
   0
Fit between Ernest Hemmingway and Ayn Rand:
   0.1
Fit between Ernest Hemmingway and Beyonce:
   0.8
Fit between Ernest Hemmingway and Wes McKinney:
   0
Fit between Ayn Rand and Ernest Hemmingway:
   0.1
Fit between Ayn Rand and Ayn Rand:
   0
Fit between Ayn Rand and Beyonce:
   0
Fit between Ayn Rand and Wes McKinney:
   0.55
Fit between Beyonce and Ernest Hemmingway:
   0.8
Fit between Beyonce and Ayn Rand:
   0
Fit between Beyonce and Beyonce:
   0
Fit between Beyonce and Wes McKinney:
   0.75
Fit between Wes McKinney and Ernest Hemmingway:
   0
Fit between Wes McKinney and Ayn Rand:
   0.55
Fit between Wes McKinney and Beyonce:
   0.75
Fit between Wes McKinney and Wes McKinney:
   0
Program ended with exit code: 0

----------------------------------------------------------------*/