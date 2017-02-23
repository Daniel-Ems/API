#ifndef DOUBLE_LINKED_H
#define DOUBLE_LINKED_H

#include <stdio.h>
#include <stdlib.h>

typedef struct dllNode{
	int size;
	
	int (*cmp)(void *p1, void *p2);
	void (*destroy)(void *data);

	struct dllNode *head;
	struct dllNode *tail;
}dllnode;

typedef struct dl_list{

	void *data;

	struct dllNode *previous;
	struct dllnode *next;

}dl_list;
	

void 
doub_list_init(dl_list *dlist, (*cmp)(void *p1, void *p2),
				 (*destroy)(void *data));

int 
doub_list_remove(dl_list *dlist, dlNode *node, void **data);

int 
doub_insert_next(dl_list *dlist, dlNode *node, const void *data);

int 
doub_insert_prev(dl_list *dlist, dlNode *node, const void *data);

void 
doub_destroy(dl_list *dlist);

#endif
