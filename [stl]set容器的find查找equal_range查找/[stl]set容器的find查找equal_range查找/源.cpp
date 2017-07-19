#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <set>

void main11()
{
	set<int> s;			//Ĭ�������Ǵ�С����
	
	for (int i = 0; i < 10; i++)
	{
		s.insert(i + 1);
	}

	for (set<int>::iterator it = s.begin(); s.end() != it; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it0 = s.find(5);
	cout << "find:" << *it0 << endl;					//���Ҽ����е���5��Ԫ�صĸ���

	set<int>::iterator it1 = s.lower_bound(5);			//���ҵ�һ�����ڵ���5��Ԫ��
	cout << "lower_bound:" << *it1 << endl;
	set<int>::iterator it2 = s.upper_bound(5);			//���ҵ�һ������5��Ԫ��
	cout << "upper_bound:" << *it2 << endl;

	//pair��ʹ��
// 	typedef pair<iterator, bool> _Pairib;   //_Pair  ib  --> iterator   bool
// 	typedef pair<iterator, iterator> _Pairii;		// _Pair  ii	--> iterator	iterator
// 	typedef pair<const_iterator, const_iterator> _Paircc;	//_Pair  cc   const_iterator	const_iterator
	pair<set<int>::iterator, set<int>::iterator> pair1 = s.equal_range(5);
	cout << *(pair1.first) << endl;
	cout << *(pair1.second) << endl;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main11();
	
	system("pause");
	return ret;
}