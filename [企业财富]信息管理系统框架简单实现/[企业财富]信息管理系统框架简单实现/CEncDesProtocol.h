//这个文件是由中石油发出的接口类文件  用于其他厂商进行继承
#pragma once 
class CEncDesProtocol
{
public:
	CEncDesProtocol(){}
	virtual ~CEncDesProtocol(){}
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen) = 0;
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen) = 0;
};