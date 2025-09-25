#define PARENT(n)   (((n)-1) >> 1)
#define LEFT(n)     (((n) << 1) + 1)
#define RIGHT(n)    (((n) + 1) << 1)

typedef struct {
    int exist[1001];
    int heap[1001];
    int size;
} SmallestInfiniteSet;

static inline void swap(SmallestInfiniteSet *obj, int i, int j) {
    if (i == j) return;
    int t = obj->heap[i]; obj->heap[i] = obj->heap[j]; obj->heap[j] = t;
}

void heapifyDown(SmallestInfiniteSet *obj) {
    int *hp = obj->heap;
    int cur = 0;
    while (cur < obj->size) {
        int left = LEFT(cur);
        int right = RIGHT(cur);
        int min_idx = cur, min_val = hp[cur];
        if (left < obj->size && hp[left] < min_val) {
            min_idx = left;
            min_val = hp[left];
        }
        if (right < obj->size && hp[right] < min_val) {
            min_idx = right;
            min_val = hp[right];
        }
        if (min_idx == cur) return;
        else swap(obj, min_idx, cur);
        cur = min_idx;
    }
}

void heapifyUp(SmallestInfiniteSet *obj) {
    int *hp = obj->heap;
    int cur = obj->size - 1;
    while (cur > 0) {
        int parent = PARENT(cur);
        if (hp[parent] > hp[cur]) {
            swap(obj, parent, cur);
            cur = parent;
        } else {
            break;
        }
    }
}

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* obj = (SmallestInfiniteSet *)malloc(sizeof(SmallestInfiniteSet));
    memset(obj->exist, -1, sizeof(obj->exist));
    obj->size = 1000;
    for (int i=1; i<=1000; i++) obj->heap[i-1] = i;
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    int ret = obj->heap[0];
    obj->exist[ret] = 0;
    obj->size --;
    obj->heap[0] = obj->heap[obj->size];
    heapifyDown(obj);
    return ret;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if (obj->exist[num]) return;
    obj->heap[obj->size] = num;
    obj->exist[num] = 1;
    obj->size ++;
    heapifyUp(obj);
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 
 * smallestInfiniteSetAddBack(obj, num);
 
 * smallestInfiniteSetFree(obj);
*/