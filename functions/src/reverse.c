#include "reverse.h"

/* File name: reverse.c
 * Author: Christopher Vote
 * Description: Reverses the elements of an integer array in place.
 */

void reverse(int *arr, size_t arr_len)
{
    for (size_t i = 0; i < arr_len / 2; i++) {
        int left = arr[i];
        int right = arr[arr_len - 1 - i];
        arr[i] = right;
        arr[arr_len - 1 - i] = left;
    }
}
