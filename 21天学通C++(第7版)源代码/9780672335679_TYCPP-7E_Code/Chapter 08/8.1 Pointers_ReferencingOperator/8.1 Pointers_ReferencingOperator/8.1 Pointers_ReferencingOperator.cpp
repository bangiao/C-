#include <iostream>
using namespace std;

int main()
{
   int Age = 30;
   const double Pi = 3.1416;

   // Use & to find the address in memory
   cout << "Integer Age is located at: 0x" << hex << &Age << endl;
   cout << "Double Pi is located at: 0x" << hex << &Pi << endl;

   return 0;
}