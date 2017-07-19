#if 0
#include <iostream>
using namespace std;

int main(void)
{
	const string s = "Keep out!";

	for (auto &c : s)
	{
		cout << typeid(c).name() << ":" << c << endl;
	}

	constexpr size_t arr_size = 10;
	int ia[arr_size];
	for (size_t ix = 0; ix <= arr_size; ++ix)
	{
		ia[ix] = ix;
	}
	system("pause");
	return 0;
}
#endif 

#include <iostream>
using namespace std;

int main(void)
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto v : arr)
	{
		cout << v << endl;
	}
	system("pause");
	return 0;
}