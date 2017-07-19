#include <iostream>

using namespace std;

class Person
{
private :
	char *m_name;
	int m_age;

public:
	Person(char *name, int age)
	{
		if (nullptr == this->m_name)
		{
			this->m_name = new char[1024];
			memset(this->m_name, 0, strlen(this->m_name) + 1);
		}
		memcpy(this->m_name, name, strlen(name) + 1);
		this->m_age = age;
	}

	Person()
	{
		this->m_name = NULL;
		this->m_age = NULL;
	}

	char *getName()
	{
		return m_name;
	}
	void setName(char *name)
	{
		if (NULL != this->m_name)
		{
			memset(this->m_name, 0, strlen(this->m_name) + 1);
		}
		memcpy(this->m_name, name, strlen(this->m_name) + 1);
	}
};

int main(void)
{
	Person p1 = Person();
	Person *p2 = new Person();



	system("pause");
	return 0;
}