char *trim(char *s) {
    while (*s && isspace(*s))
        s++;
    if (*s == 0) return NULL;
    int j = strlen(s) - 1;
    while (s[j] && isspace(s[j])) {
        s[j] = 0;
        j --;
    }
    return s;
}

char *rspace(char *s) {
    int size = strlen(s) - 1;
    while (size && !isspace(s[size])) size --;
    if (size == 0) return NULL;
    return s + size + 1;
}

char* reverseWords(char* s) {
    char *str = (char *)malloc(strlen(s) + 1);
    char sp[] = " ";
    *str = 0;
    int cnt = 0;
    while (1) {
        s = trim(s);
        char *bk = rspace(s);
        if (bk == NULL) {
            if (cnt++)
                strcat(str, sp);
            strcat(str, s);
            break;
        } else {
            if (cnt++)
                strcat(str, sp);
            strcat(str, bk);
            *(bk - 1) = 0;
        }
    }
    return str;
}