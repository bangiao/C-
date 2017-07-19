#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>

//迭代器就像一个指针  用法和指针类似
//想要知道迭代器就要知道这几点:
//一:
//1	迭代器的 begin() 指向的是数组的头个元素
//2	迭代器的 end() 指向的是数组最后一个与元素之后(此时不再指向数组的元素)

// begin()
//  1   3   5
//  △
// end()
//  1   3   5
//            △

//2  迭代器的种类

// 1)只读
// 2)只写
// 3)正向
// 4)双向
// 5)逆向

//正向遍历数组元素
int main11()
{
	vector<int> v1(10);
	int i = 0; 
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++, i++)
	{
		*it = i + 1;
	}

	for (vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	return 0;
}


//反向遍历数组元素
int main12()
{
	vector<int> v1(10);
	int i = 0;
	
	for (vector<int>::iterator it = v1.begin(); v1.end() != it; it++)
	{
		*it = i++;
	}

	for (vector<int>::reverse_iterator it1 = v1.rbegin(); it1 != v1.rend(); it1++)
	{
		cout << *it1 << " ";
	}

	cout << endl;
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	
//	main11();
	main12();
	system("pause");
	return ret;
}