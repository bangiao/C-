#include <algorithm>
#include <vector>
#include <iostream>
using namespace std; 

int main ()
{
   vector <int> vecIntegers;
   cout << "The vector contains the following sample values: ";

   // Insert sample values: 25 - 31
   for (int nCount = 25; nCount < 32; ++ nCount)
   {
      vecIntegers.push_back (nCount);
      cout << nCount << ' ';
   }
   cout << endl << "Enter divisor (> 0): ";
   int Divisor = 2;
   cin >> Divisor;

   // Find the first element that is a multiple of divisor
   auto iElement = find_if ( vecIntegers.begin ()
                      , vecIntegers.end ()
                      , [Divisor](int dividend){return (dividend % Divisor) == 0; } );
                      // , [=](int dividend){return (dividend % Divisor) == 0; } );

   if (iElement != vecIntegers.end ())
   {
      cout << "First element in vector divisible by " << Divisor;
      cout << ": " << *iElement << endl;
   }

   return 0;
}