#include <iostream>
#include "template.cpp"		///////异常重要
using namespace std;

//传说中的 .hpp 文件的使用
//模板类的本质原理是 二次编译 这就导致了不能引用其 .h 文件的根本原因
//因为在程序开始的时候 编译器将编译 .h 文件
//编译完成 .h 文件后编译器将去编译 .cpp 文件
//

int main(int argv, char *args[])
{
	AA<int> a(1, 2);
//	a.printCom();
	AA<int>a1(2, 3);
	cout << "friend a1.MySub1(): " << MySub1(a1, a) << endl;
	cout << "a1.MySub2(): " << a1.MySub2(a) << endl;
	cout << a << endl;
	system("pause");
	return 0;
}