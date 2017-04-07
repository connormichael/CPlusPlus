//  main.cpp
//  Assignment 7
//
//  Created by Connor Lynch on 2/20/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.

#include <iostream>
#include <string> 
#include <sstream>
using namespace std;

class ITunes
{
private:
   string name;
   string artist;
   int bitrate;
   int totalTime;

public:
   //constructors
   ITunes();
   ITunes(string name, string artist, int bitrate, int totalTime);

   //set default method and display method
   string toString();
   void setDefaults();

   //mutators and accesors
   bool setSongName(string name);
   bool setArtistName(string artist);
   bool setBitrate(int bitrate);
   bool setTotalTime(int totalTime);
   string getSongName();
   string getArtistName();
   int getBitrate();
   int getTotalTime();

public:
   static const int MIN_BITRATE = 64;
   static const int MAX_BITRATE = 705;
   static const int MIN_STR_LENGTH = 1;
   static const int MAX_STR_LENGTH = 80;
   static const int MIN_PLAY_TIME = 1000;
   static const int MAX_PLAY_TIME = 1000*60*60;
   static const int DEFAULT_BITRATE = 64;
   static const int DEFAULT_PLAY_TIME = 1000;
   static const string DEFAULT_STRING;
};

//initialize string constant
const string ITunes::DEFAULT_STRING = "(undefined)";

//define global method
void display(string output);

int main()
{
   //initialization of local variables
   ITunes entry1, entry2, entry3, entry4;
   string output;

   //set class objects with different member data
   cout <<"Lets set up the class objects with some initial member data\n"
      << endl;
   entry1.setBitrate(65);
   entry1.setArtistName("Cher");
   entry1.setSongName("Love");
   entry1.setTotalTime(5252);
   output = entry1.toString();
   display(output);
   entry2.setBitrate(99);
   entry2.setArtistName("US");
   entry2.setSongName("Sunday Bloody Sunday");
   entry2.setTotalTime(7777);
   output = entry2.toString();
   display(output);
   output = entry3.toString();
   display(output);
   output = entry4.toString();
   display(output);

   //Modify the class objects member data
   cout << "\nLets change some of the member data \n" << endl;
   entry1.setBitrate(200);
   output = entry1.toString();
   display(output);
   entry2.setSongName("Electric Love");
   entry2.setArtistName("BORNS");
   output = entry2.toString();
   display(output);
   entry3.setArtistName("Aphex Twin");
   entry3.setSongName("Avril 14th");
   entry3.setTotalTime(7000);
   entry3.setBitrate(300);
   output = entry3.toString();
   display(output);
   entry4.setArtistName("Mos Def");
   entry4.setSongName("Hip Hop");
   output = entry4.toString();
   display(output);

   //set all entries in ITunes library to default values
   cout << "\nNow lets make all object member data have default values \n"
      << endl;
   entry1.setDefaults();
   output = entry1.toString();
   display(output);
   entry2.setDefaults();
   output = entry2.toString();
   display(output);
   entry3.setDefaults();
   output = entry3.toString();
   display(output);
   entry4.setDefaults();
   output = entry4.toString();
   display(output);

   //Here is where we check to make sure the mutators are working
   cout << "\nHere is the output for the tests of the mutators:\n";
   if (!entry1.setBitrate(212))
      cout << "ERROR with setBitrate()";
   else
      cout << "Value within range, Return setBitrate()";

   if (!entry1.setArtistName(""))
      cout << "\nERROR with setArtistName()\n";
   else
       cout << "\nValue within range, Return setArtistName()";

   //Here is where we check to make sure the accessors are working
   cout << "\nHere is the output for the tests of the accesors:" ;
   entry2.setArtistName("Nas");
   entry4.setSongName("Stairway to Heaven");
   entry3.setBitrate(300);
   cout << "\nThe artist's name for entry2 is " << entry2.getArtistName();
   cout << "\nThe song name for entry4 is " << entry4.getSongName();
   cout << "\nThe bitrate for entry3 is " << entry3.getBitrate() << endl;

   return 0;
}

//defining default constructor
ITunes::ITunes()
{
   ITunes::setDefaults();
}

