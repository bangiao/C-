#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

template <typename T1, typename T2>
void DisplayUnorderedMap(unordered_map<T1, T2>& Input)
{
   cout << "Number of pairs, size(): " << Input.size() << endl;
   cout << "Max bucket count = " << Input.max_bucket_count() << endl;
   cout << "Load factor: " << Input.load_factor() << endl;
   cout << "Max load factor = " << Input.max_load_factor() << endl;
   cout << "Unordered Map contains: " << endl;

   for(auto iElement = Input.cbegin() // auto, cbegin: c++11 
      ; iElement != Input.cend()  // cend() is new in C++11 
      ; ++ iElement )
      cout<< iElement->first<< " -> "<< iElement->second<< endl;
}
   
int main()
{
   unordered_map<int, string> umapIntToString;
   umapIntToString.insert(make_pair(1, "One"));
   umapIntToString.insert(make_pair(45, "Forty Five"));
   umapIntToString.insert(make_pair(1001, "Thousand One"));
   umapIntToString.insert(make_pair(-2, "Minus Two"));
   umapIntToString.insert(make_pair(-1000, "Minus One Thousand"));
   umapIntToString.insert(make_pair(100, "One Hundred"));
   umapIntToString.insert(make_pair(12, "Twelve"));
   umapIntToString.insert(make_pair(-100, "Minus One Hundred"));

   DisplayUnorderedMap<int, string>(umapIntToString);

   cout << "Inserting one more element" << endl;
   umapIntToString.insert(make_pair(300, "Three Hundred"));
   DisplayUnorderedMap<int, string>(umapIntToString);

   cout << "Enter key to find for: ";
   int Key = 0;
   cin >> Key;

   auto iElementFound = umapIntToString.find(Key);
   if (iElementFound != umapIntToString.end())
   {
      cout << "Found! Key " << iElementFound->first << " points to value ";
      cout << iElementFound->second << endl;
   }
   else
      cout << "Key has no corresponding value in unordered map!" << endl;

   return 0;
}