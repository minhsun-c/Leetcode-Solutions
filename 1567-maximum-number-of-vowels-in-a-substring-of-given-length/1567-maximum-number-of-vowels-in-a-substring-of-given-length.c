#define VOWEL(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

int maxVowels(char* s, int k) {
    int max = 0;
    int sum = 0;
    int start = 0;
    for (int i=0; i<k; i++) {
        int v = VOWEL(s[i]);
        max += v;
        sum += v;
    }
    for (int i=k; s[i]; i++) {
        sum -= VOWEL(s[start]);
        start ++;
        sum += VOWEL(s[i]);
        if (sum > max) max = sum;
    }
    return max;
}