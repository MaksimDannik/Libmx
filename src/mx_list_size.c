#include "libmx.h"

int mx_list_size(t_list *list) {
	int i = 0;
	t_list* new = list;

	while (new != NULL) {
		i++;
		new = new->next;		
	}
	return i;
}

