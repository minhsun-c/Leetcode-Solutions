int lengthOfLongestSubstring(char* s) {
    int idx[128];
    memset(idx, -1, sizeof(idx));

    int sl = strlen(s);
    if (sl == 0)
        return 0;

    int max = 1;
    int cnt = 1;
    int head = 0;
    idx[s[0]] = 0;
    for (int i=1; i<sl; i++) {
        if (idx[s[i]] < head) {
            idx[s[i]] = i;
            cnt ++;
        } else {
            max = cnt > max ? cnt : max;
            head = idx[s[i]] + 1;
            idx[s[i]] = i;
            cnt = i - head + 1;
        }
    }
    max = cnt > max ? cnt : max;
    return max;
}