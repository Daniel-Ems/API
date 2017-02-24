#ifndef LINKED_LIST.H
#define LINKED_LIST.H

#include <stdio.h>

/*******************************************************************************
This struct is the node of the list. The void *data will store whatever struct 
you need for your particular situation. 
*******************************************************************************/ 
typedef struct list_node{
	void *data;
	struct list_node *next;
}list_node;


/*******************************************************************************
This struct will be passed around as the linked list. From here you will have 
access to the head, tail, destroy and compare function. You will pass this 
struct to your function and then access the members of your struct by taversing
through either the head our tail
*******************************************************************************/
typedef struct List{
	int size;

	int (*cmp)(void *p1, void *p2);
	void (*destroy)(void *data);

	list_node  *head;
	list_node *tail;
}List;

void 
list_init(List *list, int(*cmp)(void *p1, void *p2), void(*destroy)(void*));

int 
insert_next(List *list, list_node *node, const void *data);

int 
is_tail(List *list, list_node *node);

int
is_head(List *list, list_node *node);

int 
remove_next(List *list, list_node *node, void **data);

void 
list_destory(List *list);

#endif
