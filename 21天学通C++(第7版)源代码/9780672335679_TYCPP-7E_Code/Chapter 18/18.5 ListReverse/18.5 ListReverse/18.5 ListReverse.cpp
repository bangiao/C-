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

   // Insert elements at the beginning and end
   listIntegers.push_front(4);
   listIntegers.push_front(3);
   listIntegers.push_front(2);
   listIntegers.push_front(1);
   listIntegers.push_front(0);
   listIntegers.push_back(5);

   cout << "Initial contents of the list:" << endl;
   DisplayContents(listIntegers);

   listIntegers.reverse();

   cout << "Contents of the list after using reverse():" << endl;
   DisplayContents(listIntegers);

   return 0; 
}