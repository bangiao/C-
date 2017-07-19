#include<iostream>
#include<string>
using namespace std;

int main()
{
   cout << "Enter a line: " << endl;
   char CStyleStr[10] = {0};
   cin.get(CStyleStr, 10);
   cout << "CStyleStr: " << CStyleStr << endl;

   return 0;
}