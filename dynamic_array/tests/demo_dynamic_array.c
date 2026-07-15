#include <stdio.h>

#include "dynamic_array.h"

void print_da(const DynamicArray *da) {
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
printf("\nTest: append() and resize()\n");
printf("----------------------------------------\n");

DynamicArray *my_da = da_create();

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



    da_destroy(my_da);

    return 0;
}



// DYN_ARR Size/Cap: 16/16 [-1, 0, 1, 2, 3, 4, 66, 5, 6, 7, 8, 9, 10, 11, 12, 13]
