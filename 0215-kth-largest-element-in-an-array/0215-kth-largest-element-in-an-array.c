#pragma GCC optimize("O3,unroll-loops")

int findKthLargest(int* nums, int numsSize, int k) {
    // Range of nums[i] is between -10000 and 10000
    // Offset array indices by 10000 to handle negative values
    int count[20001] = {0};

    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + 10000]++;
    }

    // Traverse from highest possible value (20000) down to lowest (0)
    for (int i = 20000; i >= 0; i--) {
        if (count[i] > 0) {
            k -= count[i];
            if (k <= 0) {
                return i - 10000;
            }
        }
    }

    return 0;
}