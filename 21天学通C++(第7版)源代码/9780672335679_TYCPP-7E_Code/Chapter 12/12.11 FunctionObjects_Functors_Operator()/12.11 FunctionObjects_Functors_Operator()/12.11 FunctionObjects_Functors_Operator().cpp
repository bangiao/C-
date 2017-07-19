#include <iostream>
#include <string>
using namespace std;

class CDisplay
{
public:
   void operator () (string Input) const
   {
      cout << Input << endl;
   }
};

int main ()
{
   CDisplay mDisplayFuncObject;

   // equivalent to mDisplayFuncObject.operator () ("Display this string!");
   mDisplayFuncObject ("Display this string!"); 

   return 0;
}