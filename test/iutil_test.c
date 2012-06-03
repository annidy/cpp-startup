#include "iheader.h"

int main()
{
	int a[100];
	printf("COUNT_OF a=%d\n", COUNT_OF(a));

	int b = 513;
	printf("b , 512 align, ROUND_UP=%d, ROUND_DOWN=%d\n",
		   ROUND_UP(b, 9), ROUND_DOWN(b, 9));	
}
