#include <stdio.h>
#include <stdlib.h>	// for abs()
#include <limits.h>	// for INT_MIN and INT_MAX

#include "dynamic_array.h"

/* Helpers for higher-level operations */

// Helpers for map demos
int square(int x) {
	return x * x;
}

int double_it(int x) {
	return x* 2;
}

int negate(int x) {
	return -x;
}

// Helpers for filter demos
bool is_even(int x) {
	return x % 2 == 0;
}

bool is_odd(int x) {
	return x % 2 != 0;
}

bool is_positive(int x) {
	return x > 0;
}

bool is_negative(int x) {
	return x < 0;
}

bool is_prime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// Helpers for reduce demos
int sum(int acc, int x) {
	return acc + x;
}

int product(int acc, int x) {
	return acc * x;
}

int max(int acc, int x) {
	return acc > x ? acc : x;
}

int min(int acc, int x) {
	return acc < x ? acc : x;
}


void print_da(const DynamicArray * da) {
	printf("DYN_ARR Size/Cap: %zu/%zu [", da_size(da), da_capacity(da));

	for (size_t i = 0; i < da_size(da); i++) {
		if (i < da_size(da) - 1)
			printf("%d, ", da_get(da, i));
		else
			printf("%d", da_get(da, i));
	}

	printf("]");
}

