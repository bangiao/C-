#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <queue>
//队列: 先入先出
int main11()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << "队列的尾部元素:" << q.back() << endl;
	cout << "emplace插入到尾部" << endl;
	q.emplace(1);
	cout << "q.front()" << endl;
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}

class Teacher
{
public:
	int age;
	void print()
	{
		cout << this->age << endl;
	}
};

int main12()
{
	Teacher t1, t2, t3;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	queue<Teacher> q1;
	q1.push(t1);
	q1.push(t2);
	q1.push(t3);
	while (!q1.empty())
	{
		cout << q1.front().age << endl;
		q1.pop();
	}
	return 0;
}

int main13()
{
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	queue<Teacher *>q1;
	q1.push(&t1);
	q1.push(&t2);
	q1.push(&t3);
	while (!q1.empty())
	{
		cout << q1.front()->age << endl;
		q1.pop();
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