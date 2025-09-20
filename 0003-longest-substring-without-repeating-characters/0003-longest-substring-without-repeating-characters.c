int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int front = 0;
    int max = 0;
    for (int i=0; i<len; i++) {
        for (int j=i-1; j>=front; j--) {
            if (s[i] == s[j]) front = j + 1;
        }
        if (i-front+1 > max) max = i - front + 1;
    }
    return max;
}