#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(int argv, char *args[])
{
	double dpi = 3.131592653;

// 	int num1 = dpi;							//隐式类型转换
// 	int num2 = static_cast<int>(dpi);		//静态类型转换
// 	int num3 = (int)dpi;					//C类型转换

//	cout << num1 << num2 << num3 << endl;
	//这里的 static_cast只能用于基本类型的转换  例如 int double char float  (指针类型不算基本类型)
	//static_cast不可以转换指针的类型
	char *p1 = "aaaa";
	int *p2 = NULL;
//	p2 = p1;								//隐式类型转换无效
//	p2 = static_cast<int *>p1;				//复杂类型无法转换
//	p2 = (int *)p1;							//Success
	p2 = reinterpret_cast<int *>(p1);		//Success
	system("pause");
	return 0;
}