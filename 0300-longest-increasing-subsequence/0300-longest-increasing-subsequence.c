#define MAX(a, b) (a > b ? a : b)
int cmp(const void *a, const void *b) {return *(int *)a - *(int *)b;}

int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize + 1][numsSize + 1];
    int cp[numsSize];
    memcpy(cp, nums, sizeof(int) * numsSize);
    qsort(cp, numsSize, sizeof(int), cmp);
    for (int i=0; i<=numsSize; i++) {
        for (int j=0; j<=numsSize; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (j>=2 && cp[j-1] != cp[j-2] && nums[i-1] == cp[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else if (j == 1 && nums[i-1] == cp[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
        }
    }    
    return dp[numsSize][numsSize];
}