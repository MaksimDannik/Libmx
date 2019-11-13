#include "libmx.h"

int mx_list_size(t_list *list) {
	t_list *new = list;
	int i = 0;

	while (new != NULL) {
		new = new->next;
		i++;		
	}
	return i;
}

