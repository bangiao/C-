#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//缓冲区的概念
// int main(int argv, char *args[])
// {
// 	int ret = 0;
// 	char ch;
// 
// 	while ((ch = cin.get()) != EOF)
// 	{
// 		cout << ch << endl;
// 	}
// 	system("pause");
// 	return ret;
// }

// int main(int argv, char *args[])
// {
// 	char buf1[256];
// 	char buf2[256];
// 
// 	cin >> buf1;
// 
// 	cin.ignore(2);
// 
// 	int MyInt = cin.peek();			//peek的功能是判断缓冲区是否有数据 返回到 MyInt
// 	//但是这个函数还是有不好的地方 如果找不到则会在这里等待道是程序停住
// 	cout << "MyInt:" << MyInt << endl;
// 
// 	cin.getline(buf2, 256);			//写入 可以存在空格
// 
// 	cout << buf1 << endl;
// 	cout << buf2 << endl;
// 
// 	system("pause");
// 	return 0;
// }

int main(int argv, char *args[])
{
	int ret = 0;
	char c = cin.get(); // << aa bb cc dd ee or 1122334455  这里存在输入
	if (c >= '0' && c <= '9')
	{
		int n;
		cin.putback(c);				//putback的功能是将前面get所带来的缓冲区写入n中
		cin >> n;					//数字之间不可能有空格所以用 cin		这里不用输入了
		cout << "this is number:" << n << endl;
	}
	else
	{
		string str;
		cin.putback(c);
		getline(cin, str);	//字符串中有可能有空格所以使用 getline			这里不用输入了
		cout << "you is string:" << str << endl;
	}
	system("pause");
	return ret;
}
