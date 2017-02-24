#ifndef SET_H
#define SET_H

#include <stdlib.h>

#include "linked_list.h"

typedef List Set;

void 
set_init(Set *set, int (*match)(const void *key1, const void *key2), 
		void (*destroy)(void *data));

int 
is_member(const Set *set, const void *data);

int
set_insert(Set *set, const void *data);

int 
set_union(Set *setu, const Set *set1, const Set *set2);

int
set_instersection(Set *seti, const Set *set1, const Set *set2);

int 
set_difference(Set *setd, const Set *set1, const Set *set2);

int 
is_subset(const Set *set1, const Set *set2);

int
is_equal(const Set *set1, const Set *set2);

int
set_remove(Set *set, void **data);
