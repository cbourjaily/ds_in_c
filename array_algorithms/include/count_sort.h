#ifndef COUNT_SORT_H
#define COUNT_SORT_H

#include <stddef.h>
#include "min_max.h"
#include "is_sorted.h"
#include "reverse.h"

void count_sort(int *arr, size_t arr_len, int *sorted_arr);

#endif
