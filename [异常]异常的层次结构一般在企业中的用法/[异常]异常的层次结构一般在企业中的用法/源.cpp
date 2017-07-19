#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//企业中经常使用这种异常类的方法, 进行返回

class MyArray
{
public:
	MyArray(int len);
	~MyArray();
	int getMyArrayLen();
public :
	int &operator[](int len);
public:
	class eSize
	{
	public:
		eSize(int size)						//功能类 当为 0 时返回
		{
			this->m_size = size;
		}
		void printErr()
		{
			cout << "err eSize:" << this->m_size << endl;
		}
	protected:
		int m_size;
	};
	class eNegarive : public eSize			//当为负数的时候返回
	{
	public:
		eNegarive(int size) : eSize(size)
		{

		}
		void printErr()
		{
			cout << "err eNegarive:" << this->m_size << endl;
		}
	};
	class eTooBig : public eSize			//太大返回
	{
	public:
		eTooBig(int size) : eSize(size)
		{

		}
		void printErr()
		{
			cout << "err eTooBig:" << this->m_size << endl;
		}
	};
	class eTooSmall : public eSize			//太小返回
	{
	public:
		eTooSmall(int size) : eSize(size)
		{

		}
		void printErr()
		{
			cout << "err eTooSmall:" << this->m_size << endl;
		}
	};
protected:
private:
	int *m_space;
	int m_len;
};

MyArray::MyArray(int len)
{
	if (len < 0)
	{
		throw eNegarive(len);
	}
	if (0 == len)
	{
		throw eSize(len);
	}
	if (len > 1000)
	{
		throw eTooBig(len);
	}
	if (len < 3)
	{
		throw eTooSmall(len);
	}
	this->m_len = len;
	this->m_space = new int[len];
}
MyArray::~MyArray()
{
	if (NULL != this->m_space)
	{
		delete[]this->m_space;
		this->m_space = NULL;
	}
	this->m_len = 0;
}
int MyArray::getMyArrayLen()
{
	return this->m_len;
}

int &MyArray::operator[](int len)
{
	return this->m_space[len];
}

int main(int argv, char *args[])
{
	int ret = 0;
	int i = 0;
	
	try
	{
		MyArray a = MyArray(10);

		for (i = 0; i < a.getMyArrayLen(); i++)
		{
			a[i] = i + 1;
		}

		for (i = 0; i < a.getMyArrayLen(); i++)
		{
			cout << a[i] << " " << endl;
		}
	}
	catch (MyArray::eNegarive &e)
	{
		e.printErr();
	}
	catch (MyArray::eTooBig &e)
	{
		e.printErr();
	}
	catch (MyArray::eTooSmall &e)
	{
		e.printErr();
	}
	catch (...)
	{
		cout << "unknow" << endl;
	}
	
	system("pause");
	return ret;
}