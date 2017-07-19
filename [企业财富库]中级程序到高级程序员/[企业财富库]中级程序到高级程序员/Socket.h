#pragma  once 

typedef int(*EncDataFunc)(unsigned char *inData, int inLen, unsigned char *outData, int *outLen);
typedef int(*DecDataFunc)(unsigned char *inData, int inLen, unsigned char *outData, int *outLen);

__declspec(dllexport)
int Socket_SetEnc(void *Handle, EncDataFunc enc, DecDataFunc Dec);
__declspec(dllexport)
int Socket_Init(void **Handle);
__declspec(dllexport)
int Socket_Send(void *Handle, unsigned char *inData, int inLen);
__declspec(dllexport)
int Socket_Res(void *Handle, unsigned char *outData, int *outLen);
__declspec(dllexport)
void Socket_Destory(void **Handle);