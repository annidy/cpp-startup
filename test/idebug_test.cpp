#include "iheader.h"

void test_a()
{
	int i = 0;
	printf("ASSERT -> %s\n", TO_STRING(ASSERT(i == 1)));
	//ASSERT(i == 1);
	ASSERT(i == 0);

	printf("%s\n", TO_STRING(ASSERTP(i == 2, ASSERT_LEVEL_DEBUG)));
	ASSERTP(i == 2, ASSERT_LEVEL_DEBUG);
	//ASSERTP(i == 3, ASSERT_LEVEL_INFO);
	//ASSERTP(i == 4, ASSERT_LEVEL_CRITAL);
	printf("DOne\n");
}

int ci(int i)
{
	printf("I'm in c1\n");
	return i;
}

float cf(int i)
{
	return i*10.0f;
}
/*
bool cb()
{
	return true;
}
*/

void test_c()
{
	printf("CHECK -> %s\n", TO_STRING(CHECK(ci(1), 1)));
	CHECK(ci(1), 0);
	CHECK(ci(1), 1);
	printf("do check cf-> %f\n", CHECK(cf(3), 20.0f));
	//CHECK(cb(), false);
}

int main()
{
	printf("%s\n", TO_STRING(LOG("idebug_test\n")));
	//log_console::instance().printf("idebug_test\n");
	LOG("This is test\n");
	TIME_IT(test_c());
	TIME_IT(test_c());
	return 0;
}