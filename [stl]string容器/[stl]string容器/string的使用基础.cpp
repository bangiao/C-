#define  _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>		//算法的头文件

int main11()
{
	string s1("aaa");
	string s2 = "bbb";
	string s3 = s2 + "ccc";
	string s4(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
}

//遍历string的元素
int main12()
{
	string s1 = "abcdefg";

	//1 数组模式
	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << "  ";
	}
	cout << endl;
	//2 迭代器
	for (string::iterator it = s1.begin(); s1.end() != it; it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	//3 用 at 的方法获取元素
	try
	{
		for (int i = 0; i < s1.length(); i++)
		{
			cout << s1.at(i) << "  ";
		}
	}
	catch (char c)
	{
		cout << c << endl;
	}
	catch (...)
	{
		cout << "发生异常" << endl;
	}
	
	cout << endl;
	return 0;
}

int main13()
{
	string s = "abcd";
	//1
	printf("%s\n", s.c_str());
	//2
	printf("%s\n", s.data());
	//3 内容拷贝
	char buf[128];
	//copy 参数一 数组, 参数二 copy几个 参数三 第几个位置拷贝开始
	//不拷贝  '\0'
	s.copy(buf, 2, 1);
	buf[2] = '\0';
	cout << "buf: " << buf << endl;
	return 0;
}

//string 字符串的链接
int main14()
{
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = s1 + s2;

	cout << s3 << endl;

	string s4 = "111";
	string s5 = "222";

	//添加  类似于 strcat
	s4.append(s5);

	cout << s4 << endl;
	return 0;
}

int main15()
{
	string s1 = "aaa, bbb, ccc, ddd, bbb, fff, ddd, bbb, yyy, bbb";

	int sVal = 0;
	//find 查找 参数一的字符串 , 参数二是第几个位置
	sVal = s1.find("bbb", sVal);
	while (sVal != string::npos)
	{
		cout << sVal << endl;
		sVal = sVal + 1;
		sVal = s1.find("bbb", sVal);
	}

	sVal = s1.find("bbb", 0);
	while (sVal != string::npos)
	{
		//替换 参数一第几个位置  参数二 替换几个 参数三替换成什么
		s1.replace(sVal, 3, "vvv");
		sVal = sVal + 1;
		sVal = s1.find("bbb", sVal);
	}
	return 0;
}

//string 区间删除
int main16()
{
	string s1 = "hello1 hello2 hell3, hello4";
	//找打这个迭代器 把这个迭代器所值的位置删除
	string::iterator it = find(s1.begin(), s1.end(), 'l');
	if (it != s1.end())
	{
		//删除迭代器所指的位置
		s1.erase(it);
	}
	cout << "erase success ? -- " << s1 << endl;
	return 0;
}

//插入字符串

int main17()
{
	string s1 = "cdefgh";
	//size_type 是 int 类型 一般存放位置   elEm *Pr一般存放指针
	s1.insert(0, "ab");
	//s1.insert(0, "ab", 2);
	cout << s1 << endl;
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	//main11();
	//main12();
	//main13();
	//main14();
	//main15();
	//main16();
	main17();
	system("pause");
	return ret;
}