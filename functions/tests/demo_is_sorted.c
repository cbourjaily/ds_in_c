#include <stdio.h>

#include "is_sorted.h"
#include "array_utils.h"

static void run_demo(int *arr, size_t arr_len) {
    int result = is_sorted(arr, arr_len);

    print_array(arr, arr_len);
    printf("Result: %d\n\n", result);
}

int main(void) {
    int a[] = {-100, -28, -10, 0, 4, 9, 36, 100};
    run_demo(a, 8);

    int b[] = {200, 145, 80, 0, -80, -145, -200};
    run_demo(b, 7);

    int c[] = {1, 8, -12, 30, -20, 0};
    run_demo(c, 6);

    int d[] = {-30, 0, 0, 30, 30, 40};
    run_demo(d, 6);

    int e[] = {99};
    run_demo(e, 1);

    return 0;
}