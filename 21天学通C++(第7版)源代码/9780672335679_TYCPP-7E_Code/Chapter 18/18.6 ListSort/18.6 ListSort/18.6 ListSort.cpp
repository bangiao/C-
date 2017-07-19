#include <list>
#include <iostream>
using namespace std;

bool SortPredicate_Descending (const int& lsh, const int& rsh)
{
   // define criteria for list::sort: return true for desired order
   return (lsh > rsh);  
}

template <typename T>
void DisplayContents (const T& Input)
{
   for(auto iElement = Input.cbegin() // auto, cbegin and cend: c++11 
      ; iElement != Input.cend ()
      ; ++ iElement )
      cout << *iElement << ' ';

   cout << endl;
}

int main ()
{
   list <int> listIntegers;

   // Insert elements at the beginning and end
   listIntegers.push_front (444);
   listIntegers.push_front (2011);
   listIntegers.push_front (-1);
   listIntegers.push_front (0);
   listIntegers.push_back (-5);

   cout << "Initial contents of the list are - " << endl;
   DisplayContents (listIntegers);

   listIntegers.sort ();

   cout << "Order of elements after sort():" << endl;
   DisplayContents (listIntegers);

   listIntegers.sort (SortPredicate_Descending);
   cout << "Order of elements after sort() with a predicate:" << endl;

   DisplayContents (listIntegers);

   return 0;
}