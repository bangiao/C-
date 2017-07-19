#include <map>
#include <iostream>
#include<string>

using namespace std;

// Type-define the map and multimap definition for easy readability
typedef map <int, string> MAP_INT_STRING;
typedef multimap <int, string> MMAP_INT_STRING;

template <typename T>
void DisplayContents (const T& Input)
{
   for(auto iElement = Input.cbegin() // auto, cbegin and cend: c++11 
      ; iElement != Input.cend()
      ; ++ iElement )
      cout << iElement->first << " -> " << iElement->second << endl;

   cout << endl;
}

int main ()
{
   MAP_INT_STRING mapIntToString;

   // Insert key-value pairs into the map using value_type
   mapIntToString.insert (MAP_INT_STRING::value_type (3, "Three"));

   // Insert a pair using function make_pair
   mapIntToString.insert (make_pair (-1, "Minus One"));

   // Insert a pair object directly
   mapIntToString.insert (pair <int, string>(1000, "One Thousand"));

   // Insert using an array-like syntax for inserting key-value pairs
   mapIntToString [1000000] = "One Million";

   cout << "The map contains " << mapIntToString.size ();
   cout << " key-value pairs. They are: " << endl;
   DisplayContents(mapIntToString);
   
   // instantiate a multimap that is a copy of a map
   MMAP_INT_STRING mmapIntToString(mapIntToString.cbegin(), 
                           mapIntToString.cend());

   // The insert function works the same way for multimap too
   // A multimap can store duplicates - insert a duplicate
   mmapIntToString.insert (make_pair (1000, "Thousand"));
   
   cout << endl << "The multimap contains " << mmapIntToString.size ();
   cout << " key-value pairs. They are: " << endl;
   cout << "The elements in the multimap are: " << endl;
   DisplayContents(mmapIntToString);

   // The multimap can also return the number of pairs with the same key
   cout << "The number of pairs in the multimap with 1000 as their key: "
        << mmapIntToString.count (1000) << endl;

   return 0;
}