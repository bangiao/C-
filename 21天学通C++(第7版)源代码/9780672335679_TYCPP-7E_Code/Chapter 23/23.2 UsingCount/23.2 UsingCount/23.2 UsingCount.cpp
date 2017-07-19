#include <algorithm>
#include <vector>
#include <iostream>

// A unary predicate for the *_if functions
template <typename elementType>
bool IsEven (const elementType& number)
{
   return ((number % 2) == 0); // true, if even
}

int main ()
{
   using namespace std;
   vector <int> vecIntegers;

   cout << "Populating a vector<int> with values from -9 to 9" << endl;
   for (int nNum = -9; nNum < 10; ++ nNum) 
      vecIntegers.push_back (nNum);

   // Use count to determine the number of '0's in the vector
   size_t nNumZeroes = count (vecIntegers.begin (),vecIntegers.end (),0);
   cout << "Number of instances of '0': " << nNumZeroes << endl << endl;

   // Use the count_if algorithm with the unary predicate IsEven:
   size_t nNumEvenElements = count_if (vecIntegers.begin (), 
      vecIntegers.end (), IsEven <int> );

   cout << "Number of even elements: " << nNumEvenElements << endl;
   cout << "Number of odd elements: ";
   cout << vecIntegers.size () - nNumEvenElements << endl;

   return 0;
}