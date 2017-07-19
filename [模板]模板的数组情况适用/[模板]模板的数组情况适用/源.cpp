#include <iostream>
using namespace std;

template <class T>
class C
{
public:
	C(T *arr, int nLen)
	{
		this->m_nLen = nLen;
		this->m_pArr = new T[nLen];
		memcpy(this->m_pArr, arr, (sizeof(*(this->m_pArr)) * nLen));
	}
	T getElem(int i)
	{
		return this->m_pArr[i];
	}
	~C()
	{
		if (NULL != this->m_pArr)
			delete[]this->m_pArr;
		this->m_nLen = 0;
	}
private:
	T *m_pArr{ NULL };
	int m_nLen{ 0 };
};

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int nLen = sizeof(arr) / sizeof(*arr);

	C<int> *c = new C<int>(arr, nLen);
	for (int i = 0; i < nLen; i++)
	{
		cout << c->getElem(i) << endl;
	}
	system("pause");
	return 0;
}