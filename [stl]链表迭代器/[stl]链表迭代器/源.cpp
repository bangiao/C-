#include <iostream>
using namespace std;
#include <list>
void main()
{
	list<int > List;			//����һ������
	cout << List.size() << endl;//�����ĳ�ʼ����Ϊ 0
	for (int i = 0; i < 10; i++)
	{
		List.push_back(i + 1);
	}

	list<int>::iterator it = List.begin();
	it++;
	it++;
	it++;
	List.insert(it, 1000);
	it = List.begin();
	while (it != List.end())
	{
		cout << *it++ << endl;
	}
	cout << "sort" << endl;
	List.sort();
	it = List.begin();
	while (it != List.end())
	{
		cout << *it++ << endl;
	}

	for (list<int>::iterator p = List.begin(); p != List.end(); p++)
	{
		cout << *p << endl;
	}

	system("pause");
}