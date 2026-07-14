#include "find_mode.h"

/* File name: find_mode.c
 * Author: Christopher Vote
 * Description: Determines the mode of an array sorted in either
 *              non-descending or non-ascending order.
 *              If multiple elements share the highest frequency,
 *              selects the element which occurs first in the array.
 *              Stores the mode value and its frequency in the
 *              caller-provided output parameters.
 */

void find_mode(int *arr, size_t arr_len, int *mode, size_t *frequency) {
	int cand_mode;
	int cand_freq;
	int curr_el;
	int curr_freq;

	// initialize variables
	cand_mode = arr[0];
	cand_freq = 1;
	curr_el = arr[0];
	curr_freq = 1;

	// trivial case
	if (arr_len == 1) {
		*mode = cand_mode;
		*frequency = cand_freq;
		return;
	}

	for (int i = 1; i < arr_len; i++) {
		if (arr[i] == curr_el) {
			curr_freq++;
			if (curr_freq > cand_freq) {
				cand_freq = curr_freq;
				cand_mode = curr_el;
			}
		}
		else {
			curr_el = arr[i];
			curr_freq = 1;
	}
	*mode = cand_mode;
	*frequency = cand_freq;
	}
}

