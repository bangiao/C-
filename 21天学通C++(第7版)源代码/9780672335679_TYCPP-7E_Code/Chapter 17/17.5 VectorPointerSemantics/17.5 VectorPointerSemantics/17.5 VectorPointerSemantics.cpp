#include <iostream>
#include <vector>

int main ()
{
   using namespace std;
   vector <int> vecIntegers;

   // Insert sample integers into the vector:
   vecIntegers.push_back (50);
   vecIntegers.push_back (1);
   vecIntegers.push_back (987);
   vecIntegers.push_back (1001);

   // Access objects in a vector using iterators:
   vector <int>::iterator iElementLocator = vecIntegers.begin ();
   // iterator declared using C++11 keyword auto (uncomment next line)
   // auto iElementLocator = vecIntegers.begin (); 

   while (iElementLocator != vecIntegers.end ())
   {
      size_t Index = distance (vecIntegers.begin (), 
         iElementLocator);

      cout << "Element at position ";
      cout << Index << " is: " << *iElementLocator << endl;

      // move to the next element
      ++ iElementLocator;
   }

   return 0;
}