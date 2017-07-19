#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// void func(vector<int> &v)
// {
// 	cout << "线程执行中..." << endl;
// 	for (auto &var : v)
// 	{
// 		cout << var << endl;
// 	}
// }

int main(void)
{
	int a = 10;
	int b = 20;
	vector<int> v_arr;
	int arr[] = { 122, 333, 190, 892, 20, 38 };
	
	for (auto &v : arr)
	{
		v_arr.insert(v_arr.begin(), v);
	}

	//thread t(func, v_arr);
	thread t([&](vector<int> &v) {
		cout << "线程执行中 t..." << endl;
		for (auto &var : v)
		{
			cout << var << endl;
		}
	}, v_arr);

	thread t1([&](vector<int> &v) {
		cout << "线程执行中 t1..." << endl;
		for (auto it = v.rbegin(); it != v.rend(); it++)
		{
			cout << *it << endl;
		}
	}, v_arr);

	t.join();
	t1.join();
	
	system("pause");
	return 0;
}