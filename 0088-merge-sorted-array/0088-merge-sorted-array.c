void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m-1, j = n-1;
    for (int idx = m+n-1; idx >= 0 && i >= 0 && j >= 0; idx--) {
        if (nums1[i] > nums2[j]) {
            nums1[idx] = nums1[i];
            i --;
        } else {
            nums1[idx] = nums2[j];
            j --;
        }
    }
    if (i <= 0) {
        memcpy(nums1, nums2, (j + 1) * sizeof(int));
    }
}