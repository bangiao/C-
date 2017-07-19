#include <iostream>
using namespace std;

int main()
{
   // uninitialized pointer (bad)
   int* pTemperature; 

   cout << "Is it sunny (y/n)? ";
   char UserInput = 'y';
   cin >> UserInput;

   if (UserInput == 'y')
   {
      pTemperature = new int;
      *pTemperature = 30;
   }

   // pTemperature contains invalid value if user entered 'n'
   cout << "Temperature is: " << *pTemperature << endl;

   // delete also being invoked for those cases new wasn't done
   delete pTemperature;

   return 0;
}