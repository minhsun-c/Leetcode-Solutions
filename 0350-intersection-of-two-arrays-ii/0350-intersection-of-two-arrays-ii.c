/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *arr = malloc(sizeof(int) * 1000);
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int i=0, j=0, cnt=0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            arr[cnt] = nums1[i]; i++; j++; cnt ++;
        } else if (nums1[i] < nums2[j]) i++;
        else j++;
    }
    *returnSize = cnt;
    return arr;
}
