#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <functional>


static void printValue(int a)
{
	cout << a << " ";
}

int printValue2(int a)
{
	cout << a << endl;
	return 0;
}

int main21()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	
	//for_each 和 transform 的谓词的区别

	/*
	template<class _InIt,
	class _Fn1> inline
	void _For_each(_InIt _First, _InIt _Last, _Fn1& _Func)
	{	// perform function for each element
	for (; _First != _Last; ++_First)
	_Func(*_First);
	}
	*/


	//_Func(*_First); 不需要返回值
	for_each(v1.begin(), v1.end(), printValue);

	/*
	template<class _InIt,
	class _OutIt,
	class _Fn1> inline
	_OutIt _Transform(_InIt _First, _InIt _Last,
	_OutIt _Dest, _Fn1 _Func)
	{	// transform [_First, _Last) with _Func
	for (; _First != _Last; ++_First, ++_Dest)
	*_Dest = _Func(*_First);
	return (_Dest);
	}
	*/
	//*_Dest = _Func(*_First);这个需要返回值
	transform(v1.begin(), v1.end(), v1.begin(), printValue2);



	return 0;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	main21();
	
	system("pause");
	return ret;
}