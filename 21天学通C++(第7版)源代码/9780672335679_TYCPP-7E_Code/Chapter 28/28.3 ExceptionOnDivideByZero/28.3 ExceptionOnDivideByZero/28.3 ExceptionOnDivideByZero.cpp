#include<iostream>
using namespace std;

double Divide(double Dividend, double Divisor)
{
   if(Divisor == 0)
      throw "Dividing by 0 is a crime";

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
   catch(char* exp)
   {
      cout << "Exception: " << exp << endl;
      cout << "Sorry, can't continue!" << endl;
   }

   return 0;
}