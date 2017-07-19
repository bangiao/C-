#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
   for ( auto iElement = Input.cbegin() // auto, cbegin: c++11
        ; iElement != Input.cend()  // cend() is new in C++11 
        ; ++ iElement) 
      cout << *iElement << ' ';

   cout << "| Number of elements: " << Input.size() << endl;
}

int main ()
{
   vector <int> vecIntegers (6);

   // fill first 3 elements with value 8, last 3 with 5
   fill (vecIntegers.begin (), vecIntegers.begin () + 3, 8);
   fill_n (vecIntegers.begin () + 3, 3, 5);

   // shuffle the container
   random_shuffle (vecIntegers.begin (), vecIntegers.end ());
   
   cout << "The initial contents of the vector are: " << endl;
   DisplayContents(vecIntegers);

   cout << endl << "Using 'std::replace' to replace value 5 by 8" << endl;
   replace (vecIntegers.begin (), vecIntegers.end (), 5, 8);

   cout << "Using 'std::replace_if' to replace even values by -1" << endl;
   replace_if (vecIntegers.begin (), vecIntegers.end ()
	   , [](int element) {return ((element % 2) == 0); }, -1);

   cout << endl << "Contents of the vector after replacements:" << endl;
   DisplayContents(vecIntegers);

   return 0;
}