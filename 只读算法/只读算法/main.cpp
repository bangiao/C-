#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

template <class T>
T add(T &a, T &b)
{
	return a + b;
}

int main(void)
{
	vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> arr2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = accumulate(arr.begin(), arr.end(), 0);
	int sum2 = accumulate(arr.begin(), arr.end(), 0, add<int>);
	int sum3 = accumulate(arr.begin(), arr.end(), 0, [](int &a, int &b) {
		return a + b;
	});
	cout << sum << endl;
	cout << sum2 << endl;
	cout << sum3 << endl;

	bool bRet = equal(arr.begin(), arr.end(), arr2.begin());
	if (false == bRet)
	{
		cout << "不相等" << endl;
	}
	else
	{
		cout << "相等" << endl;
	}
	/* 填充 */
	fill(arr.begin(), arr.end(), 0);
	for (auto &c : arr)
	{
		cout << c;
	}
	cout << endl;
// 	vector<double> arr = { 0, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.2, 10.12 };
// 	double sum = accumulate(arr.begin(), arr.end(), 0, add<double>);
// 	cout << sum << endl;
	system("pause"); 
	return 0;
}