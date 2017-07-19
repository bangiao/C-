#include <iostream>
using namespace std;

struct StructA
{
   StructA() {cout << "Constructed a struct A" << endl; }
   ~StructA() {cout << "Destroyed a struct A" << endl;  }
};

struct StructB
{
   StructB() {cout << "Constructed a struct B" << endl; }
   ~StructB() {cout << "Destroyed a struct B" << endl; }
};

void FuncB()  // throws
{
      cout << "In Func B" << endl;
      StructA objA;
      StructB objB;
      cout << "About to throw up!" << endl;
      throw "Throwing for the heck of it";
}

void FuncA()
{
   try
   {
      cout << "In Func A" << endl;
      StructA objA;
      StructB objB;
      FuncB();
	  cout << "FuncA: returning to caller" << endl;
   }
   catch(const char* exp)
   {
      cout << "FuncA: Caught exception, it says: " << exp << endl;
	  cout << "FuncA: Handled it here, will not throw to caller" << endl;
	  // throw;  // uncomment this line to throw to main()
   }
}

int main()
{
   cout << "main(): Started execution" << endl;
   try
   {
      FuncA();
   }
   catch(const char* exp)
   {
      cout << "main(), Exception: " << exp << endl;
   }
   cout << "main(): exiting gracefully" << endl;
   return 0;
}