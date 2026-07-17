#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
	int *data;
	size_t size;
	size_t capacity;
} DynamicArray;

/* Construction / Destruction */
DynamicArray *da_create(void);
void da_destroy(DynamicArray *da);

/* Capacity */
size_t da_size(const DynamicArray *da);
size_t da_capacity(const DynamicArray *da);
bool da_is_empty(const DynamicArray *da);
bool da_resize(DynamicArray *da, size_t new_capacity);

/* Element Access */
int da_get(const DynamicArray *da, size_t index);
void da_set(DynamicArray *da, size_t index, int value);

/* Modification */
bool da_append(DynamicArray *da, int value);
bool da_insert_at_index(DynamicArray *da, size_t index, int value);
void da_remove_at_index(DynamicArray *da, size_t index);

/* Higher-level Operations */
DynamicArray *da_slice(const DynamicArray *da, size_t start, size_t length);
void da_merge(DynamicArray *dest, const DynamicArray *src);
DynamicArray *da_map(const DynamicArray *da, int (*func)(int));
DynamicArray *da_filter(const DynamicArray *da, bool (*pred)(int));
int da_reduce(const DynamicArray *da, int (*func)(int, int), int initial);

#endif
