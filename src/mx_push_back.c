#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
	t_list *Node = mx_create_node(data);
	t_list *new = *list;
	
	Node->data = data;
	Node->next = NULL;
	if (*list == NULL) {
		*list = new;
		return;
	}	

	while (new->next != NULL) {
		new = new->next; 
	}
	new->next = Node;
	return;
}

