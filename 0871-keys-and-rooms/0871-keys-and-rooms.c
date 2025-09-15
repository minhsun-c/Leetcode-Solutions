int locks[1000];
int count;

bool rec(int **rooms, int* roomsColSize, int cur) {
    if (locks[cur]) return false;
    locks[cur] = 1;
    count ++;
    bool ans = false;
    for (int i=0; i<roomsColSize[cur]; i++) {
        ans = ans || rec(rooms, roomsColSize, rooms[cur][i]);
    }
    return ans;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    count = 0;
    memset(locks, 0, sizeof(locks));
    rec(rooms, roomsColSize, 0);
    return count == roomsSize;
}