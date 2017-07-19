#include <iostream>
using namespace std;

int main()
{
   // Request for memory space for an int
   int* pAge = new int;

   // Use the allocated memory to store a number
   cout << "Enter your dog's age: ";
   cin >> *pAge;

   // use indirection operator* to access value 
   cout << "Age " << *pAge << " is stored at 0x" << hex << pAge << endl;

   delete pAge; // release dynamically allocated memory

   return 0;
}