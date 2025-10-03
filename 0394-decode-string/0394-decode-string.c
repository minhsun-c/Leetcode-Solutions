typedef struct {
    char *buf;
    int len, cap;
} data_t;

void init(data_t *d) {
    d->cap = 500;
    d->buf = (char *)malloc(sizeof(char)*d->cap);
    d->len = 0;
}

void expand(data_t *d) {
    d->cap *= 2;
    d->buf = (char *)realloc(d->buf, sizeof(char)*d->cap);
}

void append(data_t *d, char *str) {
    for (int i=0; str[i]; i++) {
        if (d->len == d->cap - 2) expand(d);
        d->buf[d->len] = str[i];
        d->len ++;
    }
    d->buf[d->len] = 0;
}

void repeat(data_t *d, char *str, int times) {
    for (int i=0; i<times; i++)
        append(d, str);
}

char *rec(char *s, int *idx) {
    data_t d; 
    init(&d);
    while (s[*idx] && s[*idx] != ']') {
        if (isalpha(s[*idx])) {
            if (d.len == d.cap - 1) expand(&d);
            d.buf[d.len] = s[*idx];
            d.len ++;
            d.buf[d.len] = 0;
            (*idx) ++;
        } else if (isdigit(s[*idx])) {
            int n = 0;
            while (isdigit(s[*idx])) {
                n = n * 10 + (s[*idx] - '0');
                (*idx) ++;
            }
            (*idx) ++;
            char *inner = rec(s, idx);
            repeat(&d, inner, n);
            free(inner);
        }
    }
    if (s[*idx] == ']') (*idx) ++;
    return d.buf;
}

char* decodeString(char* s) {
    int idx = 0;
    return rec(s, &idx);
}