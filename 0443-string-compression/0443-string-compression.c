int compress(char* chars, int charsSize) {
    int idx = 0;
    int cnt = 0;
    char last = '.';
    char temp[10];
    for (int i=0; i<=charsSize; i++) {
        if (i == charsSize || chars[i] != last) {
            char cur = (i!=charsSize) ? chars[i] : '.';
            if (i != 0 && cnt > 1) {
                sprintf(temp, "%d", cnt);
                for (int j=0; j<strlen(temp); j++) chars[idx + j] = temp[j];
                idx += strlen(temp);
            }
            if (i != charsSize) {
                chars[idx++] = cur;
                cnt = 1;
                last = cur;
            }
        } else {
            cnt ++;
        }
    }
    return idx;
}