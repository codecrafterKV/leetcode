/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    for (int i = 0; i < n; i++) {
        result[2 * i] = nums[i];       // Place x_i at even indices
        result[2 * i + 1] = nums[i + n]; // Place y_i at odd indices
    }
    
    return result;
}