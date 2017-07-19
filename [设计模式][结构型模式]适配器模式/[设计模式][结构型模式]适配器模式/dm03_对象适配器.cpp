#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AbsTarget
{
public:
	AbsTarget(){}
	virtual ~AbsTarget(){}
	virtual void Request() = 0;
};

//目标类
class Adaptee
{
public:
	void AdapteeRequest()
	{
		cout << "Adaptee::AdapteeRequest()" << endl;
		cout << "恭喜!达到目的~666666..." << endl;
	}
};

//适配器
class Adapter : public AbsTarget
{
public:
	
	Adapter() : m_Adaptee(new Adaptee){}
	~Adapter()
	{
		if (NULL != this->m_Adaptee)
		{
			delete this->m_Adaptee;
		}
		this->m_Adaptee = NULL;
	}
	virtual void Request()
	{
		//cout << "Adapter::Request()" << endl;
		m_Adaptee->AdapteeRequest();
	}
private:
	Adaptee *m_Adaptee;
};

int main(int argc, char *argv[])
{
	int ret = 0;

	AbsTarget *ada = NULL;
	ada = new Adapter();
	ada->Request();
	
	system("pause");
	return ret;
}