#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "linklist.cpp"
using namespace std;

class Teacher
{
public:
	int age;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Teacher t1, t2, t3;
	linklist<Teacher> list;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	cout << list.len() << endl;
	Teacher tmp;
	list.get(tmp, 0);
	cout << tmp.age << endl;
	list.get(tmp, 1);
	cout << tmp.age << endl;
	list.get(tmp, 2);
	cout << tmp.age << endl;

	while (list.len() > 0)
	{
		list.del(tmp, 0);
		cout << tmp.age << endl;
	}
	
	system("pause");
	return ret;
}