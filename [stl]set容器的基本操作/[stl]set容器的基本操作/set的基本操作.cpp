#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <set>

int main11()
{
	set<int> s;
	for (int i = 0; i < 4; i++)
	{
		int tmp = rand();
		s.insert(tmp);
	}
	s.insert(100);
	
	for (set<int>::iterator it = s.begin(); s.end() != it; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main11();

	
	system("pause");
	return ret;
}