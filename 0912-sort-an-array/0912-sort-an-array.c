#pragma GCC optimize("O3,unroll-loops")

static void merge(int* nums, int* temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize <= 1) return nums;

    int* temp = (int*)malloc(numsSize * sizeof(int));

    // Bottom-Up Iterative Merge Sort
    for (int width = 1; width < numsSize; width *= 2) {
        for (int i = 0; i < numsSize; i += 2 * width) {
            int left = i;
            int mid = i + width - 1;
            int right = (i + 2 * width - 1 < numsSize - 1) ? (i + 2 * width - 1) : (numsSize - 1);

            if (mid < right) {
                merge(nums, temp, left, mid, right);
            }
        }
    }

    free(temp);
    return nums;
}