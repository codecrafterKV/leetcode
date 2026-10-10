int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxCount = 0;
    int currentCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }

    return maxCount;
}