#include <list>
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

/*
// for non-C++11 compliant compilers
template <typename T>
void DisplayContents (const T& Input)
{
   for (T::const_iterator iElement = Input.begin () 
       ; iElement != Input.end ()
       ; ++ iElement )
       cout << *iElement << ' ';

   cout << endl;
}
*/

int main ()
{
   std::list <int> listIntegers;

   listIntegers.push_front (10);
   listIntegers.push_front (2011);
   listIntegers.push_back (-1);
   listIntegers.push_back (9999);

   DisplayContents(listIntegers);

   return 0;
}