#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <deque>

int main11(int argv, char *args[])
{
	int ret = 0;
	deque<int> a;

	a.push_front(1);
	a.push_front(3);
	a.push_front(5);

	a.push_back(11);
	a.push_back(33);
	a.push_back(55);

	for (deque<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return ret;
}