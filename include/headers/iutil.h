#pragma once

#define SAFE_DELETE(p)          { if(p) delete p, p = 0; }
#define SAFE_DELETE_ARRAY(p)    { if(p) delete[] p, p = 0; }
#define SAFE_FREE(p)            { if(p) free(p), p = 0; }

#define COUNT_OF(v) (sizeof(v)/sizeof(v[0]))

// malloc struct
#define MALLOCS(T, o) T* o = (T*)malloc(sizeof(T))

/* Round up and down @num to 2 in power of @order. */
#define ROUND_UP(num,order)	(((num) + ((1 << (order)) - 1)) & ~((1 << (order)) - 1))
#define ROUND_DOWN(num,order) ((num) & ~((1 << (order)) - 1))

/* expand the macro */
#define TO_STRING(x) TO_STRING1(x)
#define TO_STRING1(x) #x