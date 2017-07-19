#include <set>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents (const T& Input)
{
   for(auto iElement = Input.cbegin() // auto, cbegin and cend: c++11 
      ; iElement != Input.cend()
      ; ++ iElement )
      cout << *iElement << ' ';

   cout << endl;
}

typedef multiset <int> MSETINT;

int main ()
{
   MSETINT msetIntegers;

   // Insert some random values
   msetIntegers.insert (43);
   msetIntegers.insert (78);
   msetIntegers.insert (78);    // Duplicate
   msetIntegers.insert (-1);
   msetIntegers.insert (124);

   cout << "multiset contains " << msetIntegers.size () << " elements.";
   cout << " These are: " << endl;

   // Write contents of the multiset to the screen
   DisplayContents(msetIntegers);

   cout << "Please enter a number to be erased from the set" << endl;
   int nNumberToErase = 0;
   cin >> nNumberToErase;

   cout << "Erasing " << msetIntegers.count (nNumberToErase);
   cout << " instances of value " << nNumberToErase << endl;

   // Try finding an element
   msetIntegers.erase (nNumberToErase);

   cout << "multiset contains " << msetIntegers.size () << " elements.";
   cout << " These are: " << endl;
   DisplayContents(msetIntegers);

   return 0;
}