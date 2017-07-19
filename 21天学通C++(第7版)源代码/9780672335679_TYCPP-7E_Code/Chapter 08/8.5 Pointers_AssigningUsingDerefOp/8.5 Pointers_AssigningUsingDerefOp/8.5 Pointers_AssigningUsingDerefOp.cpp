#include <iostream>
using namespace std;

int main()
{
   int DogsAge = 30;
   cout << "Initialized DogsAge = " << DogsAge << endl;

   int* pAge = &DogsAge;
   cout << "pAge points to DogsAge" << endl;

   cout << "Enter an age for your dog: ";

   // store input at the memory pointed to by pAge
   cin >> *pAge;  

   // Displaying the address where age is stored
   cout << "Input stored using pAge at 0x" << hex << pAge << endl;

   cout << "Integer DogsAge = " << dec << DogsAge << endl;

   return 0;
}