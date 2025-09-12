#define MAX(a, b) (a > b ? a : b)

int longestPalindromeSubseq(char* s) {
    int len = strlen(s);
    int arr[len][len];
    for (int i=0; i<len-1; i++) arr[i+1][i] = 0;

    for (int i=0; i<len; i++) {
        for (int j=0; i+j<len; j++) {
            int k = i + j;
            if (j == k) arr[j][k] = 1;
            else if (j < k && s[j] == s[k]) arr[j][k] = arr[j+1][k-1] + 2;
            else arr[j][k] = MAX(arr[j+1][k], arr[j][k-1]);
        }
    }

    return arr[0][len-1];
}