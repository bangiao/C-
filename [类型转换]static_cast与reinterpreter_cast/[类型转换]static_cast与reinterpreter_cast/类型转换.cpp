#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(int argv, char *args[])
{
	double dpi = 3.131592653;

// 	int num1 = dpi;							//��ʽ����ת��
// 	int num2 = static_cast<int>(dpi);		//��̬����ת��
// 	int num3 = (int)dpi;					//C����ת��

//	cout << num1 << num2 << num3 << endl;
	//����� static_castֻ�����ڻ������͵�ת��  ���� int double char float  (ָ�����Ͳ����������)
	//static_cast������ת��ָ�������
	char *p1 = "aaaa";
	int *p2 = NULL;
//	p2 = p1;								//��ʽ����ת����Ч
//	p2 = static_cast<int *>p1;				//���������޷�ת��
//	p2 = (int *)p1;							//Success
	p2 = reinterpret_cast<int *>(p1);		//Success
	system("pause");
	return 0;
}