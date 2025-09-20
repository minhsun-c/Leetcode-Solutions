bool isPalindrome(int x) {
    if (x < 0) return false;
    int lg = log(x) / log(10);
    int l = lg, r = 0;
    while (l > r) {
        int ln = (x / (int) pow(10, l)) % 10;
        int rn = (x / (int) pow(10, r)) % 10;
        if (ln != rn) return false;
        l --; r++;
    }
    return true;
}