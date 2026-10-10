#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    // Set the return size of the array
    *returnSize = numsSize;
    
    // Allocate memory for the result array
    int* ans = (int*)malloc(numsSize * sizeof(int));
    if (ans == NULL) {
        return NULL; // Allocation failure check
    }
    
    // Populate the result array
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[nums[i]];
    }
    
    return ans;
}