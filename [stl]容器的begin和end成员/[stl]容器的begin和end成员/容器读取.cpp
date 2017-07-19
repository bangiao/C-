#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main(void)
{

#if 0
// 	list<string> list = { "one", "two", "three" };
// 	auto it1 = list.begin();		//iterator
// 	auto it2 = list.rbegin();		//reverse_iterator
// 	auto it3 = list.cbegin();		//const_iterator
// 	auto it4 = list.crbegin();		//const_reverse_iterator

	string str = { "zhazha one two three" };
	auto it1 = str.begin();
	auto it2 = str.rbegin();
	auto it3 = str.cbegin();
	auto it4 = str.crbegin();

// 	for (string::iterator it = str.begin(); it != str.end(); it++)
// 	{
// 		cout << *it;
// 	}
// 	cout << endl;

	/* str.begin */
// 	for (; it1 != str.end(); it1++)
// 	{
// 		cout << *it1 << endl;
// 	}

	/* str.rbegin */
	// 倒过来遍历
// 	for (; it2 != str.rend(); it2++)
// 	{
// 		cout << *it2;
// 	}
// 	cout << endl;

	/* str.cbegin */
// 	for (; it3 != str.cend(); it3++)
// 	{
// 		cout << *it3;
// 	}
// 	cout << endl;

	/* str.crbegin */
// 	for (; it4 != str.crend(); it4++)
// 	{
// 		cout << *it4;
// 	}
// 	cout << endl;

// 	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
// 
// 	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
// 	{
// 		cout << *it << endl;
// 	}
#endif

	/* 访问元素 */
#if 0
	list<string> l;
	list<string>::iterator it = l.begin();

	l.insert(it, "zhazha");
	l.insert(it, "kankan");
	l.insert(it, "luoluo");

	cout << l.back() << endl;
	cout << l.front() << endl;
// 	cout << l[0] << endl;
// 	cout << l.at(0) << endl;
#endif

	system("pause");
	return 0;
}