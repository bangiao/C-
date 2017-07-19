#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

void printV(deque<int> &d)
{
	for (unsigned int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

int main(int argv, char *args[])
{
	int ret = 0;
	
	deque<int> d(10);

	for (unsigned int i = 0; i < d.size(); i++)
	{
		d[i] = i + 1;
	}

	printV(d);

	deque<int>::iterator it = find(d.begin(), d.end(), 3);
	if (it == d.end())
	{
		cout << "un find" << endl;
	}
	else
	{
		//cout << "find:" << distance(d.begin(), d.end());			//find: 10
		cout << "find:" << distance(d.begin(), it);
	}
	
	system("pause");
	return ret;
}