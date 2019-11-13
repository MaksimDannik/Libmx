#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	if (str == NULL || sub == NULL)
		return -2;
	
	for (int i = 0 ; str[i] != '\0'; i++, str++) {
		if (str[i] == sub[i]) {
			if (mx_strstr(str, sub) == (char *)sub) {
				return i;
			}
		}
	}
	return -1; 
}

