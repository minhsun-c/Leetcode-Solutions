/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int hash[2001];

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int **arr = (int **)malloc(sizeof(int *)*2);
    arr[0] = (int *)malloc(sizeof(int)*nums1Size);
    arr[1] = (int *)malloc(sizeof(int)*nums2Size);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(*returnColumnSizes, 0, sizeof(int)*2);
    memset(hash, 0, sizeof(hash));
    for (int i=0; i<nums1Size; i++) hash[nums1[i] + 1000] |= 1;
    for (int i=0; i<nums2Size; i++) hash[nums2[i] + 1000] |= 2;
    int cnt = 0;
    for (int i=0; i<2001; i++) {
        if (hash[i] == 1) 
            arr[0][cnt ++] = i - 1000;
    }
    (*returnColumnSizes)[0] = cnt;
    cnt = 0;
    for (int i=0; i<2001; i++) {
        if (hash[i] == 2) 
            arr[1][cnt ++] = i - 1000;
    }
    (*returnColumnSizes)[1] = cnt;
    return arr;
}