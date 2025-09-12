#define VOWEL(ch) ({ \
    char c = ch | ' ' ; \
    (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');})

char* reverseVowels(char* s) {
    int size = strlen(s);
    int v = 0, i, j;
    for (i=0; i<size; i++) {
        if (VOWEL(s[i])) v ++;
    }
    v >>= 1; i = 0; j = size-1;
    while (v) {
        for (; i<size; i++) {
            if (VOWEL(s[i])) break;
        }
        for (; j>0; j--) {
            if (VOWEL(s[j])) break;
        }
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        v --; i++; j--;
    }
    return s;
}