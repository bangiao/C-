#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//�������ĸ���
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
// 	int MyInt = cin.peek();			//peek�Ĺ������жϻ������Ƿ������� ���ص� MyInt
// 	//����������������в��õĵط� ����Ҳ������������ȴ����ǳ���ͣס
// 	cout << "MyInt:" << MyInt << endl;
// 
// 	cin.getline(buf2, 256);			//д�� ���Դ��ڿո�
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
	char c = cin.get(); // << aa bb cc dd ee or 1122334455  �����������
	if (c >= '0' && c <= '9')
	{
		int n;
		cin.putback(c);				//putback�Ĺ����ǽ�ǰ��get�������Ļ�����д��n��
		cin >> n;					//����֮�䲻�����пո������� cin		���ﲻ��������
		cout << "this is number:" << n << endl;
	}
	else
	{
		string str;
		cin.putback(c);
		getline(cin, str);	//�ַ������п����пո�����ʹ�� getline			���ﲻ��������
		cout << "you is string:" << str << endl;
	}
	system("pause");
	return ret;
}
