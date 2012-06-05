#include <stdio.h>
#include "iheader.h"


int test(int i)
{
	printf("test %d\n", i);
	set_error(122);
	return errno;
	return_perror(i+1);
	return 0;
}

void test2(int i)
{
	switch(i)
	{
	case 1:
		goto_error(1, e1);
	case 2:
		goto_error(2, e2);
	case 3:
		goto_error(3, e3);
	}

e3:
	printf("e3 \n");
	return;

e2:
	printf("e2 \n");
	return;

e1:
	printf("e1\n");
	return;
}

void test3(int i)
{
	for (;i;i--)
	{
		if (i == 1)
			break_error(1);
		if (i == 2)
			break_error(2);
		if (i == 3)
			break_error(3);
	}
}

int main()
{
	int i;
	printf(TO_STRING(return_perror(1)));
	printf("test(3) = %d\n", test(3));
	printf("Now, the errno = %d\n", errno);
	printf(TO_STRING(goto_error(1, e1)));
	printf("\n");
	test2(1);
	printf("Now, the errno = %d\n", errno);
	test2(2);
	printf("Now, the errno = %d\n", errno);
	test2(3);
	printf("Now, the errno = %d\n", errno);
	printf(TO_STRING(break_error(1, e1)));
	printf("\n");
	test3(1);
	printf("Now, the errno = %d\n", errno);
	test3(2);
	printf("Now, the errno = %d\n", errno);
	test3(3);
	printf("Now, the errno = %d\n", errno);
	i = 1111111111;
	printf("%d\n", (short)i+1);
	printf("%d\n",  << 32);
	return 0;
}
