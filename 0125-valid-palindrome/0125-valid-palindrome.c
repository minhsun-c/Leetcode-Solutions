bool isPalindrome(char* s) {
    char *bg = s, *end = s + strlen(s) - 1;
    while (bg && end && bg <= end) {
        printf("[%c|%c]\n", *bg, *end);
        while (1) {
            printf("diff: %d\n", bg - s);
            if (!bg) return false;
            if (*bg && !(isalpha(*bg) || isdigit(*bg))) bg ++;
            else break;
        }
        while (1) {
            if (!end) return false;
            if (end >= s && !(isalpha(*end) || isdigit(*end))) end --;
            else break;
        }
        // printf("%c %c\n", *bg, *end);
        if (!bg || !end || (*bg && *end && tolower(*bg) != tolower(*end))) return false;
        bg ++; end --;
    }
    return true;
}