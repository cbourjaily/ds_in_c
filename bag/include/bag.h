#ifndef BAG_H
#define BAG_H

#include <stddef.h>
#include "dynamic_array.h"

typedef struct {
	DynamicArray *items;
} Bag;

/* Construction / Destruction */
Bag *bag_create(void);
void bag_destroy(Bag *bag);

/* Capacity / Size*/
size_t bag_size(const Bag *bag);
bool bag_empty(const Bag *bag);

/* Core Operations */
bool bag_add(Bag *bag, int value);
bool bag_remove(Bag *bag, int value);
size_t bag_count(const Bag *bag, int value);
void bag_clear(Bag *bag);

/* Comparison */
bool bag_equal(const Bag *bag1, const Bag *bag2);

#endif
