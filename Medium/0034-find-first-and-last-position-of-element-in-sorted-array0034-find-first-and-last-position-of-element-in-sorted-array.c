#include <stdlib.h>

int findBound(int* nums, int numsSize, int target, int isFirst) {
    int left = 0;
    int right = numsSize - 1;
    int bound = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            bound = mid;
            if (isFirst) {
                right = mid - 1; // Keep searching on the left side
            } else {
                left = mid + 1;  // Keep searching on the right side
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return bound;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    result[0] = findBound(nums, numsSize, target, 1);
    
    // If the element is not found, both boundaries are -1
    if (result[0] == -1) {
        result[1] = -1;
        return result;
    }
    
    result[1] = findBound(nums, numsSize, target, 0);
    return result;
}
