#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class Teacher
{
public:
	Teacher()
	{
		this->age = 0;
		int len = sizeof(this->name) / sizeof(char);
		memset(this->name, 0, len);
	}
	Teacher(int age, char *name)
	{
		this->age = age;
		strcpy(this->name, name);
	}
	void print()
	{
		cout << "name : " << this->name << "   age:" << this->age << endl;
	}
protected:
private:
	int age;
	char name[32];
};

int main(int argv, char *args[])
{
	int ret = 0;
	Teacher t1(1, "aaa"), t2(2, "bbb");
	char *fname = "d:\\1.dat";
	ofstream fOut(fname, ios::binary);
	if (!fOut)
	{
		cout << "err" << endl;
		return 0 ;
	}
	fOut.write((char *)&t1,  sizeof(Teacher));
	fOut.write((char *)&t2, sizeof(Teacher));
	fOut.close();

	ifstream fIn(fname);
	if (!fIn)
	{
		cout << "fIn err " << endl;
		return -1;
	}
	Teacher tmp1, tmp2;
	fIn.read((char *)&tmp1, sizeof(Teacher));
	fIn.read((char *)&tmp2, sizeof(Teacher));

	tmp1.print();
	tmp2.print();
	fIn.close();
	system("pause");
	return ret;
}