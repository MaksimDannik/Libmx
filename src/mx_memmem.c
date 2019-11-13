#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	const char *b = (const char *) big;
	const char *li = (const char *) little;

	if (big_len < little_len || !little_len || !big_len) 
		return NULL;

	if (little_len == 0) 
		return (void *)big;
	
	 char *box = mx_strstr(b, li);
		return (char *)box;

return NULL;
}

