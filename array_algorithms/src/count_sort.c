#include <string.h>
#include "count_sort.h"

/* File name: count_sort.c
 * Author: Christopher Vote
 * Description: Sorts an integer array using the counting sort algorithm.
 *              A counting array is constructed from the range of values,
 *              and the sorted result is written to a caller-provided
 *              output array in non-descending order.
 */

void count_sort(int *arr, size_t arr_len, int *sorted_arr) {
	// trivial cases: already sorted
	int check_sort = is_sorted(arr, arr_len);
	if (check_sort) {
		memcpy(sorted_arr, arr, arr_len * sizeof(int));
		if (check_sort == -1) reverse(sorted_arr, arr_len);
		return;
	}

	// Get range in order to create counting array
	int mm[2];
	min_max(arr, arr_len, mm);
	int min = mm[0];
	int max = mm[1];
	int count_len = max - min + 1;
	int count_arr[count_len];
	memset(count_arr, 0, sizeof count_arr);

	// Build count array where index is el - min
	for (int i = 0; i < arr_len; i++) {
		count_arr[arr[i] - min]++;
	}
	
	// Build sorted array where a value is el + min
	size_t j = 0;
	for (int i = 0; i < count_len; i++) {
		while (count_arr[i] > 0) {
			sorted_arr[j] = i + min;
			count_arr[i]--;
			j++;
		}
	}
}

