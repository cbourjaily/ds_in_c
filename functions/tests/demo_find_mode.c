#include <stdio.h>

#include "find_mode.h"
#include "array_utils.h"

static void demo_mode(int *arr, size_t arr_len) {
    int mode;
    size_t frequency;

    find_mode(arr, arr_len, &mode, &frequency);

    print_array(arr, arr_len);
    printf("Mode: %d, Frequency: %zu\n\n", mode, frequency);
}

int main(void) {
    int a[] = {2};
    demo_mode(a, 1);
    
    int b[] = {1, 20, 30, 40, 500, 500, 500};
    demo_mode(b, 7);

    int c[] = {2, 2, 2, 2, 1, 1, 1, 1};
    demo_mode(c, 8);

    int d[] = {-10, -10, -10, 0, 5, 5, 100};
    demo_mode(d, 7);

    int e[] = {-50, -20, 0, 10, 20};
    demo_mode(e, 5);

    return 0;
}