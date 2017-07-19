#include <iostream>
#include <vector>
using namespace std;

class person
{
public:
	person(int val = 0, int val2 = 0)
	{
		this->val = val;
		this->val2 = val2;
		this->name = new char [32];
		if (NULL == this->name)
		{
			return;
		}
		cout << "无/有参构造函数" << endl;
	}
	person(const person &p)
	{
		this->val = p.val;
		this->val2 = p.val2;
		cout << "拷贝构造函数" << endl;
	}
	~person()
	{
		if (NULL != this->name)
		{
			delete[]this->name;
		}
	}
	void print()
	{
		cout << this->val << " " << this->val2 << endl;
	}
private:
	int val;
	int val2;
	char *name;
};

int main1111()
{
	person p1;
	person p2(p1);
	person p3;

	p3 = p1;

	p1.print();
	p2.print();
	p3.print();
	system("pause");
	return 0;
}

int main()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	vector<int>b(a);
//	cout << b[4] << endl;
	system("pause");
	return 0;
}