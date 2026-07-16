#include <stdlib.h>

#include "dynamic_array.h"

#define DA_MIN_CAPACITY 4


/* File name: dynamic_array.c
 * Author: Christophr Vote
 * Description: Implements a dynamically-resizing array of integers.
 * 		The array automatically expands as needed while tracking
 * 		its current size and allocated capacity.
 * 		Provides functions for creation, destuction, element access,
 * 		resizing, and modification.
 */

/* Allocate and initialize an empty dynamic array. */
DynamicArray *da_create(void) {
	DynamicArray *da = malloc(sizeof(DynamicArray));

	if (da == NULL)
		return NULL;

	da->data = malloc(4 * sizeof(int));

	if (da->data == NULL) {
		free(da);
		return NULL;
	}

	da->size = 0;
	da->capacity = 4;

	return da;	
}

/* Release all memory owned by the dynamic array. */
void da_destroy(DynamicArray *da) {
	if (da == NULL)
		return;

	free(da->data);
	free(da);
}

/* Return the number of elements currently stored. */
size_t da_size(const DynamicArray *da) {
	return da->size;
}

/* Return the current allocated capacity. */
size_t da_capacity(const DynamicArray *da) {
	return da->capacity;
}

/* Return true if the array contains no elements. */
bool da_is_empty(const DynamicArray *da) {
	return da->size == 0;
}

/* Return the element at the specified index.
 * Precondition: index < da->size.
 */
int da_get(const DynamicArray *da, size_t index) {
	return da->data[index];
}

/* Return the element at the given index.
 * Precondition: index < da->size.
 */
void da_set(DynamicArray *da, size_t index, int value) {
	da->data[index] = value;
}

/* Resize the dynamic array's underlying storage to the specified capacity.
 * Precondition: new_capacity >= da->size.
 * Returns true if the resize succeeds, or false if memory allocation fails.
 */
bool da_resize(DynamicArray *da, size_t new_capacity) {
	if (new_capacity < DA_MIN_CAPACITY) {
		if (da->capacity == DA_MIN_CAPACITY) {
			return true;
		}
		else {
			new_capacity = DA_MIN_CAPACITY;
		}
	}

    size_t size = da_size(da);

    int *new_data = malloc(new_capacity * sizeof(int));

    if (new_data == NULL)
        return false;

    for (size_t i = 0; i < size; i++) {
        new_data[i] = da->data[i];
    }

    free(da->data);

    da->data = new_data;
    da->capacity = new_capacity;

    return true;
}

/* Append a new value to the end of the dynamic array.
 * Returns true if the value is appended, or false if memory allocation fails.
 */
bool da_append(DynamicArray *da, int value) {
	if (da->size == da->capacity) {
		if (!da_resize(da, da->capacity * 2))
			return false;
	}

	da->data[da->size++] = value;
	return true;
}

/* Insert a new value at the specified index, shifting subsequent elements
 * one position to the right.
 * Precondition: index <= da->size.
 * Returns true if the value is inserted, or false if memory allocation fails.
 */
bool da_insert_at_index(DynamicArray *da, size_t index, int value) {
	if (da->size == da->capacity) {
		if (!da_resize(da, da->capacity * 2))
			return false;
	}

	for (size_t i = da->size; i > index; i--) {
		da->data[i] = da->data[i - 1];
	}
	da->data[index] = value;
	da->size++;
	return true;
}

/* Remove the value at the specified index, shifting subsequent elements
 * one position to the left.
 * Precondition: index < da->size.
 */
void da_remove_at_index(DynamicArray *da, size_t index) {
	for (size_t i = index; i < da->size - 1; i++) {
		da->data[i] = da->data[i + 1];
	}

	da->size--;

	if (da->capacity > DA_MIN_CAPACITY && da->size < (da->capacity / 4)) {
		da_resize(da, da->size * 2);
	}
}

/* Return a new dynamic array containing length elements,
 * starting at index start.
 */
DynamicArray *da_slice(const DynamicArray *da, size_t start, size_t length) {
	DynamicArray *new_da = da_create();
	if (new_da == NULL)
		return NULL;

	for (size_t i = start; i < (start + length); i++) {
		da_append(new_da, da_get(da, i));
		}
	return new_da;
}
/* Append all elements from src to the end of dest. */
void da_merge(DynamicArray *dest, const DynamicArray *src) {
	size_t size = da_size(src);
	for (size_t i = 0; i < size; i++) {
		// Safety check for if malloc should fail in append
		if (!da_append(dest, da_get(src, i)))
			return;
	}
}


DynamicArray *da_map(const DynamicArray *da, int (*func)(int)) {

}
