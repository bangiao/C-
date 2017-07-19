#include "iostream"
#include "SocketIMP1.h"
using namespace std;

int mainOP(SocketIF *pBase, unsigned char *buf_in, int buflen_in, unsigned char *buf_out, int *buflen_out)
{
	pBase->cltSocket_senddata(buf_in, buflen_in);
	pBase->cltSocket_resvdata(buf_out, buflen_out);
	pBase->cltSocket_destory();
	return 0;
}

int main()
{
	int ret = 0;
	unsigned char buf_in[1024] = "abcdefghijklmn";
	int buflen_in = 10;
	unsigned char buf_out[1024] = { 0 };
	int buflen_out = 10;
	SocketIF *pBase = new SocketIMP1();	//new一个构造函数进行初始化 类似于 SocketIMP1 s1 = SocketIMP1();

	ret = mainOP(pBase, buf_in, buflen_in, buf_out, &buflen_out);
	printf("%s\n", buf_out);
	delete pBase;
	pBase = NULL;
	system("pause");
	return ret;
}