#define  _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>		//�㷨��ͷ�ļ�

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

//����string��Ԫ��
int main12()
{
	string s1 = "abcdefg";

	//1 ����ģʽ
	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << "  ";
	}
	cout << endl;
	//2 ������
	for (string::iterator it = s1.begin(); s1.end() != it; it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	//3 �� at �ķ�����ȡԪ��
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
		cout << "�����쳣" << endl;
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
	//3 ���ݿ���
	char buf[128];
	//copy ����һ ����, ������ copy���� ������ �ڼ���λ�ÿ�����ʼ
	//������  '\0'
	s.copy(buf, 2, 1);
	buf[2] = '\0';
	cout << "buf: " << buf << endl;
	return 0;
}

//string �ַ���������
int main14()
{
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = s1 + s2;

	cout << s3 << endl;

	string s4 = "111";
	string s5 = "222";

	//���  ������ strcat
	s4.append(s5);

	cout << s4 << endl;
	return 0;
}

int main15()
{
	string s1 = "aaa, bbb, ccc, ddd, bbb, fff, ddd, bbb, yyy, bbb";

	int sVal = 0;
	//find ���� ����һ���ַ��� , �������ǵڼ���λ��
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
		//�滻 ����һ�ڼ���λ��  ������ �滻���� �������滻��ʲô
		s1.replace(sVal, 3, "vvv");
		sVal = sVal + 1;
		sVal = s1.find("bbb", sVal);
	}
	return 0;
}

//string ����ɾ��
int main16()
{
	string s1 = "hello1 hello2 hell3, hello4";
	//�Ҵ���������� �������������ֵ��λ��ɾ��
	string::iterator it = find(s1.begin(), s1.end(), 'l');
	if (it != s1.end())
	{
		//ɾ����������ָ��λ��
		s1.erase(it);
	}
	cout << "erase success ? -- " << s1 << endl;
	return 0;
}

//�����ַ���

int main17()
{
	string s1 = "cdefgh";
	//size_type �� int ���� һ����λ��   elEm *Prһ����ָ��
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