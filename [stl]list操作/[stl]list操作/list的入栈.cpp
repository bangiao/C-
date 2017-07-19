#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <list>

int main11()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}

	cout << "迭代器遍历:" << endl;
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n普通遍历" << endl;
	while (l.size())
	{
		cout << l.front() << " ";
		l.pop_front();
	}
	cout << endl;
	return 0;
}

void printD(list<int> &l)
{
	for (list<int>::iterator it = l.begin(); l.end() != it; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//list 的插入
int main12()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}
//	0	1	2	3	4	5	6	7	8	9	10  位置
//	1	2	3	4	5	6	7	8	9	10
//	△
	list<int>::iterator it = l.begin();
	it++;
//	0	1	2	3	4	5	6	7	8	9	10  位置
//	1	2	3	4	5	6	7	8	9	10
//		△
	it++;
//	0	1	2	3	4	5	6	7	8	9	10  位置
//	1	2	3	4	5	6	7	8	9	10
//			△
	it++;
//	0	1	2	3	4	5	6	7	8	9	10  位置
//	1	2	3	4	5	6	7	8	9	10
//				△
	l.insert(it, 100);
//如果是从 1 开始的话 插入数据是插入在 3 的后面的位置  这个位置的向后一 一位然后插入数据  如图
//	1	2	3	100	4	5	6	7	8	9	10
//				△
//如果是从 0 开始的话  插入的数据是插入在 3 这个位置  这个时候 3 的数据后退一格 让出位置给新的位置
//	0	1	2	100	3	4	5	6	7	8	9
//				△	
//其实就是跳过了 0 ~ 2  0  1  2 新数据成为第四个位置
	printD(l);
	return 0;
}

// it++ 一次指向 1 因为 begin() 指向的是 第一个链表元素
//it ++ 就是指向第二个链表元素 
//it ++ 第三个链表元素

//也就是:

//it - - - - -> 0

//it++ - - - -> 1

//it++ - - - - >2

//it++ - - - -->3  所以当 it.insert(X)时 就是在这个位置插入

//插入的意思就是 替换这个位置的元素将原本这个位置的元素后移

int main13()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}

	printD(l);
	list<int>::iterator it = l.begin();
	it++;
	it++;
	it++;
//	1	2	3	4	5	6	7	8	9	10
//				△
	l.erase(l.begin(), it);  // cout		4 ...... 10
	printD(l);
	return 0;
}

int main14()
{
	list<int> l;

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}
	l.push_back(2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}

	l.erase(l.begin());

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}
	l.remove(2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
//	main11();
//	main12();
//	main13();
	main14();
	system("pause");
	return ret;
}