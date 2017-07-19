#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



class AbsCurrentV18
{
public:
	virtual void useV18() = 0;		//��������Ǵ��麯�� �Ѿ������޷��ٺ����ڵ��� CurrentV220::useV220()
	//������Ҫʵ���������������еĺ�����ʵ�ֵ���Ŀ��
};

//�ͻ�ϣ���Ľӿ�
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
	//��������麯����, ����Ŀ�����еĺ��� CurrentV220::useV220() �ﵽĿ��
	virtual void useV18()
	{
		cout << "������ʹ��:" << endl;
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


	pV200 = new CurrentV220;		//����Ŀ�����
	pAd = new Adapter(pV200);		//��Ŀ��������������
	pAd->useV18();					//�ﵽ����Ŀ������Ŀ��

	delete pAd;
	delete pV200;
	
	
	system("pause");
	return ret;
}