ITunes::ITunes(string name, string artist, int bitrate, int totalTime)
{
   if (!setSongName(name))
      setSongName(DEFAULT_STRING);
   if (!setArtistName(artist))
      setArtistName(DEFAULT_STRING);
   if (!setBitrate(bitrate))
      setBitrate(DEFAULT_BITRATE);
   if (!setTotalTime(totalTime))
      setTotalTime(DEFAULT_PLAY_TIME);
}

string ITunes::toString()
{
   string displayString;
   string name, artist, stringBitrate, stringTotalTime;
   int intBitrate, intTotalTime;

   displayString = "";
   name = getSongName();
   artist = getArtistName();

   intBitrate = getBitrate();
   ostringstream cnvrt;
   cnvrt << intBitrate;
   stringBitrate = cnvrt.str();
   //clearing cnvrt for resuse
   cnvrt.str("");
   cnvrt.clear();

   intTotalTime = getTotalTime();
   intTotalTime /= 1000;
   cnvrt << intTotalTime;
   stringTotalTime = cnvrt.str();

   displayString = displayString + artist + ", " + name + ", " +
      stringTotalTime +" seconds" + ", " + stringBitrate +
      "k bits per second\n";

   return displayString;
}

void display(string output)
{
   cout << output;
}

void ITunes::setDefaults()
{
   setSongName(DEFAULT_STRING);
   setArtistName(DEFAULT_STRING);
   setBitrate(DEFAULT_BITRATE);
   setTotalTime(DEFAULT_PLAY_TIME);
}

//Here are the mutator definitions
bool ITunes::setSongName(string name)
{
   if (name.length() < MIN_STR_LENGTH || name.length() > MAX_STR_LENGTH)
   {
      return false;
   }
   else
   {
      this->name = name;
      return true;
   }
}

bool ITunes::setArtistName(string artist)
{
   if (artist.length() < MIN_STR_LENGTH || artist.length() > MAX_STR_LENGTH)
   {
      return false;
   }
   else
   {
      this->artist = artist;
      return true;
   }
}

bool ITunes::setBitrate(int bitrate)
{
   if (bitrate < MIN_BITRATE || bitrate > MAX_BITRATE)
   {
      return false;
   }
   else
   {
      this->bitrate = bitrate;
      return true;
   }
}

bool ITunes::setTotalTime(int totalTime)
{
   if (totalTime < MIN_PLAY_TIME || totalTime > MAX_PLAY_TIME)
   {
      return false;
   }
   else
   {
      this->totalTime = totalTime;
      return true;
   }
}

//Here are the accesors
string ITunes::getSongName()
{
   return name;
}

string ITunes::getArtistName()
{
   return artist;
}

int ITunes::getBitrate()
{
   return bitrate;
}

int ITunes::getTotalTime()
{
   return totalTime;
}

/*-------------------Connor's Run ---------------------------

Lets set up the class objects with some initial member data

Cher, Love, 5 seconds, 65k bits per second
US, Sunday Bloody Sunday, 7 seconds, 99k bits per second
(undefined), (undefined), 1 seconds, 64k bits per second
(undefined), (undefined), 1 seconds, 64k bits per second

Lets change some of the member data 

Cher, Love, 5 seconds, 200k bits per second
BORNS, Electric Love, 7 seconds, 99k bits per second
Aphex Twin, Avril 14th, 7 seconds, 300k bits per second
Mos Def, Hip Hop, 1 seconds, 64k bits per second

Now lets make all object member data have default values 

(undefined), (undefined), 1 seconds, 64k bits per second
(undefined), (undefined), 1 seconds, 64k bits per second
(undefined), (undefined), 1 seconds, 64k bits per second
(undefined), (undefined), 1 seconds, 64k bits per second

Here is the output for the tests of the mutators:
Value within range, Return setBitrate()
ERROR with setArtistName()

Here is the output for the tests of the accesors:
The artist's name for entry2 is Nas
The song name for entry4 is Stairway to Heaven
The bitrate for entry3 is 300
Program ended with exit code: 0

-----------------------------------------------------------------*/