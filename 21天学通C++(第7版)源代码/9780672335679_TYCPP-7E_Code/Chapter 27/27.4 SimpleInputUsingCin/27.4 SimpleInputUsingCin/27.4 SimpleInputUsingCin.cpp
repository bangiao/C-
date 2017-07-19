#include<iostream>
using namespace std;

int main()
{
   cout << "Enter an integer: ";
   int InputInt = 0;
   cin >> InputInt;

   cout << "Enter the value of Pi: ";
   double Pi = 0.0;
   cin >> Pi;

   cout << "Enter three characters separated by space: " << endl;
   char Char1 = '\0', Char2 = '\0', Char3 = '\0';
   cin >> Char1 >> Char2 >> Char3;

   cout << "The recorded variable values are: " << endl;
   cout << "InputInt: " << InputInt << endl;
   cout << "Pi: " << Pi << endl;
   cout << "The three characters: " << Char1 << Char2 << Char3 << endl;

   return 0;
}