#include <stdio.h>
#include <stdlib.h>

#include "../include/sa_range.h"
#include "../util/array_utils.h"

static size_t size_array(int start, int end)
{
    return (size_t)(abs(end - start) + 1);
}

static void print_range(int *arr, size_t arr_len, int start, int end)
{
    printf("Start: %d, End: %d, ", start, end);
    print_array(arr, arr_len);
}

int main(void)
{
    printf("# sa_range examples\n");

    int start, end;
    size_t size;

    start = 1;
    end = 3;
    size = size_array(start, end);
    int out1[size];
    sa_range(start, end, out1);
    print_range(out1, size, start, end);

    start = -1;
    end = 2;
    size = size_array(start, end);
    int out2[size];
    sa_range(start, end, out2);
    print_range(out2, size, start, end);

    start = 0;
    end = 0;
    size = size_array(start, end);
    int out3[size];
    sa_range(start, end, out3);
    print_range(out3, size, start, end);

    start = 0;
    end = -3;
    size = size_array(start, end);
    int out4[size];
    sa_range(start, end, out4);
    print_range(out4, size, start, end);

    start = -95;
    end = -89;
    size = size_array(start, end);
    int out5[size];
    sa_range(start, end, out5);
    print_range(out5, size, start, end);

    start = -89;
    end = -95;
    size = size_array(start, end);
    int out6[size];
    sa_range(start, end, out6);
    print_range(out6, size, start, end);

    return 0;
}
