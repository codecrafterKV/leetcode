void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        // Place nums[i] at index nums[i] - 1 if it is in range [1, numsSize]
        // and not already at its correct target position
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            swap(&nums[i], &nums[nums[i] - 1]);
        }
    }

    // Find the first index where index + 1 != nums[index]
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all numbers 1..numsSize are present, the answer is numsSize + 1
    return numsSize + 1;
}