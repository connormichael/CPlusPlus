#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class MortgageData
{
private:
   double dblPrincipal;
   double dblRate;
   double dblYears;

public:
   // class constants
   static const double MIN_LOAN;
   static const double MAX_LOAN;
   static const double MIN_RATE;
   static const double MAX_RATE;
   static const double MIN_YRS;
   static const double MAX_YRS;

   // accessors
   bool setRate (double rt);
   double getRate();
   bool setPrincipal (double prin);
   double getPrincipal();
   bool setYears (double yrs);
   double getYears();

   // constructors
   MortgageData(double prin, double rt, double yr);
   MortgageData();
};

// static member intialization
double const MortgageData::MIN_LOAN = 1.;
double const MortgageData::MAX_LOAN = 100000000.;
double const MortgageData::MIN_RATE = .00001;
double const MortgageData::MAX_RATE = 25.;
double const MortgageData::MIN_YRS = 1;
double const MortgageData::MAX_YRS = 100;

// ordinary method prototypes
void stateInstructions();
void getInput(MortgageData &loan);
double computeMonthlyPayment(MortgageData loan);
void reportResults(double result);

// define the main method ---------------------

// the main method
int main()
{
   double answer;
   MortgageData loan;

   stateInstructions();
   getInput(loan);
   answer = computeMonthlyPayment(loan);
   reportResults(answer);

   getInput(loan);
   answer = computeMonthlyPayment(loan);
   reportResults(answer);

}


// stateInstructions method
void stateInstructions()
{
   string instructions;
   instructions =
   "\nThe following program will calculate the \n"
   "monthly payment  required for a loan of D dollars \n"
   "over a period of Y years at an annual \n"
   "interest rate of R%.\n";
   cout << instructions;
}

// getInput method
void getInput(MortgageData &userData)
{
   double dblResponse;

   cout.setf(ios::fixed);
   cout.precision(2);

   // get principal
   do
   {
      cout << "\nEnter amount of the loan. Only use numbers, \n"
      "please.  No commas or characters like '$'.\n"
      "Amount must be between " << MortgageData::MIN_LOAN
      << " and " << MortgageData::MAX_LOAN << ".\n"
      "Your loan amount: ";
      cin >> dblResponse;
   }
   while (!userData.setPrincipal(dblResponse));

   // get interest
   do
   {
      cout << "\nEnter the interest rate (If the quoted rate is 6.5%, \n"
      "for example, enter 6.5 without the %.)\n"
      "Rate must be between " << MortgageData::MIN_RATE
      << " and " << MortgageData::MAX_RATE << ".\n"
      "Your annual interest rate: ";
      cin >> dblResponse;
   }
   while (!userData.setRate(dblResponse));

   // get length of loan
   do
   {
      cout << "\nEnter term of the loan in years. \n"
      "Term must be between " << MortgageData::MIN_YRS
      <<  " and " << MortgageData::MAX_YRS << ".\n"
      "Term of Loan: ";
      cin >> dblResponse;
   }
   while (!userData.setYears(dblResponse));
}

// computeMonthlyPayment method
double computeMonthlyPayment(MortgageData loan)
{
   // local variabls needed only in this method
   double dblTemp, dblPmt, dblMonths, dblMoRt;

   // convert years to months
   dblMonths = loan.getYears() * 12;

   // convert rate to decimal and months
   dblMoRt = loan.getRate() / (100 * 12);

   // use formula to get result
   dblTemp = pow(1 + dblMoRt, dblMonths);
   dblPmt = loan.getPrincipal() * dblMoRt * dblTemp
   / ( dblTemp - 1 );

   // now that we have computed the payment, return it
   return dblPmt;
}


// reportResults method
void reportResults(double result)
{
   string signoff;
   signoff =
   "\nThanks for using the Foothill Mortgage Calculator. \n"
   "We hope you'll come back and see us again, soon.\n\n";

   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "Your Monthly Payment: " << result << endl;

   cout << signoff;
}

// define all MortgageData member methods ---------------------

// constructors
MortgageData::MortgageData()
{
   // default values (can assign directly if preferred)
   setPrincipal(MIN_LOAN);
   setRate(MIN_RATE);
   setYears(MIN_YRS);
}
MortgageData::MortgageData(double prin, double rt, double yr)
{
   if (!setPrincipal(prin))
      setPrincipal(MIN_LOAN);
   if (!setRate(rt))
      setRate(MIN_RATE);
   if (!setYears(yr))
      setYears(MIN_YRS);
}

// accessors
double MortgageData::getPrincipal()
{
   return dblPrincipal;
}
double MortgageData::getRate()
{
   return dblRate;
}
double MortgageData::getYears()
{
   return dblYears;
}

// mutators
bool MortgageData::setPrincipal (double prin)
{
   if (prin < MIN_LOAN || prin > MAX_LOAN)
      return false;
   dblPrincipal = prin;
   return true;
}
bool MortgageData::setRate (double rt)
{
   if (rt < MIN_RATE || rt > MAX_RATE)
      return false;
   dblRate = rt;
   return true;
}
bool MortgageData::setYears (double yr)
{
   if (yr < MIN_YRS || yr > MAX_YRS)
      return false;
   dblYears = yr;
   return true;
}