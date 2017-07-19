#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "linkstack.cpp"
#include "linklist.cpp"
using namespace std;

struct Teacher 
{
public:
	char name[64];
	int age;
	char *pdes;
	Teacher ()
	{
		memset(this->name, 0, sizeof(this->name));
		this->age = 0;
		pdes = NULL;
	}
	Teacher(const Teacher &obj)
	{
		strcpy(this->name, obj.name);
		this->age = obj.age;
		pdes = new char[100];
		memset(pdes, 0, sizeof(char) * 100);
		strcpy(pdes, obj.pdes);
	}
	~Teacher()
	{
		if (NULL != this->pdes)
		{
			delete[]this->pdes;
		}
		this->age = 0;
		memset(this->name, 0, sizeof(char) * 64);
		this->pdes = NULL;
	}
	Teacher &operator=(Teacher &obj)
	{
		if (NULL != this->pdes)
		{
			delete[]this->pdes;
			this->pdes = NULL;
		}
		this->pdes = new char[100];
		memset(this->pdes, 0, sizeof(char) * 100);
		if (NULL != obj.pdes)
		{
			strcpy(this->pdes, obj.pdes);
		}
		this->age = obj.age;
		strcpy(this->name, obj.name);
		return *this;
	}
	
};

int main01()
{
	int ret = 0;
	linkstack<Teacher> list;
	Teacher t1, t2, t3;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	
	list.push(t1);
	list.push(t2);
	list.push(t3);

	Teacher tmp;
	list.top(tmp);
	cout << tmp.age << endl;

	while (list.size() > 0)
	{
		list.pop(tmp);
		cout << tmp.age << " ";
	}
	puts("");
	
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	
	ret = main01();
	system("pause");
	return ret;
}