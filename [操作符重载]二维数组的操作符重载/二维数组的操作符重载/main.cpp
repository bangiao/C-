#include <iostream>
#include <iomanip>
using namespace std;

class M33
{
public:
	M33(int n = 0)
	{
		for (int n = 0; n < 3; n++)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						this->m_a[n][i][j][k] = n;
					}
				}
			}
		}
	}
	int &operator[](int i)
	{
		static int *tmp = (int *)this->m_a - 1;
		static int j = 0;
		static int size = sizeof(this->m_a) / sizeof(int);
		if (size == j)
		{
			j = 0;
			tmp = (int *)this->m_a - 1;
		}
		j++;
		tmp++;
		return *tmp;
	}
protected:
private:
	int m_a[3][3][3][3];
};

int main()
{
	M33 m1(0);
	int num = 0;
	for (int n = 0; n < 81; n++)
	{
		m1[n] = ++num;
	}

	for (int n = 0; n < 81; n++)
	{
		printf("%3d", m1[n]);
	}
					
	system("pause");
	return 0;
}