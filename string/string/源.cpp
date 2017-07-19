#if 0
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str1, str2;
	str1 = "hello";
	str2 = "world";

	string str3 = str1 + str2;
	cout << str3 << endl;

	string s = string("hello ") + "world";

	string s1 = s + "   zhazha" + "qieqie";
	cout << s1 << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main(void)
{
	string str("some string");
	for (auto c : str)
	{
		cout << c ;
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s("helloworld!!!");
	decltype(s.size()) punct_cnt = 0;
	for (auto c : s)
	{
		if (ispunct(c))
		{
			++punct_cnt;
		}
	}
	cout << punct_cnt << "  punctuation characters in " << s << endl;
	system("pause");
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s = "Hello world!!!";
	for (auto &c : s)
	{
		c = toupper(c);
	}
	cout << s << endl;
	system("pause");
	return 0;
}