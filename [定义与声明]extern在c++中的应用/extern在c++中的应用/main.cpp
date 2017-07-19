#include <iostream>
#include "Parent.h" 
/*只要.h中有定义变量  则引用其头文件的话就相当于定义了这个变量
多次包含头文件则多次定义一个全局变量  所以容易报错
所以头文件中只声明不定义*/
using namespace std;

int main()
{
	cout << g_aa << endl;
	system("pause");
	return 0;
}