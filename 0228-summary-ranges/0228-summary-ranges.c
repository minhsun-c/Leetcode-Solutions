/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char **arr = malloc(sizeof(char *) * 20);
    int cnt = 0;

    if (numsSize == 0) goto rt;

    int begin = nums[0];
    int prev = nums[0];

    for (int i=1; i<numsSize; i++) {
        if (nums[i] != prev + 1) {
            arr[cnt] = malloc(25);
            if (begin != prev)
                sprintf(arr[cnt], "%d->%d", begin, prev);
            else
                sprintf(arr[cnt], "%d", begin);
            cnt ++;
            begin = prev = nums[i];
        } else {
            prev = nums[i];
        }
    }
    arr[cnt] = malloc(25);
    if (begin != prev)
        sprintf(arr[cnt], "%d->%d", begin, prev);
    else
        sprintf(arr[cnt], "%d", begin);
    cnt ++;

rt:
    *returnSize = cnt;
    return arr; 
}