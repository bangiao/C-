#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;


//抽象享元角色
class Person
{
public:
	Person(string name, int age, int sex)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_sex = sex;
	}
	virtual void printT() = 0;

protected:
	string m_name;
	int m_age;
	int m_sex;//1 男 2 女
};


//具体享元角色
class Teacher : public Person
{
public:
	Teacher(string id, string name, int age, int sex) : Person(name, age, sex){}
	~Teacher()
	{
		this->m_id = "";
	}
	virtual void printT()
	{
		cout << "id:" << m_id << "  name:" << this->m_name << "  age:" << m_age << "  sex:" << m_sex << endl;
	}
protected:
private:
	string m_id;
};

//享元工厂角色
class TeacherFactory
{
public:
	TeacherFactory()
	{
		map1.clear();
	}
	~TeacherFactory()
	{
		while (!map1.empty())
		{
			Person *tmp = NULL;
			map<string, Person *>::iterator it = map1.begin();
			tmp = it->second;
			map1.erase(it); //把第一个结点 从容器中删除
			delete tmp;
		}
	}

	Person *getTeacher(string id)
	{
		Person *tmp = NULL;
		map<string, Person*>::iterator it;
		it = map1.find(id);
		if (it == map1.end())
		{
			string tmpName;
			int tmpage;
			int tmpsex;

			cout << "姓名:";
			cin >> tmpName;
			cout << "性别:";
			cin >> tmpage;
			cout << "年龄:";
			cin >> tmpsex;

			tmp = new Teacher(id, tmpName, tmpage, tmpsex);
			map1.insert(make_pair(id, tmp));
		}
		else
		{
			tmp = it->second;
		}
		return tmp;
	}
protected:
private:
	map<string, Person *> map1;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Person *p1 = NULL;
	Person *p2 = NULL;
	Person *p3 = NULL;
	TeacherFactory *FacTeacher = NULL;


	FacTeacher = new TeacherFactory;

	p1 = FacTeacher->getTeacher("001");
	p2 = FacTeacher->getTeacher("002");
	p3 = FacTeacher->getTeacher("001");

	p1->printT();
	p2->printT();
	p3->printT();
	delete FacTeacher;
	system("pause");
	return ret;
}