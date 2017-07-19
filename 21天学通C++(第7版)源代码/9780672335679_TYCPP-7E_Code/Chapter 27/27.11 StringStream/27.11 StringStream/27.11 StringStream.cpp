#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

int main()
{
   cout << "Enter an integer: ";
   int Input = 0;
   cin >> Input;

   stringstream converterStream;
   converterStream << Input; 
   string strInput;
   converterStream >> strInput;

   cout << "Integer Input = " << Input << endl;
   cout << "String gained from integer, strInput = " << strInput << endl;

   stringstream anotherStream;
   anotherStream << strInput;
   int Copy = 0;
   anotherStream >> Copy;

   cout << "Integer gained from string, Copy = " << Copy << endl;
   
   return 0;
}