#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <list>
#include <set>
/*
1. ʲô�Ǻ�������?
	����������Ƿº��� ���� �����˲��������������������  ��ӵ���� ����������
	������ () ������֮���
2. �º���������
	�º������������ڿ��Խ���������ʱ��һЩ�����ѱ����ķ�ʽ��¼����
*/

template <class T>
class ShowElem
{
public:
	ShowElem()
	{
		this->n = 0;
	}
	void operator()(T &t)
	{
		n++;
		cout << t << " ";
	}
	void printN()
	{
		cout << "n:" << this->n << endl;
	}
protected:
private:
	int n;
};

template <class T>
void FuncShowElem(T &a)
{
	cout << a << endl;
}
//typedef void(*pFuncShowElem)(int &s);

void main11()
{
	int a = 10;
	ShowElem<int> s;
	s(a);
	FuncShowElem(a);

}

void main12()
{
	vector<int > v;

	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	ShowElem<int> s;
	//����Ĳ������漰��һ����Ҫ������
	//����һ���β�
	//���㷨  for_each����ᷢ������������������ú�ָ��
	//���ʱ������Ĳ������ͺ����е� s ��������һ���Ķ���
	//��������㷨 ȴ������ ����
	//���㷨ԭ��
	/*
		template<class _InIt, class _Fn1> 
		inline _Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
		{	// perform function for each element
			_DEBUG_RANGE(_First, _Last);
			_DEBUG_POINTER(_Func);
			_For_each(_Unchecked(_First), _Unchecked(_Last), _Func);
			return (_STD move(_Func));
		}
	*/
	s = for_each(v.begin(), v.end(), s);
	//����: ���Է�����㷨�Ĳ��� �㷨���� �Ż�ֵ  ��Ϊ��Ҫ
//	pFuncShowElem pFun = for_each(v.begin(), v.end(), FuncShowElem<int>);
	for_each(v.begin(), v.end(), FuncShowElem<int>);
	s.printN();
}

int main(int argv, char *args[])
{
	int ret = 0;
	//main11();
	main12();
	
	system("pause");
	return ret;
}