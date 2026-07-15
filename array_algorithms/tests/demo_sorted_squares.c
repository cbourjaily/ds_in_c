#include <stdio.h>

#include "sorted_squares.h"
#include "array_utils.h"

static void demo_sorted_squares(int *arr, size_t arr_len, int *squares_sorted) {
    printf("Array before:\n");
    print_array(arr, arr_len);

    sorted_squares(arr, arr_len, squares_sorted);

    printf("Array after:\n");
    print_array(squares_sorted, arr_len);
}

int main(void) {
    int a[] = {1};
    int a1[1];
    demo_sorted_squares(a, 1, a1);

    int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b1[10];
    demo_sorted_squares(b, 10, b1);

    int c[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0};
    int c1[11];
    demo_sorted_squares(c, 11, c1);

    int d[] = {-9, -7, -5, -3, -1, 1, 3, 5, 7, 9};
    int d1[10];
    demo_sorted_squares(d, 10, d1);

    return 0;
}
