#include <string>
#include <iostream>
using namespace std;


//class prototype
class Patient
{
private:
   string name;
   int id;
   double temperature;

public:
   //define some static constants
   static const int MIN_LENGTH = 2;
   static const int MAX_LENGTH = 40;
   static const int MIN_ID = 0;
   static const int MAX_ID = 9999;
   static const double MIN_TEMP;
   static const double MAX_TEMP;
   static const double ALARM_TEMP;
   static const string DEFAULT_NAME;
   static const int DEFAULT_ID = 0;
   static const int DEFAULT_TEMP = 98.6;


   //define construtor
   Patient();
   Patient(string name, int id, double temperature);


   //Here is the display method
   void display();

   //define the mutators and accesors
   bool setStringName(string name);
   string getStringName();
   bool setIdNumber(int id);
   int getIdNumber();
   bool setTemperature(double temperature);
   double getTemperature();
};

//alternative way to initilize a static (required for not const ints)
const double Patient::ALARM_TEMP = 103.5;
const double Patient::MIN_TEMP = 88.;
const double Patient::MAX_TEMP = 111.;
const string Patient::DEFAULT_NAME = "nobody";



//Here is the main()
int main()
{
   Patient patient1, patient2, patient3;

   patient1.setStringName("Fred");
   patient1.setIdNumber(1234);
   patient1.setTemperature(100.3);

   patient2.setStringName("Janis");
   patient2.setIdNumber(5555);
   patient2.setTemperature(103.7);

   patient1.display();
   patient2.display();
   patient3.display();

   return 0;


}

//Here is a rough default constructor
Patient::Patient()
{
   name = DEFAULT_NAME;
   id = DEFAULT_ID;
   temperature = DEFAULT_TEMP;
}

//Here is the parameter taking constructor
Patient::Patient(string name, int id, double temperature)
{
   if (!setStringName(name))
      setStringName(DEFAULT_NAME);
   if (!setIdNumber(id))
      setIdNumber(DEFAULT_ID);
   if (!setTemperature(temperature))
      setTemperature(DEFAULT_TEMP);
}


//Here is the display method definition
void Patient::display()
{
   cout << "\nThe patients name is: " << name
   << "\nthe patients ID number is: " << id
   << "\nthe patient's temperature is: " << temperature;
   if (temperature > ALARM_TEMP)
      cout << "\n *** urgent: attend immediately ***" << endl;
}


//Here are the mutator and accessor definitions
bool Patient::setStringName(string name)
{
   if (name.length() < MIN_LENGTH || name.length() > MAX_LENGTH)
      return false;
   else
      this->name = name;
   return true;
}

bool Patient::setIdNumber(int id)
{
   if (id < MIN_ID || id > MAX_ID)
      return false;
   else
      this->id = id;
   return true;
}

bool Patient::setTemperature(double temperature)
{
   if (temperature < MIN_TEMP || temperature > MAX_TEMP)
      return false;
      this->temperature = temperature;
   return true;
}

string Patient::getStringName()
{
   return name;
}

int Patient::getIdNumber()
{
   return id;
}

double Patient::getTemperature()
{
   return temperature;
}