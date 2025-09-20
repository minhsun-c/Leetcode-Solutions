int lengthOfLastWord(char* s) {
    int ptr1 = strlen(s) - 1, ptr2;
    while (ptr1 >= 0 && isspace(s[ptr1])) ptr1 --;
    ptr2 = ptr1;
    while (ptr2 >= 0 && !isspace(s[ptr2])) ptr2 --;
    return ptr1 - ptr2;
}