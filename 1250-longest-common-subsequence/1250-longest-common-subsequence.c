#define MAX(a, b) (a > b ? a : b)

int longestCommonSubsequence(char* text1, char* text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int arr[len1+1][len2+1];
    for (int i=0; i<=len1; i++) {
        for (int j=0; j<=len2; j++) {
            if (!i || !j) arr[i][j] = 0;
            else if (text1[i-1] == text2[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = MAX(arr[i-1][j], arr[i][j-1]);
        }
    }
    return arr[len1][len2];
}