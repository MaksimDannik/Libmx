#include "libmx.h"

char * mx_itoa(int number) {
	int i = 0;
	int negative = 0;
	int size = mx_intlen(number);	
	char *str = (char *) malloc((size) * sizeof(char));

	if (number < 0) {
		negative = 1;
		number = -number;
	}
	while (number) {
		int sum = number % 10;
		str[i++] = sum + 48;
		number = number / 10;
	}
	if (negative)
		str[i++] = '-';

	str[i] = '\0';
	mx_str_reverse(str);
	return str;
}


