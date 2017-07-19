#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   cout << "Enter an integer: ";
   int Input = 0;
   cin >> Input;

   cout << "Integer in octal: " << oct << Input << endl;
   cout << "Integer in hexadecimal: " << hex << Input << endl;

   cout << "Integer in hex using base notation: ";
   cout << setiosflags(ios_base::hex|ios_base::showbase|ios_base::uppercase);
   cout << Input << endl;

   cout << "Integer after resetting I/O flags: ";
   cout << resetiosflags(ios_base::hex|ios_base::showbase|ios_base::uppercase);
   cout << Input << endl;
   
   return 0;
}