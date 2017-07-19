// Declaring default paramter types, first as int and the second type as float
template <typename T1=int, typename T2=double>
class HoldsPair
{
private:
   T1 Value1;
   T2 Value2;
public:
   // Constructor that initializes member variables
   HoldsPair (const T1& value1, const T2& value2)
   {
      Value1 = value1;
      Value2 = value2;
   };

   // Accessor functions
   const T1 & GetFirstValue () const 
   {
      return Value1;
   };

   const T2& GetSecondValue () const
   {
      return Value2;
   };
};

#include <iostream>
using namespace std;

int main ()
{
   // Two instantiations of template HoldsPair -
   HoldsPair <> mIntFloatPair (300, 10.09);
   HoldsPair <short,char*> mShortStringPair(25, "Learn templates, love C++");

   // Output values contained in the first object...
   cout << "The first object contains -" << endl;
   cout << "Value 1: " << mIntFloatPair.GetFirstValue () <<  endl;
   cout << "Value 2: " << mIntFloatPair.GetSecondValue () << endl;

   // Output values contained in the second object...
   cout << "The second object contains -" << endl; 
   cout << "Value 1: " << mShortStringPair.GetFirstValue () <<  endl;
   cout << "Value 2: " << mShortStringPair.GetSecondValue () << endl;

   return 0;
}
