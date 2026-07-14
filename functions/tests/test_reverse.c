#include <assert.h>

#include "../include/reverse.h"

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    reverse(arr, 5);

    int expected[] = {5, 4, 3, 2, 1};

    for (size_t i = 0; i < 5; i++)
        assert(arr[i] == expected[i]);

    return 0;
}
