#include "linked_list.h"

void 
list_init(List *list, int(*cmp)(void *p1, void *p2), void(*destroy)(void*))
{

	list = (List*)malloc(sizeof(*List));
	if(!List)
	{
		printf("Memory Error\n");
		return;
	}

	list->size = 0;

	list->cmp = cmp;

	list->destroy = destroy;
	
	list->head = NULL;

	list->tail = NULL;

}

int 
insert_next(List *list, list_node *node, const void *data)
{

	list_node *newNode = (list_node*)malloc(list_node);

	if(!list_node)
	{
		printf("Memory Error\n");
		return -1;
	}

	newNode->data = (void*) data;

	if(node == NULL)
	{

		if(list->size == 0)
		{
			list->tail = newNode;
		}
	
		newNode->next = list->head;
			
		list->head = newNode;
		
	}
	else
	{

		if(node->next == NULL)
		{
			list->tail = newNode;
		}

		newNode->next = node;

		node->next = newNode;
	}

	list->size++;
	
	return 0;

}

int 
is_tail(List *list, list_node *node)
{
	if(node == NULL)
	{
		return -1;
	}

	if(node == list->tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int 
is_head(List *list, list_node *node)
{
	if(node == NULL)
	{
		return -1;
	}

	if(node == list->head)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int 
remove_next(List *list, list_node *node, void **data)
{
	
	list_node *oldNode;

	if(list->size = 0)
	{
		printf("The list is empty\n");
		return -1;
	}
	
	if(node == NULL)
	{
		*data = list->head->data;
	
		oldNode = list->head;
	
		list->head = list->head->next;

		if(list->size == 1)
		{
			list->tail = NULL;
		}

	}
	else 
	{

		if(node->next == NULL)
		{
			printf("Please provide the node preceding the node you wish to"
						"remove\n");
			return -1;
		}

		*data = node->next->data;

		oldNode = node->next;

		node->next = oldNode->next;

		if(node->next == NULL)
		{
			list->tail = node;
		}
	}

	free(oldNode);
	
	list->size--;
	
	return 0;
}

void 
list_destory(List *list)
{
	void *data;

	while(list->size > 0)
	{

		if(remove_next(list, NULL, (void **)&data == 0 
						&& list->destroy != NULL))
		{
			list->destroy(data);
		}
	}

	memset(list, 0, sizeof(List));

	return; 
}




	
	
		
