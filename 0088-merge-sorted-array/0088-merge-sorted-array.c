void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int len = m + n;
    m --; n --;
    for (int i=len-1; i>=0; i--) {
        if (m < 0) nums1[i] = nums2[n--];
        else if (n < 0) nums1[i] = nums1[m--];
        else if (nums1[m] > nums2[n]) nums1[i] = nums1[m--];
        else nums1[i] = nums2[n--];
    }
}