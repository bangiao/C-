#include <vector>
#include <iostream>
#include <algorithm>

template <typename elementType>
class Multiply
{
public:
    elementType operator () (const elementType& elem1, 
                             const elementType& elem2)
    {
        return (elem1 * elem2); 
    }
};

int main ()
{
    using namespace std;

    // Create two sample vector of integers with 10 elements each
    vector <int> vecMultiplicand, vecMultiplier;

    // Insert sample values 0 to 9
    for (int nCount1 = 0; nCount1 < 10; ++ nCount1)
        vecMultiplicand.push_back (nCount1);

    // Insert sample values 100 to 109
    for (int nCount2 = 100; nCount2 < 110; ++ nCount2)
        vecMultiplier.push_back (nCount2);

    // A third container that holds the result of multiplication 
    vector <int> vecResult;

    // Make space for the result of the multiplication
    vecResult.resize (10);

    transform ( vecMultiplicand.begin (), // range of multiplicands 
                vecMultiplicand.end (), // end of range
                vecMultiplier.begin (),  // multiplier values
                vecResult.begin (), // range that holds result
                Multiply <int> () );    // multiplies: replace by next line to see lambda version
				// [](int a, int b) {return a * b; } );  // lambda version
				

    cout << "The contents of the first vector are: " << endl;
    for (size_t nIndex1 = 0; nIndex1 < vecMultiplicand.size (); ++ nIndex1)
        cout << vecMultiplicand [nIndex1] << ' ';
    cout << endl;

    cout << "The contents of the second vector are: " << endl;
    for (size_t nIndex2 = 0; nIndex2 < vecMultiplier.size (); ++nIndex2)
        cout << vecMultiplier [nIndex2] << ' ';
    cout << endl << endl;

    cout << "The result of the multiplication is: " << endl;
    for (size_t nIndex = 0; nIndex < vecResult.size (); ++ nIndex)
        cout << vecResult [nIndex] << ' '; 

    return 0;
}
