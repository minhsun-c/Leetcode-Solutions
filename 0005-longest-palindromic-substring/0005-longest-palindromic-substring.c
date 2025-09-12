#define MAX(a, b) (a > b ? a : b)


char* longestPalindrome(char* s) {
    int len = strlen(s);
    int arr[len][len];
    memset(arr, 0, sizeof(arr));
    int start = 0, end = 0;
    int max = 0;
    
    for (int i=0; i<len-1; i++) {
        arr[i+1][i] = 0;
    }

    for (int i=0; i<len; i++) {
        for (int j=0; i+j<len; j++) {
            int k = i + j;
            if (j == k) {
                arr[j][k] = 1;
            }
            else if (s[j] == s[k] && (j + 1 == k || arr[j+1][k-1])) {
                arr[j][k] = arr[j+1][k-1] + 2;
                if (i > max) {
                    max = i;
                    start = j; end = k;
                }
            }
            else {
                arr[j][k] = 0;
            }
        }
    }

    s[end+1] = 0;

    return s + start;
}