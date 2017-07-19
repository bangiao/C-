#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Unary function object type invoked by for_each
template <typename elementType>
struct DisplayElementKeepCount
{
   int Count;

   // Constructor
   DisplayElementKeepCount (): Count (0) {}

   void operator () (const elementType& element) 
   {
      ++ Count;
      cout << element << ' ';
   }
};

int main ()
{
   vector <int> vecIntegers;
   for (int nCount = 0; nCount < 10; ++ nCount)
      vecIntegers.push_back (nCount);

   cout << "Displaying the vector of integers: " << endl;

   // Display the array of integers
   DisplayElementKeepCount<int> Functor =
      for_each ( vecIntegers.begin ()   // Start of range
             , vecIntegers.end ()      // End of range
             , DisplayElementKeepCount<int> () );// Functor

   cout << endl;

   // Use the state stored in the return value of for_each!
   cout << "'" << Functor.Count << "' elements were displayed" << endl;

   string Sample ("for_each and strings!");
   cout << "String: " << Sample << ", length: " << Sample.length() << endl;

   cout << "String displayed using lambda:" << endl;
   int NumChars = 0;
   for_each ( Sample.begin()
            , Sample.end ()
            , [&NumChars](char c) { cout << c << ' '; ++NumChars; } );

   cout << endl; 
   cout << "'" << NumChars << "' characters were displayed" << endl;

   return 0;
}