int main(void) {
	printf("\nTest: append()\n");
	printf("----------------------------------------\n");

	DynamicArray * my_da = da_create();

	if (my_da == NULL) {
		printf("da_create() failed.\n");
		return 1;
	}

	printf("Start:\n");
	print_da(my_da);
	printf("\n\n");

	for (int i = 0; i < 13; i++) {
		printf("%d. Append %d\n", i + 1, i);

		if (!da_append(my_da, i)) {
			printf("da_append() failed.\n");
			da_destroy(my_da);
			return 1;
		}

		print_da(my_da);
		printf("\n");
	}

	printf("\n");

	printf("\n");

	printf("Test: da_insert_at_index()\n");
	printf("----------------------------------------\n");

	printf("1. Insert -1 at index 0\n");
	if (!da_insert_at_index(my_da, 0, -1)) {
		printf("da_insert_at_index() failed.\n");
		da_destroy(my_da);
		return 1;
	}
	print_da(my_da);
	printf("\n");

	printf("2. Insert 13 at index 14\n");
	if (!da_insert_at_index(my_da, 14, 13)) {
		printf("da_insert_at_index() failed.\n");
		da_destroy(my_da);
		return 1;
	}
	print_da(my_da);
	printf("\n");

	printf("3. Insert 66 at index 6\n");
	if (!da_insert_at_index(my_da, 6, 66)) {
		printf("da_insert_at_index() failed.\n");
		da_destroy(my_da);
		return 1;
	}
	print_da(my_da);
	printf("\n\n");

	printf("Test: da_remove_at_index()\n");
	printf("----------------------------------------\n");

	size_t test_indices[16] = {15, 0, 6, 8, 4, 5, 8, 3, 1, 2, 4, 3, 3, 2, 1, 0};

	printf("Start:\n");
	print_da(my_da);
	printf("\n\n");

	int j = 1;

	for (size_t i = 0; i < 16; i++) {
		printf("%d. Remove at index %ld\n", j++, test_indices[i]);
		da_remove_at_index(my_da, test_indices[i]);
		print_da(my_da);
		printf("\n");
	}
	printf("\n");

	printf("Test: da_slice()\n");
	printf("----------------------------------------\n");

	for (int i = 0; i < 16; i++) {
		if (!da_append(my_da, i)) {
			printf("da_append() failed.\n");
			da_destroy(my_da);
			return 1;
		}
	}

	printf("Start:\n");
	print_da(my_da);
	printf("\n\n");

	printf("1. Slice from index 0 up to length of da.\n");
	DynamicArray *my_da2 = da_slice(my_da, 0, 16);
	print_da(my_da2);
	printf("\n\n");

	printf("2. Slice from last index up to length 0.\n");
	DynamicArray *my_da3 = da_slice(my_da, my_da->size - 1, 0);
	print_da(my_da3);
	printf("\n\n");

	printf("3. Slice from index 7 to length 8.\n");
	DynamicArray *my_da4 = da_slice(my_da, 7, 8);
	print_da(my_da4);

	printf("\n\n\n");

	printf("Test: da_merge()\n");
	printf("----------------------------------------\n");

	printf("Round 1:\n");
	printf("Starting dest:\n");
	print_da(my_da);
	printf("\n");

	printf("Starting src:\n");
	print_da(my_da3);
	printf("\n");

	da_merge(my_da, my_da3);

	printf("Post-operation dest:\n");
	print_da(my_da);
	printf("\n\n");


	printf("Round 2:\n");
	printf("Starting dest:\n");
	print_da(my_da);
	printf("\n");

	printf("Starting src:\n");
	print_da(my_da);
	printf("\n");

	da_merge(my_da, my_da);

	printf("Post-operation dest:\n");
	print_da(my_da);
	printf("\n\n");


	printf("Round 3:\n");
	printf("Starting dest:\n");
	print_da(my_da4);
	printf("\n");

	printf("Starting src:\n");
	print_da(my_da);
	printf("\n");

	da_merge(my_da4, my_da);

	printf("Post-operation dest:\n");
	print_da(my_da4);
	printf("\n\n");

	printf("Test: da_map()\n");
	printf("----------------------------------------\n");

	DynamicArray *my_da5 = da_create();


	for (int i = 0; i < 8; i++) {
		if (!da_append(my_da5, i)) {
			printf("da_append() failed.\n");
			da_destroy(my_da5);
			return 1;
		}
	}

	// DynamicArray *da_map(const DynamicArray *da, int (*func)(int));

	printf("Round 1:\n");
	printf("Map: square()\n");
	printf("Starting array:\n");
	print_da(my_da5);
	printf("\n\n");

	DynamicArray *this_da = da_map(my_da5, square);

	printf("Result:\n");

	print_da(this_da);
	printf("\n\n");


	printf("Round 2:\n");
	printf("Map: negate()\n");
	printf("Starting array:\n");
	print_da(this_da);
	printf("\n\n");

	DynamicArray *this_da2 = da_map(this_da, negate);

	printf("Result:\n");

	print_da(this_da2);
	printf("\n\n");


	printf("Round 3:\n");
	printf("Map: double_it()\n");
	printf("Starting array:\n");
	print_da(this_da2);
	printf("\n\n");

	DynamicArray *this_da3 = da_map(this_da2, double_it);

	printf("Result:\n");

	print_da(this_da3);
	printf("\n\n");


	printf("Round 4:\n");
	printf("Map: abs()\n");
	printf("Starting array:\n");

	printf("Map: double()\n");
	printf("Map: abs()\n");


	da_append(this_da3, 23);
	da_insert_at_index(this_da3, 0, 10);
	da_insert_at_index(this_da3, 4, 22);
	da_insert_at_index(this_da3, 7, 19);

	printf("Starting array:\n");
	print_da(this_da3);
	printf("\n\n");

	DynamicArray *this_da4 = da_map(this_da3, abs);

	printf("Result:\n");
	print_da(this_da4);
	printf("\n\n");
	
	
	printf("Test: da_filter()\n");
	printf("----------------------------------------\n");

	DynamicArray *this_da5 = da_create();


	for (int i = 0; i < 20; i++) {
		if (is_odd(i)) {
			if (!da_append(this_da5, negate(i))) {
				printf("da_append() failed.\n");
				da_destroy(this_da5);
				return 1;
			}
		}
		else {		
			if (!da_append(this_da5, i)) {
				printf("da_append() failed.\n");
				da_destroy(this_da5);
				return 1;
			}
		}
	}

	// DynamicArray *da_filter(const DynamicArray *da, bool (*pred)(int));

	printf("Round 1:\n");
	printf("Filter: is_even()\n");
	printf("Starting array:\n");
	print_da(this_da5);
	printf("\n\n");
	
	DynamicArray *that_da = da_filter(this_da5, is_even);

	printf("Result:\n");
	print_da(that_da);
	printf("\n\n");
	
	
	printf("Round 2:\n");
	printf("Filter: is_odd()\n");
	printf("Starting array:\n");
	print_da(this_da5);
	printf("\n\n");
	
	DynamicArray *that_da2 = da_filter(this_da5, is_odd);

	printf("Result:\n");
	print_da(that_da2);
	printf("\n\n");
	

	printf("Round 3:\n");
	printf("Filter: is_positive()\n");
	printf("Starting array:\n");
	print_da(this_da5);
	printf("\n\n");
	
	DynamicArray *that_da3 = da_filter(this_da5, is_positive);

	printf("Result:\n");
	print_da(that_da3);
	printf("\n\n");
		
	
	printf("Round 4:\n");
	printf("Filter: is_negative\n");
	printf("Starting array:\n");
	print_da(this_da5);
	printf("\n\n");
	
	DynamicArray *that_da4 = da_filter(this_da5, is_negative);

	printf("Result:\n");
	print_da(that_da4);
	printf("\n\n");
	
	
	DynamicArray *this_da6 = da_create();

	for (int i = 0; i < 66; i++) {
		if (!da_append(this_da6, (i - 5))) {
			printf("da_append() failed.\n");
			da_destroy(this_da6);
			return 1;
		}
	}
	
	printf("Round 5:\n");
	printf("Filter: is_prime\n");
	printf("Starting array:\n");
	print_da(this_da6);
	printf("\n\n");
	
	DynamicArray *that_da5 = da_filter(this_da6, is_prime);

	printf("Result:\n");
	print_da(that_da5);
	printf("\n\n");
	
	
	printf("Test: da_reduce()\n");
	printf("----------------------------------------\n");
	
	int reduction;
	DynamicArray *a_da = da_create();

	// int da_reduce(const DynamicArray *da, int (*func)(int, int), int initial);
	
	printf("Round 1:\n");
	printf("Reduce: sum()\n");
	printf("Starting array:\n");
	print_da(a_da);
	printf("\n\n");
	
	reduction = da_reduce(a_da, sum, 0);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");


	for (int i = 1; i < 11; i++) {
		if (i % 3 == 0) {
			if (!da_append(a_da, negate(i))) {
				printf("da_append() failed.\n");
				da_destroy(a_da);
				return 1;
			}
		}
		else {		
			if (!da_append(a_da, i)) {
				printf("da_append() failed.\n");
				da_destroy(a_da);
				return 1;
			}
		}
	}

	
	printf("Round 2:\n");
	printf("Reduce: sum()\n");
	printf("Starting array:\n");
	print_da(a_da);
	printf("\n\n");
	
	reduction = da_reduce(a_da, sum, 0);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");
	
	DynamicArray *a_da2 = da_create();

	for (int i = 0; i < 11; i++) {
		if (!da_append(a_da2, (i - 5))) {
			printf("da_append() failed.\n");
			da_destroy(a_da2);
			return 1;
		}
	}

	printf("Round 3:\n");
	printf("Reduce: sum()\n");
	printf("Starting array:\n");
	print_da(a_da2);
	printf("\n\n");
	
	reduction = da_reduce(a_da2, sum, 0);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");
	
	
	DynamicArray *a_da3 = da_create();
	
	for (int i = 1; i < 6; i++) {
		if (!da_append(a_da3, i)) {
			printf("da_append() failed.\n");
			da_destroy(a_da3);
			return 1;
		}
	}	
	
	printf("Round 4:\n");
	printf("Reduce: product()\n");
	printf("Starting array:\n");
	print_da(a_da3);
	printf("\n\n");
	
	reduction = da_reduce(a_da3, product, 1);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");
	

	printf("Round 5:\n");
	printf("Reduce: product()\n");
	printf("Starting array:\n");
	print_da(a_da);
	printf("\n\n");
	
	reduction = da_reduce(a_da, product, 1);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");
	
	
	printf("Round 6:\n");
	printf("Reduce: product()\n");
	printf("Starting array:\n");
	print_da(a_da2);
	printf("\n\n");
	
	reduction = da_reduce(a_da2, product, 1);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");
	

	printf("Round 7:\n");
	printf("Reduce: max()\n");
	printf("Starting array:\n");
	print_da(a_da2);
	printf("\n\n");
	
	reduction = da_reduce(a_da2, max, INT_MIN);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");
	

	printf("Round 8:\n");
	printf("Reduce: min()\n");
	printf("Starting array:\n");
	print_da(a_da2);
	printf("\n\n");
	
	reduction = da_reduce(a_da2, min, INT_MAX);

	printf("Result:\n");
	printf("%d\n", reduction);
	printf("\n");


	da_destroy(my_da);
	da_destroy(my_da2);
	da_destroy(my_da3);
	da_destroy(my_da4);
	da_destroy(my_da5);
	da_destroy(this_da);
	da_destroy(this_da2);
	da_destroy(this_da3);
	da_destroy(this_da4);
	da_destroy(this_da5);
	da_destroy(this_da6);
	da_destroy(that_da);
	da_destroy(that_da2);
	da_destroy(that_da3);
	da_destroy(that_da4);
	da_destroy(that_da5);
	da_destroy(a_da);
	da_destroy(a_da2);
	da_destroy(a_da3);

	return 0;
}
