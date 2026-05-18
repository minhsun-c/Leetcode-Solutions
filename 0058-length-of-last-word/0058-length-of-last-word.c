int lengthOfLastWord(char* s) {
    int sl = strlen(s) - 1;
    while (sl >= 0 && s[sl] == ' ') {
        s[sl] = 0;
        sl --;
    }
    int ans = 0;
    while (sl >= 0 && s[sl] != ' ') {
        ans ++;
        sl --;
    }
    return ans;
}