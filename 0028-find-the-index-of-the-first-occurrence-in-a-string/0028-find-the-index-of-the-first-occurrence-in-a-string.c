int strStr(char* haystack, char* needle) {
    char *p = haystack;
    size_t len = strlen(needle);
    while (*p) {
        p = strchr(p, *needle);
        if (p == NULL) return -1;
        else if (strncmp(p, needle, len) == 0) return (p - haystack);
        p++;
    }
    return -1;
}