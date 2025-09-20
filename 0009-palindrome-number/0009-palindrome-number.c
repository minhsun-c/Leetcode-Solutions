bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0) return true;
    int lg = log(x) / log(10);
    int arr[lg+1];
    for (int i=0; i<=lg; i++) {
        arr[i] = x % 10; 
        x /= 10;
    }
    int l = lg, r = 0;
    while (l > r) {
        if (arr[l] != arr[r]) return false;
        l --; r++;
    }
    return true;
}