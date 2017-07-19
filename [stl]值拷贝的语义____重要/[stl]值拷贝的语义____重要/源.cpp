#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
//�������ڲ��ǽ���ֵ������ ��ǳ����������Ҫ���Ƕ����
//1	�������캯��
//2 ���صȺŲ�����
//3 �޲ι��캯��
class Teacher
{
public:
	Teacher(char *name = "Tom", int age = 0)
	{
		this->m_pName = new char[strlen(name) + 1];
		if (NULL == this->m_pName)
		{
			throw std::runtime_error("�����ڴ�ʧ��");
		}
		this->m_nAge = age;
		strcpy(this->m_pName, name);
	}
	Teacher(const Teacher &obj)
	{
		this->m_pName = new char[strlen(obj.m_pName) + 1];
		if (NULL == this->m_pName)
		{
			throw std::runtime_error("�����ڴ�ʧ��");
		}
		this->m_nAge = obj.m_nAge;
		strcpy(this->m_pName, obj.m_pName);
	}
	~Teacher()
	{
		if (NULL != this->m_pName)
		{
			delete[]this->m_pName;
			this->m_pName = NULL;
		}
		this->m_nAge = 0;
	}
	void printV()
	{
		cout << this->m_pName << "\t" << this->m_nAge << endl;
	}
public:
	Teacher &operator=(const Teacher&obj)
	{
		if (NULL != this->m_pName)
		{
			delete[]this->m_pName;
			this->m_pName = NULL;
		}
		this->m_nAge = 0;
		this->m_pName = new char[strlen(obj.m_pName) + 1];
		if (NULL == this->m_pName)
		{
			throw std::runtime_error("�����ڴ�ʧ��");
		}
		this->m_nAge = obj.m_nAge;
		strcpy(this->m_pName, obj.m_pName);
		return *this;
	}
private:
	char *m_pName;
	int m_nAge;
};

int main(int argv, char *args[])
{
	int ret = 0;
	try
	{
		vector<Teacher> v1;
		Teacher t1("zheng", 21);

		v1.push_back(t1);

		vector<Teacher>::iterator it = v1.begin();
		it->printV();
	}
	catch (std::runtime_error &e)
	{
		e.what();
	}
	
	system("pause");
	return ret;
}