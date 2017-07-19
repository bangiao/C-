#include <iostream>
#include "socketIMP1.h"
#include "socketprotocol.h"
using namespace std;


int mainOP(unsigned char *sIn, int Inlen, unsigned char *sOut, int *Outlen)
{
	int ret = 0;
	SocketIF *pSocket = new socketIMP1();

// 	ret = pSocket->cltSocket_init();
// 	if (-1 == ret)
// 	{
// 		cout << "func err cltSocket_init() line:" << __LINE__ << __FILE__ << endl;
// 		return ret;
// 	}

	ret = pSocket->cltSocket_senddata(sIn, Inlen);
	if (-1 >= ret)
	{
		cout << "func err cltSocket_senddata() line:" << __LINE__ << __FILE__ << endl;
		goto END;
	}
	ret = pSocket->cltSocket_resvdata(sOut, Outlen);
	if (-1 >= ret)
	{
		cout << "func err cltSocket_resvdata() line:" << __LINE__ << __FILE__ << endl;
		goto END;
	}

END:
	pSocket->cltSocket_destory();
	delete pSocket;
	pSocket = NULL;
	return ret;
}

int main()
{
	int ret = 0;
	unsigned char sIn[1024] = "aaaa454asdsaf";
	int Inlen = 10;
	unsigned char sOut[1024] = { 0 };
	int Outlen = 10;

	ret = mainOP(sIn, Inlen, sOut, &Outlen);
	if (-1 == ret)
	{
		system("pause");
		return ret;
	}

	cout << sOut << endl;
	system("pause");
	return 0;
}