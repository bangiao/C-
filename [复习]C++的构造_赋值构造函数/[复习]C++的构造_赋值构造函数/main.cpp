#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(int age = 0, char *name = "", int len = 0;)
	{
		this->name = new char[32];
		strcpy_s(this->name, 32, name);
		this->age = age;
		this->len = len;
	}
	~MyClass()
	{
		if (NULL != this->name)
		{
			delete[]this->name;
		}
		this->len = 0;
		this->age = 0;
	}
	int getAge()
	{
		return this->age;
	}
	char *getName()
	{
		return this->name;
	}
	int getLen()
	{
		return this->len;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void setName()
	{
		if (NULL != this->name)
		{
			delete[]this->name;
			this->name = NULL;
		}
		this->name = new char[32];
		strcpy_s(this->name, 32, name);
	}
protected:
private:
	int age;
	char *name;
	int len;
};
int main()
{
	char *str = "TOM";
	int len = strlen(str) + 1;
	MyClass KK(10, str, );
	system("pause");
	return 0;
}