#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

class Student
{
public:
	Student(char *name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}
	~Student()
	{
		this->age = 0;
	}
public:
	char name[32];
	int age;
};

//仿函数
struct StuFunctor
{
	bool operator()(const Student &left, const Student &right)
	{
		return (left.age < right.age);
	}
};

int main11()
{
	int ret = 0;

	Student s2("s2", 22);
	Student s5("s5", 55);
	Student s1("s1", 11);
	Student s4("s4", 44);
	Student s3("s3", 33);

	set<Student, StuFunctor> set1;
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	set1.insert(s5);

	for (set<Student, StuFunctor>::iterator it = set1.begin(); set1.end() != it; it++)
	{
		cout << it->age << "\t" << it->name << endl;
	}

	return ret;
}

//pair的使用
void main12()
{
	Student s2("s2", 22);
	Student s5("s5", 55);
	Student s1("s1", 11);
	Student s4("s4", 44);
	Student s3("s3", 33);

	set<Student, StuFunctor> set1;
	pair<set<Student, StuFunctor>::iterator, bool> pair1 = set1.insert(s1);
	if (true == pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	pair1 = set1.insert(s2);
	if (true == pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	pair1 = set1.insert(s3);
	if (true == pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	pair1 = set1.insert(s4);
	if (true == pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	pair1 = set1.insert(s5);
	if (true == pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}

	for (set<Student, StuFunctor>::iterator it = set1.begin(); set1.end() != it; it++)
	{
		cout << it->age << "\t" << it->name << endl;
	}
}

int main(int argv, char *args[])
{
	int ret = 0;
//	main11();
	main12();


	system("pause");
	return ret;
}