

char * defangIPaddr(char * address){
    int len = strlen(address);
    char *str = (char *)malloc(sizeof(char)*(len + 7));
    int i=0, j=0;
    for (; address[i]; i++) {
        if (address[i] != '.') str[j ++] = address[i];
        else {
            str[j ++] = '[';
            str[j ++] = '.';
            str[j ++] = ']';
        }
    }
    str[j] = 0;
    return str;
}