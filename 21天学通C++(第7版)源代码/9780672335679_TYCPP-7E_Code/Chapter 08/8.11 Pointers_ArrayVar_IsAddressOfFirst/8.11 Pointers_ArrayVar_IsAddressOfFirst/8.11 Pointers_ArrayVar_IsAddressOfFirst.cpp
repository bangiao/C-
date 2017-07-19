#include <iostream>
using namespace std;

int main()
{
   // Static array of 5 integers
   int MyNumbers[5];

   // Pointer initialized to array
   int* pNumbers = MyNumbers;

   // Display address contained in pointer
   cout << "pNumbers = 0x" << hex << pNumbers << endl;

   // Address of first element of array
   cout << "&MyNumbers[0] = 0x" << hex << &MyNumbers[0] << endl;

   return 0;
}