char* maxSumOfSquares(int num, int sum) {
    char *ans = malloc(num + 1);
    if (num * 9 < sum) {
        ans[0] = 0;
        return ans;
    }
    int cnt9 = sum / 9;
    int left = sum % 9;

    int i;
    for (i=0; i<cnt9; i++) {
        ans[i] = '9';
    }
    if (i < num) {
        ans[i] = left + '0';
        i ++;
    }
    for (; i<num; i++) {
        ans[i] = '0';
    }
    ans[num] = 0;
    return ans;
}