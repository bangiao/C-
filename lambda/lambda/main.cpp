#if 0
#include <iostream>
using namespace std;

void fcn1()
{
	size_t v1 = 42;
	auto f = [v1]() {return v1; };
	v1 = 0;
	auto j = f();
	//int i = [v1]() {return v1; };
}

void fcn2()
{
	size_t v1 = 42;
	auto f2 = [&v1] { return v1 };
	v1 = 0;
	auto j = f2();
}

int main(void)
{
	fcn1();
	system("pause");
	return 0;
}
#endif 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int sz = v1.size();
	auto k = [](const vector<int> &a, const vector<int> &b) 
	{
		return a.size() > b.size();
	};
	cout << typeid(k).name() << endl;
// 	auto wc = find_if(v.begin(), v.end(), [sz](const vector<int> &a) {
// 		return (a.size() > sz);
// 	});
	system("pause");
	return 0;
}