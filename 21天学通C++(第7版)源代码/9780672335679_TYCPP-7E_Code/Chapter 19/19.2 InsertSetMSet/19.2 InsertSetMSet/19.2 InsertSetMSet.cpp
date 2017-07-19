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

int main ()
{
   set <int> setIntegers;
   multiset <int> msetIntegers;

   setIntegers.insert (60);
   setIntegers.insert (-1);
   setIntegers.insert (3000);
   cout << "Writing the contents of the set to the screen" << endl;
   DisplayContents (setIntegers);

   msetIntegers.insert (setIntegers.begin (), setIntegers.end ());
   msetIntegers.insert (3000);

   cout << "Writing the contents of the multiset to the screen" << endl;
   DisplayContents (msetIntegers);

   cout << "Number of instances of '3000' in the multiset are: '";
   cout << msetIntegers.count (3000) << "'" << endl; 

   return 0;
}
