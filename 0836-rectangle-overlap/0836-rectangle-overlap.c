bool overlap(int a1, int a2, int b1, int b2) {
    return a1 < b2 && b1 < a2;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    bool x = overlap(rec1[0], rec1[2], rec2[0], rec2[2]);
    bool y = overlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    return x && y;
}