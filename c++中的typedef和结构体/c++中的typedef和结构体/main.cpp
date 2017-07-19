#include <iostream>
using namespace std;

typedef struct  
{
	int age;
	char *name;
}DATA;

struct _tag_Data 
{
	int age;
	char *name;
};

int main(void)
{
	DATA People = { 11 , "zhazha" };
	cout << People.age << " " << People.name << endl;
	_tag_Data aaa;
	memset(&aaa, 0, sizeof(aaa));
	aaa.age = 1;
	aaa.name = new char[3];
	memcpy(aaa.name, "aa", 3);
	cout << aaa.age << " " << aaa.name << endl;
	system("pause");
	return 0;
}