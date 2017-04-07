/*
 Created by Connor Lynch
 CS2C, Advanced Data Structures & Algorithms in C++
 Created March 20, 2017
 Professor Dave Harden
 Assignment 10.1
 */

#ifndef Stars__SNE_Analyzer__
#define Stars__SNE_Analyzer__

#include <iostream>
#include <math.h>
#include "StarNearEarth.h"
using namespace std;

class SNE_Analyzer: public StarNearEarth
{
private:
   double x, y, z;

public:
   void calcCartCoords();
   double getX() { return x; }
   double getY() { return y; }
   double getZ() { return z; }
   string coordToString();
   SNE_Analyzer & operator=( const StarNearEarth &sne );


   //Here is would be interesting to add the item to spars matrix.
   //So you would have a seperate object that you are updating when you
   //have a make a new element
   //something like "add item to sparse matrix" but the sparse matrix wouldnt
   //belong to anyone object, it would be independent so you want to add every
   //star

};



void SNE_Analyzer::calcCartCoords()
{
   float LY, RARad, DECRad;
   float parallaxInArcSec = getParallaxMean(); 


   LY = 3.262 / parallaxInArcSec;

   RARad = getRAsc() * (3.14 / 180);
   DECRad = getDec() * (3.14 / 180); //FIXME: Should use const for Pi

   x = LY * cos(DECRad) * cos(RARad);
   y = LY * cos(DECRad) * sin(RARad);
   z = LY * sin(DECRad);
}


string SNE_Analyzer::coordToString()
{
   string coordString;
   //coordString = "XXX";
   //std::cout << " coords " << getX() << " " << getY() << " " << getZ() << " " << std::endl;
   coordString = "X: " + to_string(x) + " Y: " + to_string(y) + " Z: " + to_string(z);
   return coordString;
}



SNE_Analyzer & SNE_Analyzer::operator=( const StarNearEarth &sne )
{

   setRank(sne.getRank());
   setNameCns(sne.getNameCns());
   setNumComponents(sne.getNumComponents());
   setNameLhs(sne.getNameLhs());
   setRAsc(sne.getRAsc());
   setDec(sne.getDec());
   setPropMotionMag(sne.getPropMotionMag());
   setPropMotionDir(sne.getPropMotionDir());
   setParallaxMean(sne.getParallaxMean());
   setParallaxVariance(sne.getParallaxVariance());
   setWhiteDwarfFlag(sne.getWhiteDwarfFlag());
   setSpectralType(sne.getSpectralType());
   setMagApparent(sne.getMagApparent());
   setMagAbsolute(sne.getMagAbsolute());
   setMass(sne.getMass());
   setNotes(sne.getNotes());
   setNameCommon(sne.getNameCommon());
   calcCartCoords();

   return *this;
}
 


#endif