#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <process.h>
using namespace std;

//饿汉式单例:
//提前new一个对象

//区别是:
//在指针初始化的时候不在是 NULL 而是 new
//懒汉式的第三步骤的函数直接改成 return singel; 不用判断和放回

class Singelton
{
public:
	static Singelton *GetSingelton()
	{
		if (NULL == Singelton::singel)
		{
			Singelton::singel = new Singelton;
		}
		return singel;
	}
	void printS()
	{
		cout << Singelton::num << endl;
	}

	static void DestroySingel()
	{
		if (NULL != singel)
		{
			delete singel;
			singel = NULL;
		}
		num = 0;
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

private:
	static Singelton *singel;		//2. 
	static int num;
};

Singelton *Singelton::singel = NULL;	//饿汉式单例和懒汉式单例的区别
int Singelton::num = 0;

void threadFunc(void *p)
{
	DWORD id = GetCurrentThreadId();	//DWORD  ==> unsigned long
	Singelton::GetSingelton()->printS();
	printf("id:%d\n", id);
	Singelton::DestroySingel();
	return;
}

int main02()
{
	int ret = 0;
	int threadnum = 3;
	int i = 0;
	unsigned int threadhal[100];
	/*
	_CRTIMP uintptr_t __cdecl _beginthread (_In_ void (__cdecl * _StartAddress) (void *),
	_In_ unsigned _StackSize, _In_opt_ void * _ArgList);
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
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	
	main02();
	system("pause");
	return ret;
}