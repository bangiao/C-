#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main11()
{
	int ret = 0;
	vector<int> vArray;
	vArray.push_back(1);
	vArray.push_back(2);
	vArray.push_back(3);
	vArray.push_back(4);
	vArray.push_back(5);

	//迭代器的概念就是类似于指针
	for (vector<int>::iterator it = vArray.begin(); vArray.end() != it; it++)
	{
		cout << *it << endl;
	}

	system("pause");
	return ret;
}

class Teacher
{
public:
	int age;
};

int main12()
{
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher> vT1;
	vT1.push_back(t1);
	vT1.push_back(t2);
	vT1.push_back(t3);

	for (vector<Teacher>::iterator it = vT1.begin(); it != vT1.end(); it++)
	{
		cout << it->age << endl;
	}
	return 0;
}

int main13()
{
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher *> vT1;
	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	vT1.push_back(p1);
	vT1.push_back(p2);
	vT1.push_back(p3);

	for (vector<Teacher *>::iterator it = vT1.begin(); it != vT1.end(); it++)
	{
		cout << (*it)->age << endl;
	}
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	//main11();
	//main12();
	main13();
	system("pause");
	return ret;
}