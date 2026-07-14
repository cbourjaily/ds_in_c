#include <stdio.h>

#include "reverse.h"
#include "array_utils.h"

int main(void) {
    printf("# reverse example 1\n");

    int arr1[6];
    build_array(arr1, 6, -20, 7);

    printf("Start array:\n");
    print_array(arr1, 6);

    reverse(arr1, 6);

    printf("Reversed array:\n");
    print_array(arr1, 6);

    printf("\n# reverse example 2\n");

    int arr2[7];
    build_array(arr2, 7, -1, 7);

    printf("Start array:\n");
    print_array(arr2, 7);

    reverse(arr2, 7);

    printf("Reversed array:\n");
    print_array(arr2, 7);

    return 0;
}
