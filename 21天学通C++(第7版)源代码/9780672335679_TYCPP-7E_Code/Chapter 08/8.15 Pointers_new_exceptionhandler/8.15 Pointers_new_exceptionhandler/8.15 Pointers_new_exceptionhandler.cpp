#include <iostream>
using namespace std;

// remove the try catch block to see this application crash disgracefully
int main()
{
   try
   {
      // Request lots of memory space 
      int* pAge = new int [0x1fffffff];

      // Use the allocated memory 

	  delete[] pAge;
   }
   catch (bad_alloc)
   {
      cout << "Memory allocation failed. Ending program" << endl;
   }
   return 0;
}