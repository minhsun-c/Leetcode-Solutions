/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXLEN 1e9
void push(int **arr, int *colsize, int *size, int a, int b, int c) {
    arr[*size] = (int *)malloc(sizeof(int) * 3);
    arr[*size][0] = a;
    arr[*size][1] = b;
    arr[*size][2] = c;
    colsize[*size] = 3;
    (*size) ++;
}

void solve(int *nums, int numsSize, int **arr, int *colsize, int *size) {
    int last1 = INT_MIN, last2 = INT_MIN, last3 = INT_MIN;
    for (int i=0; i<numsSize-2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0) k --;
            else if (sum < 0) j ++;
            else {
                push(arr, colsize, size, nums[i], nums[j], nums[k]);
                while (j < k && nums[j] == nums[j+1]) j++;
                while (j < k && nums[k] == nums[k-1]) k--;
                j++;
                k--;
            }
        }
    }
}

void merge(int *nums, int left, int mid, int right) {
    int l1[mid - left + 1];
    int l2[right - mid];
    memcpy(l1, nums + left, sizeof(int) * (mid - left + 1));
    memcpy(l2, nums + mid + 1, sizeof(int) * (right - mid));
    int i = 0, j = 0, start = left;
    while (left + i <= mid && mid + 1 + j <= right) {
        if (l1[i] < l2[j]) {
            nums[start++] = l1[i++];
        } else {
            nums[start++] = l2[j++];
        }
    }
    while (left + i <= mid) nums[start++] = l1[i++];
    while (mid + 1 + j <= right) nums[start++] = l2[j++];
}

void mergesort(int *nums, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(nums, left, mid);
    mergesort(nums, mid+1, right);
    merge(nums, left, mid, right);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **arr = (int **)malloc(sizeof(int *) * MAXLEN);
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAXLEN);
    *returnSize = 0;

    mergesort(nums, 0, numsSize - 1);

    solve(nums, numsSize, arr, *returnColumnSizes, returnSize);
    return arr;
}