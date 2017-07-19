#include<map>
#include<string>

template<typename KeyType>
struct ReverseSort
{
   bool operator()(const KeyType& key1, const KeyType& key2)
   {
      return (key1 > key2);
   }
};

int main ()
{
   using namespace std;

   // map and multimap key of type int to value of type string
   map<int, string> mapIntToString1;
   multimap<int, string> mmapIntToString1;

   // map and multimap constructed as a copy of another
   map<int, string> mapIntToString2(mapIntToString1);
   multimap<int, string> mmapIntToString2(mmapIntToString1);

   // map and multimap constructed given a part of another map or multimap
   map<int, string> mapIntToString3(mapIntToString1.cbegin(), 
                                    mapIntToString1.cend());

   multimap<int, string> mmapIntToString3(mmapIntToString1.cbegin(),
                                          mmapIntToString1.cend());

   // map and multimap with a predicate that inverses sort order
   map<int, string, ReverseSort<int> > mapIntToString4
      (mapIntToString1.cbegin(), mapIntToString1.cend());

   multimap<int, string, ReverseSort<int> > mmapIntToString4
      (mapIntToString1.cbegin(), mapIntToString1.cend());

   return 0;
}