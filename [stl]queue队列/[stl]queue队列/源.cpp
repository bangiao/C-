#include <iostream>
using namespace std;
#include <queue>

void main11()
{
	queue<int> q;
	for (int i = 0; i < 5; i++)
	{
		q.push(i + 1);
	}

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

int main(int argv, char *args[])
{
	int ret = 0;
	main11();
	system("pause");
	return ret;
}