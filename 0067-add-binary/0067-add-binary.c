#define MAX(a, b) (a > b ? a : b)

void reverse(char *str, int size) {
    for (int i=0, j=size-1; i<j; i++, j--) {
        str[i] = str[i] ^ str[j];
        str[j] = str[i] ^ str[j];
        str[i] = str[i] ^ str[j];
    }
}

char* addBinary(char* a, char* b) {
    int la = strlen(a);
    int lb = strlen(b);
    char *buf = (char *)malloc(sizeof(char) * (MAX(la, lb) + 2));
    int idx = 0;
    int sum, carry = 0;
    int op1, op2;
    for (int i = la-1, j = lb-1; i>=0 || j>=0 || carry; i--, j--) {
        op1 = (i >= 0) ? (a[i] - '0') : 0;
        op2 = (j >= 0) ? (b[j] - '0') : 0;
        sum = op1 + op2 + carry;
        carry = !!(sum & 2);
        sum = sum & 1;
        buf[idx ++] = sum + '0';
    }
    buf[idx] = 0;
    reverse(buf, idx);
    return buf;
}