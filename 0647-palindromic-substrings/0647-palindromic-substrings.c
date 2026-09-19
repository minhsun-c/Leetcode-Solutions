int countSubstrings(char* s) {
    int count = 0;
    ssize_t sl = strlen(s);
    for (int c=0; c<(int)sl; c++) {
        // odd
        for (int l=c, r=c; l>=0 && c<sl; ) {
            if (s[l] == s[r]) {
                l --; r ++;
                count ++;
            } else 
                break;
        }
        // even
        for (int l=c, r=c+1; l>=0 && c<sl; ) {
            if (s[l] == s[r]) {
                l --; r ++;
                count ++;
            } else 
                break;
        }
    }
    return count;
}