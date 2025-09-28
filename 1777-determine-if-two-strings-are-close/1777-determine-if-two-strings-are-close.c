int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
bool closeStrings(char* word1, char* word2) {
    int a[26] = {0};
    int b[26] = {0};
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1 != len2) return false;
    for (int i=0; i<len1; i++) {
        a[word1[i] - 'a'] ++;
        b[word2[i] - 'a'] ++;
    }
    for (int i=0; i<26; i++) 
        if ((a[i] && !b[i]) || (!a[i] && b[i]))
            return false;
            
    qsort(a, 26, sizeof(int), cmp);
    qsort(b, 26, sizeof(int), cmp);
    for (int i=0; i<26; i++) 
        if (a[i] != b[i])
            return false;
    return true;
}