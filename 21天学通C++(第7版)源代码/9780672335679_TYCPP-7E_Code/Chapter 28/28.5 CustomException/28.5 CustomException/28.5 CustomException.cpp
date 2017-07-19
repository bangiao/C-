#include <exception>
#include <iostream>
#include <string>
using namespace std;

class CustomException: public std::exception
{
   string Reason;
public:
   // constructor, needs reason
   CustomException(const char* why):Reason(why) {}

   // redefining virtual function to return 'Reason'
   virtual const char* what() const throw()
   {
	   throw 10;
      return Reason.c_str(); 
   }
};

double Divide(double Dividend, double Divisor)
{
   if(Divisor == 0)
      throw CustomException("CustomException: Dividing by 0 is a crime");

   return (Dividend / Divisor);
}

int main()
{
   cout << "Enter dividend: ";
   double Dividend = 0;
   cin >> Dividend;
   cout << "Enter divisor: ";
   double Divisor = 0;
   cin >> Divisor;
   try
   {
      cout << "Result of division is: " << Divide(Dividend, Divisor);
   }
   catch(exception& exp)// catch CustomException, bad_alloc, etc
   {
      cout << exp.what() << endl;
      cout << "Sorry, can't continue!" << endl;
   }

   return 0;
}