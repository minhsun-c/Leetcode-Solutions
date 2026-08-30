bool divisorGame(int n) {
    bool win[n+1];
    memset(win, 0, sizeof(win));

    for (int i=2; i<=n; i++) {
        for (int x=1; x<i; x++) {
            if (i % x == 0 && !win[i-x]) {
                win[i] = true;
                break;
            }
        }
    }
    return win[n];
}