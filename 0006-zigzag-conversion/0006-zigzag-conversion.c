char* convert(char* s, int numRows) {
    int sl = strlen(s);

    if (numRows == 1 || sl < numRows) 
        return s;

    char arr[numRows][sl];
    int idxs[numRows];
    memset(idxs, 0, sizeof(idxs));

    int dir = 1, row = 0;
    for (int i=0; i<sl; i++) {
        arr[row][idxs[row]] = s[i];
        idxs[row] ++;

        if (dir == 1 && row == numRows - 1) dir = -1;
        if (dir == -1 && row == 0) dir = 1;

        row += dir;
    }

    char *ans = malloc(sl + 1);
    ans[0] = 0;

    for (int i=0; i<numRows; i++) {
        arr[i][idxs[i]] = 0;
        strcat(ans, arr[i]);
    }
    ans[sl] = 0;

    return ans;
}