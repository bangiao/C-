// A structure as a unary predicate
template <typename numberType>
struct IsMultiple
{
   numberType Divisor;

   IsMultiple (const numberType& divisor)
   {
      Divisor = divisor;
   }

   bool operator () (const numberType& element) const
   {
      // Check if the dividend is a multiple of the divisor
      return ((element % Divisor) == 0);
   }
};

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

   // Find the first element that is a multiple of 4 in the collection
   auto iElement = find_if ( vecIntegers.begin ()
                      , vecIntegers.end ()
					  , IsMultiple<int>(Divisor) );  // replace this line by next: lambda version
					  // , [](int divisor){return (divisor % 4) == 0; } );  // lambda version

   if (iElement != vecIntegers.end ())
   {
      cout << "First element in vector divisible by " << Divisor;
      cout << ": " << *iElement << endl;
    }

   return 0;
}