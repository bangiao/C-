#include <iostream>
#include <string.h>
using namespace std;

/*
����:
	������������ʱ��, ǰ�����������Ĺ��캯��, �ٵ����������Ĺ��캯��
	�������ȳ�ʼ�������vptrָ��, �ڳ�ʼ����������vptrָ��
	(1) ***���и������ж�***
	�����ٶ����ʱ���ȵ�������������������, ��������������ٵ��ø������������
	(2) ***�ȹ���ĺ�����, �����������***
*/

class AbsParent 
{
public:
	AbsParent(char *name = "Tom", int age = 0) noexcept
	{
		int len = strlen(name);
		this->m_age = age;
		this->m_name = new char[len + 1];
		memcpy(this->m_name, name, len + 1);
	}
	virtual ~AbsParent() noexcept
	{
		if (NULL != this->m_name)
		{
			delete this->m_name;
		}
		this->m_name = 0;
	}
	virtual void say_name()
	{
		cout << this->m_name << endl;
	}
	virtual void say_years()
	{
		cout << this->m_age << endl;
	}

	AbsParent() = delete;
	AbsParent(const AbsParent&) = delete;
	AbsParent(const AbsParent &&) = delete;
	AbsParent &operator=(const AbsParent&) = delete;
	AbsParent &operator=(const AbsParent&&) = delete;
protected:
	int m_age;
	char *m_name;
};

class Child : public AbsParent
{
public:
	using AbsParent::say_name;
	using AbsParent::say_years;
	Child(char *play_game = "zhazha", char *name = "Child", int age = 0) noexcept
		 : AbsParent(name, age)
	{
		int len = strlen(play_game);
		this->m_play_game = new char[len + 1];
		memcpy(this->m_play_game, play_game, len + 1);
	}
	~Child() noexcept
	{
		if (NULL != this->m_play_game)
		{
			delete this->m_play_game;
		}
	}
	void say_game()
	{
		cout << this->m_play_game << endl;
	}

	Child() = delete;
	Child(const Child &) = delete;
	Child operator=(const Child &) = delete;
	Child(const Child &&) = delete;
	Child &operator=(const Child &&) = delete;
protected:
	char *m_play_game;
};

int main(int argc, char *argv[])
{
	AbsParent *base = new Child("youxiwan", "zhangjie", 22);


	base->say_name();		// ������̬
	base->say_years();		// ������̬


	if (NULL != base)
	{
		delete base;
		base = NULL;
	}
	system("pause");
	return 0;
}