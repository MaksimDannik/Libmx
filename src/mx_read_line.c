#include "libmx.h"

static char * mx_returned (char **lineptr) {
	mx_strdel(lineptr);
	return NULL;
}
static int set_str(char **rem, char **lineptr, int delim) {
	char *tmp;
    int len;

	if (*rem && mx_strchr(*rem, delim)) {
		len = mx_get_char_index(*rem, delim);
		*lineptr = mx_strnew(len);  
        *lineptr = mx_strncpy(*lineptr, *rem, len);
        tmp = mx_strdup(&((*rem)[len + 1]));
        mx_strdel(rem);
        *rem = tmp;
		if (*rem[0] == '\0') 
			mx_strdel(rem);
    }
	else {
		len = mx_strlen(*rem);
	(*rem) ? *lineptr = mx_strdup(*rem) : (*lineptr = mx_returned(lineptr));
    mx_strdel(rem);  
	}
	return (len);
}

static int get_ret_value(char **rem, char **lineptr, char delim, int ret) {
	if (ret < 0)
    	return -2;
	if (ret == 0) {
    	set_str(rem, lineptr, delim);
        return -1;
    }
    else
		return set_str(rem, lineptr, delim);
}

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
	static char *rem [256];
	char buf[buf_size + 1];
	char *tmp;
	int ret = 0;

	if (buf_size < 0 || fd < 0)
		return -2;
	if ((rem[fd] && !mx_strchr(rem[fd], delim)) || !rem[fd])
		while ((ret = read(fd, buf, buf_size)) > 0) {
        	buf[ret] = '\0';
			if (rem[fd] == NULL)
				rem[fd] = mx_strdup(buf);
    		else {
    			tmp = mx_strjoin(rem[fd], buf);
        		free(rem[fd]);
        		rem[fd] = tmp;
    		}
    		if (rem[fd] && mx_strchr(rem[fd], delim))
    			break;
    }
	if (ret != -1 && ret < buf_size)
		ret = 0;
    return get_ret_value(&rem[fd], lineptr, delim, ret);
}

int main() {
          int fd = open("file", O_RDONLY);
       //   int fd2 = open("file2", O_RDONLY);
          char *str = NULL;
          printf("%d:%s\n", mx_read_line(&str, 20, 'f', fd), str);
          printf("%d:%s\n", mx_read_line(&str, 20, 'f', fd), str);
          printf("%d:%s\n", mx_read_line(&str, 20, 'f', fd), str);
    printf("%d: %s\n", mx_read_line(&str, 20, 'f', fd), str);
printf("%d: %s\n", mx_read_line(&str, 20, 'f', fd), str);
printf("%d: %s\n", mx_read_line(&str, 20, 'f', fd), str);
printf("%d: %s\n", mx_read_line(&str, 20, 'f', fd), str);
printf("%d: %s\n", mx_read_line(&str, 20, 'f', fd), str);
         // printf("%d: %s\n", mx_read_line(&str, 35, 't', fd), str);
       //   printf("%d: %s\n", mx_read_line(&str, 4, '.', fd2), str);
  }
