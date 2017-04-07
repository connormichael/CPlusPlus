/*
 Created by Connor Lynch
 CS2B, Intermeditate Software Design in C++
 Created October 3, 2016
 Professor Dave Harden
 Assignment 2.1 Operator Overloading
 
 Description:
 This program lays out the methods for the Fraction class. Within this class
 Fraction objects are composed of two data members, numerator and denominator. 
   numerator: an integar that can be any value, including zero 
   denominator: an integar that can be any positive value; it cannot have values 
   less than or equal to 0. 

 There is also a member function, simplify, which simplifies
 fractions e.g. 12/6 becomes 1/2. All Fractions are thus stored in reduced form.
 
 The class provides friend and member methods for operator overloading.
 The class constructor includes default parameters for both member data, 
 thus allowing an object to be instantiated with 0, 1, or 2 parameters. 
 The overloaded operators include: <, >, <=, >=, ==, !=, +, -, /, *, ++, --, 
 +=, -=, *=, /=, <<, >>. Operations between integers and Fraction objects are 
 supported where necessary. 
*/

#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "Fraction.h"
using namespace std;

namespace cs_Fraction
{
   //class constructor that initilized that two member data
   Fraction::Fraction(int numerator, int denominator)
   {
      assert(denominator != 0);
      this->denominator = denominator;
      this->numerator = numerator;
      simplify();
   }






   //Overloaded < (less than) operator for comparing fraction and integar objects
   bool operator<(const Fraction& left, const Fraction& right)
   {
      return (right.denominator * left.numerator < left.denominator * right.numerator);
   }






   //Overloaded > (greater than) operator for comparing fraction and integar objects
   bool operator>(const Fraction& left, const Fraction& right)
   {
      return (right.denominator * left.numerator > left.denominator * right.numerator);
   }






   //Overloaded >= (greater than or equal to) operator for comparing fraction
   //and integar objects
   bool operator>=(const Fraction& left, const Fraction& right)
   {
      return (right.denominator * left.numerator >= left.denominator * right.numerator);
   }






   //Overloaded <= (less than or equal to) operator for comparing fraction
   //and integar objects
   bool operator<=(const Fraction& left, const Fraction& right)
   {
      return (right.denominator * left.numerator <= left.denominator * right.numerator);
   }






   //Overloaded == (equal to) operator for comparing fraction and integar objects
   bool operator==(const Fraction& left, const Fraction& right)
   {
      return (right.denominator * left.numerator == left.denominator * right.numerator);
   }






   //Overloaded != (not equal to) operator for comparing fraction and integar objects
   bool operator!=(const Fraction& left, const Fraction& right)
   {
      return (right.denominator * left.numerator != left.denominator * right.numerator);
   }






   //Overloaded addition operator for addition of either two fraction objects
   //or one fraction object and one integar object
   Fraction operator+(const Fraction &left, const Fraction &right)
   {
      //local Fraction object used to add two other Fraction objects
      Fraction answer;

      answer.numerator = (left.numerator * right.denominator) +
         (left.denominator * right.numerator);
      answer.denominator= (left.denominator * right.denominator);
      answer.simplify();
      return answer;
   }






   //Overloaded subtraction operator for subtraction of either two fraction objects
   //or one fraction object and one integar object
   Fraction operator-(const Fraction &left, const Fraction &right)
   {
      //local Fraction object used to subtract two other Fraction objects
      Fraction answer;

      answer.numerator = (left.numerator * right.denominator) -
         (left.denominator * right.numerator);
      answer.denominator= (left.denominator * right.denominator);
      answer.simplify();
      return answer;
   }






   //Overloaded mutliplication operator for multiplication of either two fraction objects
   //or one fraction object and one integar object
   Fraction operator*(const Fraction &left, const Fraction &right)
   {
      //local Fraction object used to multiply two other Fraction objects
      Fraction answer;

      answer.numerator = left.numerator * right.numerator;
      answer.denominator = left.denominator * right.denominator;
      answer.simplify();
      return answer;
   }






   //Overloaded division operator for division of either two fraction objects
   //or one fraction object and one integar object
   Fraction operator/(const Fraction &left, const Fraction &right)
   {
      //local Fraction object used to divide two other Fraction objects
      Fraction answer;

      answer.numerator = left.numerator * right.denominator;
      answer.denominator = left.denominator * right.numerator;
      answer.simplify();
      return answer;
   }





   //Overloaded pre-increment operator for adding one to the fraction value
   //and returning the updated fraction value
   Fraction Fraction::operator++()
   {
      numerator += denominator;
      return *this;
   }





   //Overloaded post-increment operator for adding one to the fraction value
   //and returning the original fraction value
   Fraction Fraction::operator++(int)
   {
      //local Fraction object used to ouput the orignal value of the calling object
      Fraction tempFract(numerator, denominator);

      numerator += denominator;
      return tempFract;
   }





