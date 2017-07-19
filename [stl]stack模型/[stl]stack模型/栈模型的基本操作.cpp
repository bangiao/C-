#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stack>


int main11()
{
	stack<int> s;
	int tmp = 0;
	for (int i = 0; i < 10; i++)
	{
		s.push(i + 1);
	}
	//³öÕ»
	while (!s.empty())
	{
		tmp = s.top();
		cout << tmp << " ";
		cout << endl;
		s.pop();
	}
	return 0;
}

class Teacher
{
public:
	int age;
	char name[32];
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

	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);
	while (!s.empty())
	{
		Teacher tmp = s.top();
		tmp.print();
		s.pop();
	}
	return 0;
}

int main13()
{
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	stack<Teacher *>s1;
	s1.push(&t1);
	s1.push(&t2);
	s1.push(&t3);

	while (!s1.empty())
	{
		Teacher *tmp = s1.top();
		tmp->print();
		s1.pop();
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