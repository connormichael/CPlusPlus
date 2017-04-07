/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created September 27, 2016
 Professor Dave Harden
 Assignment 1.1 Operator Overloading
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

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








//Constructor definition
Fraction::Fraction(int numerator,int denominator)
{
   assert(denominator != 0);
   this->denominator = denominator;
   this->numerator = numerator;
   simplify();
}







bool operator<(const Fraction& left, const Fraction& right)
{
   return (right.denominator * left.numerator < left.denominator * right.numerator);
}





bool operator>(const Fraction& left, const Fraction& right)
{
   return (right.denominator * left.numerator > left.denominator * right.numerator);
}






bool operator>=(const Fraction& left, const Fraction& right)
{
   return (right.denominator * left.numerator >= left.denominator * right.numerator);
}






bool operator<=(const Fraction& left, const Fraction& right)
{
   return (right.denominator * left.numerator <= left.denominator * right.numerator);
}






bool operator==(const Fraction& left, const Fraction& right)
{
   return (right.denominator * left.numerator == left.denominator * right.numerator);
}






bool operator!=(const Fraction& left, const Fraction& right)
{
   return (right.denominator * left.numerator != left.denominator * right.numerator);
}






Fraction operator+(const Fraction &left, const Fraction &right)
{
   Fraction answer;

   answer.numerator = (left.numerator * right.denominator) +
   (left.denominator * right.numerator);
   answer.denominator= (left.denominator * right.denominator);
   return answer;
}






Fraction operator-(const Fraction &left, const Fraction &right)
{
   Fraction answer;

   answer.numerator = (left.numerator * right.denominator) -
   (left.denominator * right.numerator);
   answer.denominator= (left.denominator * right.denominator);
   return answer;
}






Fraction operator*(const Fraction &left, const Fraction &right)
{
   Fraction answer;

   answer.numerator = left.numerator * right.numerator;
   answer.denominator = left.denominator * right.denominator;
   return answer;
}






Fraction operator/(const Fraction &left, const Fraction &right)
{
   Fraction answer;

   answer.numerator = left.numerator * right.denominator;
   answer.denominator = left.denominator * right.numerator;
   return answer;
}






Fraction Fraction::operator++()
{
   numerator += denominator;
   return *this;
}






Fraction Fraction::operator++(int)
{
   Fraction tempFract(numerator, denominator);

   numerator += denominator;
   return tempFract;
}






Fraction Fraction::operator--()
{
   numerator -= denominator;
   return *this;
}






Fraction Fraction::operator--(int)
{
   Fraction tempFract(numerator, denominator);

   numerator -= denominator;
   return tempFract;
}






Fraction Fraction::operator+=(const Fraction& rightFract)
{
   *this = *this + rightFract;
   return *this;
}






Fraction Fraction::operator-=(const Fraction& rightFract)
{
   *this = *this - rightFract;
   return *this;
}






Fraction Fraction::operator*=(const Fraction& rightFract)
{
   *this = *this * rightFract;
   return *this;
}






Fraction Fraction::operator/=(const Fraction& rightFract)
{
   *this = *this / rightFract;
   return *this;
}






ostream& operator<<(ostream& out, const Fraction& rightFract)
{
   Fraction remainder;
   int divisor;
   int result = 0;

   remainder = rightFract;

   while (remainder.numerator >= remainder.denominator)
   {
      remainder.numerator -= remainder.denominator;
      result++;
   }
   if ((result > 0) && (remainder.numerator))
      out << result << endl;
   else
      out << remainder.numerator << "/" << remainder.denominator;
   return out;
}






void Fraction::simplify()
{
   bool notSimplified = true;
   int k = 9;

   if (denominator < 0)
   {
      denominator *= -1;
      numerator *= -1;
   }

   while (notSimplified)
   {
      for (k; k > 1; k--)
      {
         if ((numerator % k == 0) && (denominator % k == 0))
         {
            numerator /= k;
            denominator /= k;
            notSimplified = true;
            break;
         }
         notSimplified = false;
      }
   }
}





int main()
{
   Fraction f2(4,2);
   cout << f2 << endl;
   cout << "working...";
   return 0;
}





