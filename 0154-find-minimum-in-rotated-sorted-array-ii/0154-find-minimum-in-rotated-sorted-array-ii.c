#pragma GCC optimize("O3")

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            // The minimum must be in the left half, including mid
            right = mid;
        } else if (nums[mid] > nums[right]) {
            // The minimum must be in the right half, excluding mid
            left = mid + 1;
        } else {
            // nums[mid] == nums[right], duplicate encountered
            // Safely shrink the search space by decrementing right
            right--;
        }
    }

    return nums[left];
}