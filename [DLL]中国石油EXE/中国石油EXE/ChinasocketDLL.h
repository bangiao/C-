#pragma once
class __declspec(dllexport) ChinaSocketDLL
{
public:
	ChinaSocketDLL();
	virtual ~ChinaSocketDLL();
	int mainOP(char *inBuf, int inLen, char *OutBuf, int *OutLen);


// 	int socket_send(char *inBuf, int inLen, char *OutBuf, int *OutLen);
// 	int socket_rev(char *inBuf, int inLen, char *OutBuf, int *OutLen);
};
