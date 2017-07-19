#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <functional>



template<class T>
void printV(vector<T> a)
{
	for (vector<T>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
}

template <class T>
class ShowElem
{
public:
	ShowElem()
	{
		num = 0;
	}
	void operator()(T a)
	{
		num++;
		cout << a << " ";
	}
	void printNum()
	{
		cout << "num:" << num << endl;
	}
private:
	T num;
};

static void printValue(int a)
{
	cout << a << " ";
}

int main_for_each()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV<int>(v1);
	cout << endl;

	ShowElem<int> myElem;

	//��ʱ����������
	for_each(v1.begin(), v1.end(), ShowElem<int>());
	cout << endl;
	myElem.printNum();
	//����������
	myElem = for_each(v1.begin(), v1.end(), myElem);
	printV<int>(v1);
	myElem.printNum();
	cout << endl;
	//�ص�����������
	for_each(v1.begin(), v1.end(), printValue);

	return 0;
}

int increase(int i)
{
	return i + 100;
}

template<class T>
void PrintList(list<T> l)
{
	for (list<T> ::iterator it = l.begin(); l.end() != it; it++)
	{
		cout << *it << " ";
	}
}

int main_transform()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV<int>(v1);
	cout << endl;

	list<int> myList;
	myList.resize(v1.size());
	//�ص�����
	transform(v1.begin(), v1.end(), myList.begin(), increase);
	PrintList<int>(myList);

	cout << endl;
	//ʹ��Ԥ���庯��  ����:ȡ��
	transform(myList.begin(), myList.end(), myList.begin(), negate<int>());
	PrintList<int>(myList);

	cout << endl;
	transform(myList.begin(), myList.end(), myList.begin(), bind2nd(multiplies<int>(), 10));
	PrintList<int>(myList);
	cout << endl;

	//������ֱ���������Ļ
	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, "--"), bind2nd(multiplies<int>(), 10));

	return 0;
}



// int main(int argc, char *argv[])
// {
// 	int ret = 0;
// //	main_for_each();
// 	main_transform();
// 	system("pause");
// 	return ret;
// }