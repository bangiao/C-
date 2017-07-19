#include<iostream>
#include<string>
using namespace std;

template <typename Type>
const Type& GetMax (const Type& value1, const Type& value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

template <typename Type>
void DisplayComparison(const Type& value1, const Type& value2)
{
   cout << "GetMax(" << value1 << ", " << value2 << ") = ";
   cout << GetMax(value1, value2) << endl;
}

int main()
{
   int Int1 = -101, Int2 = 2011;
   DisplayComparison<int>(Int1, Int2);

   double d1 = 3.14, d2 = 3.1416;
   DisplayComparison(d1, d2);

   string Name1("Jack"), Name2("John");
   DisplayComparison(Name1, Name2);

   return 0;
}