char* convert(char* s, int numRows) {
    int len = strlen(s);
    char buf[len+1];
    strcpy(buf, s);
    int idx = 0;
    int offset = numRows * 2 - (numRows >= 1) - (numRows >= 2);
    int round = len / offset + (len % offset != 0);
    for (int i=0; i<=offset/2 && idx < len; i++) {
        for (int j=0; j<round && j * offset + i < len; j++) {
            s[idx++] = buf[j * offset + i];
            int side = j * offset + (offset - i);
            if (i && offset - i != i && side < len) {
                s[idx++] = buf[side];
            }
        }
    }
    return s;
}