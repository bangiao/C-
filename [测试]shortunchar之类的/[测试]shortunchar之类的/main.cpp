#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argv, char *args[])
{
	int ret = 0;
	short int s = 255;
	short *pS = &s;
	unsigned char sh = s;
	unsigned char *pSh = &sh;
	printf("%d\n", sh);
	system("pause");
	return ret;
}
