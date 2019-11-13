#include "libmx.h"
char *mx_strstr(const char *haystack, const char *needle) { // шукаємо перше входження підстроки needle в строці haystac
	int i = mx_strlen(needle);

	if (needle == NULL) 
		return (char *)haystack;
	
	while (haystack) {
		if (mx_strchr(haystack, *needle) == haystack) 
			if (mx_strncmp(haystack, needle, i) == 0)
				return (char *)haystack;
		haystack++;
	}		
	return NULL;
}
