static void reverse(char *s, int len) {
    for (int i = 0; i < len / 2; i++) {
        char t = s[i]; s[i] = s[len-i-1]; s[len-i-1] = t;
    }
}

static void add_into(char *dst, const char *src) {
    int i = strlen(dst) - 1;
    int j = strlen(src) - 1;
    int carry = 0, k = 0;
    char acc[1000];
    while (i >= 0 || j >= 0 || carry) {
        int s = carry;
        if (i >= 0) s += dst[i--] - '0';
        if (j >= 0) s += src[j--] - '0';
        carry = s / 10;
        acc[k++] = '0' + s % 10;
    }
    acc[k] = '\0';
    reverse(acc, k);
    strcpy(dst, acc);
}

char *multiply(char *num1, char *num2) {
    static char result[1000];
    static char temp[1000];
    int l1 = strlen(num1), l2 = strlen(num2);

    if ((l1==1 && num1[0]=='0') || (l2==1 && num2[0]=='0')) {
        result[0]='0'; result[1]='\0'; return result;
    }

    result[0] = '0'; result[1] = '\0';

    for (int i = l2 - 1; i >= 0; i--) {
        int d = num2[i] - '0';
        if (d == 0) continue;

        int zeros = l2 - 1 - i;
        int carry = 0, pos = 0;

        for (int j = l1 - 1; j >= 0; j--) {
            int s = carry + (num1[j] - '0') * d;
            carry = s / 10;
            temp[pos++] = '0' + s % 10;
        }
        if (carry) temp[pos++] = '0' + carry;

        reverse(temp, pos);

        for (int z = 0; z < zeros; z++) temp[pos++] = '0';
        temp[pos] = '\0';

        add_into(result, temp);
    }
    return result;
}