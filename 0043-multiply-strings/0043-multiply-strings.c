char sum[500];
char temp[500];
int l1, l2;
void strip(char *arr) {
    if (arr[0] == '0' && arr[1] == 0) return;
    int z = 0, i;
    for (int i=0; arr[i]; i++) {
        if (arr[i] == '0') z++;
        else break;
    }
    
    if (z) {
        for (i=z; arr[i]; i++) 
            arr[i-z] = arr[i];
        arr[i-z] = 0;
    }
}

void azero(char *arr, int z) {
    int len = strlen(arr);
    for (int i=0; i<z; i++) arr[len + i] = '0';
    arr[len + z] = 0;
} 

void reverse(char *arr) {
    int len = strlen(arr);
    for (int i=0; i<len/2; i++) {
        char t = arr[i]; 
        arr[i] = arr[len-i-1]; 
        arr[len-i-1] = t;
    }
}

void mul(char *num1, char dig) {
    int carry = 0;
    int s = 0;
    for (int i=l1-1; i>=0; i--) {
        printf("[i=%d] %d x %d\n", i, num1[i] - '0', dig - '0');
        s = carry + (num1[i] - '0') * (dig - '0');
        carry = s / 10;
        s = s % 10;
        temp[i+1] = '0' + s;
        printf("s = %d\n", s);
    }
    temp[0] = carry + '0';
    temp[l1 + 1] = 0;
    printf("temp: %s [%d] [%d]\n", temp, strlen(temp), l1);
}

void add() {
    printf("%s + %s ", temp, sum);
    char acc[500];
    reverse(temp);
    reverse(sum);
    int s = 0, c = 0;
    int tv = 1, sv = 1;
    
    int i;
    for (i=0; tv || sv; i++) {
        s = c;
        if (!temp[i] || tv == 0) tv = 0;
        else s += (temp[i] - '0');
        if (!sum[i] || sv == 0) sv = 0;
        else s += (sum[i] - '0');
        c = s / 10;
        s %= 10;
        acc[i] = s + '0';
    }
    acc[i] = 0;
    reverse(acc);
    strip(acc);
    strncpy(sum, acc, 500);
    printf("= %s\n", sum);
}

char* multiply(char* num1, char* num2) {
    l1 = strlen(num1);
    l2 = strlen(num2);
    if (num1[0] == '0' && l1 == 1) return num1;
    if (num2[0] == '0' && l2 == 1) return num2;
    sum[0] = '0'; sum[1] = '\0';
    for (int i=l2-1; i>=0; i--) {
        printf("%c\n", num2[i]);
        mul(num1, num2[i]);
        azero(temp, l2-1-i);
        add();
    }
    return sum;

}