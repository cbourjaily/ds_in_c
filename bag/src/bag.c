#include <stdlib.h>
#include "bag.h"

/* File name: bag.c
 * Author: Christopher Vote
 * Description: Implements a bag (multiset) of integers using a dynamic array.
 * 		The bag stores unordered values and permits duplicate elements.
 * 		Provides functions for creation, destruction, insertion,
 * 		removal, counting, comparison, and other bag operations.
 */

/* Initialize an allocate empty bag. */
Bag *bag_create(void) {
	Bag *bag = malloc(sizeof(Bag));
	
	if (bag == NULL)
		return NULL;
	
	bag->items = da_create();

	if (bag->items == NULL) {
		free(bag);
		return NULL;
	}

	return bag;
}

/* Release all memory owned by the bag. */
void bag_destroy(Bag *bag) {
	if (bag == NULL)
		return;

	da_destroy(bag->items);
	free(bag);
}

/* Return the number of elements currently stored. */
size_t bag_size(const Bag *bag) {
	return da_size(bag->items);
}

/* Returns true if the bag contains no elements. */
bool bag_empty(const Bag *bag) {
	return da_size(bag->items) == 0;
}

/* Add a value to the bag. Returns true on success. */
bool bag_add(Bag *bag, int value) {
	da_append(bag->items, value);
}

/* Remove the first occurrence of a value. Returns true if found. */
bool bag_remove(Bag *bag, int value) {
	size_t size = da_size(bag->items);
	
	for (size_t i = 0; i < size; i++) {
		if (da_get(bag->items, i) == value) {
			da_remove_at_index(bag->items, i);
			return true;
		}
	}
	return false;
}

/* Count the number of occurrences of a value in the bag. */
size_t bag_count(const Bag *bag, int value) {
	size_t size = da_size(bag->items);
	size_t count = 0;

	for (size_t i = 0; i < size; i++) {
		if (da_get(bag->items, i) == value)
			count++;
	}

	return count;
}
		
// Note: The following function may be reimplemented later with a hash map once such a data structure is available.

/* Return true if two bags contain the same elements, regardless of order. */
bool bag_equal(const Bag *bag1, const Bag *bag2) {
	if (bag_size(bag1) != bag_size(bag2))
		return false;

	size_t size = bag_size(bag1);
	
	bool seen = false;

	for (size_t i = 0; i < size; i++) {
		int curr_value = da_get(bag1->items, i);

		for (size_t j = 0; j < i; j++) {
			if (curr_value == da_get(bag1->items, j)) {
				seen = true;
				break;
			}
		}
		if (seen == true) {
			seen = false;
			continue;
		}

		if (!(bag_count(bag1, curr_value) == bag_count(bag2, curr_value)))	
			return false;
		
	}
	return true;
}






