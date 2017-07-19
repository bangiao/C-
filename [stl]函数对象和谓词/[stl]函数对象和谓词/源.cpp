#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <functional>
#include <algorithm>
#include <vector>
#include <list>
#include <set>


//一元谓词
template <class T>
class IsDiv
{
public:
	IsDiv(const T &divsor)
	{
		this->divsor = divsor;
	}
	bool operator()(const T &a)
	{
		return (a % this->divsor == 0);
	}
protected:
private:
	T divsor;
};

int main01()
{
	vector<int> v;

	for (int i = 22; i < 66; i++)
	{
		v.push_back(i);
	}
// 	IsDiv<int> show1(4);
// 	vector<int>::iterator it = v.begin();
// 	for (; v.end() != it;)
// 	{
// 		it = find_if(it, v.end(), IsDiv<int>(4));
// 		cout << *it << endl;
// 		it++;
// 	}


	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		it = find_if(it, v.end(), IsDiv<int>(4)); 
		if (it == v.end())
		{
			cout << "找不到" << endl;
			break;
		}
		else
		{
			cout << *it << endl;
		}
		it++;
	}
	cout << endl;
	return 0;
}

template <typename T>
class SumAdd
{
public:
	T operator()(const T a1, const T a2)
	{
		return a1 + a2;
	}
};

template <typename T>
class SumAdd1
{
public:
	SumAdd1( T a)
	{
		this->a = a;
	}
	T operator()(const T a1)
	{
		return (a1 - this->a);
	}
private:
	T a;
};

//遍历函数
void Func(int a)
{
	cout << a << " ";
}

int main02()
{
	vector<int> v1, v2;
	vector<int> v3;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);


	v3.resize(5);
	//transform 实现减号
// 	v3.begin() = transform(v1.begin(), v1.end(), v3.begin(), SumAdd1<int>(1));
// 
// 	for (vector<int>::iterator it = v3.begin(); v3.end() != it; it++)
// 	{
// 		cout << *it << " ";
// 	}
// 	cout << endl;


	//transform 实现相加
	v3.begin() = transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

// 	for (vector<int>::iterator it = v3.begin(); v3.end() != it; it++)
// 	{
// 		cout << *it << endl;
// 	}
// 	cout << endl;

	//使用  for_each 遍历容器
	for_each(v3.begin(), v3.end(), Func);

	return 0;
}

bool funcSort(const int &a, const int &b)
{
	return a > b;
}

//find 区分大小写的排序
int main03()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = rand();
	}
	for_each(v1.begin(), v1.end(), Func);
	cout << endl;
	sort(v1.begin(), v1.end(), funcSort);
	for_each(v1.begin(), v1.end(), Func);
	cout << endl;
	return 0;
}

//不区分大小写的排序

class  CompareNoCase
{
public:
	bool operator()(const string &str1, const string &str2)
	{
		string _str1;
		_str1.resize(str1.size());
		transform(str1.begin(), str1.end(), _str1.begin(), tolower);

		string _str2;
		_str2.resize(str2.size());
		transform(str2.begin(), str2.end(), _str2.begin(), tolower);
		return (_str1 < _str2);
	}
};

int main04()
{
	set<string, CompareNoCase> set1;

	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");


	set<string, CompareNoCase>::iterator it = set1.find("aAa");
	if (it == set1.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到字符串" << endl;
		cout << it->data() << endl;
	}

	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
//	main01();
//	main02();
	//main03();
	main04();
	system("pause");
	return ret;
}