#include "linked_list.h"

void 
listInit(List *list, int(*cmp)(void *p1, void *p2), void(*destroy)(void*))
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
insertNext(List *list, list_node *node, const void *data)
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
removeNext(List *list, list_node *node, void **data)
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


	
	
		
