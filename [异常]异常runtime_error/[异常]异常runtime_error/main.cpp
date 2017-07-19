#include <iostream>
using namespace std;

class A
{
public:
	A(int a) noexcept (false)
	{
		if (-1 == a)
		{
			throw runtime_error("runtime_error");
		}
		if (1 == a)
		{
			throw exception("exception");
		}
		if (2 == a)
		{
			throw range_error("range_error");
		}
		if (3 == a)
		{
			throw overflow_error("overflow_error");
		}
		if (4 == a)
		{
			throw underflow_error("underflow_error");
		}
		if (5 == a)
		{
			throw logic_error("logic_error");
		}
		if (6 == a)
		{
			throw domain_error("domain_error");
		}
		if (7 == a)
		{
			throw invalid_argument("invalid_argument");
		}
		if (8 == a)
		{
			throw length_error("length_error");
		}
		if (9 == a)
		{
			throw out_of_range("out_of_range");
		}
		this->a = a;
	}
private:
	int a;
};

int main(void)
{
	int n = 0;
	try
	{
		cin >> n;
		A a(n);
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

// 	catch (range_error e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	catch (overflow_error e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	catch (underflow_error e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	catch (logic_error e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	catch (domain_error e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	catch (invalid_argument e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	catch (length_error e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	catch (out_of_range e)
// 	{
// 		cout << e.what() << endl;
// 	}

	system("pause");
	return 0;
}