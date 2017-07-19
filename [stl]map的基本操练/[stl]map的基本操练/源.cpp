#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
using namespace std;
#include <map>

//初始化的方法
void main11()
{
	map<int, string> m;

	//方法一
	m.insert(make_pair(1, "name: 01"));
	m.insert(make_pair(2, "name: 02"));
	cout << m.at(1) << endl;
	cout << m[2] << endl;
	
	//方法二
	m.insert(pair<int, string>(3, "name: 03"));
	m.insert(pair<int, string>(4, "name: 04"));
	cout << m.at(3) << endl;
	cout << m[4] << endl;
	//方法三
	m.insert(map<int, string>::value_type(5, "name: 05"));
	m.insert(map<int, string>::value_type(6, "name: 06"));
	cout << m.at(5) << endl;
	cout << m[6] << endl;
	//方法四
	m[7] = "name: 07";
	m[8] = "name: 08";

	cout << m.at(7) << endl;
	cout << m[8] << endl;


	for (map<int, string>::iterator it = m.begin(); m.end() != it;)
	{
		cout << it->first << "\t" << it->second << endl;
		m.erase(it++);
	}

// 	while (!m.empty())
// 	{
// 		map<int, string>::iterator it = m.begin();
// 		cout << it->first << "\t" << it->second << endl;
// 		m.erase(it);
// 	}
}

// 方法的区别
void main12()
{
	map<int, string> m;
	//insert 的返回值是 _Pairib    _Pair       i     b
	//typedef pair<iterator, bool> _Pairib;
	//方法一
	pair<map<int, string>::iterator, bool> pair1 = m.insert(make_pair(1, "name: 01"));
	if (false == pair1.second)
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << pair1.first->first << "\t" << pair1.first->second << endl;
	}
	pair1 = m.insert(make_pair(1, "name: 02"));
	if (false == pair1.second)
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << pair1.first->first << "\t" << pair1.first->second << endl;
	}
	//方法二
	pair1 = m.insert(pair<int, string>(2, "name: 03"));
	if (false == pair1.second)
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << pair1.first->first << "\t" << pair1.first->second << endl;
	}
	pair1 = m.insert(pair<int, string>(2, "name: 04"));
	if (false == pair1.second)
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << pair1.first->first << "\t" << pair1.first->second << endl;
	}

	//方法三
	pair1 = m.insert(map<int, string>::value_type(3, "name: 05"));
	if (false == pair1.second)
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << pair1.first->first << "\t" << pair1.first->second << endl;
	}
	pair1 = m.insert(map<int, string>::value_type(3, "name: 06"));
	if (false == pair1.second)
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << pair1.first->first << "\t" << pair1.first->second << endl;
	}

	//方法四
	m[4] = "name: 07";
	m[4] = "name: 08";
}

//find
void main13()
{
	map<int, string> m;

	m[3] = "name:03";
	m[2] = "name:02";
	m[5] = "name:05";
	m[1] = "name:01";
	m[4] = "name:04";

	for (map<int, string>::iterator it = m.begin(); it != m.end(); it ++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	map<int, string>::iterator it = m.find(2);
	cout << it->first << "\t" << it->second << endl;

	map<int, string>::iterator it1 = m.lower_bound(3);
	if (it1 == m.end())
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << "lower_bound:" << endl;
		cout << it1->first << "\t" << it1->second << endl;
	}
	map<int, string>::iterator it2 = m.upper_bound(3);

	if (it2 == m.end())
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << "upper_bound:" << endl;
		cout << it2->first << "\t" << it2->second << endl;
	}

	pair<map<int, string>::iterator, map<int, string>::iterator> pair1 = m.equal_range(3);
	if (pair1.first == m.end() || pair1.second == m.end())
	{
		cout << "err " << endl;
	}
	else
	{
		cout << "lower_bound:" << endl;
		cout << pair1.first->first << "\t" << pair1.first->second << endl;
		cout << "upper_bound:" << endl;
		cout << pair1.second->first << "\t" << pair1.second->second << endl;
	}
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