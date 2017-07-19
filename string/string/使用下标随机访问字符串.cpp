#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	const string str = "0123456789ABCDEFG";
	string::size_type n;
	string String;
	while (cin >> n)
	{
		if (n < str.size())
		{
			String += str[n];
		}
	}
	cout << String << endl;
	system("pause");
	return 0;
}