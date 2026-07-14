#include <assert.h>

#include "is_sorted.h"

int main(void) {
    int a[] = {-100, -28, -10, 0, 4, 9, 36, 100};
    assert(is_sorted(a, 8) == 1);

    int b[] = {200, 145, 80, 0, -80, -145, -200};
    assert(is_sorted(b, 7) == -1);

    int c[] = {1, 8, -12, 30, -20, 0};
    assert(is_sorted(c, 6) == 0);

    int d[] = {-30, 0, 0, 30, 30, 40};
    assert(is_sorted(d, 6) == 1);

    int e[] = {99};
    assert(is_sorted(e, 1) == 1);
}

