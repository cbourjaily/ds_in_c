#include <stdio.h>
#include "array_utils.h"

void build_array(int *arr, size_t arr_len, int lower, int jump)
{
    for (size_t i = 0; i < arr_len; i++) {
        int result = lower + ((int)i * jump);
        arr[i] = result;
    }
}

void print_array(int *arr, size_t arr_len)
{
    printf("ARR Size: %zu ", arr_len);

    if (arr_len == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < arr_len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[arr_len - 1]);
}
