#include <iostream>
using namespace std;
const double Pi = 3.14159265;

void QueryAndCalculate()
{
   cout << "Enter radius: ";
   double Radius = 0;
   cin >> Radius;

   cout << "Area: " << Pi * Radius * Radius << endl;

   cout << "Do you wish to calculate circumference (y/n)? ";
   char CalcCircum = 'n';
   cin >> CalcCircum;

   if (CalcCircum == 'y')   
	   cout << "Circumference: " << 2 * Pi * Radius << endl;
   return;
}

int main() 
{
   QueryAndCalculate ();

   return 0;
}