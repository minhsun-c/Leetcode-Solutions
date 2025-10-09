#define LEFT    1
#define RIGHT   -1

typedef struct {
    int cost;
    int idx;
} node_t;

static inline bool node_less(node_t a, node_t b) {
    if (a.cost != b.cost) return a.cost < b.cost;
    return a.idx < b.idx;            
}

typedef struct {
    node_t *a;    
    int size;     
    int cap;      
    int ptr;      
    int dir;      
} heap_t;

static void heap_swap(node_t *x, node_t *y) { node_t t = *x; *x = *y; *y = t; }

static void heapify_up(heap_t *h) {
    int cur = h->size - 1;
    while (cur > 0) {
        int p = (cur - 1) / 2;
        if (node_less(h->a[cur], h->a[p])) {
            heap_swap(&h->a[cur], &h->a[p]);
            cur = p;
        } else break;
    }
}

static void heapify_down(heap_t *h) {
    int cur = 0;
    for (;;) {
        int l = 2*cur + 1, r = 2*cur + 2, s = cur;
        if (l < h->size && node_less(h->a[l], h->a[s])) s = l;
        if (r < h->size && node_less(h->a[r], h->a[s])) s = r;
        if (s == cur) break;
        heap_swap(&h->a[cur], &h->a[s]);
        cur = s;
    }
}

static void heap_init(heap_t *h, int cap, int start_ptr, int dir) {
    h->a = (node_t *)malloc(sizeof(node_t) * cap);
    h->size = 0;
    h->cap  = cap;
    h->ptr  = start_ptr;   // i for left, j for right
    h->dir  = dir;         // +1 left, -1 right
}

static void heap_free(heap_t *h) {
    free(h->a);
    h->a = NULL;
    h->size = h->cap = 0;
}

static bool heap_push(heap_t *h, node_t v) {
    if (h->size == h->cap) return false; // cap == candidates
    h->a[h->size++] = v;
    heapify_up(h);
    return true;
}

static node_t heap_top(const heap_t *h) {
    assert(h->size > 0);
    return h->a[0];
}

static node_t heap_pop(heap_t *h) {
    assert(h->size > 0);
    node_t ret = h->a[0];
    h->a[0] = h->a[--h->size];
    if (h->size) heapify_down(h);
    return ret;
}

static bool heap_try_refill(heap_t *h, const int *costs, int other_ptr) {
    if (h->dir == LEFT) {                
        if (h->ptr <= other_ptr) {
            node_t x = (node_t){ costs[h->ptr], h->ptr };
            h->ptr += 1;
            return heap_push(h, x);
        }
    } else {                        
        if (other_ptr <= h->ptr) {
            node_t x = (node_t){ costs[h->ptr], h->ptr };
            h->ptr -= 1;
            return heap_push(h, x);
        }
    }
    return false;
}


long long totalCost(int* costs, int costsSize, int k, int candidates) {
    heap_t L, R;
    heap_init(&L, candidates, 0,                LEFT);
    heap_init(&R, candidates, costsSize - 1,    RIGHT);

    // Preload up to `candidates` from each side, avoiding overlap.
    while (L.size < candidates && L.ptr <= R.ptr)
        heap_try_refill(&L, costs, R.ptr);
    while (R.size < candidates && L.ptr <= R.ptr)
        heap_try_refill(&R, costs, L.ptr);

    long long total = 0;
    for (int t = 0; t < k; ++t) {
        bool pickLeft;
        if (L.size && R.size) {
            pickLeft = node_less(heap_top(&L), heap_top(&R));
        } else if (L.size) {
            pickLeft = true;
        } else {
            pickLeft = false;
        }

        if (pickLeft) {
            node_t x = heap_pop(&L);
            total += x.cost;
            if (L.ptr <= R.ptr) heap_try_refill(&L, costs, R.ptr);
        } else {
            node_t x = heap_pop(&R);
            total += x.cost;
            if (L.ptr <= R.ptr) heap_try_refill(&R, costs, L.ptr);
        }
    }

    heap_free(&L);
    heap_free(&R);
    return total;
}