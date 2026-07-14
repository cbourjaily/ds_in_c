#include <stdio.h>

#include "../include/rotate.h"
#include "../util/array_utils.h"

static void print_rotate(int *arr, size_t arr_len, int step)
{
    printf("ARR Size: %zu ", arr_len);

    if (arr_len == 0) {
        printf("[] %d\n", step);
        return;
    }

    printf("[");
    for (size_t i = 0; i < arr_len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d] %d\n", arr[arr_len - 1], step);
}

int main(void)
{
    printf("# rotate example 1\n");

    int steps[] = {
        1,
        2,
        0,
        -1,
        -2,
        28,
        -100,
        268435456,
        -2147483648
    };

    int arr[6];
    int rotated[6];

    build_array(arr, 6, -20, 7);

    print_array(arr, 6);

    for (size_t i = 0; i < sizeof(steps) / sizeof(steps[0]); i++) {
        rotate(arr, 6, steps[i], rotated);
        print_rotate(rotated, 6, steps[i]);
    }

    print_array(arr, 6);

    return 0;
}
