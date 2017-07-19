#include <iostream>
#include <vector>

int main ()
{
   using namespace std;
   vector <int> vecIntegerArray;

   // Insert sample integers into the vector:
   vecIntegerArray.push_back (50);
   vecIntegerArray.push_back (1);
   vecIntegerArray.push_back (987);
   vecIntegerArray.push_back (1001);

   for (size_t Index = 0; Index < vecIntegerArray.size (); ++Index)
   {
      cout << "Element[" << Index << "] = " ;
      cout << vecIntegerArray[Index] << endl;
   }
   
   // changing 3rd integer from 987 to 2011
   vecIntegerArray[2] = 2011;
   cout << "After replacement: " << endl;
   cout << "Element[2] = " << vecIntegerArray[2] << endl;

   return 0;
}