#include "iheader.h"

int do1(int i)
{
	return i+1;
}

int main()
{
	int i = 0;
	printf("%s\n", TO_STRING(ASSERT(i == 1)));
	//ASSERT(i == 1);
	ASSERT(i == 0);

	printf("%s\n", TO_STRING(ASSERTP(i == 2, ASSERT_LEVEL_DEBUG)));
	ASSERTP(i == 2, ASSERT_LEVEL_DEBUG);
	//ASSERTP(i == 3, ASSERT_LEVEL_INFO);
	//ASSERTP(i == 4, ASSERT_LEVEL_CRITAL);
	printf("DOne\n");
	CHECK(do1(1), 2);
	CHECK(do1(2), 3);
	CHECK(do1(3), 2); // check failed

	CODE_TRACE
	//FOR_DEBUG(printf("only debug\n"));
	CODE_TRACE
	return 0;
}
