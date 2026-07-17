#include <stdio.h>

#include "bag.h"

void print_bag(const Bag *bag) {
	size_t size = bag_size(bag);

	printf("BAG Size: %zu [", size);

	for (size_t i = 0; i < size; i++) {
		if (i < size - 1)
			printf("%d, ", da_get(bag->items, i));
		else
			printf("%d", da_get(bag->items, i));
	}

	printf("]");
}

bool build_bag(Bag *bag, int *arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (!bag_add(bag, arr[i])) {
			printf("bag_add() failed.\n");
			return false;
		}
	}

	return true;
}

int main(void) {
	printf("\nTest: bag_add()\n");
	printf("----------------------------------------\n");

	int adder[13] = {3, 8, 99, 4, 6, 7, 8, 54, 1, 3, 8, 6, 8};
	
	Bag *my_bag = bag_create();
	
	if (my_bag == NULL) {
		printf("bag_create() failed.\n");
		return 1;
	}
	
	printf("Start:\n");
	print_bag(my_bag);
	printf("\n\n");	
		
	for (size_t i = 0; i < 13; i++) {
		printf("%ld. Add %d\n", i+1, adder[i]);
		
		if (!bag_add(my_bag, adder[i])) {
			printf("bag_add() failed.\n");
			bag_destroy(my_bag);
			return 1;
		}
		
		print_bag(my_bag);
		printf("\n");
	}
	printf("\n\n");
	
	
	printf("\nTest: bag_remove()\n");
	printf("----------------------------------------\n");
	
	int remover[15] = {-2, 54, 8, 6, 1, 3, 99, 8, 7, 6, 8, 4, 3, 8, 8};
	
	printf("Start:\n");
	print_bag(my_bag);
	printf("\n\n");
	
	for  (size_t i = 0; i < 15; i++) {
		printf("%ld. Remove %d\n", i+1, remover[i]);
		if (!bag_remove(my_bag, remover[i])) {
			printf("%d not found in the bag.\n", remover[i]);
			continue;
		}
		
		print_bag(my_bag);
		printf("\n");
	}
	printf("\n\n");

	
	printf("\nTest: bag_count()\n");
	printf("----------------------------------------\n");
	
	int to_count[13] = {0, -1, 5, -1, 0, 5, 7, 7, -1, 5, 0, 7, 5};
	
	if (!build_bag(my_bag, to_count, 13)) {
		bag_destroy(my_bag);
		return 1;
	}
	
	printf("Start:\n");
	print_bag(my_bag);
	printf("\n\n");
	
	for (int i = -1; i < 8; i++) {
		printf("%d. Count element %d\n", i + 2, i);
		int count = bag_count(my_bag, i);
		printf("The element %d occured %d times\n\n", i, count);
	}
	printf("\n\n");
	
	printf("\nTest: bag_equal()\n");
	printf("----------------------------------------\n");
	
	bool result;
	
	printf("Round 1:\n\n");
	
	int this[5] = {1, 2, 3, 4, 5};
	int that[5] = {3, 5, 2, 1, 3};
	Bag *this_bag = bag_create();
	Bag *that_bag = bag_create();
	
	if (!build_bag(this_bag, this, 5)) {
		bag_destroy(this_bag);
		return 1;
	}
	
	if (!build_bag(that_bag, that, 5)) {
		bag_destroy(that_bag);
		return 1;
	}
		
	printf("bag1:\n");
	print_bag(this_bag);
	printf("\n");
	
	printf("bag2:\n");
	print_bag(that_bag);
	printf("\n");	
	
	result = bag_equal(this_bag, that_bag);
	
	printf("Equality test result: %d\n\n", result);
	
	
	printf("Round 2:\n\n");
	
	int this2[6] = {0, 1, 2, 3, 4, 5};
	int that2[5] = {3, 5, 2, 1, 3};
	Bag *this_bag2 = bag_create();
	Bag *that_bag2 = bag_create();
	
	if (!build_bag(this_bag2, this2, 6)) {
		bag_destroy(this_bag2);
		return 1;
	}
	
	if (!build_bag(that_bag2, that2, 5)) {
		bag_destroy(that_bag2);
		return 1;
	}
		
	printf("bag1:\n");
	print_bag(this_bag2);
	printf("\n");
	
	printf("bag2:\n");
	print_bag(that_bag2);
	printf("\n");	
	
	result = bag_equal(this_bag2, that_bag2);
	
	printf("Equality test result: %d\n\n", result);
	
	
	printf("Round 3:\n\n");
	
	int this3[6] = {0, 30, 100, 99, 100, 5};
	int that3[6] = {300, 5, 99, 100, 0, 100};
	Bag *this_bag3 = bag_create();
	Bag *that_bag3 = bag_create();
	
	if (!build_bag(this_bag3, this3, 6)) {
		bag_destroy(this_bag3);
		return 1;
	}
	
	if (!build_bag(that_bag3, that3, 6)) {
		bag_destroy(that_bag3);
		return 1;
	}
		
	printf("bag1:\n");
	print_bag(this_bag3);
	printf("\n");
	
	printf("bag2:\n");
	print_bag(that_bag3);
	printf("\n");	
	
	result = bag_equal(this_bag3, that_bag3);
	
	printf("Equality test result: %d\n\n", result);
	
	
	printf("Round 4:\n\n");
	
	int this4[17] = {0, 30, -212, 0, 5, 999, 30, 30, 100, 99, 100, 5, 300, 999, -212, 0, 100};
	int that4[17] = {30, 100, -212, 999, 0, 30, 5, 100, 99, 0, 300, 5, -212, 100, 999, 30, 0};
	Bag *this_bag4 = bag_create();
	Bag *that_bag4 = bag_create();
	
	if (!build_bag(this_bag4, this4, 17)) {
		bag_destroy(this_bag4);
		return 1;
	}
	
	if (!build_bag(that_bag4, that4, 17)) {
		bag_destroy(that_bag4);
		return 1;
	}
		
	printf("bag1:\n");
	print_bag(this_bag4);
	printf("\n");
	
	printf("bag2:\n");
	print_bag(that_bag4);
	printf("\n");	
	
	result = bag_equal(this_bag4, that_bag4);
	
	printf("Equality test result: %d\n\n", result);
	
	printf("Round 5:\n\n");
	
	Bag *this_bag5 = bag_create();
	Bag *that_bag5 = bag_create();
			
	printf("bag1:\n");
	print_bag(this_bag5);
	printf("\n");
	
	printf("bag2:\n");
	print_bag(that_bag5);
	printf("\n");	
	
	result = bag_equal(this_bag5, that_bag5);
	
	printf("Equality test result: %d\n\n", result);
	
	
	printf("Round 6:\n\n");
	
	printf("bag1:\n");
	print_bag(this_bag5);
	printf("\n");
	
	printf("bag2:\n");
	print_bag(that_bag);
	printf("\n");	
	
	result = bag_equal(this_bag5, that_bag);
	
	printf("Equality test result: %d\n\n", result);
	
	
	printf("Round 7:\n\n");
	
	printf("bag1:\n");
	print_bag(this_bag2);
	printf("\n");
	
	printf("bag2:\n");
	print_bag(that_bag5);
	printf("\n");	
	
	result = bag_equal(this_bag2, that_bag5);
	
	printf("Equality test result: %d\n\n", result);	
		
	
	bag_destroy(my_bag);
	bag_destroy(this_bag);
	bag_destroy(this_bag2);
	bag_destroy(this_bag3);
	bag_destroy(this_bag4);
	bag_destroy(this_bag5);	
	bag_destroy(that_bag);
	bag_destroy(that_bag2);
	bag_destroy(that_bag3);
	bag_destroy(that_bag4);
	bag_destroy(that_bag5);
}














