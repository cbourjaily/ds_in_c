#include <stdio.h>

#include "min_max.h"
#include "array_utils.h"

int main(void) {
    printf("# min_max example 1\n");

    int arr1[] = {7, 8, 6, -5, 4};
    int mm1[2];

    print_array(arr1, 5);
    min_max(arr1, 5, mm1);

    printf("Min: %d, Max: %d\n\n", mm1[0], mm1[1]);

    printf("# min_max example 2\n");

    int arr2[] = {100};
    int mm2[2];

    print_array(arr2, 1);
    min_max(arr2, 1, mm2);

    printf("Min: %d, Max: %d\n\n", mm2[0], mm2[1]);

    printf("# min_max example 3\n");

    int arr3[] = {3, 3, 3};
    int mm3[2];

    print_array(arr3, 3);
    min_max(arr3, 3, mm3);

    printf("Min: %d, Max: %d\n", mm3[0], mm3[1]);

    return 0;
}
