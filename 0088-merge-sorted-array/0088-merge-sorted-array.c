#pragma GCC optimize("O3")

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;          // Pointer for nums1 end element
    int p2 = n - 1;          // Pointer for nums2 end element
    int p = m + n - 1;       // Pointer for insertion at the end of nums1

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // Copy remaining elements from nums2 if any exist
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}