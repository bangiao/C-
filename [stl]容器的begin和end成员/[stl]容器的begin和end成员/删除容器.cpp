#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
	map<int, string> m_map;
	map<int, string>::iterator it = m_map.begin();
	for (int i = 0; i < 10; i++)
	{
		m_map.insert(make_pair(i, "zhazha"));
	}
	for (auto &c : m_map)
	{
		cout << "ID:" << c.first << "  Val: " << c.second << endl;
	}

	system("pause");
	return 0;
}