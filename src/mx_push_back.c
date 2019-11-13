#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
	if (!list || !*list)
		return;
	
	t_list *Node = mx_create_node(data);
	t_list *new = *list;
	
	while (new->next != NULL) {
		new = new->next; 
	}
	new->next = Node;

}

