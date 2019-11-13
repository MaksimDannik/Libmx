#include "libmx.h"
	
void mx_del_strarr(char ***arr) {
	char **str = *arr;

	while (str++) {
		mx_strdel(str);
	}
	mx_strdel(*arr);

}
