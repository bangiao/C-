#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



class AbsCurrentV18
{
public:
	virtual void useV18() = 0;		//这个函数是纯虚函数 已经定型无法再函数内调用 CurrentV220::useV220()
	//所以需要实例化子类在子类中的函数中实现调用目的
};

//客户希望的接口
class CurrentV220
{
public:
	void useV220()
	{
		cout << "use V220" << endl;
	}
};

class Adapter : public AbsCurrentV18
{
public:
	Adapter(CurrentV220 *CurV200)
	{
		m_CurV200 = CurV200;
	}
	//在子类的虚函数中, 调用目标类中的函数 CurrentV220::useV220() 达到目的
	virtual void useV18()
	{
		cout << "适配器使用:" << endl;
		m_CurV200->useV220();
	}
protected:
private:
	CurrentV220 *m_CurV200;

};

int main(int argc, char *argv[])
{
	int ret = 0;
	CurrentV220 *pV200 = NULL;
	Adapter *pAd = NULL;


	pV200 = new CurrentV220;		//创建目标对象
	pAd = new Adapter(pV200);		//将目标对象放入适配器
	pAd->useV18();					//达到调用目标对象的目的

	delete pAd;
	delete pV200;
	
	
	system("pause");
	return ret;
}