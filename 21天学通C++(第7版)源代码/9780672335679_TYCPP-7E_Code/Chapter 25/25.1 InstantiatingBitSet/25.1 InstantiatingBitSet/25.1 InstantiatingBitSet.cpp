#include <bitset>
#include <iostream>
#include <string>

int main ()
{
   using namespace std;

   // instantiate a bitset object 
   bitset <4> fourBits;  // 4 bits initialized to 0000
   cout << "Initial contents of fourBits: " << fourBits << endl;

   bitset <5> fiveBits ("10101"); // 5 bits 10101
   cout << "Initial contents of fiveBits: " << fiveBits << endl;

   bitset <8> eightbits (255); // 8 bits initialized to long int 255
   cout << "Initial contents of eightBits: " << eightbits << endl;

   // instantiate one bitset as a copy of another
   bitset <8> eightBitsCopy(eightbits);

   return 0;
}