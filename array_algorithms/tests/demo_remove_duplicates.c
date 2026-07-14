#include <stdio.h>

#include <remove_duplicates.h>
#include <array_utils.h>

static void demo_remove_duplicates(int *arr, size_t arr_len) {
    size_t new_length;

    printf("Array before duplicate removal:\n");
    print_array(arr, arr_len);

    new_length = remove_duplicates(arr, arr_len);

    printf("Array after duplicate removal:\n");
    print_array(arr, new_length);
}

int main(void) {
    int a[] = {1};
    demo_remove_duplicates(a, 1);

    int b[] = {1, 2, 3, 4};
    demo_remove_duplicates(b, 4);

    int c[] = {5, 3, 1, -1, -3};
    demo_remove_duplicates(c, 5);

    int d[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    demo_remove_duplicates(d, 10);

    int e[] = {-8, -8, -7, -5, -3, -3, -3, -2, -1, -1, 0, 0};
    demo_remove_duplicates(e, 12);
}
