#include <iostream>
#include "template.cpp"		///////�쳣��Ҫ
using namespace std;

//��˵�е� .hpp �ļ���ʹ��
//ģ����ı���ԭ���� ���α��� ��͵����˲��������� .h �ļ��ĸ���ԭ��
//��Ϊ�ڳ���ʼ��ʱ�� ������������ .h �ļ�
//������� .h �ļ����������ȥ���� .cpp �ļ�
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