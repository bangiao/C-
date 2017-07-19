#include <iostream>
using namespace std;

int main()
{
   cout << "How many integers you wish to enter? ";
   int InputNums = 0;
   cin >> InputNums;

   int* pNumbers = new int [InputNums];
   int* pCopy = pNumbers;

   cout << "Successfully allocated memory for " << InputNums << " integers" << endl;
   for(int Index = 0; Index < InputNums; ++Index)
   {
      cout << "Enter number "<< Index << ": ";
      cin >> *(pNumbers + Index); 
   }

   cout << "Displaying all numbers input: " << endl;
   for(int Index = 0; Index < InputNums; ++Index)
      cout << *(pCopy++) << " ";

   cout << endl;

   // done with using the pointer? release memory
   delete[] pNumbers;

   return 0;
}