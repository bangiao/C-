#include <iostream>
using namespace std;

//��������ǵĵط�����ʹ���� (T a) �ĵط� 
//Ҳ����˵ֻҪ�������� a �ĵط���Ҫ��  �����б�
template <class T>
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
	void setA(T a)
	{
		this->a = a;
	}
	int getA()
	{
		return this->a;
	}
protected:
private:
	T a;		//////////////////////////////////////////////////////////////////////////
};

class BB : public AA<int>	//////////////////////////////////////////////////////////////////////////
{
public:
	BB(int a = 0, int b = 0) : AA<int>(a)	/////////////////////////////////////////////////
	{
		this->b = b;
	}
protected:
private:
	int b;
};
int main()
{
	AA<int> a1(1);	//////////////////////////////////////////////////////////////////////////
	BB b1(2, 3);
	system("pause");
	return 0;
}