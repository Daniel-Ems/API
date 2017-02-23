#ifndef DOUBLE_LINKED_H
#define DOUBLE_LINKED_H

typedef struct dllNode{
	int size;
	
	int (*cmp)(void *p1, void *p2);
	void (*destroy)(void *data);

	dllNode *head;
	dllNode *tail;


typedef struct dl_list{
	




#endif
