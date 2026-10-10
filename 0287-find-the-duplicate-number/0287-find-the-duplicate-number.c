int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect the cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}