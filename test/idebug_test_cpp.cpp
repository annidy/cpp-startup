#include "iheader.h"

int t()
{
	printf("ttt\n");
	return 1;
}

int main()
{
	int i = 0;
	printf("%s\n", TO_STRING(ASSERT(i == 1)));
	ASSERT(i == 1);
	/*
	//ASSERT(i == 0);

	printf("%s\n", TO_STRING(ASSERTP(i == 2, ASSERT_LEVEL_DEBUG)));
	ASSERTP(i == 2, ASSERT_LEVEL_DEBUG);
	//ASSERTP(i == 3, ASSERT_LEVEL_INFO);
	//ASSERTP(i == 4, ASSERT_LEVEL_CRITAL);
	printf("DOne\n");
	CHECK(t(), 2);
	*/
	return 0;
}
