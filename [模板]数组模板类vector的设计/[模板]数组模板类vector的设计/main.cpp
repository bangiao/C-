#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyVector.cpp"
using namespace std;

// int main(int argv, char *args[])
// {
// 	MyVector<int> a(20);
// 	int i = 0;
// 	for (i = 0; i < a.getLen(); i++)
// 	{
// 		a[i] = i + 1;
// 	}
// 
// 	for (i = 0; i < a.getLen(); i++)
// 	{
// 		printf("a[%d]: %d\n", i, a[i]);
// 	}
// 
// 	cout << endl << endl;
// 
// 	MyVector<int> b = a;
// 	for (i = 0; i < a.getLen(); i++)
// 	{
// 		printf("a[%d]: %d\n", i, a[i]);
// 	}
// 	system("pause");
// 	return 0;
// }

//ÈÝÆ÷µÄ¸ÅÄî

class Teacher
{
public:
	Teacher(int age = 0, char *name = "")
	{
		this->age = age;
		memcpy(this->name, name, sizeof(char) * 32);
	}
	void print()
	{
		cout << this->age << ", " << this->name << endl;
	}
private:
	int age;
	char name[32];
};

int main1()
{
	Teacher t1(21, "aaa"), t2(21, "bbb"), t3(21, "ccc");
	MyVector<Teacher> TArray(3);
	TArray[0] = t1;
	TArray[1] = t2;
	TArray[2] = t3;

	for (int i = 0; i < TArray.getLen(); i++)
	{
		Teacher tmp = TArray[i];
		tmp.print();
	}
	return 0;
}

int main()
{
	main1();
	system("pause");
	return 0;
}