#include <algorithm>
#include <string>
using namespace std;

class CompareStringNoCase
{
public:
   bool operator () (const string& str1, const string& str2) const
   {
     string str1LowerCase;

     // Assign space
     str1LowerCase.resize (str1.size ());

     // Convert every character to the lower case
     transform (str1.begin (), str1.end (), str1LowerCase.begin (), tolower);

     string str2LowerCase;
     str2LowerCase.resize (str2.size ());
     transform (str2.begin (), str2.end (), str2LowerCase.begin (), 
     tolower);

     return (str1LowerCase < str2LowerCase);
   }
};

#include <vector>
#include <iostream>

template <typename T>
void DisplayContents (const T& Input)
{
   for(auto iElement = Input.cbegin() // auto, cbegin and cend: c++11 
      ; iElement != Input.cend ()
      ; ++ iElement )
      cout << *iElement << endl;
}

int main ()
{
   // Define a vector of string to hold names
   vector <string> vecNames;

   // Insert some sample names in to the vector
   vecNames.push_back ("jim");
   vecNames.push_back ("Jack");
   vecNames.push_back ("Sam");
   vecNames.push_back ("Anna");

   cout << "The names in vector in order of insertion: " << endl;
   DisplayContents(vecNames);

   cout << "Names after sorting using default std::less<>: " << endl;
   sort(vecNames.begin(), vecNames.end());
   DisplayContents(vecNames);

   cout << "Names after sorting using predicate that ignores case:" << endl;
   sort(vecNames.begin(), vecNames.end(), CompareStringNoCase());
   DisplayContents(vecNames);
   
   return 0;
}