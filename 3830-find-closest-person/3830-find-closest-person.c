int findClosest(int x, int y, int z) {
    int res = abs(x-z) - abs(y-z);
    if (res == 0) return 0;
    else if (res < 0) return 1;
    else return 2;
}