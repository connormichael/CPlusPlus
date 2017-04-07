#include <iostream>
using namespace std;

// class Rectangle prototype ---------------
class Rectangle
{
   // member data for the class -- some private
   // and some public
private:
   double width, height;

public:
   char label;

   // all the methods are going to be public
   // first a static method
   static Rectangle whichIsBigger(Rectangle r1, Rectangle r2);

   // then instance methods
   bool setWidthHeight(double width, double height);
   double getWidth();
   double getHeight();
   double getArea();
   double getPerimeter();
   void showAllData();
};

// main method ---------------------------------
int  main()
{
   Rectangle r1, r2, r3;

   // create a new rectangle, r1, with dimensions 5 x 8
   r1.label = 'a';
   r1.setWidthHeight(5, 8);
   r1.showAllData();
   cout << "Rectangle with label " << r1.label
   << " has area " << r1.getArea()
   << " and perimeter " << r1.getPerimeter() << endl;

   // create a new rectangle, r2, with dimensions 6 x 6
   // based on r1's dimensions:
   r2.label = 'b';
   r2.setWidthHeight( r1.getWidth()+1, r1.getHeight()-2);
   r2.showAllData();
   cout << "Rectangle with label " << r2.label
   << " has area " << r2.getArea()
   << " and perimeter " << r2.getPerimeter() << endl;

   // find out which is bigger - result copied to r3:
   r3 = Rectangle::whichIsBigger(r1, r2);
   cout << "Rectangle with label " << r3.label
   << " is larger, having area " << r3.getArea() << endl;

   // finally, a demonstration of how to use the bool return value
   if ( ! r3.setWidthHeight(-3, 40) )
      cout << "ERROR in setWidthHeight()!\n";
   else
      cout << "OK Return setWidthHeight()!\n";

   if ( ! r3.setWidthHeight(21, 40) )
      cout << "ERROR in setWidthHeight()!\n";
   else
      cout << "OK Return setWidthHeight()!\n";

   return 0;
}
// -------  Rectangle Method Definitions --------------

Rectangle  Rectangle::whichIsBigger(Rectangle r1, Rectangle r2)
{
   if ( r1.width * r1.height > r2.width * r2.height )
      return r1;
   else
      return r2;
}

bool Rectangle::setWidthHeight(double width, double height)
{
   if ( width<=0 || height<=0 )
   {
      // no negatives
      return false;
   }
   this->width = width;
   this->height = height;
   return true;
}

double Rectangle::getWidth()
{
   return width;
}

double Rectangle::getHeight()
{
   return height;
}

double Rectangle::getArea()
{
   return width*height;
}

double Rectangle::getPerimeter()
{
   return 2*(width + height);
}

void Rectangle::showAllData()
{
   cout << "Label=" << label << " Width="
   << width << " Height=" << height << endl;
}

