#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// class x
// {
// public:
// protected:
// private:
// };
// 
// class y :public virtual x
// {
// public:
// protected:
// private:
// };
// 
// class z : public virtual x
// {
// public:
// protected:
// private:
// };
// 
// class a : public y, public z
// {
// public:
// protected:
// private:
// };
// 
// 
// 
// int main(int argv, char *args[])
// {
// 	cout << sizeof(a) << endl;
// 	printf("hello world...\n");
// 	system("pause");
// 	return 0;
// }

class x{};
class Y : public virtual x
{

};
class Z : public virtual x
{

};
class A : public Y, public Z
{

};
int main()
{
	cout << sizeof(A) << endl;
	system("pause");
	return 0;
}
