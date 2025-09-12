char * mergeAlternately(char * word1, char * word2){
    int size = strlen(word1) + strlen(word2) + 1;
    char *ret = (char *) malloc(sizeof(char) * size);
    char *ptr = ret;
    int cnt = 0;
    while (*word1 && *word2) {
        if (cnt & 1) { // word2
            *ptr++ = *word2++;
        } else {
            *ptr++ = *word1++;
        }
        cnt ++;
    }
    if (*word1) strcpy(ptr, word1);
    else if (*word2) strcpy(ptr, word2);
    return ret;
}