/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 3, 2016
 Professor Dave Harden
 Assignment 2.1 Operator Overloading
 */

/* 
 Description:
 This program lays out the methods for the Fraction class. Within this class
 Fraction objects are composed of two data members, numerator and denominator, 
 which combined represent a fraction value.
 The class provides friend and member methods for operator overloading.
 The class constructor includes default parameters for both member data,
 thus allowing an object to be instantiated with 0, 1, or 2 parameters.
 The overloaded operators include: <, >, <=, >=, ==, !=, +, -, /, *, ++, --,
 +=, -=, *=, /=, <<, >>. Operations between integers and Fraction objects are
 supported where necessary.

 Member Functions: 
 Fraction(int numerator = DEFAULT_NUM, int denominator = DEFAULT_DENOM)
   Precondition: denominator is a non-zero integar. 
   numerator is an integar. with default parameters constructor can be called 
   with zero, one, or two parameters. DEFAULT_NUM is set to 0, and DEFAULT_DENOM   
   is set to 1. 
   Postcondition: A Fraction object with two member data, numerator and 
   denominator where the denominator is non-zero.
 
 friend std::ostream& operator<<(std::ostream& out, const Fraction& rightFract)
   Precondition: rightFract is a Fraction object representing a numeric fraction 
   or integar. Fraction object member data numerator and denominator, both 
   integars, where denominator is a non-zero value. Values are stored in reduced form.
   out is a stream.
   Postcondition: Output stream of rightFraction represented as a mixed number 
   when applicable.
 
 friend std::istream& operator>>(std::istream& in, Fraction& rightFract)
   Precondition: in is a stream containing a numeric fraction
   or integar. Has member data numerator and denominator, both integars, where 
   denominator is a non-zero value. in can read a whole integar, a mixed fraction
   e.g 1+1/2, or a standard fraction.
   rightFract has member data numerator and denominator, both integars, where
   denominator is a non-zero value. rightFract is reduced.
   Postcondition: returns in, which is then ready to read future data. 
   Stores results from in into rightFract. rightFract is a reduced fraction.
 
 friend bool operator<(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar. 
   right is either a Fraction object or an integar.
   Postcondition: returns boolean result, true or false, of whether left is 
   less than right
 
 friend bool operator>(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition: returns boolean result, true or false, of whether left is
   greater than right

 friend bool operator>=(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition: returns boolean result, true or false, of whether left is
   greater than  or equal to right

 friend bool operator<=(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition: returns boolean result, true or false, of whether left is
   less than or equal to right

 friend bool operator==(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition: returns boolean result, true or false, of whether left is
   equal to right

 friend bool operator!=(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition: returns boolean result, true or false, of whether left is not
   equal to right

 friend Fraction operator+(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition: returns reduced Fraction object which is the sum of
   left and right.
 
 friend Fraction operator-(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition:returns reduced Fraction object which is the
   difference of left and right.

 friend Fraction operator*(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition:returns reduced Fraction object which is the
   product of left and right.

 friend Fraction operator/(const Fraction& left, const Fraction& right)
   Precondition: left is either a Fraction object or an integar.
   right is either a Fraction object or an integar.
   Postcondition:returns reduced Fraction object which is the
   quotient of left and right

 Fraction operator++()
   Precondition: Calling object is either a Fraction object or an integar.
   Postcondition: Calling object is returned with a value plus one. If used an 
   ouput statement, the new value of the calling object is displayed.
 
 Fraction operator++(int)
   Precondition: Calling object is either a Fraction object or an integar.
   int is not a variable, but rather allows for method overloading.
   Postcondition: Calling object is returned with a value plus one. If used an
   ouput statement, the original value of the calling object is displayed.

 Fraction operator--()
   Precondition: Calling object is either a Fraction object or an integar.
   Postcondition: Calling object is returned with a value minus one. If used an
   ouput statement, the new value of the calling object is displayed.

 Fraction operator--(int)
   Precondition: Calling object is either a Fraction object or an integar.
   int is not a variable, but rather allows for method overloading.
   Postcondition: Calling object is returned with a value plus one. If used an
   ouput statement, the original value of the calling object is displayed.

 Fraction operator+=(const Fraction& rightFract)
   Precondition: Calling object is either a Fraction object or an integar.
   rightFract is either a Fraction object or an integar.
   Postcondition: returns the calling object with the added value of right Fract. 
   If a Fraction object, the numerator and denomintor have been reduced.
 
 Fraction operator-=(const Fraction& rightFract)
   Precondition: Calling object is either a Fraction object or an integar.
   rightFract is either a Fraction object or an integar.
   Postcondition: returns the calling object with the subtracted value of right Fract.
   If a Fraction object, the numerator and denomintor have been reduced.

 Fraction operator*=(const Fraction& rightFract)
   Precondition: Calling object is either a Fraction object or an integar.
   rightFract is either a Fraction object or an integar.
   Postcondition: returns the calling object multiplied by the value of right Fract.
   If a Fraction object, the numerator and denomintor have been reduced.

 Fraction operator/=(const Fraction& rightFract)
   Precondition: Calling object is either a Fraction object or an integar.
   rightFract is either a Fraction object or an integar.
   Postcondition: returns the calling object divided by the value of right Fract.
   If a Fraction object, the numerator and denomintor have been reduced.
*/


#ifndef Fraction_h
#define Fraction_h

namespace cs_Fraction
{
   class Fraction
   {
   private:
      int denominator;
      int numerator;
      void simplify();

   public:
      static const int DEFAULT_DENOM = 1;
      static const int DEFAULT_NUM = 0;

      Fraction(int numerator = DEFAULT_NUM, int denominator = DEFAULT_DENOM);

      friend std::ostream& operator<<(std::ostream& out, const Fraction& rightFract);
      friend std::istream& operator>>(std::istream& in, Fraction& rightFract);

      friend bool operator<(const Fraction& left, const Fraction& right);
      friend bool operator>(const Fraction& left, const Fraction& right);
      friend bool operator>=(const Fraction& left, const Fraction& right);
      friend bool operator<=(const Fraction& left, const Fraction& right);
      friend bool operator==(const Fraction& left, const Fraction& right);
      friend bool operator!=(const Fraction& left, const Fraction& right);

      friend Fraction operator+(const Fraction& left, const Fraction& right);
      friend Fraction operator-(const Fraction& left, const Fraction& right);
      friend Fraction operator*(const Fraction& left, const Fraction& right);
      friend Fraction operator/(const Fraction& left, const Fraction& right);

      Fraction operator++();
      Fraction operator++(int);
      Fraction operator--();
      Fraction operator--(int);

      Fraction operator+=(const Fraction& rightFract);
      Fraction operator-=(const Fraction& rightFract);
      Fraction operator*=(const Fraction& rightFract);
      Fraction operator/=(const Fraction& rightFract);
   };
}

#endif