   //Overloaded pre-decrement operator for subtracting one from the fraction value
   //and returning the updated fraction value
   Fraction Fraction::operator--()
   {
      numerator -= denominator;
      return *this;
   }





   //Overloaded post-decrement operator for subtracting one from the fraction value
   //and returning the original fraction value
   Fraction Fraction::operator--(int)
   {
      //local Fraction object used to print the orignal value of the calling object
      Fraction tempFract(numerator, denominator);

      numerator -= denominator;
      return tempFract;
   }






   //overloaded addition operator using a single input parameter. Function allows
   //for addition of another Fraction or of an integar
   Fraction Fraction::operator+=(const Fraction& rightFract)
   {
      *this = *this + rightFract;
      simplify();
      return *this;
   }






   //overloaded subtraction operator using a single input parameter. Function allows
   //for subtraction of another Fraction or of an integar
   Fraction Fraction::operator-=(const Fraction& rightFract)
   {
      *this = *this - rightFract;
      simplify();
      return *this;
   }






   //overloaded multiplication operator using a single input parameter. Function allows
   //for multiplication of another Fraction or of an integar
   Fraction Fraction::operator*=(const Fraction& rightFract)
   {
      *this = *this * rightFract;
      return *this;
   }






   //overloaded division operator using a single input parameter. Function allows
   //for division of another Fraction or of an integar
   Fraction Fraction::operator/=(const Fraction& rightFract)
   {
      *this = *this / rightFract;
      return *this;
   }





   //Overloaded stream insertion operator for output of fractions.
   //Function allows for output of whole numbers, mixed fractions or
   //reduced fractions
   ostream& operator<<(ostream& out, const Fraction& rightFract)
   {
      //whole: An integar value that results from division. It is the number of times
      //the denominator can go into the numerator
      //remainder: An integar value that results from division. It is the quantity
      //remainding after the numerator is divided by the denominator
      int whole, remainder;

      whole = rightFract.numerator / rightFract.denominator;
      remainder = abs(rightFract.numerator % rightFract.denominator);

      if ((whole != 0) && (remainder == 0))
      {
         cout << whole;
      }
      else if ((whole != 0) && (remainder != 0))
      {
         cout << whole << "+" << remainder << "/" << rightFract.denominator;
      }
      else if ((whole == 0) && (remainder == 0))
      {
         cout << rightFract.numerator;
      }
      else
      {
         cout << rightFract.numerator << "/" << rightFract.denominator;
      }

      return out;
   }






   //Overloaded stream extraction operator for input of fractions.
   //Function allows for input of whole numbers, mixed fractions, or
   //reduced fractions and saves them into Fraction object in a reduced format
   istream& operator>>(istream& in,  Fraction& rightFract)
   {
      //temp: the storage variable for read streams
      //whole: the whole number in mixed fraction numbers
      //numer: the numerator of a read fraction
      int temp, whole, numer;

      in >> temp;
      if (in.peek() == '+')
      {
         whole = temp;
         in.ignore();
         in >> numer;
         in.ignore();
         in >> rightFract.denominator;
         if (whole < 0)
            rightFract.numerator = (whole * rightFract.denominator) - numer;
         else
            rightFract.numerator = (whole * rightFract.denominator) + numer;
      }
      else if (in.peek() == '/')
      {
         numer = temp;
         in.ignore();
         in >> rightFract.denominator;
         rightFract.numerator = numer;
      }
      else
      {
         rightFract.numerator = temp;
      }

      rightFract.simplify();

      return in;
   }





   //Member function that reduces fractions by looking for commond denominators
   //between the numerator and denominator. Once the numerator and denominator
   //can no longer be divided by integars 9-2 without resulting an a remainder,
   //the function ends.
   void Fraction::simplify()
   {
      bool notSimplified = true;
      int k;

      if (denominator < 0)
      {
         denominator *= -1;
         numerator *= -1;
      }
      while (notSimplified)
      {
         for (k=9; k > 1; k--)
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
}






/*----------------- Connor's Program Output -----------------

 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10
 Fraction [3] = -4
 Fraction [4] = 0
 Fraction [5] = 4+2/3
 Fraction [6] = 0

 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6
 Read Fraction = 5
 Read Fraction = -8
 Read Fraction = 1+2/5
 Read Fraction = -16+2/3
 Read Fraction = 1+1/4
 Read Fraction = 2
 Read Fraction = -4+1/4
 Read Fraction = -10+5/6

 ----- Testing relational operators between Fractions
 Comparing 1/2 to 1/2
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false
 Comparing 1/2 to -1/2
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing -1/2 to 1/10
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing 1/10 to 0
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing 0 to 0
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false

 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing -3 to 1/4
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true

 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4

 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6

 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2

 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3

 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3
 Program ended with exit code: 0
 
------------------------ End  ------------------------*/



