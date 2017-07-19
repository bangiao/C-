#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1: 0 1  == 2;
//2: 01 10 00 == 3;
//3: 000 001 010 100 101 == 5;
int result = -1;

void cal(int cur, int total, int pre)
{
	if (cur > total)
	{
		result++;
		return;
	}
	if (pre == 1)
	{
		cal(cur + 1, total, 0);
	}
	else
	{
		cal(cur + 1, total, 0);
		cal(cur + 1, total, 1);
	}
}

unsigned long long calc(int len)
{
	unsigned long long d1 = 1;
	unsigned long long d2 = 1;
	int i = 0;

	for (i = 0; i < len; i++)
	{
		unsigned long long tmp = d1;
		d1 += d2;
		d2 = tmp;
	}
	return d1 + d2;
}

int main01()
{
	int ret = 0;
	int count = 0;
	cin >> count;
	int i = 1;
// 
	while (count--)
	{
		int len;
		cin >> len;
		result = 0;
		cal(1, len, 0);
		cout << "Scenaro #" << i++ << ";" << endl;
		cout << result << endl;
	}
	return ret;
}

int main02()
{
	int ret = 0;
	int len = 0;
	cout << "请输入数列长度:";
	cin >> len;
	cout << calc(len) << endl;
	return ret;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main02();
	system("pause");
	return ret;
}