#include <stdio.h>
#include "iheader.h"


int test(int i)
{
	printf("test %d\n", i);
	return_perror(i+1);
	return 0;
}

int main()
{
	printf(TO_STRING(return_perror(1)));
	test(3);
	printf("Now, the errno = %d\n", errno);
	return 0;
}
