#include <list>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
   for(auto iElement = Input.cbegin() // auto, cbegin: c++11 
      ; iElement != Input.cend()  // cend() is new in C++11 
      ; ++ iElement )
     cout << *iElement << ' ';

   cout << endl;
}

int main()
{
   std::list <int> listIntegers;

   // Insert elements at the beginning and end...
   listIntegers.push_back(4);
   listIntegers.push_front(3);
   listIntegers.push_back(5);

   // Store an iterator obtained in using the 'insert' function
   auto iValue2 = listIntegers.insert(listIntegers.begin(), 2);

   cout << "Initial contents of the list:" << endl;
   DisplayContents(listIntegers);

   listIntegers.erase(listIntegers.begin(), iValue2);
   cout << "Contents after erasing a range of elements:" << endl;
   DisplayContents(listIntegers);

   cout << "After erasing element '"<< *iValue2 << "':" << endl;
   listIntegers.erase(iValue2);
   DisplayContents(listIntegers);

   listIntegers.erase(listIntegers.begin(), listIntegers.end());
   cout << "Number of elements after erasing range: ";
   cout << listIntegers.size() << endl;

   return 0;
}