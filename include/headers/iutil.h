#pragma once

#define SAFE_DELETE(p)          { if(p) delete p, p = 0; }
#define SAFE_DELETE_ARRAY(p)    { if(p) delete[] p, p = 0; }
#define SAFE_FREE(p)            { if(p) free(p), p = 0; }

#define COUNT_OF(v) (sizeof(v)/sizeof(v[0]))

// malloc struct
#define MALLOCS(T, o) T* o = (T*)malloc(sizeof(T));

/* Round up and down @num to 2 in power of @order. */
#define ROUND_UP(num,order)	(((num) + ((1 << (order)) - 1)) & ~((1 << (order)) - 1))
#define ROUND_DOWN(num,order) ((num) & ~((1 << (order)) - 1))

/* expand the macro */
#define TO_STRING(x) TO_STRING1(x)
#define TO_STRING1(x) #x

#ifdef _MSC_VER
#define INT64_FORMAT    "I64"  
#else  
#define INT64_FORMAT    "ll"  
#endif

#ifdef __cplusplus
#include <time.h>
// there was a bug of __LINE__ in MSVC, see
// http://bytes.com/topic/c/answers/692912-creating-unique-temporary-variables-using-__line__-other-macro
template<long i>
struct _UniqueClock_t {
	static clock_t var;
};
template<long i>
clock_t _UniqueClock_t<i>::var;

#define EXEC(F) F
#define TIME_IT(F) \
	_UniqueClock_t<__LINE__>::var = clock();\
	EXEC(F);\
	LOG("Time "#F" = %dms\n", (clock()-_UniqueClock_t<__LINE__>::var)*1000/CLOCKS_PER_SEC);
#else
#define TIME_IT(F) F
#endif // #ifdef __cplusplus

#define BREAK_CHECK(L, R)  if((R) != (L)) break;
#define RETURN_CHECK(L, R) if((R) != (L)) return;
#define RETURN_CHECK1(L, R, R1) if((R) != (L)) return (R1);
#define GOTO_CHECK(L, R, G) if((R) != (L)) goto G;

#define BREAK_CHECK_NOT(L, R)  if((R) == (L)) break;
#define RETURN_CHECK_NOT(L, R) if((R) == (L)) return;
#define RETURN_CHECK_NOT1(L, R, R1) if((R) == (L)) return (R1);
#define GOTO_CHECK_NOT1(L, R, G) if((R) == (L)) goto G;