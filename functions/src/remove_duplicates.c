#include "remove_duplicates.h"

/* File name: remove_duplicates.c
 * Author: Christopher Vote
 * Description: Takes an array sorted in non-ascending or non-descending order and
 * 		modifies the array in place, removing all duplicates.
 * 		Returns the new length of the array after modification.
 */

size_t remove_duplicates(int *arr, size_t arr_len) {
	// trivial case
	if (arr_len < 2) return arr_len;

	int write_index = 1;
	int curr = arr[0];

	for (int i = 1; i < arr_len; i++) {
		if (arr[i] != curr) {
			arr[write_index++] = arr[i];
			curr = arr[i];
		}
	}
	return write_index;
}
