#include "set.h"

void 
set_init(Set *set, int (*match)(const void *key1, const void *key2), 
		void (*destroy)(void *data));
{
	list_init(set, match, destroy);
	return;
}

int 
is_member(const Set *set, const void *data)
{
	list_node *setNode;

	for(node = set->next; node !=NULL; node = node->next)
	{
		if(set->match(data, node->data)
		{
			return 1;
		}
	}
	return 0;
}
 

int
set_insert(Set *set, const void *data)
{
	if(is_member(set, data))
	{
		return 1;
	}
	
	return insert_next(set, set->tail, data);
}

int 
set_union(Set *setu, const Set *set1, const Set *set2)
{
	list_node *node;

	void *data;

	set_init(setu, set1->match, NULL);
	
	for(node = set1->head; node !=NULL; node = node->next)
	{
	
		data = node->data;

		if(insert_next(setu, setu->tail, data)!=0)
		{
	
			list_destroy(setu);
			return -1;

		}

	}

	for(node = set2->head; node != NULL; node = node->next)
	{

		if(is_member(set1, node->data))
		{
			continue;
		}

		else
		{
			
			data = node->data;

			if(insert_next(setu, setu->tail, data) !=  0)
			{
				list_destroy(setu);
				return -1;	
			}

		}

	}

	return 0;
	
}

int
set_instersection(Set *seti, const Set *set1, const Set *set2)
{
	list_node *node;
	
	void *data; 

	set_init(seti, set1->match, NULL);

	for(node = set1->head; node !=NULL; node = node->next)
	{
		
		if(is_member(set2, node->data))
		{
			data = node->data; 	
		
			if(insert_next(seti, seti->tail, data) != 0)
			{
				set_destroy(seti);
				return -1;
			}
		
		}
		
	}
	
	return 0;

}

int 
set_difference(Set *setd, const Set *set1, const Set *set2)
{
	list_node *node;

	void *data;

	set_init(setd, set1->match, NULL);
	
	for(node = set1->head; node != NULL; node = node->next)
	{
		
		if(!is_member(set2, node->data)
		{
			
			data = node->data;
	
			if(insert_next(setd, setd->tail, data) !=0)
			{			
				set_Destroy(setd);
				return -1;
			}
		
		}
	
	}
	
	return 0;

}

int 
is_subset(const Set *set1, const Set *set2)
{
	
	list_node *node;

	if(set1->size > set2->size)
	{
		return 0;
	}

	for(node = node->head(set1); node != NULL; node = node->next)
	{
		
		if(is_member(set2, node->data))
		{
			return 0;
		}
	}

	return 1;
}

int
is_equal(const Set *set1, const Set *set2)
{

	if(set1->size != set2->size)
	{
		return 0;
	}
	
	return is_subset(set1, set2);
}

int
set_remove(Set *set, void **data)
{
	list_node *newNode, *prevNode;

	prevNode = NULL;
	
	for(newNode = set->head; node !=NULL; newNode = newNode->next)
	{
		if(set->match(*data,  newNode->data))
		{
			break;
		}

	prevNode = newNode;

	}
	
	if(newNode == NULL)
	{
		return -1;
	}

	return remove_next(set,  prevNode, data);
}
