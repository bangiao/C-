#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

template<typename elementType>
struct DisplayElementKeepCount
{
   int Count;

   // Constructor
   DisplayElementKeepCount() : Count(0) {}

   // Display the element, hold count!
   void operator()(const elementType& element)
   {
      ++ Count;
      cout << element<< ' ';
   }
};

int main()
{
   vector<int> vecIntegers;
   for(int nCount = 0; nCount< 10; ++ nCount)
      vecIntegers.push_back(nCount);

   cout << "Displaying the vector of integers: "<< endl; 

   // Display the array of integers
   DisplayElementKeepCount<int> Result;
   Result = for_each( vecIntegers.begin()   // Start of range
                     , vecIntegers.end()        // End of range
                     , DisplayElementKeepCount<int>() );// function object

   cout << endl<< endl;

   // Use the state stores in the return value of for_each!
   cout << "'"<< Result.Count<< "' elements were displayed!"<< endl;

   return 0;
}