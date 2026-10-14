char* maxSumOfSquares(int num, int sum) {
    char *ans = malloc(num + 1);
    for (int i=0; i<num; i++) {
        if (sum >= 9) {
            ans[i] = '9';
            sum -= 9;
        } else {
            ans[i] = sum + '0';
            sum = 0;
        }
    }
    if (sum != 0)
        ans[0] = 0;
    else
        ans[num] = 0;
    return ans;
}