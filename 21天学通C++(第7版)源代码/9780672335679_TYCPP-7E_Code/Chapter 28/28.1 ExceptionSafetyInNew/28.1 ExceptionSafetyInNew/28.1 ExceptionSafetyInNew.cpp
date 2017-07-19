#include <iostream>
using namespace std;
   
int main()
{
   cout << "Enter number of integers you wish to reserve: ";
   try
   {
      int Input = 0;
      cin >> Input;

      // Request memory space and then return it
      int* pReservedInts = new int [Input];
      delete[] pReservedInts;  
   }
   catch (...)
   {
      cout << "Exception encountered. Got to end, sorry!" << endl;
   }
   return 0;
}