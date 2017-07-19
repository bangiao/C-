#include <iostream>
#include<exception>
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
   catch (std::bad_alloc& exp)
   {
      cout << "Exception encountered: " << exp.what() << endl;
      cout << "Got to end, sorry!" << endl;
   }
   catch(...)
   {
      cout << "Exception encountered. Got to end, sorry!" << endl;
   }
   return 0;
}