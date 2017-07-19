#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <functional>
#include <string>

//bind1st  bind2nd 函数对象适配器
//not1  not2 取反器

//plus 类
int main01()
{
	plus<int> Intadd;
	int x = 10;
	int y = 11;

	int z = Intadd(x, y);
	cout << z << endl;
	plus<string> stringadd;

	string str1 = "aaa";
	string str2 = "bbb";

	string str3 = stringadd(str1, str2);
	cout << str3 << endl;


	minus<int> IntMin;
	int x1 = 11;
	int y1 = 10;
	int z1 = IntMin(x1, y1);
	cout << z1 << endl;

// 	minus<string> stringMin;
//  	string str4 = stringMin(str1, str2);
// 	cout << str4 << endl;
	return 0;
}

template <typename T>
void FuncSort(const T &a)
{
	cout << a << " ";
}

//排序和找相同名字的数量
int main02()
{
	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("ccc");
	v1.push_back("aaa");
	v1.push_back("ddd");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("ccc");

	sort(v1.begin(), v1.end(), less<string>());
	vector<string>::iterator it = v1.begin();
	for_each(v1.begin(), v1.end(), FuncSort<string>);
	cout << endl;

	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), "ccc"));
	cout << num << endl;
	return 0;
}

template <class T>
class IsGreat
{
public:
	IsGreat(const T a)
	{
		this->num = a;
	}
	bool operator()(const T &num)
	{
		if (this->num > num)
		{
			return false;
		}
		else if (this->num < num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	T num;
};

int main03()
{
	vector <int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	for (vector<int>::iterator it = v1.begin();it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	int num1 = count_if(v1.begin(), v1.end(), IsGreat<int>(2));
	cout << num1 << endl;
	int num2 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	cout << num2 << endl;


	//求奇数
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << num3 << endl;
	
	int num4 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << num4 << endl;
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	//main01();
	//main02();
	main03();
	system("pause");
	return ret;
}