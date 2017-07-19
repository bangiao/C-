#include<iostream>
#include<string>
using namespace std;

int main()
{
   cout << "Enter your name: ";
   string Name;
   getline(cin, Name);
   cout << "Hi " << Name << endl;

   return 0;
}