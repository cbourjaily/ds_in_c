#include "sorted_squares.h"

/* File name: sorted_squares.c
 * Author: Christopher Vote
 * Description: Takes a sorted integer array and writes the squares of
 *              its elements to a caller-provided output array in
 *              non-descending order. Runs in O(n) time using a
 *              two-pointer approach.
 */

void sorted_squares(int *arr, size_t arr_len, int *squares_sorted) {
    size_t i = 0;
    size_t j;
    size_t k; 
    j = k = arr_len - 1;

    if (arr_len == 0)
	    return;

    while (i <= j) {
	    if (arr[i] < 0) {
		    if ((arr[i] * arr[i]) > (arr[j] * arr[j])) {
			    squares_sorted[k] = arr[i] * arr[i];
			    i++;
			    k--;
		    }
		    else {
			    squares_sorted[k] = (arr[j] * arr[j]);
			    j--;
			    k--;
		    }
	    }
	    else {
		    squares_sorted[k] = (arr[j] * arr[j]);
		    j--;
		    k--;
	    }
    }
}
