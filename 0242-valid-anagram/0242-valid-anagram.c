bool isAnagram(char* s, char* t) {
    int ht1[26], ht2[26];
    memset(ht1, 0, sizeof(ht1));
    memset(ht2, 0, sizeof(ht2));
    for (char *c = s; *c; c++) 
        ht1[*c - 'a'] ++;
    for (char *c = t; *c; c++) 
        ht2[*c - 'a'] ++;
    return memcmp(ht1, ht2, sizeof(ht1)) == 0;
}