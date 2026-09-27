#include <stdlib.h>

#pragma GCC optimize("O3,unroll-loops")

#define OFFSET 10001
#define MAX_VAL 20002

static inline void update(int* bit, int idx, int val) {
    for (; idx < MAX_VAL; idx += idx & -idx) {
        bit[idx] += val;
    }
}

static inline int query(int* bit, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)malloc(numsSize * sizeof(int));
    if (numsSize == 0) return counts;

    // Fixed-size BIT initialized to 0 on stack/heap
    int bit[MAX_VAL] = {0};

    // Process array from right to left
    for (int i = numsSize - 1; i >= 0; i--) {
        int val = nums[i] + OFFSET;
        counts[i] = query(bit, val - 1);
        update(bit, val, 1);
    }

    return counts;
}