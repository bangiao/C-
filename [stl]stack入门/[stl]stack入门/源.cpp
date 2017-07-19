#include <iostream>
using namespace std;
#include <stack>

void main11()
{
	stack<int>s;

	for (int i = 0; i < 5; i++)
	{
		s.push(i + 1);
	}
	int tmp = 0;
	while (!s.empty())
	{
		tmp = s.top();
		printf("%d\n", tmp);
		s.pop();
	}

	system("pause");
}

struct Teacher 
{
	char *name;
	int age;
};

void printStack(stack<Teacher> &s)
{
	while (!s.empty())
	{
		cout << s.top().age << endl;
		s.pop();
	}
}

int *getA()
{
	static int a = 2;
	return &a;
}

void main()
{

	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	stack<Teacher>s;
	s.push(t1);
	s.push(t2);
	s.push(t3);


	int a = 10;
	int *p = &a;
	p = getA();

//	(int *)getA() = p;

	printStack(s);

	system("pause");
}