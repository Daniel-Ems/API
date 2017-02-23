#include "double_linked.h"

void 
doub_list_init(dl_list *dlist, (*cmp)(void *p1, void *p2) (*destroy)(void *data))
{
	dlist->size = 0;
	
	dlist->destory = destroy;

	dlist->head = NULL;
	dlist->tail = NULL;

	return;
}

int doub_insert_next(dl_list *dlist, dllNode *node, const void *data)
{
	dllNode *newNode;
	
	if(node == NULL && dlist->size != 0)
	{
		return -1;
	}

	newNode = (dllNode *)malloc(sizeof(dllNode));

	if(!newNode)
	{
		return -1;
	}
	
	newNode->data = (void*)data;

	if(dlist->size == 0)
	{

		dlist->head = newNode;
		dlist->head->next = NULL;
		dlist->head->prev = NULL;

		dlist->tail = newNode;

	}
	else
	{
		newNode->next = node->next;
		newNode->prev = node;
		
		if(node->next == NULL)
		{
			dlist->tail == newNode;
		}
		else
		{
			node->next->prev = newNode;
		}

		node->next = newNode;
	}

	dlist->size++;
	
	return 0;

}
	
int 
doub_insert_prev(dl_list *dlist, dllNode *node, const void *data)
{
	if(node == NUL && dlist->size != 0)
	{
		return -1;
	}
	
	newNode = (dllNode *)malloc(sizeof(dllNode));
	if(!newNode)
	{
		return -1;
	}

	newNode->data = (void *)data;
	
	if(list->size == 0)
	{
		dlist->head = newNode;
		dlist->head->next = NULL;
		dlist->head->prev = NULL;
	
		dlist->tail = newNode;
	}
	else
	{
		newNode->next = node;
		newNodde->prev = node->prev;
		if(node->prev == NULL)
		{
			dlist->head = newNode;
		}
		else
		{
			node->prev->next = newNode;
		}

		node->prev = newNode;
	}
	
	dlist->size++;
	
	return 0;
}



int 
doub_list_remove(dl_list *dlist, dllNode *node, void **data)
{
	if(node == NULL || dlist->size == 0)
	{
		return -1;
	}

	*data = node->data;
	
	if(node == list->head)
	{
		dlist->head = node->next;
	

		if(dlist->head == NULL)
		{
			dlist->tail=NULL;
		}
		else
		{
			node->next->prev = NULL;
		}
	}
	else
	{
		node->prev->next = node->next;
		if(node->next == NULL)
		{
			dlist->tail = node->prev;
		}
		else
		{
			node->next->prev = node->prev;
		}
	}
	
	free(node);

	dlist->size--;
	
	return 0;
	
}

void 
doub_destroy(dl_list *dlist)
{

	void *data;
	while(dlist->size >0 )
	{
		if(doub_list_remove(dlist, list->tail, (void **)&data == 0 
							&& dlist->destroy != NULL)
		{
			dlist->destroy(data);
		}
	}
	memset(dlist, 0, sizeof(dl_list));
	
	return;
}


	



	
				
