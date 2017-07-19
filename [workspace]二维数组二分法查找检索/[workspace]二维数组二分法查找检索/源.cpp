#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <thread>
#include <vector>
#include <stdlib.h>
using namespace std;

static bool bol = false;

void find_var(const vector<int> v, const int val)
{
	for (auto &k : v)
	{
		if (k == val)
		{
			bol = true;
			return;
		}
	}
}

int main(void)
{
	int val = 0;
	vector<int> v;

	srand(time((time_t*)0));

	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 10);
	}

	cin >> val;
	int flag = 0;

	thread t1(find_var, v, val);

	t1.join();

	cout << bol << endl;
	
	system("pause");
	return 0;
}