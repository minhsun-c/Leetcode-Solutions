/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {int idx; int n;} pair;
pair cnt[50];
int cmp(const void *a, const void *b) { 
    int ndiff = ((pair*) b)->n - ((pair *) a)->n; 
    if (ndiff) return ndiff;
    else return ((pair*) b)->idx - ((pair *) a)->idx; 
}

int calc(int x)
{
    pair arr[50];
    memcpy(arr, cnt, sizeof(cnt));
    qsort(arr, 50, sizeof(pair), cmp);

    int sum = 0;
    if (arr[x-1].n == 0) {
        for (int i=0; i<50; i++) sum += cnt[i].idx * cnt[i].n;
    } else {
        for (int i=0; i<x; i++) sum += arr[i].idx * arr[i].n;
    }
    return sum;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int *ret = (int *)malloc(sizeof(int) * *returnSize);
    
    for (int i=0; i<50; i++) cnt[i] = (pair){i+1, 0};
    for (int i=0; i<k; i++) cnt[nums[i]-1].n ++;
    for (int i=k-1; i<numsSize; i++) {
        ret[i-k+1] = calc(x);
        if (i<numsSize-1) {
            cnt[nums[i-k+1]-1].n --;
            cnt[nums[i+1]-1].n ++;
        }
    }
    return ret;
}