#include "iheader.h"

int test(int i)
{
	printf("return %d\n", i+i);
	return_perror(i);
}

int main()
{
	test(0);
}
