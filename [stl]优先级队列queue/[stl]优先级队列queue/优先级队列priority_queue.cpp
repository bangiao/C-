#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "queue"

int main11()
{
	priority_queue<int> p1;

	p1.push(33);
	p1.push(11);
	p1.push(55);
	p1.push(22);
	cout << "对头元素:" << p1.top() << endl;
	cout << "队列的大小:" << p1.size() << endl;

	while (!p1.empty())
	{
		cout << p1.top() << endl;
		p1.pop();
	}
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main11();
	
	system("pause");
	return ret;
}