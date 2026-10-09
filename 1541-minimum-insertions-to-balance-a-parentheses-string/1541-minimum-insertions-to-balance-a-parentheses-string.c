int minInsertions(char* s) {
    int cnt = 0;
    int top = 0;
    for (int i=0; s[i]; i++) {
        if (s[i] == '(') {
            if (top % 2 == 1) { // require one ')'
                top --;
                cnt ++;
            }
            top += 2;
        } else {
            top --;
            if (top < 0) { // add one '(', require another ')'
                top = 1;
                cnt ++;
            }
        }
    }
    return cnt + top;
}