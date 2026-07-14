#include "min_max.h"

/* File name: min_max.c
 * Author: Christopher Vote
 * Description: Stores the minimum and maximum values of an integer array
 *              in a caller-provided output array.
 */

void min_max(int *arr, size_t arr_len, int *mm)
{
    int min = arr[0];
    int max = arr[0];

    for (size_t i = 0; i < arr_len; i++) {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    mm[0] = min;
    mm[1] = max;
}
