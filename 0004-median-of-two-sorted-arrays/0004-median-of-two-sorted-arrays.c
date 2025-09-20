double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    int mid1 = (size-1) / 2;    
    int mid2 = size / 2;
    int m1 = INT_MIN, m2 = INT_MIN;
    int idx1 = 0, idx2 = 0;
    int cnt = 0;
    while (idx1 < nums1Size && idx2 < nums2Size && cnt <= mid2) {
        int min;
        if (nums1[idx1] < nums2[idx2]) {
            min = nums1[idx1];
            idx1 ++;
        } else {
            min = nums2[idx2];
            idx2 ++;
        }
        if (cnt == mid1) m1 = min;
        if (cnt == mid2) m2 = min;
        cnt ++;
    }
    while (idx1 < nums1Size && cnt <= mid2) {
        if (cnt == mid1) m1 = nums1[idx1];
        if (cnt == mid2) m2 = nums1[idx1];
        cnt ++; idx1 ++;
    }
    while (idx2 < nums2Size && cnt <= mid2) {
        if (cnt == mid1) m1 = nums2[idx2];
        if (cnt == mid2) m2 = nums2[idx2];
        cnt ++; idx2 ++;
    }
    return (m1 + m2) / 2.0;
}