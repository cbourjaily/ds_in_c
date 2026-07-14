#include <stdio.h>

#include "count_sort.h"
#include "array_utils.h"

static void demo_count_sort(int *arr, size_t arr_len, int *sorted_arr) {
    printf("Array before sort:\n");
    print_array(arr, arr_len);

    count_sort(arr, arr_len, sorted_arr);

    printf("Array after sort:\n");
    print_array(sorted_arr, arr_len);
}

int main(void) {
    int a[] = {1};
    int a1[1];
    demo_count_sort(a, 1, a1);

    int b[] = {99, 4, 1000, 2, 5, 44, 33, 33, 99, 4};
    int b1[10];
    demo_count_sort(b, 10, b1);

    int c[] = {5, 3, 1, -1, -3, 3, -50, 5, 1, -44, 100};
    int c1[11];
    demo_count_sort(c, 11, c1);

    int d[] = {100, 90, 80, 70, 60, 60, 60, 50, 50, 50, 50, 50, 40, 40, 30, 20, 20, 10, 10, 100};
    int d1[20];
    demo_count_sort(d, 20, d1);

    return 0;
}
