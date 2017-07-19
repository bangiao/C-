#include <algorithm>
#include <vector>
#include <iostream>

int main ()
{
   using namespace std;

   // Initialize a sample vector with 3 elements
   vector <int> vecIntegers (3);

   // fill all elements in the container with value 9
   fill (vecIntegers.begin (), vecIntegers.end (), 9);

   // Increase the size of the vector to hold 6 elements
   vecIntegers.resize (6);

   // Fill the three elements starting at offset position 3 with value -9
   fill_n (vecIntegers.begin () + 3, 3, -9);

   cout << "Contents of the vector are: " << endl;
   for (size_t nIndex = 0; nIndex < vecIntegers.size (); ++ nIndex)
   {
      cout << "Element [" << nIndex << "] = ";
      cout << vecIntegers [nIndex] << endl; 
   }

   return 0;
}
