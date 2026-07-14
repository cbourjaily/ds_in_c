#include "sa_range.h"

/* File name: sa_range.c
 * Author: Christopher Vote
 * Description: Fills a caller-provided array with the consecutive integers
 *              between start and end (inclusive).
 */

void sa_range(int start, int end, int *out_array)
{
    int step = (start <= end) ? 1 : -1;
    int value = start;

    while (1) {
        *out_array++ = value;

        if (value == end)
            break;

        value += step;
    }
}