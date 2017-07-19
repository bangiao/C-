#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <map>
#include <string>

const char *pSale = "sale";
const char *pDeve = "development";
const char *pFinancial = "financial";

class Person
{
public:
	string name;
	int age;
	string tel;
	double salary;	//����
};

void main11()
{
	multimap<string, Person>m;
	Person p1, p2, p3, p4, p5, p6;

	p1.name = "zheng1";
	p1.age = 21;
	
	p2.name = "zheng2";
	p2.age = 22;

	p3.name = "zhong1";
	p3.age = 23;

	p4.name = "zhong2";
	p4.age = 24;

	p5.name = "zhen1";
	p5.age = 25;

	p6.name = "zhen2";
	p6.age = 26;

	m.insert(make_pair(pSale, p1));
	m.insert(make_pair(pSale, p2));
	m.insert(make_pair(pDeve, p3));
	m.insert(make_pair(pDeve, p4));
	m.insert(make_pair(pFinancial, p5));
	m.insert(make_pair(pFinancial, p6));

	cout << "������ʼ:" << endl;
	for (multimap<string, Person>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "\t" << it->second.name << endl;
	}
	cout << "��������" << endl;
}

//����ָ�����ŵ���Ա��Ϣ
void main12()
{
	multimap<string, Person>m;
	Person p1, p2, p3, p4, p5, p6;
	int num = 0;
	int tag = 0;

	p1.name = "zheng1";
	p1.age = 21;

	p2.name = "zheng2";
	p2.age = 22;

	p3.name = "zhong1";
	p3.age = 23;

	p4.name = "zhong2";
	p4.age = 24;

	p5.name = "zhen1";
	p5.age = 25;

	p6.name = "zhen2";
	p6.age = 26;

	m.insert(make_pair(pSale, p1));
	m.insert(make_pair(pSale, p2));
	m.insert(make_pair(pDeve, p3));
	m.insert(make_pair(pDeve, p4));
	m.insert(make_pair(pFinancial, p5));
	m.insert(make_pair(pFinancial, p6));

	num = m.count(pDeve);
	if (0 == num)
	{
		cout << "�������û����Ա" << endl;
	}
	else
	{
		cout << "������Ա��:" << num << endl;
	}

//	cout << (m.find(pDeve))->first << "\t" << ((m.find(pDeve))->second).name << endl;

	map<string, Person>::iterator it1 = m.find(pDeve);
	while (it1 != m.end() && tag++ < num)
	{
		cout << it1->first << "\t" << it1->second.name << endl;
		it1++;
	}
}

void main13()
{
	multimap<string, Person>m;
	Person p1, p2, p3, p4, p5, p6;

	p1.name = "zheng1";
	p1.age = 21;

	p2.name = "zheng2";
	p2.age = 22;

	p3.name = "zhong1";
	p3.age = 23;

	p4.name = "zhong2";
	p4.age = 24;

	p5.name = "zhen1";
	p5.age = 25;

	p6.name = "zhen2";
	p6.age = 26;

	m.insert(make_pair(pSale, p1));
	m.insert(make_pair(pSale, p2));
	m.insert(make_pair(pDeve, p3));
	m.insert(make_pair(pDeve, p4));
	m.insert(make_pair(pFinancial, p5));
	m.insert(make_pair(pFinancial, p6));

	for (map<string, Person>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (22 == it->second.age)
		{
			it->second.name = "name:22";
		}
	}

	for (map<string, Person>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "\t" << it->second.name << endl;
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