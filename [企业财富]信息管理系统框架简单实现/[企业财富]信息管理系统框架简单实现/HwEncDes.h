//����ǻ�Ϊ(����������)�Ķ�Ӧ��ʯ�͵Ľӿ���д���Լ�������
#pragma once
#include "CEncDesProtocol.h"
class HwEncDes : public CEncDesProtocol
{
public:
	int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);
	int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);
};
