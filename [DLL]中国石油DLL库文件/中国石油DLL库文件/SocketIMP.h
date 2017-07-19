#pragma once
#include "socketIF.h"
class __declspec(dllexport)  SocketIMP : public socketIF
{
public:
	SocketIMP();
	~SocketIMP();
	int socket_send(char *inBuf, int inLen, char *OutBuf, int *OutLen);
	int socket_rev(char *inBuf, int inLen, char *OutBuf, int *OutLen);
};

