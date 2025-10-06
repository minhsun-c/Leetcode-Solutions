#define MAXN 100005
#define MAX(a, b) (a > b ? a : b)

#define PARENT(n)   (((n)-1) >> 1)
#define LEFT(n)     (((n) << 1) + 1)
#define RIGHT(n)    (((n) + 1) << 1)

typedef struct { int x; int y; } Node;

static Node heap[MAXN];
static int size = 0;

static inline int cmp(Node a, Node b) {
    if (a.x != b.x) return (a.x < b.x) ? -1 : 1;
    if (a.y != b.y) return (a.y < b.y) ? -1 : 1;
    return 0;
}

static inline void swap(int i, int j) {
    if (i == j) return;
    Node t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

static void heapifyDown(void) {
    int cur = 0;
    while (true) {
        int l = LEFT(cur), r = RIGHT(cur);
        int s = cur;
        if (l < size && cmp(heap[l], heap[s]) < 0) s = l;
        if (r < size && cmp(heap[r], heap[s]) < 0) s = r;
        if (s == cur) break;
        swap(cur, s);
        cur = s;
    }
}

static void heapifyUp(void) {
    int cur = size - 1;
    while (cur > 0) {
        int p = PARENT(cur);
        if (cmp(heap[cur], heap[p]) < 0) {
            swap(cur, p);
            cur = p;
        } else break;
    }
}

bool heap_empty(void) { return size == 0; }
int heap_size(void) { return size; }

bool heap_push(Node v) {
    if (size >= MAXN) return false; 
    heap[size++] = v;
    heapifyUp();
    return true;
}

Node heap_top(void) {
    return heap[0];                      
}

Node heap_pop(void) {
    Node ret = heap[0];                  
    heap[0] = heap[--size];
    if (size > 0) heapifyDown();
    return ret;
}

static int cmp_sort(const void *a, const void *b) {
    int x_diff = ((Node *)b)->x - ((Node *)a)->x;
    int y_diff = ((Node *)b)->y - ((Node *)a)->y;
    return x_diff ? x_diff : y_diff;
}

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    long long sum = 0;
    long long ret = 0;
    
    size = 0;
    Node *arr = (Node*)malloc(sizeof(Node) * nums1Size);
    if (!arr) return 0;

    for (int i = 0; i < nums1Size; ++i) {
        arr[i].x = nums2[i];
        arr[i].y = nums1[i];
    }
    qsort(arr, nums1Size, sizeof(Node), cmp_sort);

    for (int i = 0; i < nums1Size; ++i) {
        
        heap_push((Node){ .x = arr[i].y, .y = i });
        sum += arr[i].y;

        if (heap_size() > k) {
            Node t = heap_pop(); 
            sum -= t.x;
        }

        if (heap_size() == k) {
            long long cand = sum * (long long)arr[i].x; 
            ret = MAX(ret, cand);
        }
    }

    return ret;
}