#include "is_sorted.h"

/* File name: is_sorted.c
 * Author: Christopher Vote
 * Description: Checks whether an integer array is sorted.
 *              Returns 1 if the array is sorted in non-descending order, 
 *				-1 if it is sorted in strictly non-ascending order, and 
 *				0 otherwise.
 */

// Assume array contains at least one element and arr_len is at lest 1.
int is_sorted(int *arr, size_t arr_len) {
	int result;
	
	// trivial cases
	if (arr_len == 1) return 1;
	if (arr[0] == arr[1]) return 0;
	
	// initialize result
	result = arr[0] > arr[arr_len - 1] ? -1 : 1;

	for (size_t i = 1; i < arr_len - 1; i++) {
		if (result == 1) {
			if (arr[i] > arr[i + 1]) return 0;
		}
		else {
			if (arr[i] < arr[i + 1]) return 0;
		}
	}
	return result;
}
