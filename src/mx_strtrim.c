#include "libmx.h"

char *mx_strtrim(const char *str) {
	if (!str) 
		return NULL;
	
	int cw = 0;
	int size = mx_strlen(str);
	int len = size;

	while (mx_isspace(str[size-1])) {
		size--;
		cw++;
	}

	while (mx_isspace(*str)) {
			str++;
			size--;
			cw++;
	}

	if (len == size)
		return (char*)str;
	char *src = mx_strnew(size);
	src = mx_strncpy(src, str, size);

	if (cw <= 0)
		return NULL;
	return src;
}
