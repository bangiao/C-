#include <iostream>
using namespace std;

class String
{
public:
	String()
	{
		cout << "无参构造函数" << endl;
		this->m_nLen = 0;
		this->m_str = NULL;
	}
	String(char *str) noexcept(true)
	{
		cout << "有参构造函数" << endl;
		int len = strlen(str) + 1;
		this->m_nLen = len;
		this->m_str = new char[len * sizeof(*(this->m_str))];
		if (NULL == this->m_str)
		{
			throw 1;// 不抛出异常, 但是就是给他抛出, 给他出错
		}
		memset(this->m_str, 0, len * sizeof(*(this->m_str)));
		memcpy(this->m_str, str, len * sizeof(*(this->m_str)));
		
	}
	String(const String &s) noexcept(true)
	{
		cout << "拷贝构造函数" << endl;
		this->m_nLen = s.m_nLen;
		this->m_str = new char[this->m_nLen * sizeof(*(this->m_str))];
		if (NULL == this->m_str)
		{
			throw 1;
		}
		memset(this->m_str, 0, this->m_nLen * sizeof(*(this->m_str)));
		memcpy(this->m_str, s.m_str, this->m_nLen * sizeof(*(this->m_str)));
	}
	String &operator=(String &s) noexcept(true)
	{
		cout << "函数重载" << endl;
		if (this->m_str != NULL)
		{
			delete[]this->m_str;
			this->m_str = NULL;
		}
		this->m_nLen = s.m_nLen;
		this->m_str = new char[s.m_nLen];
		if (NULL == this->m_str)
		{
			throw 1;
		}
		memset(this->m_str, 0, this->m_nLen * sizeof(*(this->m_str)));
		memcpy(this->m_str, s.m_str, this->m_nLen * sizeof(*(this->m_str)));
		return *this;
	}
	~String()
	{
		cout << "析构函数" << endl;
		if (NULL != this->m_str)
		{
			delete []this->m_str;
		}
		this->m_str = NULL;
		this->m_nLen = 0;
	}
private:
	char *m_str{ NULL };
	int m_nLen{0};
};

void mainOP()
{
	String s("zhazha");
	String s1 = String(s);
	String s2;
	s2 = String("重载");
}

int main(void)
{
	mainOP();
	system("pause");
	return 0;
}