#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <map>

int main(int argc, char *argv[])
{
	int ret = 0;
	int a[] = { 1, 1, 2, 3, 4, 5, 6, 5, 5, 7, 8 };
	int i = 0;
	int Array_Len = sizeof(a) / sizeof(int);


	//map的int int 分别为 key和value 同时都为 int
	// 第一的int 用于存放 a[i] 第二个 数量 遇到相同
	//利用 插入map如遇到相同key会错误的方法
	//也就是 insert 的放回值
	//查看源码得知 是 _Pairib  pair <iterator, bool>
	/*
	_Pairib insert(const value_type& _Val)
	{	// try to insert node with value _Val, favoring right side
	return (_Insert_nohint(false,
	_Val, _Nil_obj));
	}
	*/
	/*
	思路:
		成为 key = value ====>
		a[i] = a[i]出现的次数
		利用map的特性无重复值  和 insert 的返回值
	*/
	map<int, int>m;

	for (i = 0; i < Array_Len; i++)
	{
		pair<map<int, int>::iterator, bool> pairib = m.insert(map<int, int>::value_type(a[i], 1));
		//这里必须是 1   第一次的值 必须是一  代表插入成功一次这个key
		if (false == pairib.second)
		{
			m[a[i]]++;
		}
	}
	int nMax = 0;
	int ArrayValue = 0;
	int n = 0;
	for (i = 0; i < Array_Len; i++)
	{
		if (nMax < m[a[i]])
		{
			nMax = m[a[i]];
			ArrayValue = a[i];
			n = i;
		}
	}
	cout << "下标:" << n << "最多的元素:" << ArrayValue << "多少个:" << nMax << endl;

	system("pause");
	return ret;
}