#define VOWEL(n) \
    ((n == 'a' - 'a') || (n == 'e' - 'a') || (n == 'i' - 'a') || (n == 'o' - 'a') || (n == 'u' - 'a'))
#define MAX(a, b) \
    (a > b ? a : b)

int maxFreqSum(char* s) {
    int alp[26] = {0};
    for (int i=0; s[i]; i++) alp[s[i] - 'a'] ++;
    int v = 0, c = 0;
    for (int i=0; i<26; i++) {
        if (VOWEL(i)) v = MAX(v, alp[i]);
        else c = MAX(c, alp[i]);
    }
    return v + c;
}