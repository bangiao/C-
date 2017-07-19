#include <iostream>
#include <string.h>
using namespace std;

/*
结论:
	创建子类对象的时候, 前创建父类对象的构造函数, 再调用子类对象的构造函数
	这样就先初始化父类的vptr指针, 在初始化子类对象的vptr指针
	(1) ***现有父亲再有二***
	在销毁对象的时候先调用子类对象的析构函数, 等子类析构完毕再调用父类的析构函数
	(2) ***先构造的后析构, 后构造的先析构***
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


	base->say_name();		// 产生多态
	base->say_years();		// 产生多态


	if (NULL != base)
	{
		delete base;
		base = NULL;
	}
	system("pause");
	return 0;
}