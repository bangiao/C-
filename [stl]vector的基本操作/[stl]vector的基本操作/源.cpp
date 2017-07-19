#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>

//vector 的添加元素和删除元素  读取头部元素和尾部元素
int main11()
{
	vector<int > a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	a.push_back(9);
	
	//读取长度
	cout << a.size() << endl;

	//读取头部元素
	cout << "读取头部元素\n" << a.front() << endl;

	//修改元素的值
	a.front() = 11;

	cout << "读取尾部元素" << endl;
	while (a.size() != 0)
	{
		//读取尾部元素
		cout << a.back() << endl;
		a.pop_back();
	}
	return 0;
}

void printA(vector<int> &v1)
{
	for (vector<int>::iterator it = v1.begin(); v1.end() != it; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main13()
{
	vector<int> a(10);
	int i = 0;

	for (i = 0; i < a.size(); i++)
	{
		a[i] = i + 1;
	}

// 	cout << "删除前:" << endl;
// 	printA(a);
// 
// 	a.erase(a.begin(), a.end());
// 
// 	cout << "删除后" << endl;
// 	printA(a);
// 	for (i = 0; i < a.size(); i++)
// 	{
// 		a[i] = i + 1;
// 	}
//	a.erase(a.begin());
// 	for (i = 0; i < a.size(); i++)
// 	{
// 		a[i] = i + 1;
// 	}
	
	
//	删除指定元素的值
	for (vector<int>::iterator it = a.begin(); a.end() != it;)
	{
		if (2 == *it)
		{
			it = a.erase(it);		//这个 erase 函数会将 it当前的值删除 并且向后移动一个位置
		}
		else
		{
			it++;
		}
	}

	printA(a);

	return 0;
}

//头部插入和尾部插入
void main14()
{
	vector<int> v1(10);
	int i = 0;
	for (i = 0; i < v1.size(); i++)
	{
		v1[i] = i + 1;
	}

	v1.insert(v1.begin(), 10);

	v1.insert(v1.end(), 22);

	printA(v1);
}

int main(int argv, char *args[])
{
	int ret = 0;
	//main11();
	//main13();
	main14();
	system("pause");
	return ret;
}