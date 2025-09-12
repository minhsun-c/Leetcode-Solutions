#define ARRSIZE 10005
typedef struct {
    int q[ARRSIZE];
    int front;
    int end;    
    int size
} RecentCounter;

void push(RecentCounter *obj, int val) {
    obj->q[obj->end] = val;
    obj->end = (obj->end + 1) % ARRSIZE;
    obj->size ++;
}

void pop(RecentCounter *obj) {
    obj->front = (obj->front + 1) % ARRSIZE;
    obj->size --;
}

RecentCounter* recentCounterCreate() {
    RecentCounter *obj = (RecentCounter *) malloc (sizeof(RecentCounter));
    obj -> front = obj -> end = obj -> size = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    int min = t - 3000;
    push(obj, t);
    while (obj->size) {
        if (obj->q[obj->front] < min) 
            pop(obj);
        else
            break;
    }
    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/