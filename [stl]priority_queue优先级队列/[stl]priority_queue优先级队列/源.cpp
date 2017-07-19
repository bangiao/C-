#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

void main11()
{
	priority_queue<int> pq;

	for (int i = 0; i < 5; i++)
	{
		pq.push(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//从大到小排序

void main12()
{
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < 5; i++)
	{
		pq.push(rand());
	}
	for (int i = 0; i < 5; i++)
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

//从小到大
void main13()
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < 5; i++)
	{
		pq.push(rand());
	}
	for (int i = 0; i < 5; i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main(int argv, char *args[])
{
	int ret = 0;
//	main11();
//	main12();
	main13();
	system("pause");
	return ret;
}