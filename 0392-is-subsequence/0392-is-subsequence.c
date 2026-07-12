bool isSubsequence(char* s, char* t) {
    while (*s && *t) {
        while (*t && *s != *t) t ++;
        if (!*t) break;
        s++; t++;
    }
    if (!*s) return true;
    return false;
}