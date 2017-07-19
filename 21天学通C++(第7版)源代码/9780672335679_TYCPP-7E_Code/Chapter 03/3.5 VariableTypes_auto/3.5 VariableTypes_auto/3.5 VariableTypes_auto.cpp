#include <iostream>
using namespace std;

int main()
{
   auto Flag = true;
   auto Number = 2500000000000;

   cout << "Flag = " << Flag;
   cout << " , sizeof(Flag) = " << sizeof(Flag) << endl;
   cout << "Number = " << Number;
   cout << " , sizeof(Number) = " << sizeof(Number) << endl;

   return 0;
}

/* auto with vectors
#include <vector>

int main()
{
   auto Flag = true;
   auto Number = 2500000000000;

   cout << "Flag = " << Flag;
   cout << " , sizeof(Flag) = " << sizeof(Flag) << endl;
   cout << "Number = " << Number;
   cout << " , sizeof(Number) = " << sizeof(Number) << endl;

   vector<int> MyNumbers;
   MyNumbers.push_back(-45);
   MyNumbers.push_back(202);
   MyNumbers.push_back(0);
   MyNumbers.push_back(1000);

   cout << "Using older C++ style, elements are: " << endl;
   for( vector<int>::const_iterator Iterator = MyNumbers.begin();
        Iterator < MyNumbers.end(); 
        ++Iterator )
      cout << *Iterator << " ";

   cout << endl;

   cout << "Using auto to iterate, elements are: " << endl;
   for( auto Iterator = MyNumbers.begin(); 
        Iterator < MyNumbers.end(); 
        ++Iterator )
      cout << *Iterator << " ";

   cout << endl;

   return 0;
}
*/