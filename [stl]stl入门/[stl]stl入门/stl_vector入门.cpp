#include <iostream>
#include <vector>
using namespace std;

//stl 中的所有 成员都是有模板类组成的  你可以把它们当做类型来使用

void printArray(vector<int> &v1)
{
	int Size = v1.size();

	for (int i = 0; i < Size; i++)
	{
		cout << v1[i] << endl;
	}
}

//	error
// void printArray2(vector<int> *v1)
// {
// 	int Size = v1->size();
// 
// 	for (int i = 0; i < Size; i++)
// 	{
// 		cout << v1[i] << endl;
// 	}
// }

int main11()
{
	vector<int > v1(5);

	for (int i = 0; i < 5; i++)
	{
		v1[i] = i + 1;
	}

	vector<int >v2(10);
	
	v2 = v1;

	for (int i = 0; i < 5; i++)
	{
		v1[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << v2[i] << endl;
	}

	printArray(v1);
	printArray(v2);
	system("pause");
	return 0;
}

void main12()
{
	vector<int >v3(0);

	v3.push_back(1);		//这个成员函数的功能是将数组从最后一个位起在申请空间存放
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(4);
	printArray(v3);

	vector<int>v4(10);

	int size = v4.size();

	for (int i = 0; i < size; i++)
	{
		v4[i] = i + 1;
	}

	printArray(v4);

	v4.push_back(11);
	v4.push_back(12);
	v4.push_back(13);

	printArray(v4);

	system("pause");
}

struct Teacher 
{
	char *name;
	int age;
};

void main()
{
	vector<Teacher>v4(0);
	Teacher *tmp = NULL;

	Teacher t1, t2, t3;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	v4.push_back(t1);
	v4.push_back(t2);
	v4.push_back(t3);

	for (int i = 0; i < 3; i++)
	{
		cout << v4[i].age << endl;
	}

	vector<Teacher *>v5(0);

	v5.push_back(&t1);
	v5.push_back(&t2);
	v5.push_back(&t3);

	for (int i = 0; i < 3; i++)
	{
		tmp = v5[i];
		cout << tmp->age << endl;
	}
	
	system("pause");
}