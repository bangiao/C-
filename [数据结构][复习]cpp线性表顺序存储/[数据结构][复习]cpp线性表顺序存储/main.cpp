#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "seqList.cpp"
using namespace std;

class Teacher
{
public:
	int age;
};

int mainOP()
{
	try
	{
		Teacher t1, t2, t3;
		Teacher tmp;
		seqList<Teacher> list(10);
		t1.age = 11;
		t2.age = 22;
		t3.age = 33;

		list.insert(t1, 0);
		list.insert(t2, 0);
		list.insert(t3, 0);

		cout << list.len() << endl;
		cout << list.capacity() << endl;

		list.get(tmp, 1);
		cout << tmp.age << endl;
		list.get(tmp, 2);
		cout << tmp.age << endl;
		list.get(tmp, 3);
		cout << tmp.age << endl;

		for (int i = 0; i < list.len(); i++)
		{
			list.get(tmp, i);
			cout << tmp.age << endl;
		}

		while (list.len() > 0)
		{
			list.del(tmp, 0);
			cout << tmp.age << endl;
		}
	}
	catch (int& e)
	{
		cout << "func err" << e << endl;
	}
	catch (...)
	{
		cout << "func err " << endl;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	mainOP();
	system("pause");
	return ret;
}