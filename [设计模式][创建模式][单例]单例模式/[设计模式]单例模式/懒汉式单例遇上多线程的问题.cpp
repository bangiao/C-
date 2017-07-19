#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <process.h>
using namespace std;

//����ʽ����
//ȱ�� :
//C++�Ĺ��캯�����ܱ�֤�߳��ǰ�ȫ��

class Singelton
{
public:
	static Singelton *GetSingelton()
	{
		if (NULL == Singelton::singel)//�߳�1  �߳�2  �߳�3 ͬʱ���е�ʱ�򽫻��ж�
			//����� Singelton::singel ������new Singelton ��������� ���캯��
			//�� ���캯���д��� Sleep(1000)[���ǽ����ⷽ����]
			//��������� Singelton::singel ��������������3���̶߳��ж� Singelton::singel
			//Ϊ NULL �������ƻ��˵���
		{
			Singelton::singel = new Singelton;
		}
		return singel;
	}
	void printS()
	{
		cout << Singelton::num << endl;
	}
protected:
private:
	//
	Singelton()		//1. 
	{
		this->num++;
		printf("Singelton begin\n");
		Sleep(1000);
		printf("Singelton end\n");
	}
	~Singelton()
	{
		if (NULL != this->singel)
		{
			delete this->singel;
		}
		this->singel = NULL;
	}
private:
	static Singelton *singel;		//2. 
	static int num;
};

Singelton *Singelton::singel = NULL;
int Singelton::num = 0;

int main02(int argc, char *argv[])
{
	int ret = 0;
	Singelton *s1 = Singelton::GetSingelton();

	Singelton *s2 = Singelton::GetSingelton();

	if (s1 == s2)
	{
		cout << "s1 == s2" << endl;
	}
	else
	{
		cout << "s1 != s2" << endl;
	}

	system("pause");
	return ret;
}

void threadFunc(void *p)
{
	DWORD id = GetCurrentThreadId();	//DWORD  ==> unsigned long
	Singelton::GetSingelton()->printS();
	printf("id:%d\n", id);
	return;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int threadnum = 3;
	int i = 0;
	unsigned int threadhal[100];
	/*
	_CRTIMP uintptr_t __cdecl _beginthread (_In_ void (__cdecl * _StartAddress) (void *),
	_In_ unsigned _StackSize, _In_opt_ void * _ArgList);

	uintptr_t _beginthread (void (* _StartAddress) (void *), unsigned _StackSize, void * _ArgList);
	
	*/
	for (i = 0; i < threadnum; i++)
	{
		threadhal[i] = _beginthread(threadFunc, 0, NULL);		//uintptr_t ==> unsigned int
	}
	for (i = 0; i < threadnum; i++)
	{
		WaitForSingleObject((HANDLE)threadhal[i], INFINITE);		//HANDLE == void *
	}
	printf("main()\n");
	system("pause");
	return ret;
}