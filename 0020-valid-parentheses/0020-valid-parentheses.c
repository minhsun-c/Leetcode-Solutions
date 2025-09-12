bool isValid(char* s) {
    int idx = 0;
    int top = -1;
    for (; s[idx]; idx ++) {
        switch (s[idx]) {
            case ')':
                if (top == -1 || s[top] != '(') return false;
                else top --;
                break;
            case ']':
                if (top == -1 || s[top] != '[') return false;
                else top --;
                break;
            case '}':
                if (top == -1 || s[top] != '{') return false;
                else top --;
                break;
            default:
                s[++top] = s[idx];
                break;
        }
    }
    if (top != -1) return false;
    return true;
}