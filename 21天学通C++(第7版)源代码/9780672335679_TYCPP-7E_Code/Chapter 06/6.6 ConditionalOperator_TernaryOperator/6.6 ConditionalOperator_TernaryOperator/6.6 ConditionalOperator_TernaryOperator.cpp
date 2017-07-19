#include <iostream>
using namespace std;

int main()
{
   cout << "Enter two numbers" << endl;
   int Num1 = 0, Num2 = 0;
   cin >> Num1;
   cin >> Num2;

   // use a conditional operator ?:
   int Max = (Num1 > Num2)? Num1 : Num2;

   /* Similar to -
   int Max = 0;
   if (Num1 > Num2)
	   Max = Num1;
   else 
	   Max = Num2;
   */

   cout << "The greater of " << Num1 << " and " \
       << Num2 << " is: " << Max << endl; 
   
   return 0;
}