bool isValid(char* s) {
    int sl = strlen(s);
    char stack[sl];
    int top = 0;
    for (char *c = s; *c; c ++) {
        switch (*c) {
        case '(': 
            stack[top] = *c;
            top ++;
            break;
        case ')':
            top --;
            if (top < 0 || stack[top] == '[' || stack[top] == '{') return false;
            break;
        case '[':
            stack[top] = *c;
            top ++;
            break;
        case ']':
            top --;
            if (top < 0 || stack[top] == '(' || stack[top] == '{') return false;
            break;
        case '{':
            stack[top] = *c;
            top ++;
            break;
        case '}':
            top --;
            if (top < 0 || stack[top] == '[' || stack[top] == '(') return false;
            break;
        }
        if (top < 0)
            return false;
    }
    return top == 0;
}