char *sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int val[]  = {1000, 900,  500, 400,  100,  90,  50,  40,   10,   9,    5,   4,    1};

char* intToRoman(int num) {
    char *ans = malloc(32);
    ans[0] = 0;
    for (int i=0; i<13; i++) {
        while (num >= val[i]) {
            strcat(ans, sym[i]);
            num -= val[i];
        }
    }
    return ans;
}