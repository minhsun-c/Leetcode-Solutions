bool isPalindrome(char* s) {
    char *bg = s, *end = s + strlen(s) - 1;
    while (bg && end && bg <= end) {
        while (1) {
            if (!bg) return false;
            if (*bg && !(isalpha(*bg) || isdigit(*bg))) bg ++;
            else break;
        }
        while (1) {
            if (!end) return false;
            if (end >= s && !(isalpha(*end) || isdigit(*end))) end --;
            else break;
        }
        if (!bg || !end || (*bg && *end && tolower(*bg) != tolower(*end))) return false;
        bg ++; end --;
    }
    return true;
}