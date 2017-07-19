#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// struct that behaves as a unary function
template <typename elementType>
struct DisplayElement
{
    void operator () (const elementType& element) const
    {
        cout << element << ' ';
    }
};

int main ()
{
    vector <int> vecIntegers;

    for (int nCount = 0; nCount < 10; ++ nCount)
        vecIntegers.push_back (nCount);

    list <char> listChars;
    for (char nChar = 'a'; nChar < 'k'; ++nChar)
        listChars.push_back (nChar);

    cout << "Displaying the vector of integers: " << endl;

    // Display the array of integers
    for_each ( vecIntegers.begin ()    // Start of range
          , vecIntegers.end ()        // End of range
          , DisplayElement <int> () ); // Unary function object

    cout << endl << endl;
    cout << "Displaying the list of characters: " << endl;

    // Display the list of characters
    for_each ( listChars.begin ()        // Start of range
          , listChars.end ()        // End of range
          , DisplayElement <char> () );// Unary function object

    return 0;
}
