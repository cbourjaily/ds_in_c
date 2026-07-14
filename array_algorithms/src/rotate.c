#include "rotate.h"

/* File name: rotate.c
 * Author: Christopher Vote
 * Description: Rotates the contents of an integer array into a
 *              caller-provided output array. Positive values rotate
 *              right, while negative values rotate left.
 */

void rotate(int *arr, size_t arr_len, int step, int *new_array)
{
    int mod_step = step % (int)arr_len;

    for (size_t i = 0; i < arr_len; i++) {
        size_t new_index = (i + mod_step + arr_len) % arr_len;
        new_array[new_index] = arr[i];
    }
}
