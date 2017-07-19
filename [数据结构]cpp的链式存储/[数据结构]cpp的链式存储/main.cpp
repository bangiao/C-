#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "linklist.cpp"
using namespace std;

struct Teacher 
{
	int age;
};

int main01()
{
	int ret = 0;
	int i = 0;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;
	linklist<Teacher> list;
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);
	list.insert(t4, 0);
	list.insert(t5, 0);

	cout << list.len() << endl;
	Teacher tmp;
	int len = list.len();
	for (i = 0; i < len; i++)
	{
		list.get(tmp, i);
		cout << tmp.age << " ";
	}
	cout << endl;

	while (list.len() > 0)
	{
		list.del(0, tmp);
		cout << tmp.age << " ";
	}
	cout << endl;
	return ret;
}


int main02()
{
	int ret = 0;
	int i = 0;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;
	Teacher *p1, *p2, *p3, *p4, *p5;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	p4 = &t4;
	p5 = &t5;

	linklist<Teacher *> list;
	list.insert(p1, 0);
	list.insert(p2, 0);
	list.insert(p3, 0);
	list.insert(p4, 0);
	list.insert(p5, 0);

	cout << list.len() << endl;
	Teacher *tmp;
	int len = list.len();
	for (i = 0; i < len; i++)
	{
		list.get(tmp, i);
		cout << tmp->age << " ";
	}
	cout << endl;

	while (list.len() > 0)
	{
		list.del(0, tmp);
		cout << tmp->age << " ";
	}
	cout << endl;
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	//main01();
	main02();
	system("pause");
	return ret;
}