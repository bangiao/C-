#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
   vector<int> vecNums;
   vecNums.push_back(25);
   vecNums.push_back(101);
   vecNums.push_back(2011);
   vecNums.push_back(-50);

   auto iEvenNum = find_if( vecNums.cbegin()
                          , vecNums.cend()  // range to find in
                          , [](const int& Num){return ((Num % 2) == 0); } );

   if (iEvenNum != vecNums.cend())
	   cout << "Even number in collection is: " << *iEvenNum << endl;

   return 0;
}